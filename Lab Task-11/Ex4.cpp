#include <iostream>
#include <fstream>
using namespace std;

class Student {
public:
    string name;
    int age;
};

int main() {
    ofstream file("students.dat", ios::binary);

    Student s;

    for (int i = 0; i < 3; i++) {
        cout << "Enter Name And Age: " << endl;
        cin >> s.name >> s.age;
        file.write((char*)&s, sizeof(s));
    }

    file.close();

    cout << "Data stored in binary file successfully" << endl;

    return 0;
}