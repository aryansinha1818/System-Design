#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

// product
class Burger
{
public:
    bool cheese = false;
    bool lettuce = false;
    bool tomato = false;
    bool onion = false;
    bool pickle = false;
    bool mayo = false;

    // constructor

    void show()
    {
        cout << "Burger with : " << endl;
        if (cheese)
            cout << "Cheese" << endl;
        if (lettuce)
            cout << "Lettuce" << endl;
        if (tomato)
            cout << "Tomato" << endl;
        if (onion)
            cout << "Onion" << endl;
        if (pickle)
            cout << "Pickle" << endl;
        if (mayo)
            cout << "Mayo" << endl;
    }
};

// buidler

class BurgerBuilder
{
    // composition - cloured diamond
    Burger b;

public:
    BurgerBuilder &addCheese()
    {
        b.cheese = true;
        return *this;
    }

    BurgerBuilder &addLettuce()
    {
        b.lettuce = true;
        return *this;
    }

    BurgerBuilder &addTomato()
    {
        b.tomato = true;
        return *this;
    }

    BurgerBuilder &addOnion()
    {
        b.onion = true;
        return *this;
    }

    BurgerBuilder &addPickle()
    {
        b.pickle = true;
        return *this;
    }

    BurgerBuilder &addMayo()
    {
        b.mayo = true;
        return *this;
    }

    Burger build()
    {
        return b;
    }
};

int main()
{

    Burger b1 = BurgerBuilder().addCheese().addLettuce().addTomato().build();
    b1.show();

    return 0;
}