// weak - has a
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

class Engine
{
public:
    void start()
    {
        cout << "Engine started" << endl;
    }
};

class Car
{
    // Weak relation: Car only has a reference to Engine, not ownership
    Engine *e;

public:
    // Constructor takes an Engine from outside
    Car(Engine *engine)
    {
        e = engine;
    }
    void drive()
    {
        if (e)
        {
            e->start();
            cout << "Car is moving" << endl;
        }
        else
        {
            cout << "No engine found, car cannot move!" << endl;
        }
    }
};

int main()
{
    Engine e; // Engine created independently
    e.start();

    Car c(&e); // Car uses Engine (aggregation)
    c.drive();

    return 0;
}