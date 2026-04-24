#include <iostream>
using namespace std;

template <class T>
class Array {
    T arr[100];
    int size;

public:
    Array(int s) {
        size = s;
    }

    void input() {
        for (int i = 0; i < size; i++) {
            cin >> arr[i];
        }
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    T findMax() {
        T max = arr[0];
        for (int i = 1; i < size; i++) {
            if (arr[i] > max) {
                max = arr[i];
            }
        }
        return max;
    }
};

int main() {
    int n;
    cin >> n;

    Array<int> a(n);

    a.input();

    cout << "Elements: ";
    a.display();

    cout << "Max: " << a.findMax() << endl;

    return 0;
}