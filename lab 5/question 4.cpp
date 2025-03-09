#include<iostream>
using namespace std;
class BankAccount{
	int accountNumber;
	string accountHolderName;
	static int balance;
	public:
		BankAccount(int a,string b,int c){
			accountNumber=a;
			accountHolderName=b;
			balance=c;
		}
		void setaccountNumber(int a){
			accountNumber=a;
		}
		int getaccountNumber(){
			return accountNumber;
		}
		void setaccountHolderName(string a){
			accountHolderName=a;
		}
		string getaccountHolderName(){
			return accountHolderName;
		}
		void deposit(double amount){
			balance+=amount;
		}
		void withdraw(double amount){
			if(balance>=amount){
				balance-=amount;
			}
			else
			cout<<"no enough balnace"<<endl;
		}
		void display(){
			 cout<<"Account Number:"<<getaccountNumber()<<endl;
			 cout<<"Account Holder Name:"<<getaccountHolderName()<<endl;
			 cout<<"Balance:"<<balance<<endl;
		}
};
int BankAccount::balance=0;
int main(){
	BankAccount employee(1442422,"owais",40000);
	employee.deposit(100000);
	employee.withdraw(30000);
	employee.deposit(55000);
	employee.display();
}
