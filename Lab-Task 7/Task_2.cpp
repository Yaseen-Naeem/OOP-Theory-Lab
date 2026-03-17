// Create a base class Employee with function:
// calculateSalary()

// Create derived classes:
// Manager
// Developer
// Intern
// Override the salary calculation in each class.

#include <iostream>
using namespace std;

// Base Class
class Employee {
public:
    void calculateSalary() {
        cout << "Calculating Employee Salary" << endl;
    }
};

// Derived managee class
class Manager : public Employee {
public:
    void calculateSalary() {
        cout << "Manager Salary = 80000" << endl;
    }
};

// Derived developer class
class Developer : public Employee {
public:
    void calculateSalary() {
        cout << "Developer Salary = 50000" << endl;
    }
};

// Derived intern class
class Intern : public Employee {
public:
    void calculateSalary() {
        cout << "Intern Salary = 20000" << endl;
    }
};

int main() {
    Manager m;
    Developer d;
    Intern i;

    m.calculateSalary();
    d.calculateSalary();
    i.calculateSalary();
    return 0;


}