#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string name;
    int age;

    cout << "Enter Name And Age: " << endl;

    cin >> name >> age;

    ofstream file("student.txt");

    file << "Name: " << name << endl;
    file << "Age: " << age << endl;

    file.close();

    cout << "Data stored successfully" << endl;

    return 0;
}