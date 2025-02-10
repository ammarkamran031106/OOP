#include <iostream>
using namespace std;

class BankAccount {
    private:
        string holderName, accNumber;
        double accBalance;

    public:
        BankAccount() {
            accBalance = 0.0;
        }
        BankAccount(string accNum, string holder, double balance) {
            accNumber = accNum;
            holderName = holder;
            accBalance = balance;
        } 

        void deposit(double amount) {
            accBalance += amount;
        }

        void withdraw(double amount) {
            if (accBalance >= amount) {
                accBalance -= amount;
            } else {
                cout << "Insufficient balance." << endl;
            }
        }

        void checkBalance() {
            cout << "Your current balance is: " << accBalance << endl;
        }
};

int main() {
    BankAccount account1;
    BankAccount account2;
    BankAccount account3;

    account1 = BankAccount("1234", "Sameed", 1000.24);
    account2 = BankAccount("1456", "Ali", 20.54);
    account3 = BankAccount("002", "Faraz", 0);

    account1.deposit(20.69);
    account1.withdraw(350.42);
    account1.checkBalance();
}
