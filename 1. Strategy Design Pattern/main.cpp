#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

// strategy
class Payment
{
    // interface -- pure virtual functions
public:
    virtual void payVia() = 0;
};

// concrete startegy
class UPI : public Payment
{
    void payVia() override
    {
        cout << "Payment by UPI" << endl;
    }
};
class Card : public Payment
{
    void payVia() override
    {
        cout << "Payment by card" << endl;
    }
};

// context - uses the strategy and does not implement it
class PaymentContext
{
    Payment *strategy;

public:
    // constructor
    PaymentContext(Payment *s)
    {
        strategy = s;
    }

    void makePayment()
    {
        strategy->payVia();
    }
};

int main()
{
    UPI upi;

    PaymentContext py(&upi);
    py.makePayment();
    return 0;
}