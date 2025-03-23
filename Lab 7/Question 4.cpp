#include <iostream>
#include <string>
using namespace std;
class Person {
protected:
    string name, id, address, phoneNumber, email;
public:
    Person(string n, string i) : name(n), id(i) {}
    virtual void displayInfo() const {  
        cout << "Name: " << name << ", ID: " << id << endl;
    }
    virtual ~Person() {} 
};

class Student : public Person {
    string coursesEnrolled;
    double GPA;
    int enrollmentYear;
public:
    Student(string n, string i, string courses, double gpa, int year)
        : Person(n, i), coursesEnrolled(courses), GPA(gpa), enrollmentYear(year) {}
    void displayInfo() const override {  
        Person::displayInfo();
        cout << "Courses: " << coursesEnrolled << ", GPA: " << GPA << ", Year: " << enrollmentYear << endl;
    }
};

class Professor : public Person {
    string department;
    int coursesTaught;
    double salary;
public:
    Professor(string n, string i, string dept, int courses, double sal)
        : Person(n, i), department(dept), coursesTaught(courses), salary(sal) {}
    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << department << ", Courses: " << coursesTaught << ", Salary: $" << salary << endl;
    }
};

class Staff : public Person {
    string department, position;
    double salary;
public:
    Staff(string n, string i, string dept, string pos, double sal)
        : Person(n, i), department(dept), position(pos), salary(sal) {}
    void displayInfo() const override {
        Person::displayInfo();
        cout << "Department: " << department << ", Position: " << position << ", Salary: $" << salary << endl;
    }
};

int main() {
    Person* people[3];
    people[0] = new Student("Alice", "S123", "Math, Physics", 3.8, 2023);
    people[1] = new Professor("Dr. Bob", "P456", "Physics", 3, 75000);
    people[2] = new Staff("Charlie", "ST789", "Admin", "Manager", 50000);
    for (int i = 0; i < 3; ++i) {
        people[i]->displayInfo();
        cout << "-------------------" << endl;
    }
    for (int i = 0; i < 3; ++i) delete people[i];

    return 0;
}
