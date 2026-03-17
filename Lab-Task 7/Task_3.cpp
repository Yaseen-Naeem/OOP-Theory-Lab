// Write a program that demonstrates operator overloading for complex numbers using:

// +
// -
// *

#include <iostream>
using namespace std;

class Complex {
public:
    int real, imag;
    Complex(int r = 0, int i = 0) {
        real = r;
        imag = i;
    }

    // + operator
    Complex operator+(Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }

    // - operator
    Complex operator-(Complex c) {
        return Complex(real - c.real, imag - c.imag);
    }

    // * operator
    Complex operator*(Complex c) {
        return Complex(real * c.real - imag * c.imag,
                       real * c.imag + imag * c.real);
    }

    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(2, 3), c2(1, 4);

    Complex sum = c1 + c2;
    Complex diff = c1 - c2;
    Complex prod = c1 * c2;

    cout << "Addition: ";
    sum.display();

    cout << "Subtraction: ";
    diff.display();

    cout << "Multiplication: ";
    prod.display();

      return 0;


}