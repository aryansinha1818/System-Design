#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

// observer
class Display
{
public:
    void update(int temp)
    {
        cout << "Temperature is " << temp << endl;
    }
};

// Subject
class Weather
{
    Display *display;

public:
    void setDisplay(Display *d)
    {
        display = d;
    }

    void setTemperature(int t)
    {
        display->update(t); // notify observer
    }
};

int main()
{
    Weather weather;
    Display screen;

    weather.setDisplay(&screen);

    weather.setTemperature(25);
    weather.setTemperature(30);

    return 0;
}