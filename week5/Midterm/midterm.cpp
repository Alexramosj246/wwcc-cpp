#include <iostream>
#include <string>
#include <chrono>
#include <algorithm>
#include <cctype>

/*
	Here is a summary of my findings:
	- I do not see:
		- comments in your code
		- input validation
		- books within a range
		- check in/out functionality
		- a way to mark book as due/overdue
	- Some issues with indentation that make the card difficult to read in places
	- checkedOut is hard-coded to false

	Overall, for what you did the output looked nice.  There was just some missing functionality.
	Work on formatting readability and consistancy
*/

const int SIZE = 10; // This is a good approach to handling array sizes

struct Book
{ // Good struct, would have liked to see the Date struct as well
	std::string title;
	std::string author;
	int year;
	std::string isbn;
	std::string genre;
	bool checkedOut;
	// Date dueDate;
};

void addBook(Book library[], int &bookCount);
void searchBook(const Book library[], int bookCount);

std::string toLower(const std::string &str)
{
	std::string result = str;
	std::transform(result.begin(), result.end(), result.begin(),
				   [](unsigned char c)
				   { return std::tolower(c); }); // This would be a good place for a comment to describe what is going on here.
	return result;
}

int main()
{

	Book library[SIZE];
	int bookCount = 0;
	char letter;
	int choice;

	do
	{ // This whould be indented along with the content within it.  General rule of thumb is everything within curly brackets should be one tab level over for readability

		std::cout << "Book Library Catalog" << std::endl;
		std::cout << "------------------------" << std::endl;
		std::cout << "1. Search\n"
					 "2. Add book to catalog\n"
					 "3. Exit program\n"; // Why switch to \n when others are std::endl?
		std::cout << "Enter a number: " << std::endl;
		std::cin >> choice;
		std::cin.ignore();

		switch (choice)
		{
		case 1:
			searchBook(library, bookCount);
			break;
		case 2:
			addBook(library, bookCount);
			break;
		case 3:
			std::cout << "Now Exiting... Thank you for your time!" << std::endl;
			break;
		default:
			std::cout << "Please enter one of the choices!" << std::endl;
		}
	} while (choice != 3); // Due to the above indent issues I almost missed this loop.

	return 0;
}

void addBook(Book library[], int &bookCount)
{ // Some places you have a space, sometimes you don't after the method definition and the {
	if (bookCount >= SIZE)
	{
		std::cout << "Library is full..." << std::endl;
		return;
	}
	Book book; // Another indent issue that should align with the above if statement

	// The following block would be a good place for user input validation

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
	book.checkedOut = false; // a new line above this would be good for readability

	library[bookCount] = book;
	bookCount++;

	std::cout << "Book entered successfully!\n"; // Another \n that does not match the rest.  Generally it is a good idea to pick one or the other and use everywhere

	std::cout << std::endl;
}

void searchBook(const Book library[], int bookCount)
{
	// Sometimes you have an empty line here, other times not.  Consistency is always a good goal.
	int searchChoice;
	// The following again has some indent issues as well as mixed \n and std::endl
	std::cout << "------------------------" << std::endl;
	std::cout << "Choose an option: \n";
	std::cout << "1. Search by Title\n"
				 "2. Search by Author\n"
				 "3. Search by Genre\n";
	std::cout << "Enter Number 1-3" << std::endl;
	std::cin >> searchChoice;
	std::cin.ignore();
	std::string query; // keeping variable definitions together is a good practice.  This could go above near searchChoice.
	bool found = false;

	std::cout << "Enter search term: ";
	std::getline(std::cin, query);

	std::string loweredQuery = toLower(query); // Good approach here setting to lowercase

	for (int i = 0; i < bookCount; i++)
	{
		std::string compareField;

		// more indent issues
		// This if would probably work better as a switch statement
		if (searchChoice == 1)
		{
			// std::cout << "Searching title..." << std::endl;
			compareField = library[i].title;
		}
		else if (searchChoice == 2)
		{
			// std::cout << "Searching author..." << std::endl;
			compareField = library[i].author;
		}
		else if (searchChoice == 3)
		{
			// std::cout << "Searching genre..." <<std::endl;
			compareField = library[i].genre;
		}
		else
		{
			std::cout << "Enter a choice!" << std::endl;
			return; // rather than a return here, a loop might have been a better choice to validate this input
		}

		if (toLower(compareField) == loweredQuery)
		{ // spacing issues here as well
			found = true;

			// This section uses all \n, which is good... but having the whole file be consistent is the goal
			std::cout << "\nBook Found:\n";
			std::cout << "Title: " << library[i].title << "\n";
			std::cout << "Author: " << library[i].author << "\n";
			std::cout << "Year: " << library[i].year << "\n";
			std::cout << "ISBN: " << library[i].isbn << "\n";
			std::cout << "Genre: " << library[i].genre << "\n";
			std::cout << "Checked Out: " << (library[i].checkedOut ? "Yes" : "No") << "\n\n"; // Good output of the bool value here.
		}
	}

	if (!found)
	{
		std::cout << "No books found matching your search.\n";
	}
}