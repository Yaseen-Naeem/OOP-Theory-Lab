#include <iostream>
using namespace std;

class CarEngine {
private:
    int horsepower;

public:
    CarEngine() {
        horsepower = 0;
    }

    CarEngine(int h) {
        horsepower = h;
    }

    friend class Mechanic;
};

class Car {
public:
    CarEngine engine;

    Car(int h) : engine(h) {}
};

class Mechanic {
public:
    void displayEngine(CarEngine e) {
        cout << "Horsepower: " << e.horsepower << endl;
    }

    void upgradeEngine(CarEngine &e) {
        int newHP;
        cout << "Enter new horsepower: ";
        cin >> newHP;

        while (newHP < 100 || newHP > 1000) {
            cout << "Invalid! Enter between 100 and 1000: ";
            cin >> newHP;
        }

        e.horsepower = newHP;
        cout << "Engine upgraded\n";
    }

    void displayCarEngine(Car c) {
        cout << "Car Engine HP: " << c.engine.horsepower << endl;
    }
};

int main() {
    CarEngine e1(150);
    Mechanic m;

    m.displayEngine(e1);

    m.upgradeEngine(e1);
    m.displayEngine(e1);

    Car c1(200);
    m.displayCarEngine(c1);

    return 0;
}