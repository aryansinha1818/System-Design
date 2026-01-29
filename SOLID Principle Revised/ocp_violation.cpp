#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

class Payment
{
public:
    void process(string method)
    {
        if (method == "cash")
        {
            cout << "Processing cash payment" << endl;
        }
        else if (method == "card")
        {
            cout << "Processing card payment" << endl;
        }
        else if (method == "UPI")
        {
            cout << "Processing UPI payment" << endl;
        }
    }
};

// if the future comes credit card then we would have ti modify the exiting code which would violate ocp

int main()
{
    Payment p;
    p.process("cash");
    p.process("card");
    p.process("UPI");
    return 0;
}