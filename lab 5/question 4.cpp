#include<iostream>
using namespace std;
class BankAccount{
	int accountNumber;
	string accountHolderName;
	int balance;
	public:
		BankAccount(int a,string b,int c){
			accountNumber=a;
			accountHolderName=b;
			balance=c;
		}
		int get_balance(){
			return balance;
		}
		void set_balance(int s){
			balance=s;
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
			 cout<<"Balance:"<<get_balance()<<endl;
		}
};
int main(){
	BankAccount accounts[3] = {
    BankAccount(0000000, "Ammar", 5000),
    BankAccount(0000001, "Owais", 3400),
    BankAccount(0000002, "Saqib", 4000)};
	for(int i=0;i<3;i++){
		accounts[i].display();
	}
	accounts[0].deposit(500);
	accounts[1].deposit(1000);
	accounts[2].deposit(700);
	for(int i=0;i<3;i++){
		accounts[i].display();
	}
	accounts[0].withdraw(200);
	accounts[1].withdraw(700);
	accounts[2].withdraw(400);
	for(int i=0;i<3;i++){
		accounts[i].display();
	}
}
