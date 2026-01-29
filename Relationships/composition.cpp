// is-a strong relationship

//In UML class diagrams, composition is represented by a filled diamond (◆) at the “whole” end of the relationship.
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
    // strong relation - Car would have Engine
    Engine e;

public:
    void drive()
    {
        e.start();
        cout << "Car is moving" << endl;
    }
};

int main()
{
    Car c;     // when Car is created, its Engine is also created
    c.drive(); // Car automatically uses its own Engine

    // when Car object 'c' is destroyed, its Engine is also destroyed
    return 0;
}