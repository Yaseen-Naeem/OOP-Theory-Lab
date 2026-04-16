#include <iostream>
using namespace std;

class Person {
public:
    int id;
    string name;

    Person() {
        id = 0;
        name = "";
    }

    Person(int i, string n) {
        id = i;
        name = n;
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
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "GPA: " << gpa << endl;
        cout << "Salary: " << salary << endl;
    }
};

int main() {
    TeachingAssistant t(101, "Ali", 3.7, 50000);

    t.display();

    return 0;
}