#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

class Light;

// state interface
class State
{
public:
    virtual void press(Light *light) = 0;
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
        state = s;
    }

    void press()
    {
        state->press(this);
    }
};

// concrete state
class ON : public State
{
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
};

void OFF::press(Light *light)
{
    cout << "Light turned ON\n";
    light->setState(new ON());
};

int main()
{
    // off class --- new off creates an obj of off
    Light light(new OFF());

    // first the light get's turned on
    light.press();
    // then it is turned off
    light.press();
    light.press();

    // working : Client does not change state
    //  State objects change the context internally
    //  Behavior changes automatically with state
    //  No if / else

    return 0;
}
