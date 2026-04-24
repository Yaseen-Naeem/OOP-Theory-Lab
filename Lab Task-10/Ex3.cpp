#include <iostream>
using namespace std;

int main() {
    int age;
    cin >> age;

    try {
        if (age < 18) {
            throw age;
        }
        cout << "Access Granted" << endl;
    }
    catch (int a) {
        cout << "Exception: Age must be 18 or above" << endl;
    }

    return 0;
}