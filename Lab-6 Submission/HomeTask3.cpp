// Create:
// Driver
// Mechanic
// Technician (inherits both)
// Demonstrate both abilities.

#include <iostream>
using namespace std;

// First Base Class
class Driver {
    public:
    void drive() {
        cout << "Technician can drive vehicles." << endl;
    }
};

// Second Base Class
class Mechanic {
    public:
    void repair() {
        cout << "Technician can repair vehicles." << endl;
    }
};

// Derived Class 
class Technician : public Driver, public Mechanic {
    public:
    void showAbilities() {
        drive();    
        repair();   
    }
};

int main() {

    Technician t;  
    t.showAbilities();   

    return 0;
}