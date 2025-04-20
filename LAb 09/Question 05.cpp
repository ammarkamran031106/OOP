#include<iostream>
using namespace std;
class Activity{
	public:
		void virtual calculateCaloriesBurned()=0;
};
class Running:public Activity{
	public:
	double distance;
	double time;
	void calculateCaloriesBurned(){
		cout<<"Calories burned through Activity ";
		cout<<"is : "<<time*distance<<endl;
	}
};
class Cycling:public Activity{
	public:
		double speed;
		double time;
		void calculateCaloriesBurned(){
			cout<<"Calories burned thrrough Cycling ";
			cout<<"is : "<<speed*time<<endl;
		}
};
int main(){
	Running obj;
	Cycling obj1;
	obj.distance=50;
	obj.time=60;
	obj1.speed=100;
	obj1.time=50;
	obj.calculateCaloriesBurned();
	obj1.calculateCaloriesBurned();
}
