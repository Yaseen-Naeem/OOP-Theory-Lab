#include <iostream>
#include <string>
#include "IDisplay.h"
#include "IFilter.h"
#include "IMessage.h"
#include "IAd.h"

using namespace std;

// CONCEPT: COMPOSITION 
// Engine and Location are "composed" into the Vehicle class.
// This represents a "Has-A" relationship (Vehicle Has-A Engine).
class Engine {
    int hp;
public:
    Engine(int h = 0) : hp(h) {

    }
    
// CONCEPT: OPERATOR OVERLOADING
// Overloading '==' to compare engine power directly.
    bool operator==(const Engine& e) const {
        return hp == e.hp; 
    }

// Overloading '+' to combine horsepower from two engines.
    Engine operator+(const Engine& e) const {
        return Engine(hp + e.hp); 
    }
    
// CONCEPT: FRIEND FUNCTION (Operator Overloading)
// Allows the use of 'cout << engine' by giving the global operator access to private hp.

    friend ostream& operator<<(ostream& out, const Engine& e) {
        return out << e.hp << "HP"; 
    }
};

class Location {
    string city;
public:
    Location(string c = "") : city(c) {

    }

    bool operator==(const Location& l) const {
        return city == l.city; 
    }

    friend ostream& operator<<(ostream& out, const Location& l) {
        return out << l.city; 
    }
};

// CONCEPT: INHERITANCE (Base Class) 
// Vehicle inherits from IDisplay and IFilter (Multiple Inheritance).
// This acts as the root for all specialized transport types.

class Vehicle : public IDisplay, public IFilter {
protected:
    int id; string brand; double price; bool approved; Engine engine; Location loc;
public:
    Vehicle(int i, string b, double p, Engine e, Location l) : id(i), brand(b), price(p), engine(e), loc(l), approved(false) {

    }

    void approve() {
        approved = true;
    }

// CONCEPT: POLYMORPHISM (Virtual Function Overriding)
// Providing a base implementation for display.

    void display() const override {
        cout << "\n" << brand << " | PKR " << price; 
    }

// CONCEPT: PURE VIRTUAL FUNCTION
// Makes Vehicle an abstract class; forces children to define their own 'details'.

    virtual void details() const = 0;

// Implementing the IFilter interface functionality.

    bool match(string b, double maxP) const override {
        return (brand == b || b == "") && price <= maxP; 
    }

    bool operator==(const Vehicle& v) const {
        return id == v.id; 
    }

    bool operator<(const Vehicle& v) const {
        return price < v.price; 
    }

    friend ostream& operator<<(ostream& out, const Vehicle& v) {
        return out << v.brand << " " << v.price; 
    }
    
// CONCEPT: FRIEND FUNCTION
// A non-member function that can access private/protected vehicle data.
    friend bool comparePrice(const Vehicle& v1, const Vehicle& v2);
    virtual ~Vehicle() {

    }
};

bool comparePrice(const Vehicle& v1, const Vehicle& v2) { 
    return v1.price < v2.price; 
}

// CONCEPT: INHERITANCE (Derived Classes) 
// Car and Bike specialize the Vehicle class.
class Car : public Vehicle {
    int doors;
public:
    Car(int i, string b, double p, Engine e, Location l, int d) : Vehicle(i, b, p, e, l), doors(d) {

    }
    
// Overriding the pure virtual function from the base class.
    void details() const override {
        cout << " [Doors: " << doors << "]"; 
    }

// CONCEPT: POLYMORPHISM (Function Overloading)
// Two functions with the same name but different parameters.
    void discount(double d) {
        price -= d; 
    }

    void discount(double d, string r) {
        price -= d; cout << " Reason: " << r;
    }
};

class Bike : public Vehicle {
    int cc;
public:
    Bike(int i, string b, double p, Engine e, Location l, int c) : Vehicle(i, b, p, e, l), cc(c) {

    }

    void details() const override {
        cout << " [CC: " << cc << "]";
    }
};

// Further Inheritance levels to hit the 10-12 relationship requirement.
class ElectricCar : public Car { 
public: 
    ElectricCar(int i, string b, double p, Engine e, Location l, int d) : Car(i, b, p, e, l, d) {

    } 
};

class SportsBike : public Bike { public: SportsBike(int i, string b, double p, Engine e, Location l, int c) : Bike(i, b, p, e, l, c) {

    } 
};

class Truck : public Vehicle { public: Truck(int i, string b, double p, Engine e, Location l) : Vehicle(i, b, p, e, l) {

    }

void details() const override {
    cout << " [Truck]"; 
    } 
};

// CONCEPT: ABSTRACTION (User Hierarchy) 
// User is an abstract class because showProfile() is pure virtual.
class User : public IDisplay {
protected:
    int id; string name;
public:
    User(int i, string n) : id(i), name(n) {

    }

    bool operator==(const User& u) const {
        return id == u.id;
    }

    virtual void showProfile() const = 0;
    
// CONCEPT: FRIEND CLASS
// Grants the Admin class access to User's private and protected members.
    friend class Admin;
    virtual ~User() {

    }
};

class Buyer : public User, public IMessage {
public:
    Buyer(int i, string n) : User(i, n) {

    }

    void receive(string m) override {
        cout << "\nBuyer " << name << ": " << m;
     }

    void display() const override {
        cout << "\nBuyer: " << name; 
    }

    void showProfile() const override {
        cout << "\nBuyer Profile: " << name; 
    }
};

class Seller : public User, public IMessage, public IAd {
public:
    Seller(int i, string n) : User(i, n) {

    }

    void addAd(Vehicle* v) override {

    } // Implementation of IAd interface

    void receive(string m) override {
        cout << "\nSeller " << name << ": " << m; 
    }

    void display() const override {
        cout << "\nSeller: " << name; 
    }

    void showProfile() const override {
        cout << "\nSeller Profile: " << name;
     }
};

class Admin : public User {
public:
    Admin(int i, string n) : User(i, n) {

    }

    void approve(Vehicle* v) {
        v->approve(); 
    }

    void display() const override {
        cout << "\nAdmin: " << name; 
    }

    void showProfile() const override {
        cout << "\nAdmin Profile: " << name; 
    }
    
// Admin uses its Friend status to modify User data directly.
    void resetUserID(User* u) {
        u->id = 0; 
    } 
};

// Final inheritance relationship.
class SuperAdmin : public Admin {
public: 
    SuperAdmin(int i, string n) : Admin(i, n) {

    } 
};

//  MAIN PROGRAM 

int main() {
    Admin a(1, "SystemAdmin");
    Seller s(2, "Shoaib");
    Buyer b(3, "Ali");
    Engine e1(200), e2(100);
    Location l1("Karachi");

// Dynamic allocation demonstrating polymorphism.
    Car* c = new Car(101, "Honda", 4500000, e1, l1, 4);
    Bike* bk = new Bike(102, "Yamaha", 300000, e2, l1, 125);

    a.approve(c);
    s.addAd(c);

    cout << "--- MARKET ---";
    c->display(); c->details(); // Runtime Polymorphism
    bk->display(); bk->details();

    cout << "\n\n--- OPERATORS & FRIENDS ---";
    cout << "\nTotal Power (Op+): " << (e1 + e2);
    
// Function Overloading 
    c->discount(10000, "LoyaltyDiscount");

// Memory Clean
    delete c; delete bk;
    
    return 0;
}