#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

class Print
{
public:
    void print()
    {

        cout << "Book is printed" << endl;

        cout << "File is printed" << endl;
    }
};

int main()
{
    Print p;
    p.print();
    return 0;
}
