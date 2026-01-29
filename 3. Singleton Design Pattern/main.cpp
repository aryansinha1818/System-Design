#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

//
class Singleton
{
    // private constructor

    // so outside when you would make an obj that is not allowed
private:
    Singleton()
    {
        cout << " Singleton created \n"
             << endl;
    }
    // public
    // static instance
public:
    static Singleton &getInstance()
    {
        // one shared obj
        static Singleton instance;

        return instance;
    }
    void show()
    {
        cout << "Hello from Singleton \n"
             << endl;
    }
};

int main()
{
    Singleton &s1 = Singleton::getInstance();
    Singleton &s2 = Singleton::getInstance();

    s1.show();
    s2.show();

    cout << (&s1 == &s2) << endl;

    return 0;
}