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
        if (b == 0) {
            throw "Division by zero error";
        }
        return a / b;
    }
};

int main() {
    double x, y;

    try {
        cin >> x >> y;

        if (cin.fail()) {
            throw "Invalid input";
        }

        Calculator<double> c(x, y);

        cout << "Addition: " << c.add() << endl;
        cout << "Subtraction: " << c.subtract() << endl;
        cout << "Multiplication: " << c.multiply() << endl;
        cout << "Division: " << c.divide() << endl;
    }
    catch (const char* msg) {
        cout << "Exception: " << msg << endl;
    }

    return 0;
}