// Create:
// Base class with:
// public variable
// protected variable
// private variable
// Create:
// Public inheritance class
// Protected inheritance class
// Private inheritance class
// Test accessibility inside and outside the class.

#include <iostream>
using namespace std;

// Base Class
class Base {
    public:
    int pubVar;

    protected:
    int protVar;

    private:
    int privVar;

    void showBaseVars() {
        cout << "Inside Base Class:" << endl;
        cout << "Public: " << pubVar << endl;
        cout << "Protected: " << protVar << endl;
        cout << "Private: " << privVar << endl;
    }
};

// Public Inheritance
class PublicDerived : public Base {
    public:
    void showDerived() {
        cout << "\nInside PublicDerived (public inheritance):" << endl;
        cout << "Public: " << pubVar << endl;     // accessible
        cout << "Protected: " << protVar << endl; // accessible
    }
};

// Protected Inheritance
class ProtectedDerived : protected Base {
    public:
    void showDerived() {
        cout << "\nInside ProtectedDerived (protected inheritance):" << endl;
        cout << "Public (as protected): " << pubVar << endl;     // becomes protected
        cout << "Protected: " << protVar << endl;                // accessible
    }
};

// Private Inheritance
class PrivateDerived : private Base {
    public:
    void showDerived() {
        cout << "\nInside PrivateDerived (private inheritance):" << endl;
        cout << "Public (as private): " << pubVar << endl;       // becomes private
        cout << "Protected (as private): " << protVar << endl;   
    }
};

int main() {

    Base b;
    b.pubVar = 10;
    // NOT accessible outside
    // NOT accessible outside
    b.showBaseVars();

    PublicDerived pd;
    pd.pubVar = 100;  // accessible (public inheritance)
    pd.showDerived();

    ProtectedDerived prd;  // Not accessible (protected inheritance)
    prd.showDerived();

    PrivateDerived pvd; // Not accessible (private inheritance)
    pvd.showDerived();

    return 0;
}