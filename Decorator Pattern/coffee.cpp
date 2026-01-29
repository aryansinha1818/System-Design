#include <iostream>
#include <string>
using namespace std;

// ==========================================================
// Step 1: Component Interface
// ==========================================================
// Coffee is the main interface (abstract class here).
// It defines what operations a "coffee" must support.
// => Every type of coffee must provide a description and a cost.
class Coffee
{
public:
    // Pure virtual function = must be implemented by subclasses.
    // "const" means this function won’t modify the object.
    virtual string getDescription() const = 0;

    // Another pure virtual function for cost.
    virtual double getCost() const = 0;

    // Always provide a virtual destructor in base classes
    // to avoid memory leaks when deleting through base pointer.
    virtual ~Coffee() {}
};

// ==========================================================
// Step 2: Concrete Component
// ==========================================================
// This is the "real" basic coffee that we sell without extras.
// Implements the Coffee interface.
class PlainCoffee : public Coffee
{
public:
    // Returns the basic description.
    string getDescription() const override
    {
        return "Plain Coffee";
    }

    // Returns the base cost.
    double getCost() const override
    {
        return 50.0; // base price
    }
};

// ==========================================================
// Step 3: Decorator (Abstract Wrapper)
// ==========================================================
// This is the key part of the pattern.
// CoffeeDecorator also "is a Coffee" (inherits from Coffee),
// but it wraps another Coffee object inside it.
// It does not add extra features yet, just forwards calls.
class CoffeeDecorator : public Coffee
{
protected:
    // A pointer to some Coffee object (can be PlainCoffee or another decorator).
    Coffee *coffee;

public:
    // Constructor: accepts a Coffee object to wrap.
    CoffeeDecorator(Coffee *c) : coffee(c) {}

    // Forwarding the description request to the wrapped coffee.
    string getDescription() const override
    {
        return coffee->getDescription();
    }

    // Forwarding the cost request to the wrapped coffee.
    double getCost() const override
    {
        return coffee->getCost();
    }
};

// ==========================================================
// Step 4: Concrete Decorators
// ==========================================================
// These add new behavior (extra features) by overriding methods.
// Each one modifies description/cost on top of what it wrapped.

// ----------------- Milk Decorator -------------------------
class MilkDecorator : public CoffeeDecorator
{
public:
    // Constructor: pass the base coffee to the parent decorator.
    MilkDecorator(Coffee *c) : CoffeeDecorator(c) {}

    // Add ", Milk" to the description.
    string getDescription() const override
    {
        return coffee->getDescription() + ", Milk";
    }

    // Add Rs. 10 to the base cost.
    double getCost() const override
    {
        return coffee->getCost() + 10.0;
    }
};

// ----------------- Sugar Decorator ------------------------
class SugarDecorator : public CoffeeDecorator
{
public:
    // Constructor: pass the base coffee to the parent decorator.
    SugarDecorator(Coffee *c) : CoffeeDecorator(c) {}

    // Add ", Sugar" to the description.
    string getDescription() const override
    {
        return coffee->getDescription() + ", Sugar";
    }

    // Add Rs. 5 to the base cost.
    double getCost() const override
    {
        return coffee->getCost() + 5.0;
    }
};

// ==========================================================
// Step 5: Client Usage
// ==========================================================
// The client builds coffee step by step, wrapping it with decorators.
// This shows how flexible and runtime-based the pattern is.
int main()
{
    // Start with a plain coffee.
    Coffee *coffee = new PlainCoffee();

    // Wrap it with MilkDecorator.
    // Now coffee has all features of PlainCoffee + Milk.
    coffee = new MilkDecorator(coffee);

    // Wrap it again with SugarDecorator.
    // Now coffee has all features of PlainCoffee + Milk + Sugar.
    coffee = new SugarDecorator(coffee);

    // Display the final description and cost.
    cout << coffee->getDescription() << endl; // Output: Plain Coffee, Milk, Sugar
    cout << coffee->getCost() << endl;        // Output: 65

    // Cleanup (important since we used new).
    delete coffee;

    return 0;
}
