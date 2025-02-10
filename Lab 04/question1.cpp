#include<iostream>
#include<string>
using namespace std;
class student
{
int stu_id;
string name;
int age;
char grade;
public:
	student(void){
		grade='N';
	}
	student(int stu_id,string name,int age,char grade){
		this ->stu_id=stu_id;
		this ->name=name;
		this ->age=age;
		this->grade=grade;
	}
	void promoteStudent(){
		if(grade !='A'){
			grade--;
		}
	}
	bool iseligibleForscholar(){
		if(grade=='A'){
			return true;
		}
		else 
		return false;
	}
	void display(){
		cout<<"the student id: "<<stu_id<<"   name: "<<name<<"    age: "<<age<<"    has grade: "<<grade<<endl;
	}
};
int main(){
	student c;
	c.promoteStudent();
	bool check1=c.iseligibleForscholar();
	c.display();
	if(check1==true){
		cout<<"eligib-le for scholship"<<endl;
	}
	else
	cout<<"not eligible for scholarship"<<endl;
	student a(3423,"areesh",17,'C');
	a.promoteStudent();
	bool check2=a.iseligibleForscholar();
	a.display();
	if(check2==true){
		cout<<"eligible for scholship"<<endl;
	}
	else
	cout<<"not eligible for scholarship"<<endl;
	student b(42423,"ammar",15,'B');
	b.promoteStudent();
	bool check3=b.iseligibleForscholar();
	b.display();
	if(check3==true){
		cout<<"eligible for scholship"<<endl;
	}
	else
	cout<<"not eligible for scholarship"<<endl;
	
}
