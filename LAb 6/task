/*1. Create a Message class
o It should have a private instance variable text of type string to store the message
content.
o Implement a method toString() that returns the message text.
o Provide a setter method to modify the text value.
2. Create an SMS class that inherits from Message
o It should have an additional instance variable recipientContactNo to store the
recipient’s phone number.
o Implement appropriate accessor and mutator methods.
o Override the toString() method to return a concatenated string containing the
recipient’s contact number and the message text.
3. Create an Email class that inherits from Message
o It should have additional instance variables: sender, receiver, and subject.
o Implement appropriate accessor and mutator methods.
o Override the toString() method to return a concatenated string containing sender,
receiver, subject, and the message text.
4. Implement Keyword Search Function
o Define a function:
o bool ContainsKeyword(const Message& messageObject, const string& keyword);
o This function should return true if the text of the Message object contains the
given keyword, otherwise return false.

5. Implement Message Encoding
o Define a function to encode a given message using the following scheme:
 Each character should be replaced by the next character in the alphabet
(e.g., ‘A’ → ‘B’, ‘b’ → ‘c’, ‘Z’ → ‘A’, ‘z’ → ‘a’).
 Example: If the message is "This is Java", the encoded message should be
"Uijt jt Kbwb".
6. Test the Implementation
o In the main() function, create sample objects of SMS and Email, assign values,
and test the functionalities including keyword search and encoding.*/
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Message {
private:
    string text;
public:
    void set_text(string t) {
        text = t;
    }
    string toString() const {
        return text;
    }
};

class SMS : public Message {
    string recipientContactNo;
public:
    void set_recipientContactNo(string num) {
        recipientContactNo = num;
    }
    string get_recipientContactNo() {
        return recipientContactNo;
    }
    string toString() {
        return "Recipient Contact No: " + recipientContactNo + "Message:" + Message::toString();
    }
};

class Email : public Message {
    string sender, receiver, subject;
public:
    void set_sender(string s) {
        sender = s;
    }
    void set_receiver(string r) {
        receiver = r;
    }
    void set_subject(string sub) {
        subject = sub;
    }
    string get_sender() const {
        return sender;
    }
    string get_receiver() const {
        return receiver;
    }
    string get_subject() const {
        return subject;
    }
    string toString() const  {
        return "Sender: " + sender + " Receiver: " + receiver + " Subject: " + subject + "Message:" + Message::toString();
    }
};

bool ContainsKeyword(const Message& messageObject, const string& keyword) {
    string check = messageObject.toString();
    if (check.find(keyword) != string::npos) {
        return true;
    }
    else
    return false;
}

string encodeMessage(const string & text) {
    string encodedMessage = text;
    for (int i = 0; i < encodedMessage.length(); i++) {
        if(encodedMessage[i]=='z'){
        	encodedMessage[i]='a';
		}
		else if(encodedMessage[i]=='Z'){
			encodedMessage[i]='A';
		}
		else if (isalpha(encodedMessage[i])) {
			encodedMessage[i]=encodedMessage[i]+1;
		}
	}
	return encodedMessage;
}

int main() {
    SMS sms;
    sms.set_text("Hello, this is a testing SMS!");
    sms.set_recipientContactNo("123-456-7890");

    Email email;
    email.set_text("tommorrow meeting in conference room with ceo at 5PM");
    email.set_sender("john@example.com");
    email.set_receiver("jane@example.com");
    email.set_subject("Important Information");

    string keyword = "test";
    if (ContainsKeyword(sms, keyword)) {
        cout << "Keyword found in SMS!" << endl;
    } 
	else {
        cout << "Keyword not found in SMS." << endl;
    }
    if (ContainsKeyword(email, keyword)) {
        cout << "Keyword found in Email!" << endl;
    } 
	else {
        cout << "Keyword not found in Email." << endl;
    }
	cout<<"Orignal SMS Message: " <<sms.toString()<<endl;
	cout << "Encoded SMS Message: " << encodeMessage(sms.toString()) << endl;
    cout<<"orignal Email Message: " <<email.toString() <<endl;
	cout << "Encoded Email Message: " << encodeMessage(email.toString()) << endl;
    return 0;
}
