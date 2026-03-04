// Create your own diamond structure using:
// Machine
// Printer
// Scanner
// AllInOne
// Show ambiguity problem.

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
class Printer : public Machine {
    public:
    void print() {
        cout << "Printing document..." << endl;
    }
};

// Derived Class 2
class Scanner : public Machine {
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
    }
};

int main() {

    AllInOne aio;

    aio.print();
    aio.scan();

    aio.allFunctions();

    return 0;
}