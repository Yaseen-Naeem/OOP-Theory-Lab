#include <iostream>
using namespace std;

class Transaction {
protected:
    int accountNumber;
    double amount;

public:
    Transaction(int acc, double amt) {
        accountNumber = acc;
        amount = amt;
    }

    virtual void processTransaction() = 0;
};

class Deposit : public Transaction {
public:
    Deposit(int acc, double amt) : Transaction(acc, amt) {

    }

    void processTransaction() {
        cout << "Deposit Transaction" << endl;
        cout << "Account: " << accountNumber << endl;
        cout << "Amount: " << amount << endl;
        cout << "Status: Amount Deposited Successfully\n\n";
    }
};

class Withdrawal : public Transaction {
public:
    Withdrawal(int acc, double amt) : Transaction(acc, amt) {
        
    }

    void processTransaction() {
        cout << "Withdrawal Transaction" << endl;
        cout << "Account: " << accountNumber << endl;
        cout << "Amount: " << amount << endl;
        cout << "Status: Amount Withdrawn Successfully\n\n";
    }
};

class Transfer : public Transaction {
    int targetAccount;

public:
    Transfer(int acc, int target, double amt) : Transaction(acc, amt) {
        targetAccount = target;
    }

    void processTransaction() {
        cout << "Transfer Transaction" << endl;
        cout << "From Account: " << accountNumber << endl;
        cout << "To Account: " << targetAccount << endl;
        cout << "Amount: " << amount << endl;
        cout << "Status: Amount Transferred Successfully\n\n";
    }
};

int main() {
    Transaction* t1 = new Deposit(12345, 5000);
    Transaction* t2 = new Withdrawal(12345, 2000);
    Transaction* t3 = new Transfer(12345, 67890, 1500);

    t1->processTransaction();
    t2->processTransaction();
    t3->processTransaction();

    delete t1;
    delete t2;
    delete t3;

    return 0;
}