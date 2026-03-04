// Create:
// Class Employee
// Data: ID, Salary
// Function: showEmployee()
// Class Manager (inherits Employee)
// Data: Bonus
// Function: showManager()
// Display complete salary (Salary + Bonus).

#include <iostream>
using namespace std;

// Base Class
class Employee {
    public:
    int id;
    double salary;

    Employee() {
        id = 0;
        salary = 0;
        cout << "Employee Default Constructor Called" << endl;
    }

    Employee(int i, double s) {
        id = i;
        salary = s;
    }

    void showEmployee() {
        cout << "Employee ID: " << id << endl;
        cout << "Salary: " << salary << endl;
    }
};

// Derived Class
class Manager : public Employee {
    public:
    double bonus;

    Manager() : Employee() {
        bonus = 0;
        cout << "Manager Default Constructor Called" << endl;
    }

    Manager(int i, double s, double b) : Employee(i, s) {
        bonus = b;
    }

    void showManager() {
        cout << "Bonus: " << bonus << endl;
        cout << "Complete Salary (Salary + Bonus): "
             << salary + bonus << endl;
    }
};

int main() {

    Manager m(101, 50000, 10000);

    cout << "\n--- Manager Details ---" << endl;
    m.showEmployee();
    m.showManager();

    return 0;
}