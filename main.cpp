#include <iostream>
#include <string>
#include <map>

using namespace std;

struct Book {
    string title;
    string authors;
    int year;
};

int main() {
    map<string, Book> library;

    Book book1 = { "The Great Gatsby", "F. Scott Fitzgerald", 1925 };
    library["9780743273565"] = book1;

    Book book2 = { "To Kill a Mockingbird", "Harper Lee", 1960 };
    library["9780061120084"] = book2;

    Book book3 = { "1984", "George Orwell", 1949 };
    library["9780451524935"] = book3;

    string isbn = "9780451524935";
	cout << "----------------------------------------" << endl;
    cout << "---Book with ISBN " << isbn << ":" << endl;
    cout << "---Title: " << library[isbn].title << endl;
    cout << "---Authors: " << library[isbn].authors << endl;
    cout << "---Year of Publication: " << library[isbn].year << endl;
	cout << "----------------------------------------" << endl;

	system("pause");
    return 0;
}