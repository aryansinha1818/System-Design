#include <iostream>
using namespace std;

class Light;

// state interface
class State
{
public:
    virtual void press(Light *light) = 0;
    //  virtual destructor
    virtual ~State() {}
};

// context
class Light
{
    State *state;

public:
    Light(State *s)
    {
        state = s;
    }

    void setState(State *s)
    {
        // deletes old state before switching
        delete state;
        state = s;
    }

    void press()
    {
        state->press(this);
    }

    ~Light()
    {
        // clean up last state
        delete state;
    }
};

// concrete States
class ON : public State
{
public:
    void press(Light *light) override;
};

class OFF : public State
{
public:
    void press(Light *light) override;
};

void ON::press(Light *light)
{
    cout << "Light turned OFF\n";
    light->setState(new OFF());
}

void OFF::press(Light *light)
{
    cout << "Light turned ON\n";
    light->setState(new ON());
}

int main()
{
    Light light(new OFF());

    light.press();
    light.press();
    light.press();

    return 0;
}
