#include "Book.h"
#include <iostream>
using namespace std;


	Book::Book(string t, string a, string I) : title(t), author(a), ISBN(I){}
		
	string Book::getTile(){
		return title;
	}
	string Book::getAuthor(){
		return author;
	}
	string Book::getISBN(){
		return ISBN;
	}




