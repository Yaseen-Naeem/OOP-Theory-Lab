#include <iostream>
using namespace std;

int main() {
    int marks;
    cin >> marks;

    try {
        if (marks < 0 || marks > 100) {
            throw marks;
        }
        cout << "Marks are valid" << endl;
    }
    catch (int m) {
        if (m < 0)
            cout << "Exception: Marks cannot be negative" << endl;
        else
            cout << "Exception: Marks cannot be greater than 100" << endl;
    }

    return 0;
}