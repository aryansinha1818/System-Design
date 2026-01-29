// is-a
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

class Animal
{
public:
    void fun()
    {
        cout << "Animal class is called!!" << endl;
    }
};

class Bird : public Animal
{
public:
    void fun1()
    {
        cout << "I am bird class" << endl;
    }
};

int main()
{
    Animal a;
    a.fun();
    Bird b;
    b.fun1();
    b.fun();
    return 0;
}