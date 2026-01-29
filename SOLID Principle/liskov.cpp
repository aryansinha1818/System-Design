#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;
class Payment
{
public:
    virtual void pay(int amount)
    {
        cout << "The amounnt is " << amount << endl;
    }
};

class credit : public Payment
{
public:
    void payto(int amount)
    {
        cout << "The amount paid through credit " << amount << endl;
    }
};

class UPI : public Payment
{
public:
    void pay(int amount) override
    {
        cout << "The amount paid through upi " << amount << endl;
    }
};

void processPayment(Payment *p1)
{
    p1->pay(500);
}
int main()
{
    credit c;
    // virtual ka matlab: agar koi child class is function ko override karegi, toh child class ka version chalega.
    c.pay(5000);
    c.payto(50000);

    credit c1;
    processPayment(&c1);

    UPI upi;
    // processPayment(&upi);
    upi.pay(1807);

    return 0;
}