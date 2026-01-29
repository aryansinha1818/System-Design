#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

class Car
{
public:
    void car()
    {
        cout << "A new car is created!" << endl;
    }
};

int main()
{
    Car c1;
    c1.car();
    Car c2;
    c2.car();
}