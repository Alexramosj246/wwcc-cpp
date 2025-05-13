#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
#include <cctype>

const int SIZE = 10;

struct Book {
	std::string title;
	std::string author;
    int year;
    std::string isbn;
	std::string genre;
    bool checkedOut;
    // Date dueDate;
};


void addBook(Book library[], int& bookCount);
void searchBook(const Book library[], int bookCount);

std::string toLower(const std::string& str) {
	std::string result = str;
	std::transform(result.begin(), result.end(), result.begin(),
				   [](unsigned char c) { return std::tolower(c); });
	return result;
}

int main() {

	Book library[SIZE];
	int bookCount = 0;
	char letter;
	int choice;

do {

	std::cout << "Book Library Catalog" << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << "1. Search\n" "2. Add book to catalog\n" "3. Exit program\n";
	std::cout << "Enter a number: " << std::endl;
	std::cin >> choice;
	std::cin.ignore();

	switch (choice) {
		case 1: searchBook(library, bookCount);
		break;
		case 2: addBook(library, bookCount);
		break;
		case 3: std::cout << "Now Exiting... Thank you for your time!" << std::endl;
		break;
		default: 
		std::cout << "Please enter one of the choices!" << std::endl;
			}
		} while (choice != 3);

	return 0;

}

void addBook(Book library[], int& bookCount){
	if (bookCount >= SIZE){
		std::cout << "Library is full..." << std::endl;
		return;
	}
Book book;

		std::cout << "Enter book title: " << std::endl;
		getline(std::cin, book.title);
		std::cout << "Enter author:" << std::endl;
		getline(std::cin, book.author);
		std::cout << "Enter the books release year: " << std::endl;
		std::cin >> book.year;
		std::cin.ignore();
		std::cout << "Enter ISBN: " << std::endl;
		getline(std::cin, book.isbn);
		std::cout << "Enter Genre: " << std::endl;
		getline(std::cin, book.genre);
		book.checkedOut = false;

		library[bookCount] = book;
		bookCount++;

		std::cout << "Book entered successfully!\n";

		std::cout << std::endl;
	}


	void searchBook(const Book library[], int bookCount){

		int searchChoice;
			std::cout << "------------------------" << std::endl;
			std::cout << "Choose an option: \n";
			std::cout << "1. Search by Title\n" "2. Search by Author\n" "3. Search by Genre\n";
			std::cout << "Enter Number 1-3" << std::endl;
			std::cin >> searchChoice;
			std::cin.ignore();
			std::string query;
			bool found = false;

			std::cout << "Enter search term: ";
			std::getline(std::cin, query);

			std::string loweredQuery = toLower(query);

			for (int i = 0; i < bookCount; i++){
				std::string compareField;
			

			if (searchChoice == 1){
				// std::cout << "Searching title..." << std::endl;
				compareField = library[i].title;
			}else if (searchChoice == 2) {
				// std::cout << "Searching author..." << std::endl;
				compareField = library[i].author;
			}else if (searchChoice == 3){
				// std::cout << "Searching genre..." <<std::endl;
				compareField = library[i].genre;
			}else {
				std::cout<< "Enter a choice!" << std::endl;
				return;
			}

			if (toLower(compareField)== loweredQuery){
				found = true;

				std::cout << "\nBook Found:\n";
				std::cout << "Title: " << library[i].title << "\n";
				std::cout << "Author: " << library[i].author << "\n";
				std::cout << "Year: " << library[i].year << "\n";
				std::cout << "ISBN: " << library[i].isbn << "\n";
				std::cout << "Genre: " << library[i].genre << "\n";
				std::cout << "Checked Out: " << (library[i].checkedOut ? "Yes" : "No") << "\n\n";
			}
		}
	
		if (!found) {
			std::cout << "No books found matching your search.\n";
		}
	}