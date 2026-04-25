#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string name;
    int age;

    try {
        ofstream file("students.txt");

        if (!file) {
            throw "File not opened for writing";
        }

        cout << "Enter Name and Age: " << endl;
        cin >> name >> age;

        file << "Name: " << name << endl;
        file << "Age: " << age << endl;

        file.close();

        ifstream readFile("students.txt");

        if (!readFile) {
            throw "File not opened for reading";
        }

        string line;
        while (getline(readFile, line)) {
            cout << line << endl;
        }

        readFile.close();
    }
    catch (const char* msg) {
        cout << "Exception: " << msg << endl;
    }

    return 0;
}