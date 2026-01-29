#include <iostream>
using namespace std;

// Abstract base class
class Beverage
{
public:
    // ✅ Template Method → Defines the fixed algorithm structure
    void prepareRecipe()
    {
        boilWater();     // Concrete step
        brew();          // Abstract step (implemented by subclass)
        pourInCup();     // Concrete step
        addCondiments(); // Abstract step (implemented by subclass)
    }

    // ✅ Abstract Methods (must be overridden by subclasses)
    virtual void brew() = 0;
    virtual void addCondiments() = 0;

    // ✅ Concrete Methods (common steps, same for all subclasses)
    void boilWater()
    {
        cout << "Boiling water" << endl;
    }
    void pourInCup()
    {
        cout << "Pouring into cup" << endl;
    }
};

// Concrete subclass: Coffee
class Coffee : public Beverage
{
public:
    // Override abstract methods
    void brew() override
    {
        cout << "Dripping Coffee through filter" << endl;
    }
    void addCondiments() override
    {
        cout << "Adding Sugar and Milk" << endl;
    }
};

// Concrete subclass: Tea
class Tea : public Beverage
{
public:
    // Override abstract methods
    void brew() override
    {
        cout << "Steeping the tea" << endl;
    }
    void addCondiments() override
    {
        cout << "Adding Lemon" << endl;
    }
};

int main()
{
    // Using Template Method for Coffee
    Coffee c;
    c.prepareRecipe();

    // Using Template Method for Tea
    Tea t;
    t.prepareRecipe();

    return 0;
}
