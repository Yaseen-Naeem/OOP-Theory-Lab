// Create a class Calculator that overloads a function multiply() to perform:
// Multiplication of two integers
// Multiplication of three integers
// Multiplication of two floating values

#include <iostream>
using namespace std;

class Calculator {
public:

    int multiply(int a, int b) {
        return a * b;
    }

    int multiply(int a, int b, int c) {
        return a * b * c;
    }

    float multiply(float a, float b) {
        return a * b;
    }
};

int main() {
    Calculator c;

    cout << "Multiplication of 2 integers: "
         << c.multiply(2, 3) << endl;

    cout << "Multiplication of 3 integers: "
         << c.multiply(2, 3, 4) << endl;

    cout << "Multiplication of 2 floats: "
         << c.multiply(2.5f, 3.5f) << endl;

    return 0;
}