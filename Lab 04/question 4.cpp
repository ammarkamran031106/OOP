#include <iostream>
using namespace std;

class Car {
private:
    int id, manufactureYear;
    string carModel;
    bool rentedStatus;

public:
    Car() {
        rentedStatus = false;
    }

    Car(int cID, int mYear, string cModel, bool rStatus) {
        id = cID;
        manufactureYear = mYear;
        carModel = cModel;
        rentedStatus = rStatus;
    }

    void rentCar() {
        rentedStatus = true;
    }

    void returnCar() {
        rentedStatus = false;
    }

    bool isVintage() {
        if (manufactureYear < 2000) {
            return true;
        }
        return false;
    }
};

int main() {
    Car car1, car2, car3;
    car1 = Car(1234, 1998, "BMW", false);
    car2 = Car(1432, 2006, "Corvette", true);
    car1.rentCar();
    car2.returnCar();
    cout << car1.isVintage();
}
