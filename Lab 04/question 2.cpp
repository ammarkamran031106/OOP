#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Book {
    private:
        int bookID;
        string bookTitle;
        string bookAuthor;
        bool availability;

    public:
        Book() { }

        Book(int id, string title, string author, bool avail) {
            bookID = id;
            bookTitle = title;
            bookAuthor = author;
            availability = avail;
        }

        Book(int id, string title, string author) {
            bookID = id;
            bookTitle = title;
            bookAuthor = author;
            availability = false;
        }

        int get_bookID() {
            return bookID;
        }

        bool is_available() {
            return availability;
        }

        string get_title() {
            return bookTitle;
        }

        string get_author() {
            return bookAuthor;
        }

        bool check_availability() {
            return availability;
        }

        void set_availability(bool avail) {
            availability = avail;
        }
};

class Library {
    private:
        int bookCount;
        int currentIndex = 0;
        Book * books = new Book[20];

    public:
        void add_book(int id) {
            string title, author;
            bool avail;
            cout << "Enter title: ";
            cin >> title;
            cout << "Enter author: ";
            cin >> author;
            Book temp(id, title, author);

            if (currentIndex < 20) {
                books[currentIndex] = temp;
                bookCount++;
                currentIndex++;
            } else {
                cout << "Library already full" << endl;
            }

            cout << "Enter availability: ";
            cin >> avail;
            Book temp1(id, title, author, avail);
            books[currentIndex] = temp1;
            currentIndex++;
            bookCount++;
        }

        int get_bookCount() {
            return bookCount;
        }

        void borrow(int id) {
            for (int i = 0; i < 20; i++) {
                if (books[i].get_bookID() == id) {
                    books[i].set_availability(false);
                    cout << "Book Borrowed: " << books[i].get_title() << endl;
                }
            }
        }

        void return_book(int id) {
            for (int i = 0; i < 20; i++) {
                if (books[i].get_bookID() == id) {
                    books[i].set_availability(true);
                    cout << "Book Returned: " << books[i].get_title() << endl;
                }
            }
        }

        void display_all() {
            cout << setw(30) << "BOOK LIST" << endl;
            int count = get_bookCount();
            for (int i = 0; i < count; i++) {
                cout << "Book Name: " << books[i].get_title() << endl;
                cout << "Book ID: " << books[i].get_bookID() << endl;
                cout << "Book Author: " << books[i].get_author() << endl;
                cout << "Book Available: " << books[i].is_available() << endl;
            }
        }
};

int main() {
    Library L;
    L.add_book(12);
    L.add_book(15);
    L.borrow(12);
    L.return_book(12);
    L.display_all();
}
