// Create:
// Appliance
// WashingMachine
// SmartWashingMachine
// Add a smart control function.

#include <iostream>
using namespace std;

// Base Class
class Appliance {
    public:
    string brand;

    Appliance(string b) {
        brand = b;
    }

    void showAppliance() {
        cout << "Appliance Brand: " << brand << endl;
    }
};

// Derived Class
class WashingMachine : public Appliance {
    public:
    int capacity; 

    WashingMachine(string b, int c) : Appliance(b) {
        capacity = c;
    }

    void showWashingMachine() {
        cout << "Capacity: " << capacity << " kg" << endl;
    }
};

// Derived Class 
class SmartWashingMachine : public WashingMachine {
    public:
    SmartWashingMachine(string b, int c) : WashingMachine(b, c) {}

    void smartControl() {
        cout << "Smart Control Activated: You can control via app!" << endl;
    }
};

int main() {

    SmartWashingMachine swm("LG", 7);

    cout << "\n--- Smart Washing Machine Details ---" << endl;
    swm.showAppliance();
    swm.showWashingMachine();
    swm.smartControl();

    return 0;
}