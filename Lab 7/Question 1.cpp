#include<iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;
    string accountHolderName;
    string accountType;

public:
    Account(int ac_no, double x, string name, string type) {
        accountNumber = ac_no;
        balance = x;
        accountHolderName = name;
        accountType = type;
    }

    void deposit(double amount) {
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient Balance" << endl;
        }
    }

    void getAccountInfo() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Balance: " << balance << endl;
        cout << "Account Type: " << accountType << endl;
    }

    // Base print_statement() - no need for virtual or override
    void print_statement() {
        getAccountInfo();
    }

    virtual void calculateInterest() {}
};

// Derived class: SavingAccount
class SavingAccount : public Account {
public:
    double interestRate;
    double minimalBalance;

    SavingAccount(int ac_no, double x, string name, string type, double irate)
        : Account(ac_no, x, name, type), interestRate(irate), minimalBalance(5000) {}

    void calculateInterest() {
        if (balance > minimalBalance) {
            balance += balance * interestRate;
        } else {
            cout << "Balance is less than minimal balance for interest calculation." << endl;
        }
    }

    void print_statement() {
        getAccountInfo();
        cout << "Minimal Balance: " << minimalBalance << endl;
        cout << "Interest Rate: " << interestRate * 100 << "%" << endl;
        //cout << "Balance after Interest: " << balance << endl;
    }
};
class FixedDepositAccount : public Account {
public:
    string maturityDate;
    double fixedRate;

    FixedDepositAccount(int ac_no, double x, string name, string type, double fixRate, string date)
        : Account(ac_no, x, name, type), fixedRate(fixRate), maturityDate(date) {}

    void calculateInterest() {
        if (balance >=100000) {
            balance += balance * fixedRate;
        } else {
            cout << "Insufficient balance for interest applying" << endl;
        }
    }
    void print_statement() {
        getAccountInfo();
        cout << "Maturity Date: " << maturityDate << endl;
        cout << "Fixed Interest Rate: " << fixedRate * 100 << "%" << endl;
        //cout << "Balance after Interest: " << balance << endl;
    }
};
class CheckingAccount : public Account {
public:
    CheckingAccount(int ac_no, double x, string name, string type)
        : Account(ac_no, x, name, type) {}

    bool validateAccount(int accountToCheck) {
        if (this->accountNumber == accountToCheck) {
            return true;
        }
        return false; 
    }

    void print_statement() {
        getAccountInfo();
        cout << "Checking Account - Validating Account..." << endl;
    }
};
int main() {
    SavingAccount savingAcc(12345, 5000.0, "John Doe", "Saving", 0.05);
    FixedDepositAccount fixedAcc(12346, 100000.0, "Jane Doe", "Fixed Deposit", 0.07, "2025-03-22");
    CheckingAccount checkingAcc(12347, 2000.0, "Alice", "Checking");

    cout << "Saving Account Statement:" << endl;
    savingAcc.print_statement();
    savingAcc.calculateInterest();
    savingAcc.print_statement();
    cout << endl;

    cout << "Fixed Deposit Account Statement:" << endl;
    fixedAcc.print_statement();
    fixedAcc.calculateInterest();
    fixedAcc.print_statement();
    cout << endl;

    cout << "Checking Account Statement:" << endl;
    checkingAcc.print_statement();
    cout << endl;

    // Check if an account number is valid using CheckingAccount
    int accountToCheck = 12345; // This account number is for savingAcc, not checkingAcc
    if (checkingAcc.validateAccount(accountToCheck)) {
        cout << "Account number " << accountToCheck << " is valid." << endl;
    } else {
        cout << "Account number " << accountToCheck << " is invalid." << endl;
    }

    // Check for a valid account number (should be 12347 for checkingAcc)
    accountToCheck = 12347; // This is the correct account number for checkingAcc
    if (checkingAcc.validateAccount(accountToCheck)) {
        cout << "Account number " << accountToCheck << " is valid." << endl;
    } else {
        cout << "Account number " << accountToCheck << " is invalid." << endl;
    }

    return 0;
}
