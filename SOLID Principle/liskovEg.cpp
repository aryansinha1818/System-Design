#include <iostream>
using namespace std;

class PaymentMethod
{
public:
    virtual void pay(int amount)
    {
        cout << "Paying " << amount << " using base method." << endl;
    }
};

class CreditCard : public PaymentMethod
{
public:
    void pay(int amount) override
    {
        cout << "Paid " << amount << " using Credit Card." << endl;
    }
};

class UPI : public PaymentMethod
{
public:
    void pay(int amount) override
    {
        cout << "Paid " << amount << " using UPI." << endl;
    }
};

void processPayment(PaymentMethod *method)
{
    method->pay(500);
}

int main()
{
    CreditCard cc;
    UPI upi;

    processPayment(&cc);  // ✅ works
    processPayment(&upi); // ✅ works

    return 0;
}

// Base class PaymentMethod ke pointer se hum CreditCard aur UPI dono ko use kar paa rahe hain bina crash ke ✅
// LSP follow ho raha hai.

// ❌ Bad Example (LSP Broken)
// Now let’s say we create a new class:

// class Cash : public PaymentMethod {
// public:
//     void pay(int amount) override {
//         throw runtime_error("Cash payments not supported online!");
//     }
// };

// Cash c;
// processPayment(&c); // ❌ Will crash!
// 🚫 Problem:
// Cash bhi PaymentMethod hai, but pay() karte hi crash ho gaya.

// LSP break ho gaya — kyunki parent type (PaymentMethod) assume karta hai ki har child pay() safely karega.

// 🔑 Rule yaad rakh:
// Agar base class ka pointer (jaise PaymentMethod*) kisi child class ko point kare, aur code safely chale — toh LSP follow ho raha hai.