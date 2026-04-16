#include <iostream>
using namespace std;

class Person {
private:
    int id;
    string name;

public:
    Person() {
        id = 0;
        name = "";
    }

    Person(int i, string n) {
        id = i;
        name = n;
    }

    void displayPerson() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
    }
};

class Student : virtual public Person {
public:
    float gpa;

    Student() {
        gpa = 0;
    }

    Student(int i, string n, float g) : Person(i, n) {
        gpa = g;
    }
};

class Employee : virtual public Person {
public:
    float salary;

    Employee() {
        salary = 0;
    }

    Employee(int i, string n, float s) : Person(i, n) {
        salary = s;
    }
};

class TeachingAssistant : public Student, public Employee {
public:
    TeachingAssistant(int i, string n, float g, float s)
        : Person(i, n), Student(i, n, g), Employee(i, n, s) {}

    void display() {
        // No ambiguity now due to virtual inheritance
        displayPerson();
        cout << "GPA: " << gpa << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {

    // NOTE:
    // If virtual is removed → two copies of Person → ambiguity:
    // t.id or t.name will cause error

    TeachingAssistant t(101, "Ali", 3.8, 40000);

    t.display();

    return 0;
}