#include "Book.h"
#include <iostream>
using namespace std;

int main(){
	Book b("Ammar Kamran", "Sameed", "892232534");
	cout << b.getAuthor() << endl;
}