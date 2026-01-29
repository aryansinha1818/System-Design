#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

class Print
{
public:
    void bookPrint()
    {
        cout << "Book printed" << endl;
    }
};

class Print2
{
public:
    void filePrint()
    {
        cout << "File printed" << endl;
    }
};

int main()
{
    Print p;
    Print2 p2;
    p.bookPrint();
    p2.filePrint();
    return 0;
}