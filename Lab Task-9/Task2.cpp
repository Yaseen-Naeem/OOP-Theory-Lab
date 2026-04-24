#include <iostream>
using namespace std;

class Notification {
protected:
    string recipient;

public:
    Notification(string r) {
        recipient = r;
    }

    virtual void sendNotification() = 0;
};

class EmailNotification : public Notification {
public:
    EmailNotification(string r) : Notification(r) {
        
    }

    void sendNotification() {
        cout << "Email Notification" << endl;
        cout << "To: " << recipient << endl;
        cout << "Message: Welcome to our service" << endl;
        cout << "Status: Sent Successfully\n\n";
    }
};

class SMSNotification : public Notification {
public:
    SMSNotification(string r) : Notification(r) {

    }

    void sendNotification() {
        cout << "SMS Notification" << endl;
        cout << "To: " << recipient << endl;
        cout << "Message: Your OTP is 1234" << endl;
        cout << "Status: Sent Successfully\n\n";
    }
};

class PushNotification : public Notification {
public:
    PushNotification(string r) : Notification(r) {

    }

    void sendNotification() {
        cout << "Push Notification" << endl;
        cout << "To: " << recipient << endl;
        cout << "Message: You have a new alert" << endl;
        cout << "Status: Sent Successfully\n\n";
    }
};

int main() {
    Notification* n1 = new EmailNotification("user@email.com");
    Notification* n2 = new SMSNotification("03001234567");
    Notification* n3 = new PushNotification("UserDevice");

    n1->sendNotification();
    n2->sendNotification();
    n3->sendNotification();

    delete n1;
    delete n2;
    delete n3;

    return 0;
}