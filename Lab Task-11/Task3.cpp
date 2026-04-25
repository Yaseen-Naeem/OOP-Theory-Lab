#include <iostream>
#include <fstream>
using namespace std;

void display() {
    ifstream file("students.txt");
    string line;

    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

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

    cout << "Records stored successfully\n\n";
    cout << "Stored Data:\n";

    display();

    return 0;
}