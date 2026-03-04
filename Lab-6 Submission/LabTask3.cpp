// Create:
// Class Write
// Function: write()
// Class Speaker
// Function: speak()
// Class Author
// Inherits from both
// Call both functions from Author

#include <iostream>
using namespace std;

// First Base Class
class Write {
    public:
    void write() {
        cout << "Author is writing a book." << endl;
    }
};

// Second Base Class
class Speaker {
    public:
    void speak() {
        cout << "Author is giving a speech." << endl;
    }
};

// Derived Class
class Author : public Write, public Speaker {
    public:
    void show() {
        write();   
        speak();   
    }
};

int main() {

    Author a;   
    a.show();   // Calling both functions

    return 0;
}