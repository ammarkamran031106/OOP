#include<iostream>
#include <string>
using namespace std;

class ValidateString {
    string inputString;

public:
    ValidateString(string str) {
        inputString = str;
    }

    void validate() const {
        bool isValid = false;
        for (int i = 0; i < inputString.length(); i++) {
            if ((inputString[i] >= 'A' && inputString[i] <= 'Z')) {
                isValid = true;
            }
            else if (inputString[i] >= 'a' && inputString[i] <= 'z') {
                isValid = true;
            } else {
                isValid = false;
                break;
            }
        }

        if (isValid) {
            cout << "valid";
        }
        else {
            cout << "Invalid";
        }
    }
};

int main() {
    ValidateString s1("burai r");
    s1.validate();
}
