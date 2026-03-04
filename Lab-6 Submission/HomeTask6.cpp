// Design your own hybrid inheritance system using:
// Device
// Computer
// Network
// Server

        Device
       /     \
  Computer    Network
       \       /
         Server


#include <iostream>
using namespace std;

// Base Class
class Device {
    public:
    string brand;
    int deviceID;

    void getDevice() {
        cout << "Enter Device Brand: ";
        cin.ignore();
        getline(cin, brand);
        cout << "Enter Device ID: ";
        cin >> deviceID;
    }

    void showDevice() {
        cout << "Device Brand: " << brand << endl;
        cout << "Device ID: " << deviceID << endl;
    }
};

// Derived Class: Computer
class Computer : public Device {
    public:
    string CPU;
    int RAM; 

    void getComputer() {
        cin.ignore();
        cout << "Enter CPU: ";
        getline(cin, CPU);
        cout << "Enter RAM (GB): ";
        cin >> RAM;
    }

    void showComputer() {
        showDevice(); 
        cout << "CPU: " << CPU << endl;
        cout << "RAM: " << RAM << " GB" << endl;
    }
};

// Derived Class: Network
class Network : public Device {
    public:
    string networkType;

    void getNetwork() {
        cin.ignore();
        cout << "Enter Network Type (LAN/WiFi/etc): ";
        getline(cin, networkType);
    }

    void showNetwork() {
        showDevice(); 
        cout << "Network Type: " << networkType << endl;
    }
};

// Derived Class: 
class Server : public Computer, public Network {
    public:
    string serverName;

    void getServer() {
        cin.ignore();
        cout << "Enter Server Name: ";
        getline(cin, serverName);
    }

    void showServer() {
        // Device is inherited twice, so call explicitly
        cout << "\n--- Device Details via Computer ---" << endl;
        Computer::showDevice();

        cout << "--- Computer Details ---" << endl;
        cout << "CPU: " << CPU << endl;
        cout << "RAM: " << RAM << " GB" << endl;

        cout << "--- Network Details ---" << endl;
        cout << "Network Type: " << networkType << endl;

        cout << "--- Server Details ---" << endl;
        cout << "Server Name: " << serverName << endl;
    }
};

int main() {

    Server s;

    cout << "--- Enter Device Details ---" << endl;
    s.getDevice();      
    s.getComputer();     
    s.getNetwork();      
    s.getServer();       

    cout << "\n--- Server Complete Details ---" << endl;
    s.showServer();

    return 0;
}