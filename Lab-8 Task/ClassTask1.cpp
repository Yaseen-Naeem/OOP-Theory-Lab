#include <iostream>
using namespace std;

class Student {
private:
    int m1, m2, m3;

public:
    void input() {
        cout << "Enter marks of 3 subjects: ";

        cin >> m1 >> m2 >> m3;

        while (m1 < 0 || m1 > 100 || m2 < 0 || m2 > 100 || m3 < 0 || m3 > 100) {
            cout << "Invalid marks! Enter again (0-100 only): ";
            cin >> m1 >> m2 >> m3;
        }
    }

    friend float calculateAverage(Student s);
};

float calculateAverage(Student s) {
    return (s.m1 + s.m2 + s.m3) / 3.0;
}

int main() {
    Student s;

    s.input();

    cout << "Average = " << calculateAverage(s);

    return 0;
}