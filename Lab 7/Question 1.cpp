#include<iostream>
using namespace std;
class Account{
	int accountNumber;
	double balance;
	string accountHolderName;
	string accountType;
	public:
		void deposit(double amount){
			balance+=amount;
		}
		void withdraw(double amount){
			if(amount<balance){
				balance-=amount;
			}
			else
			cout<<"Insufficent Balance"<<endl;
		}
		//void calculateInterest()
		//void print_statement(){
	//		cout<<""
		//}
		void getAccountInfo(){
			cout<<"Account Number:"<<accountNumber<<endl;
			cout<<"Account Holder Name:"<<accountHolderName<<endl;
			cout<<"Balance:"<<balance<<endl;
			cout<<"Accout type:"<<accountType<<endl;
		}
};
class SavingAccount: public Account{
	public:
		double interestRate;
		double minimalBalance;
}
