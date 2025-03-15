#include<iostream>
using namespace std;
class engine{
	int engine_no;
	string engine_model;
	int cc;
	public:
		engine(){
			engine_no=0000;
			engine_model="unknown";
			cc=0;
		}
		void set_engine_no(int a){
			engine_no=a;
		}
		int get_engine_no(){
			return engine_no;
		}
		void set_engine_model(string b){
			engine_model=b;
		}
		string get_engine_model(){
			return engine_model;
		}
		void set_cc(int c){
			cc=c;
		}
		int get_cc(){
			return cc;
		}
};
class wheel{
	int wheelsize;
	string wheelcompany;
	public:
		wheel(){
			wheelsize=0;
			wheelcompany="notspecified";
		}
		void set_wheelsize(int x){
			wheelsize=x;
		}
		int get_wheelsize(){
			return wheelsize;
		}
		void set_wheelcompany(string z){
			wheelcompany=z;
		}
		string get_wheelcompany(){
			return wheelcompany;
		}
};
class Headlights {
    bool isOn;  // True = ON, False = OFF

public:
    Headlights() : isOn(false) {} // Default OFF

    void turnOn() {
        isOn = true;
        cout << "Headlights turned ON." << endl;
    }

    void turnOff() {
        isOn = false;
        cout << "Headlights turned OFF." << endl;
    }

    bool getStatus() {
        return isOn;
    }
};
class Steering {
    string direction;

public:
    Steering() : direction("Straight") {} 

    void turnLeft() {
        direction = "Left";
        cout << "Steering turned LEFT." << endl;
    }

    void turnRight() {
        direction = "Right";
        cout << "Steering turned RIGHT." << endl;
    }

    void goStraight() {
        direction = "Straight";
        cout << "Steering set to STRAIGHT." << endl;
    }

    string getDirection() {
        return direction;
    }
};
class car{
	engine *Engine; //aggregation 
	wheel *Wheel;
	Headlights headlights;
	Steering steering;
	public:
		car(){
			Engine=new engine();
			Wheel=new wheel();
		}
	 void set_enginedetails(){
	 //Engine-> engine();
	 Engine->set_engine_model("RXV_turbo");
	 Engine->set_engine_no(186);
	 Engine->set_cc(5000);
	 }
	 void set_wheeldetails(){
	 //Engine-> engine();
	 Wheel->set_wheelcompany("Hotwheel");
	 Wheel->set_wheelsize(20);
	 }
	 void on_lights(){
	 	headlights.turnOn();
	 }
	 void off_lights(){
	 	headlights.turnOff();
	 }
	 void move_left(){
	 	steering.turnLeft();
	 }
	 void move_straight(){
	 	steering.goStraight();
	 }
	 void move_right(){
	 	steering.turnRight();
	 }
	 void get_enginedetails(){
	 	cout<<"engine details:"<<endl;
		 cout<<"model:"<<Engine->get_engine_model()<<endl;;
	 	cout<<"engine no:"<<Engine->get_engine_no()<<endl;
	 	cout<<"power in cc:"<<Engine->get_cc()<<" cc"<<endl;
	 }
	 void get_wheeldetails(){
		cout<<"wheel details:"<<endl;
		cout<<"wheel company:"<<Wheel->get_wheelcompany()<<endl;
	 	cout<<"wheel size:"<<Wheel->get_wheelsize()<<endl;
	 }
	 void light_status(){
	 	cout<<"light status:"<<endl;
		cout<<"status:"<<headlights.getStatus()<<endl;
	 }
	 void get_movingdirection(){
	 	cout<<"direction of moving:"<<endl;
		cout<<"moving in:"<<steering.getDirection()<<"  direction"<<endl;
	 }
};
int main() {
    car bmw; // Creating a BMW car object

    // Setting details for Engine and Wheels
    bmw.set_enginedetails();
    bmw.set_wheeldetails();

    // Controlling Headlights
    bmw.on_lights();
    bmw.off_lights();
	bmw.on_lights();
    // Controlling Steering
    bmw.move_left();
    bmw.move_straight();
    bmw.move_right();

    // Display Engine and Wheel details
    bmw.get_enginedetails();
    bmw.get_wheeldetails();

    // Display Headlights and Movement Direction
    bmw.light_status();
    bmw.get_movingdirection();

    return 0;
}

