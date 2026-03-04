// Create:
// Class Account
// Data: Account Number
// Function: showAccount()
// Class SavingsAccount
// Function: calculateInterest()
// Class CurrentAccount
// Function: calculateOverdraft()

#include <iostream>
using namespace std;

// Base Class
class Account {
    public:
    int accountNumber;

    void getAccount() {
        cout << "Enter Account Number: ";
        cin >> accountNumber;
    }

    void showAccount() {
        cout << "Account Number: " << accountNumber << endl;
    }
};

// Derived Class for Savings Account
class SavingsAccount : public Account {
    public:
    double balance;
    double interestRate; 

    void getSavingsDetails() {
        cout << "Enter Balance: ";
        cin >> balance;
        cout << "Enter Interest Rate (%): ";
        cin >> interestRate;
    }

    void calculateInterest() {
        double interest = (balance * interestRate) / 100;
        cout << "Interest Amount: " << interest << endl;
    }
};

// Derived Class for Current Account
class CurrentAccount : public Account {
    public:
    double balance;
    double overdraftLimit;

    void getCurrentDetails() {
        cout << "Enter Balance: ";
        cin >> balance;
        cout << "Enter Overdraft Limit: ";
        cin >> overdraftLimit;
    }

    void calculateOverdraft() {
        cout << "Maximum Withdrawable Amount (Balance + Overdraft): "
             << balance + overdraftLimit << endl;
    }
};

int main() {

    cout << "--- Savings Account ---" << endl;
    SavingsAccount sa;
    sa.getAccount();
    sa.getSavingsDetails();
    sa.showAccount();
    sa.calculateInterest();

    cout << "\n--- Current Account ---" << endl;
    CurrentAccount ca;
    ca.getAccount();
    ca.getCurrentDetails();
    ca.showAccount();
    ca.calculateOverdraft();

    return 0;
}