// Create hybrid + virtual inheritance together:
// Device
// Camera
// Phone
// SmartPhone
// Ensure only one Device exists.

#include <iostream>
using namespace std;

// Base Class
class Device {
    public:
    string brand;

    void showDevice() {
        cout << "Device Brand: " << brand << endl;
    }
};

// Derived Class 1: Camera 
class Camera : virtual public Device {
    public:
    int megapixels;

    void setCamera(int mp) {
        megapixels = mp;
    }

    void showCamera() {
        showDevice(); 
        cout << "Camera Megapixels: " << megapixels << " MP" << endl;
    }
};

// Derived Class 2: Phone
class Phone : virtual public Device {
    public:
    string phoneNumber;

    void setPhone(string num) {
        phoneNumber = num;
    }

    void showPhone() {
        showDevice(); 
        cout << "Phone Number: " << phoneNumber << endl;
    }
};

// Derived Class: SmartPhone
class SmartPhone : public Camera, public Phone {
    public:
    string os;

    void setSmartPhone(string osName) {
        os = osName;
    }

    void showSmartPhone() {
        showDevice(); 
        showCamera();
        showPhone();
        cout << "Operating System: " << os << endl;
    }

    void showAddresses() {
        cout << "Address of Device via Camera: " << (void*) static_cast<Device*>(static_cast<Camera*>(this)) << endl;
        cout << "Address of Device via Phone: " << (void*) static_cast<Device*>(static_cast<Phone*>(this)) << endl;
        cout << "Address of Device via SmartPhone: " << (void*) static_cast<Device*>(this) << endl;
    }
};

int main() {

    SmartPhone sp;

    // Initialize data
    sp.brand = "Apple";         
    sp.setCamera(12);
    sp.setPhone("123-456-7890");
    sp.setSmartPhone("iOS 17");

    cout << "--- SmartPhone Details ---" << endl;
    sp.showSmartPhone();

    cout << "\n--- Memory Addresses of Device ---" << endl;
    sp.showAddresses();

    return 0;
}