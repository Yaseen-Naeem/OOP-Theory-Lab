// Create a program that demonstrates function overloading for calculating area:
// Functions required:

// area(int side) → square
// area(int length, int width) → rectangle
// area(double radius) → circle

#include <iostream>
using namespace std;

class Area {
public:

    // Area of square
    int area(int side) {
        return side * side;
    }

    // Area of rectangle
    int area(int length, int width) {
        return length * width;
    }

    // Area of circle
    double area(double radius) {
        return 3.14 * radius * radius;
    }
};

int main() {
    
    Area a;
    cout << "Area of Square: "<< a.area(4) << endl;
    cout << "Area of Rectangle: " << a.area(4, 5) << endl;
    cout << "Area of Circle: " << a.area(2.5)<< endl;
     return 0;
}