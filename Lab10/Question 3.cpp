#include<iostream>
#include<fstream>
using namespace std;

int main() {
    ifstream chapter1("chapter 1.txt");
    ifstream chapter2("chapter 2.txt");
    ofstream book("book.txt", ios::app);

    if (!chapter1.is_open() || !chapter2.is_open() || !book.is_open()) {
        cout << "Error in opening files" << endl;
        return 1;
    }

    string line;

    while (getline(chapter1, line)) {
        book << line << endl;
    }
    book << endl; // Add a blank line between chapters

    while (getline(chapter2, line)) {
        book << line << endl;
    }
    book.close();
    chapter1.close();
    chapter2.close();

    ifstream readBook("book.txt");
    if (!readBook.is_open()) {
        cout << "Error in opening book.txt" << endl;
        return 1;
    }

    cout << "\nCombined Book Content:\n";
    while (getline(readBook, line)) {
        cout << line << endl;
    }
    readBook.close();

    return 0;
}
