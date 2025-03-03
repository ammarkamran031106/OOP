#include <iostream>
using namespace std;

class Square {
    float side;
    float area;
    static float totalArea;

public:
    static float get_totalArea();
    static void set_totalArea(float total);

    Square() {
        side = 0.0;
        area = 0.0;
    }

    Square(float sideLength) {
        side = sideLength;
    }

    float calculate_area() {
        area = side * side;
        totalArea += area;
        return area;
    }

    void set_area(float areaValue) {
        area = areaValue;
    }

    void set_side(float sideLength) {
        side = sideLength;
    }

    float get_area() const {
        return area;
    }

    float get_side() const {
        return side;
    }
};

float Square::get_totalArea() {
    return totalArea;
}

void Square::set_totalArea(float total) {
    totalArea = total;
}

float Square::totalArea = 0.0;

int main() {
    Square s1;
    Square s2;
    Square s3;

    s1.set_side(9.0);
    s2.set_side(6.0);
    s3.set_side(4.0);

    s1.calculate_area();
    cout << "The area of s1 is: " << s1.get_area() << endl;
    cout << "The total area is: " << Square::get_totalArea() << endl;

    s2.calculate_area();
    cout << "The area of s2 is: " << s2.get_area() << endl;
    cout << "The total area is: " << Square::get_totalArea() << endl;

    s3.calculate_area();
    cout << "The area of s3 is: " << s3.get_area() << endl;
    cout << "The total area is: " << Square::get_totalArea() << endl;

    float result = Square::get_totalArea();
    cout << "The total area of all squares is: " << result << endl;

    return 0;
}
