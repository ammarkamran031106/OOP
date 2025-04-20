#include<iostream>
using namespace std;
class PaymentMethod {
	public:
		void virtual processPayment(double amount)=0;
};
class CreditCard:public PaymentMethod {
	string cardNumber;
	public:
		double balance;
		void processPayment(double amount){
			cout<<"Processing Payment through Credit Card"<<endl;
			if(balance<amount){
			cout<<"Insufficent Balance"<<endl;
			}
			else{
			balance-=amount;
			cout<<amount<<" withdraw from your accout and your balance is: "<<balance<<endl;
			}
		}
};
class DigitalWallet:public PaymentMethod{
	public:
		double balance;
		void processPayment(double amount){
			cout<<"Processsing Payment through Digital Wallet"<<endl;
			if(balance<amount){
			cout<<"insufficent balance"<<endl;
		}
		else 
			balance-=amount;
			cout<<amount<<" Withdraw from your Account and your Balance is: "<<balance<<endl;
		}
};
int main(){
	CreditCard obj;
	DigitalWallet obj1;
	obj.balance=1000;
	obj.processPayment(1500);
	obj1.balance=2000;
	obj1.processPayment(1500);
}
