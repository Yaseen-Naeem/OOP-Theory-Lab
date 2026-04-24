#include <iostream>
using namespace std;

template <class T>
class Calculator {
    T a, b;

public:
    Calculator(T x, T y) {
        a = x;
        b = y;
    }

    T add() {
        return a + b;
    }

    T subtract() {
        return a - b;
    }

    T multiply() {
        return a * b;
    }

    T divide() {
        return a / b;
    }
};

int main() {
    Calculator<int> c1(10, 5);

    cout << "Addition: " << c1.add() << endl;
    cout << "Subtraction: " << c1.subtract() << endl;
    cout << "Multiplication: " << c1.multiply() << endl;
    cout << "Division: " << c1.divide() << endl;

    return 0;
}