#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;
// Yeh ek simple example hai of Runtime Polymorphism in C++.
class Bird
{
public:
    virtual void act()
    {
        cout << " This is bird in general " << endl;
    }
};

class Sparrow : public Bird
{
public:
    void act() override
    {
        cout << "I can fly " << endl;
    }
};
int main()
{
    Bird *b = new Sparrow();
    b->act();

    return 0;
}

// 🔍 Step-by-step:
// Bird *b = new Sparrow();
// ➤ Ek pointer banaya jo Bird type ka hai
// ➤ But actual object jisko wo point kar raha hai, wo Sparrow ka hai.

// ⚠️ Yahi hai runtime polymorphism : Base class pointer → Derived class object

// b->act();
// ➤ act() virtual function hai.
// ➤ So C++ runtime dekhega ki b actually kis type ka object point kar raha hai.
// ➤ Wo dekh ke Sparrow ka act() run karega.