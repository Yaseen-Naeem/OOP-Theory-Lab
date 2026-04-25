#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    string name;
    int age;
};

int main() {
    ifstream file("students.dat", ios::binary);

    Student s;

    while (file.read((char*)&s, sizeof(s))) {
        cout << "Name: " << s.name << endl;
        cout << "Age: " << s.age << endl;
        cout << "-------------------" << endl;
    }

    file.close();

    return 0;
}