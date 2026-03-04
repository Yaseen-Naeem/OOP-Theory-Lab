// Create:
// Person
// Employee (inherits Person)
// Developer (inherits Employee)
// Display:
// Name
// Salary
// Programming Language

#include <iostream>
using namespace std;

// Base Class
class Person {
    public:
    string name;

    Person(string n) {
        name = n;
    }
};

// Derived from Person
class Employee : public Person {
    public:
    double salary;

    Employee(string n, double s) : Person(n) {
        salary = s;
    }
};

// Derived from Employee
class Developer : public Employee {
    public:
    string language;

    Developer(string n, double s, string lang)
        : Employee(n, s) {
        language = lang;
    }

    void display() {
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "Programming Language: " << language << endl;
    }
};

int main() {

    Developer d("Ali", 80000, "C++");

    cout << "\n--- Developer Details ---" << endl;
    d.display();

    return 0;
}