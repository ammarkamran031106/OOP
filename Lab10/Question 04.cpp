#include<iostream>
#include<fstream>
using namespace std;

int main() {
    
    ofstream fileOut("info.txt", ios::out);
    if (!fileOut.is_open()) {
        cout << "Error opening file for writing." << endl;
        return 1;
    }
    fileOut << "C++ is a powerful programming language.";
    fileOut.close();

    fstream file("info.txt", ios::in | ios::out);
    if (!file.is_open()) {
        cout << "Error opening file for reading and writing." << endl;
        return 1;
    }

    cout << "Initial get pointer position: " << file.tellg() << endl;
    cout << "Initial put pointer position: " << file.tellp() << endl;

    file.seekg(6);
    char word[9]; 
    file.read(word, 8);
    word[8] = '\0';
    cout << "Word read from position 6: " << word << endl;

    file.seekp(6);
    file.write("dynamic", 8);
    
    cout << "After modification, get pointer position: " << file.tellg() << endl;
    cout << "After modification, put pointer position: " << file.tellp() << endl;

    file.close();

    ifstream fileIn("info.txt");
    if (!fileIn.is_open()) {
        cout << "Error opening file to read updated content." << endl;
        return 1;
    }
    string line;
    cout << "\nUpdated file content:\n";
    while (getline(fileIn, line)) {
        cout << line << endl;
    }
    fileIn.close();

    return 0;
}
