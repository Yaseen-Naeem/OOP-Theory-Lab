// Create:
// University
// Faculty (inherits University)
// Administration
// HOD (inherits Faculty + Administration)
// Demonstrate all inherited functions.

#include <iostream>
using namespace std;

// Base Class
class University {
    public:
    string uniName;

    void getUniversity() {
        cout << "Enter University Name: ";
        cin.ignore();
        getline(cin, uniName);
    }

    void showUniversity() {
        cout << "University: " << uniName << endl;
    }
};

// Derived Class - Multilevel
class Faculty : public University {
    public:
    string facultyName;

    void getFaculty() {
        cout << "Enter Faculty Name: ";
        getline(cin, facultyName);
    }

    void showFaculty() {
        cout << "Faculty: " << facultyName << endl;
    }
};

// Separate Base Class
class Administration {
    public:
    string adminName;

    void getAdmin() {
        cout << "Enter Administration Name: ";
        getline(cin, adminName);
    }

    void showAdmin() {
        cout << "Administration: " << adminName << endl;
    }
};

// Derived Class from Faculty and Administration 
class HOD : public Faculty, public Administration {
    public:
    string hodName;

    void getHOD() {
        cout << "Enter HOD Name: ";
        getline(cin, hodName);
    }

    void showHOD() {
        cout << "HOD: " << hodName << endl;
    }

    void showAll() {
        showUniversity();   
        showFaculty();      
        showAdmin();        
        showHOD();          
    }
};

int main() {

    HOD h;

    cout << "--- Enter Details ---" << endl;
    h.getUniversity();
    h.getFaculty();
    h.getAdmin();
    h.getHOD();

    cout << "\n--- HOD Complete Details ---" << endl;
    h.showAll();

    return 0;
}