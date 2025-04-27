#include<iostream>
#include<fstream>
using namespace std;

class Student {
public:
    int id;
    string name;
    float gpa;
};

int main() {
    Student *s1 = new Student[5];  // Allocate memory for 5 students

    ofstream file("student.txt", ios::out);
    if (!file.is_open()) {
        cout << "Error in opening the file" << endl;
        return 1;
    }

    for (int i = 0; i < 5; i++) {
        cin >> (s1 + i)->id >> (s1 + i)->name >> (s1 + i)->gpa;
    }
    for (int i = 0; i < 5; i++) {
        file << (s1 + i)->id << " " << (s1 + i)->name << " " << (s1 + i)->gpa << endl;
    }
    file.close();
    delete[] s1;  // Free the allocated memory

    Student s2;
    cout << "Enter new student details (id name gpa): ";
    cin >> s2.id >> s2.name >> s2.gpa;

    ofstream file2("student.txt", ios::app); 
    if (!file2.is_open()) {
        cout << "Error in opening the file" << endl;
        return 1;
    }
    file2 << s2.id << " " << s2.name << " " << s2.gpa << endl;
    file2.close();

    ifstream file3("student.txt", ios::in);
    if (!file3.is_open()) {
        cout << "Error in opening the file" << endl;
        return 1;
    }
    string line;
    while (getline(file3, line)) {
        cout << line << endl;
    }
    file3.close();

    return 0;
}
