#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string name;
    int age;     
    
    cout << "Enter Name And Age: " << endl;

    cin >> name >> age;

    ofstream file("student.txt", ios::app);

    file << "Name: " << name << endl;
    file << "Age: " << age << endl;
    file << "-------------------" << endl;

    file.close();

    cout << "Data appended successfully" << endl;

    return 0;
}