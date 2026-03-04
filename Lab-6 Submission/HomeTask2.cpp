// Create:
// Shape
// Circle
// Calculate area of circle using inherited radius.

#include <iostream>
using namespace std;

// Base Class
class Shape {
    public:
    double radius;

    Shape(double r) {
        radius = r;
    }
};

// Derived Class
class Circle : public Shape {
    public:

    Circle(double r) : Shape(r) {}

    void calculateArea() {
        double area = 3.14 * radius * radius;
        cout << "Radius: " << radius << endl;
        cout << "Area of Circle: " << area << endl;
    }
};

int main() {

    Circle c(5);   // radius 5
    c.calculateArea();

    return 0;
}