#include <iostream>
using namespace std;

class LibraryBook {
private:
    string title;
    bool issued;

public:
    LibraryBook() {
        title = "";
        issued = false;
    }

    LibraryBook(string t) {
        title = t;
        issued = false;
    }

    // Friend class
    friend class Librarian;
};

class Librarian {
public:
    void issueBook(LibraryBook &b) {
        if (b.issued == true) {
            cout << "Book already issued\n";
        } else {
            b.issued = true;
            cout << "Book issued: " << b.title << endl;
        }
    }

    void returnBook(LibraryBook &b) {
        if (b.issued == false) {
            cout << "Book was not issued\n";
        } else {
            b.issued = false;
            cout << "Book returned: " << b.title << endl;
        }
    }

    void display(LibraryBook b) {
        cout << "Title: " << b.title << endl;
        if (b.issued)
            cout << "Status: Issued\n";
        else
            cout << "Status: Available\n";
    }
};

int main() {
    LibraryBook b1("OOP in C++");
    Librarian l;

    l.display(b1);

    l.issueBook(b1);
    l.issueBook(b1);   

    l.display(b1);

    l.returnBook(b1);
    l.returnBook(b1);  

    l.display(b1);

    return 0;
}