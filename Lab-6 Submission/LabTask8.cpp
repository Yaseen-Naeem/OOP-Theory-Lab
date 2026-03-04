// Implement the above structure.
// Observe the compilation error.
// Fix temporarily using:
// obj.Student::show();

#include <iostream>
using namespace std;

// Base Class 1
class Person {
    public:
    string name;

    void show() {
        cout << "Person Name: " << name << endl;
    }
};

// Base Class 2
class Student {
    public:
    int rollNo;

    void show() {
        cout << "Student Roll No: " << rollNo << endl;
    }
};

// Derived Class 
class Graduate : public Person, public Student {
    public:
    string course;
};

int main() {

    Graduate obj;
    obj.name = "Ali";
    obj.rollNo = 101;
    obj.course = "Computer Science";

    obj.Person::show();
    obj.Student::show();

    cout << "Course: " << obj.course << endl;

    return 0;
}