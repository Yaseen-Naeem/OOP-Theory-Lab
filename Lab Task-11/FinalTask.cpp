#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    string name;
    int age;
};

void addStudent() {
    ofstream file("students.txt", ios::app);

    Student s;
    cin >> s.name >> s.age;

    file << s.name << " " << s.age << endl;

    file.close();

    cout << "Student added successfully\n";
}

void viewStudents() {
    ifstream file("students.txt");

    Student s;

    while (file >> s.name >> s.age) {
        cout << "Name: " << s.name << endl;
        cout << "Age: " << s.age << endl;
        cout << "-------------------" << endl;
    }

    file.close();
}

void searchStudent() {
    ifstream file("students.txt");

    string key;
    cout << "Enter Key: " << endl;
    cin >> key;

    Student s;
    bool found = false;

    while (file >> s.name >> s.age) {
        if (s.name == key) {
            cout << "Student Found" << endl;
            cout << "Name: " << s.name << endl;
            cout << "Age: " << s.age << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Student not found" << endl;
    }

    file.close();
}

int main() {
    int choice;

    do {
        cout << "\n1. Add Student\n2. View Students\n3. Search Student\n4. Exit\n";
        cin >> choice;

        if (choice == 1) addStudent();
        else if (choice == 2) viewStudents();
        else if (choice == 3) searchStudent();

    } while (choice != 4);

    return 0;
}