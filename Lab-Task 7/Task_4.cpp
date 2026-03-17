// Create a virtual function example where:
// Base Class → Vehicle
// Derived Classes → Car, Bike, Truck
// Each class should override the function: startEngine()
// Use base class pointer to call functions dynamically.

#include <iostream>
using namespace std;

// Base Class
class Vehicle {
public:
    virtual void startEngine() {
        cout << "Starting Vehicle Engine" << endl;
    }
};

// Derived car class
class Car : public Vehicle {
public:
    void startEngine() {
        cout << "Car Engine Started" << endl;
    }
};

// Derived bike class
class Bike : public Vehicle {
public:
    void startEngine() {
        cout << "Bike Engine Started" << endl;
    }
};

// Derived truck class
class Truck : public Vehicle {
public:
    void startEngine() {
        cout << "Truck Engine Started" << endl;
    }
};

int main() {
    Vehicle* v;  

    Car c;
    Bike b;
    Truck t;

    v = &c;
    v->startEngine();

    v = &b;
    v->startEngine();

    v = &t;
    v->startEngine();

    return 0;

 }