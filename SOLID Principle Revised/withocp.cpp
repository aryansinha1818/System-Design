#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

class Payment
{
public:
    virtual void payVia() = 0;
};

class Credit : public Payment
{
public:
    void payVia() override
    {
        cout << "The amount paid through credit" << endl;
    }
};

class UPI : public Payment
{
public:
    void payVia() override
    {
        cout << "paid by UPI" << endl;
    }
};

int main()
{
    Credit *c = new Credit();
    UPI *u = new UPI();
    c->payVia();
    u->payVia();

    return 0;
}