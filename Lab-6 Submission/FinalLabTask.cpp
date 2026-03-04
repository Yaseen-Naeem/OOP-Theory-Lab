// Design a complete Hospital system of your choice that must include: 
// At least 3 types of inheritance
// Use of all access specifiers 
// One diamond structure
// One virtual inheritance solution
// Proper output demonstration

        Staff
       /     \
   Medical   Administrative
       \     /
     HospitalManager


#include <iostream>
using namespace std;

// Base Class
class Person {
    public:
    string name;

    Person(string n) {
        name = n;
    }

    void showPerson() {
        cout << "Name: " << name << endl;
    }
};

class Doctor : public Person {
    protected:
    string specialization;

    public:
    Doctor(string n, string spec) : Person(n) {
        specialization = spec;
    }

    void showDoctor() {
        showPerson();
        cout << "Specialization: " << specialization << endl;
    }
};

class Surgeon : public Doctor {
    private:
    int surgeriesPerformed;

    public:
    Surgeon(string n, string spec, int s)
        : Doctor(n, spec) {
        surgeriesPerformed = s;
    }

    void showSurgeon() {
        showDoctor();
        cout << "Surgeries Performed: "
             << surgeriesPerformed << endl;
    }
};

// Base
class Staff {
    public:
    int staffID;

    Staff(int id) {
        staffID = id;
    }

    void showStaff() {
        cout << "Staff ID: " << staffID << endl;
    }
};

// First virtual path 
class Medical : virtual public Staff {
    public:
    Medical(int id) : Staff(id) {}
};

// Second virtual path 
class Administrative : virtual public Staff {
    public:
    Administrative(int id) : Staff(id) {}
};

// Diamond bottom structure
class HospitalManager : public Medical, public Administrative {
    public:
    string department;

    HospitalManager(int id, string dept)
        : Staff(id), Medical(id), Administrative(id) {
        department = dept;
    }

    void showManager() {
        showStaff();  
        cout << "Department: " << department << endl;
    }
};

// MAIN 
int main() {

    cout << "----- Surgeon Details -----" << endl;
    Surgeon s("Dr. Ali", "Cardiology", 120);
    s.showSurgeon();

    cout << "\n----- Hospital Manager Details -----" << endl;
    HospitalManager hm(101, "Emergency");
    hm.showManager();

    return 0;
}