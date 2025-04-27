#include<iostream>
#include<fstream>
using namespace std;

int main() {
    string name, email, summary;
    int yearsOfExperience;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your email: ";
    getline(cin, email);

    cout << "Enter your years of experience: ";
    cin >> yearsOfExperience;
    cin.ignore(); // To clear the newline character after int input

    cout << "Enter your summary: ";
    getline(cin, summary);

    ofstream file("resume.txt", ios::trunc); // open file and delete old contents
    if (!file.is_open()) {
        cout << "Error in opening the file" << endl;
        return 1;
    }

    file << "Name: " << name << endl;
    file << "Email: " << email << endl;
    file << "Years of Experience: " << yearsOfExperience << endl;
    file << "Summary: " << summary << endl;
    file.close();

    ifstream file2("resume.txt");
    if (!file2.is_open()) {
        cout << "Error in opening the file" << endl;
        return 1;
    }

    string line;
    cout << "\nYour Resume:\n";
    while (getline(file2, line)) {
        cout << line << endl;
    }
    file2.close();

    return 0;
}
