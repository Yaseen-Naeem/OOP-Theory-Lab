#include <iostream>
using namespace std;

template <class T>
T getMin(T a, T b) {
    return (a < b) ? a : b;
}

int main() {
    cout << getMin(10, 5) << endl;
    cout << getMin(3.5, 7.2) << endl;
    cout << getMin('z', 'a') << endl;

    return 0;
}