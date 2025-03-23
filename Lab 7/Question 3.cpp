#include <iostream>
#include <string>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    double exchangeRate; 
public:
    Currency(double amt, string code, double rate)
        : amount(amt), currencyCode(code), exchangeRate(rate) {}

    virtual double convertToBase()  {
        return amount * exchangeRate;
    }

    virtual void displayCurrency(){ 
        cout << "Currency: " << currencyCode << ", Amount: " << amount << endl;
    }

    virtual ~Currency() {}
};
class Dollar : public Currency {
public:
    Dollar(double amt) : Currency(amt, "USD", 1.0) {} 
    void displayCurrency()  override {
        cout << "Dollar Amount: $" << amount << endl;
    }
};
class Euro : public Currency {
public:
    Euro(double amt) : Currency(amt, "EUR", 1.1) {} // Example rate: 1 EUR = 1.1 USD

    double convertToBase()  override {
        return amount * exchangeRate;
    }

    void displayCurrency()  override {
        cout << "Euro Amount: €" << amount << endl;
    }
};
class Rupee : public Currency {
public:
    Rupee(double amt) : Currency(amt, "INR", 0.012) {} // Example rate: 1 INR = 0.012 USD

    double convertToBase()  override {
        return amount * exchangeRate;
    }

    void displayCurrency()  override {
        cout << "Rupee Amount: ?" << amount << endl;
    }
};
int main() {
    Currency* currencies[3];
    currencies[0] = new Dollar(100);
    currencies[1] = new Euro(50);
    currencies[2] = new Rupee(5000);

    for (int i = 0; i < 3; ++i) {
        currencies[i]->displayCurrency();
        cout << "Converted to USD: $" << currencies[i]->convertToBase() << endl;
        cout << "----------------------" << endl;
    }

    for (int i = 0; i < 3; ++i) {
    	delete currencies[i];
		}
    return 0;
}
