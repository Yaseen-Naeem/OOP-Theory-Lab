#include <iostream>
using namespace std;

class Rectangle {
private:
    float length;
    float width;

public:
    void input() {
        cout << "Enter length and width: ";
        cin >> length >> width;

        while (length <= 0 || width <= 0) {
            cout << "Invalid input! Enter positive values: ";
            cin >> length >> width;
        }
    }

    friend void calculate(Rectangle r);
};

void calculate(Rectangle r) {
    float area = r.length * r.width;
    float perimeter = 2 * (r.length + r.width);

    cout << "Area = " << area << endl;
    cout << "Perimeter = " << perimeter << endl;
}

int main() {
    Rectangle r;

    r.input();

    calculate(r);

    return 0;
}