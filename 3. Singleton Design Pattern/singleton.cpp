#include <iostream>
using namespace std;

class TVRemote
{
private:
    // static instance
    static TVRemote *instance;

    // private constructor
    TVRemote() {};

public:
    static TVRemote *getInstance()
    {
        if (instance == nullptr)
        {
            instance = new TVRemote();
        }
        return instance;
    }

    void button()
    {
        cout << "Button is pressed!!" << endl;
    }
};

TVRemote *TVRemote::instance = nullptr;

int main()
{
    TVRemote *r1 = TVRemote::getInstance();
    TVRemote *r2 = TVRemote::getInstance();

    r1->button();
    r2->button();

    if (r1 == r2)
    {
        cout << "Both are same" << endl;
    }
}