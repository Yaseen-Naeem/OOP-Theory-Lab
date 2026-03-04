// Create a class Person with:
// Name
// Age
// A function displayInfo()
// 2. Create a class Student that inherits from Person and adds:
// Roll Number
// Function displayStudent()
// 3. Create an object and display all information.


#include <iostream>
using namespace std;

// Base Class
class Person {
    public:
    string name;
    int age;

    void getInfo() {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Age: ";
        cin >> age;
    }

    void displayInfo() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

// Derived Class
class Student : public Person {
    public:
    int rollNo;

    void getStudent() {
        cout << "Enter Roll Number: ";
        cin >> rollNo;
    }

    void displayStudent() {
        cout << "Roll Number: " << rollNo << endl;
    }
};

int main() {

    Student s;  
    s.getInfo();
    s.getStudent();

    cout << "\n--- Student Details ---" << endl;

    s.displayInfo();
    s.displayStudent();

    return 0;
}