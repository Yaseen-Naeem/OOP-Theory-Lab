// Create a class Vehicle with:
// Brand
// Speed
// Function showVehicle()
// Derive a class Car from Vehicle that adds:
// Fuel Type
// Function showCarDetails()

#include <iostream>
using namespace std;

// Base Class
class Vehicle {
    public:
    string brand;
    int speed;

    void getVehicle() {
        cout << "Enter Brand: ";
        cin >> brand;
        cout << "Enter Speed: ";
        cin >> speed;
    }

    void showVehicle() {
        cout << "Brand: " << brand << endl;
        cout << "Speed: " << speed << " km/h" << endl;
    }
};

// Derived Class
class Car : public Vehicle {
    public:
    string fuelType;

    void getCar() {
        cout << "Enter Fuel Type: ";
        cin >> fuelType;
    }

    void showCarDetails() {
        cout << "Fuel Type: " << fuelType << endl;
    }
};

int main() {

    Car c;   
    c.getVehicle();
    c.getCar();

    cout << "\n--- Car Details ---" << endl;

    c.showVehicle();
    c.showCarDetails();

    return 0;
}