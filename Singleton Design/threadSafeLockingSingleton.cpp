#include <iostream> // For input/output operations (cout)
#include <mutex>    // For std::mutex and std::lock_guard (thread safety)

using namespace std;

// Singleton class definition
class Singleton
{
private:
    // Static pointer to hold the single instance of the class
    static Singleton *instance;

    // Mutex used to ensure only one thread creates the instance at a time
    static mutex mtx;

    // Private constructor so that objects cannot be created directly
    Singleton()
    {
        cout << "Singleton Constructor Called!" << endl;
    }

    // delete copy constructor & assignment operator
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

public:
    // Public static method to provide global access to the single instance
    static Singleton *getInstance()
    {
        // Lock the mutex when entering this block (RAII style lock)
        // Ensures only one thread can run this code at a time
        lock_guard<mutex> lock(mtx);

        // If instance has not been created yet, create it
        if (instance == nullptr)
        {
            instance = new Singleton();
        }

        // Return the same instance every time
        return instance;
    }
};

// Define and initialize static members
Singleton *Singleton::instance = nullptr; // No instance initially
mutex Singleton::mtx;                     // Mutex object for synchronization

int main()
{
    // First call → creates Singleton instance and prints constructor message
    Singleton *s1 = Singleton::getInstance();

    // Second call → reuses the already created instance, no constructor call
    Singleton *s2 = Singleton::getInstance();

    // Prints 1 (true) since s1 and s2 point to the same memory address
    cout << (s1 == s2) << endl;

    return 0;
}

// this is thread-safe.
//  Here’s why:
//  You wrapped the object creation inside a lock_guard<mutex> lock(mtx);.
//  That means only one thread can enter the getInstance() method at the point where the instance is created.
//  Even if 10 threads call getInstance() at the same time, the mutex makes sure only one of them actually creates the object.
//  Once instance is created, all other threads will just skip the new Singleton() line and return the same pointer.

// ⚡ But — small note
//  This is thread-safe but not optimal because:
//  The mutex is locked every single time you call getInstance(), even after the instance is already created.
//  This adds a tiny overhead.
//  👉 That’s why interviewers sometimes ask:
//  “How would you improve performance?”
//  Answer: Use Double-Checked Locking → lock only when instance == nullptr.