#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("students.txt");

    string name;
    int age;

    for (int i = 0; i < 5; i++) {
        cout << "Enter Name And Age: " << endl;
        cin >> name >> age;

        file << "Name: " << name << endl;
        file << "Age: " << age << endl;
        file << "-------------------" << endl;
    }

    file.close();

    cout << "Records stored successfully" << endl;

    return 0;
}