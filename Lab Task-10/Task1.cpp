#include <iostream>
using namespace std;

template <class T>
T getSum(T a, T b) {
    return a + b;
}

template <class T>
T getDifference(T a, T b) {
    return a - b;
}

template <class T>
T getProduct(T a, T b) {
    return a * b;
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << "Sum: " << getSum(a, b) << endl;
    cout << "Difference: " << getDifference(a, b) << endl;
    cout << "Product: " << getProduct(a, b) << endl;

    return 0;
}