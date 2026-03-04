// Create:
// BankAccount
// Derive SavingsAccount using private inheritance
// Try accessing base class data from main()
// Explain the result.

#include <iostream>
using namespace std;

// Base Class
class BankAccount {
    public:
    int accountNumber;
    double balance;

    void showAccount() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : private BankAccount {
    public:
    double interestRate;

    void setSavings(int accNo, double bal, double rate) {
        accountNumber = accNo;   // accessible inside derived class
        balance = bal;           // accessible inside derived class
        interestRate = rate;
    }

    void showSavings() {
        showAccount();           
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

int main() {

    SavingsAccount sa;
    sa.setSavings(101, 5000, 5);
    sa.showSavings();

    // Trying access base class data from main
    // sa.accountNumber = 102; -> ERROR! Not accessible (private inheritance)
    // sa.balance = 6000;      -> ERROR! Not accessible
    // sa.showAccount();       -> ERROR! Not accessible

    return 0;
}