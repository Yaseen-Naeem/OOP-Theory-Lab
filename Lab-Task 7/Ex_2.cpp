// Create the following classes:
// Base Class: Shape
// Derived Classes: Circle, Rectangle
// Each class should have a function: draw()
// Override the function in each derived class.

#include <iostream>
using namespace std;

// Base Class
class Shape {
public:
    void draw() {
        cout << "Drawing Shape" << endl;
    }
};

// Derived circle class
class Circle : public Shape {
public:
    void draw() {
        cout << "Drawing Circle" << endl;
    }
};

// Derived rectangle  class
class Rectangle : public Shape {
public:
    void draw() {
        cout << "Drawing Rectangle" << endl;
    }
};

int main() {
    Circle c;
    Rectangle r;

    c.draw();
    r.draw();

    return 0;
}