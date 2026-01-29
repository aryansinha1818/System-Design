#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

// strategy
class PaymentStrategy
{
public:
    virtual void pay() = 0;
};

// context startegy
class UPI : public PaymentStrategy
{
public:
    void pay() override
    {
        cout << "Paying via UPI";
    }
};

class Card : public PaymentStrategy
{
public:
    void pay() override
    {
        cout << "Paying via card" << endl;
    }
};

// context
class PaymentContext
{
    PaymentStrategy *strategy;

public:
    // constructor
    PaymentContext(PaymentStrategy *s)
    {
        strategy = s;
    }
    void payment()
    {
        strategy->pay();
    }
};

int main()
{
    UPI u1;
    Card c1;

    PaymentContext p1(&u1);
    p1.payment();

    return 0;
}