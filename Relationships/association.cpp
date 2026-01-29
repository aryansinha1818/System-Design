// simple it shows how obj of 1 class is connected to obj of another class
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

class Teacher
{
public:
    string name;
    // constructor
    //  Teacher(string s) : name(s){};

    Teacher(string s)
    {
        name = s;
    }
    // method
    void teach()
    {
        cout << name << " is teaching \n";
    }
};

class Student
{
public:
    string name;
    Student(string s)
    {
        name = s;
    }
    // association - student knows teacher
    void learnFrom(Teacher &t)
    {
        // saare chiz idhar aagye teacher ke
        // t naame ka ek obj bana hua hai
        cout << name << " is learning from " << t.name << "\n";
        t.teach();
        cout << "the name- " << t.name;
    }
};
int main()
{
    Teacher t("Sumit");
    Student s("Aryan");

    t.teach();
    Teacher y1("Pickachu");
    // ek obj ko bhejo ge
    s.learnFrom(y1);

    return 0;
}