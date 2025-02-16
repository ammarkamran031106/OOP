# include <iostream>
# include <iomanip>
using namespace std;

class Account{
	
	private:
		string accNum;
		string ownerName;
		float balance;
		
	public:
	
		Account(){
			balance = 0.0;
		}		

		Account(string accnum , string name, float balancep){
			
			this->accNum = accnum;
			this->ownerName = name;
			this-> balance = balancep;
			

		}
		
		void deposit_money(float amount){
			balance = balance + amount;
			cout <<"Amount Deposited : "<<amount<<endl;
		}
		
		void withdraw_money(float amount){
			
			if (amount>balance){
				cout <<"You have inssufcient Balance!"<<endl;
			}
			else if (amount==balance ){
				balance =0.0;
				cout <<"Transaction Successfull!"<<endl;
				cout <<"Amount Withdrew: "<<amount<<endl;
				cout <<"Current balance :"<<balance<<endl;
				cout <<"You withdrew your all Money!"<<endl;
			}
			else {
				balance = balance - amount;
				cout <<"Transaction Successfull!"<<endl;
				cout <<"Amount Withdrew: "<<amount<<endl;
				cout <<"Current balance :"<<balance<<endl;
			}
			
		}
		
		void display_detail(){
			cout<<endl;
			cout<<setw(20)<<"*****ACCOUNT DETAILS*****"<<endl;
			cout <<endl;
			cout <<"Account Number: "<<accNum<<endl;
			cout <<"Account Holde Name: "<<ownerName<<endl;
			cout <<"Current Balance: "<<balance<<endl;
		}
};		

int main(){
	Account a1("PAK10212121234","BURAIR HYDER",2000);
	a1.deposit_money(10000);
	a1.withdraw_money(1000);
	a1.display_detail();	
}
