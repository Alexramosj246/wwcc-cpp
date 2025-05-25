#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

/*
still a work in progress but feel free to grade me on this. 
I worked on something like this on my midterm. Definately learned more ways 
to do it better. I need to sand some rough edges for sure. 
This is my first time using Vectors!

*/




string toLower(const string& str);

class Author{
	private: 
	string name;
	int birthYear;

	public:
	Author(string n, int y) : name(n), birthYear(y){}

	void displayInfo() const {
		cout << "Author: " << name << " (born " << birthYear << ")" << endl;
	}
	string getName () const{
		return name;
		}

	int getBirthYear () const{
		return birthYear;
	}
};

class Book {
	private:
	string title;
	Author author;
	int releaseYear;
	int ISBN;

	public:
	Book(string t, Author a, int rYear, int isbn) : title(t), author(a), releaseYear(rYear), ISBN(isbn) {}

	void displayInfo() const {
		cout << "\""  << title << "\"" << endl;
		author.displayInfo();
		cout << "Released: " << releaseYear << endl;
		cout << "ISBN: " << ISBN << endl << endl;
	}

	string getTitle() const { return title;}
	int getISBN() const {return ISBN; }
	int getReleaseYear () const {return releaseYear; }
	Author getAuthor () const { return author;}
};


class Library{
	private:
	string libraryName;
	string address;
	vector <Book> books;

	public:


	Library(string l, string a) : libraryName(l), address(a) {}

	void addBook(const Book& book) {
		books.push_back(book);}


	 void searchBook(const string& title) const {
		string searchTitle = toLower(title);
		bool found = false;
		for (const Book& book : books) {
			if (toLower(book.getTitle()).find(searchTitle) != string::npos) {
				book.displayInfo();
				found = true;
			}
		}
		if (!found) {
			cout << "Book not found: " << title << endl;
		}
	}

	string getLibraryName() const {return libraryName;}
	string getAddress() const{return address;}
	Book* getBook (int i) {
		if (i >= 0 && i < books.size()){
			return &books[i];
		}
		return nullptr;
	}

	void getLibraryInfo () const {
		cout << "\nLIBRARY MANAGEMENT SYSTEM" << endl;
		cout << "-------------------------" << endl;
		cout << "Library: " << libraryName << endl;
		cout << "Address: " << address << endl;
		cout << endl << "CATALOG:" << endl;
		for (const Book& book : books ){
		book.displayInfo();
		}
	}
};

string toLower(const string& str) {
	string result = str;
	transform(result.begin(), result.end(), result.begin(), [](unsigned char c) {
		return tolower(c);
	});
	return result;
}

int main(){	
	
	Library lib("Gotham City Library", "266 Newman Ave, Gotham City");

	Author a1("Harper Lee", 1926);
	Book b1("To Kill a Mockingbird", a1, 1960, 123456789);

	Author a2("F. Scott Fitzgerald", 1896);
	Book b2("The Great Gatsby", a2, 1925, 24681012);

	Author a3("George Orwell", 1903);
	Book b3("1984", a3, 1949, 300544889);

	Author a4("George Orwell", 1903);
	Book b4("Animal Farm", a4, 1945, 200054442);


	lib.addBook(b1);
	lib.addBook(b2);
	lib.addBook(b3);
	lib.addBook(b4);

	lib.getLibraryInfo();

	cout << "Searching for a book..." << endl;
	cout << "\nSEARCH RESULTS: " << endl;
	lib.searchBook("animal");

	cout << "Searched titles with the word \"Animal\" " << endl;
	cout << b4.getTitle() << " (" << b4.getReleaseYear() << ")" <<  endl << endl;

	return 0;

}