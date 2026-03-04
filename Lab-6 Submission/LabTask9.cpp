// Modify the previous diamond problem:
// Add virtual
// Verify no ambiguity
// Print memory address of base class from both paths

#include <iostream>
using namespace std;

// Base Class
class Machine {
    public:
    void start() {
        cout << "Machine starting..." << endl;
    }
};

// Derived Class 1 
class Printer : virtual public Machine {
    public:
    void print() {
        cout << "Printing document..." << endl;
    }
};

// Derived Class 2 
class Scanner : virtual public Machine {
    public:
    void scan() {
        cout << "Scanning document..." << endl;
    }
};

// Derived Class from both Printer and Scanner
class AllInOne : public Printer, public Scanner {
    public:
    void allFunctions() {
        print();
        scan();
        start(); 
    }

    void showAddresses() {
        cout << "Address of Machine via Printer: " << (void*) static_cast<Machine*>(static_cast<Printer*>(this)) << endl;
        cout << "Address of Machine via Scanner: " << (void*) static_cast<Machine*>(static_cast<Scanner*>(this)) << endl;
        cout << "Address of Machine via AllInOne: " << (void*) static_cast<Machine*>(this) << endl;
    }
};

int main() {

    AllInOne aio;

    aio.print();
    aio.scan();
    aio.start();      
    aio.allFunctions(); // Calls all functions

    cout << "\n--- Memory Addresses of Base Machine ---" << endl;
    aio.showAddresses();

    return 0;
}