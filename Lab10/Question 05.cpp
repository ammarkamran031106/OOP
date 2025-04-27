#include<iostream>
#include<fstream>
using namespace std;

int main() {
    string searchWord, replacementWord;
    cout << "Enter the word to search: ";
    cin >> searchWord;
    cout << "Enter the replacement word: ";
    cin >> replacementWord;

    if (replacementWord.length() > searchWord.length()) {
        cout << "Replacement word must be equal or smaller in length than search word." << endl;
        return 1;
    }

    fstream file("data.txt", ios::in | ios::out);
    if (!file.is_open()) {
        cout << "Error opening the file." << endl;
        return 1;
    }

    string word;
    streampos pos;

    while (!file.eof()) {
        pos = file.tellg();
        word = "";

        char ch;
        while (file.get(ch)) {
            if (ch == ' ' || ch == '.' || ch == '\n') {
                break;
            }
            word += ch;
        }

        if (word == searchWord) {
            file.seekp(pos); 
            file.write(replacementWord.c_str(), replacementWord.length());

            int extraSpaces = searchWord.length() - replacementWord.length();
            for (int i = 0; i < extraSpaces; i++) {
                file.put(' ');
            }
        }
    }

    file.close();
  ifstream fileIn("data.txt");
    if (!fileIn.is_open()) {
        cout << "Error opening the file to read updated content." << endl;
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
