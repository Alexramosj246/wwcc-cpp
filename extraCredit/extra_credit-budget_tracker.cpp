#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

struct Date {
	int day;
	int month;
	int year;

	Date(int d, int m, int y) : day(d), month(m), year(y){}
};

struct Expense {
	double amount;
	Date date;
	string category;
	string description;
};

	vector<Expense> expenses;

Expense addExpense() {
	int day, month, year;
	double amount;
	string category, description;

	cout << "\n===ADD NEW EXPENSE===\n";
	cout << "Date (MM DD YYYY): \n";
	cin >> month >> day >> year;

	while (cin.fail() || month < 1 || month > 12 || day < 1 || day > 31 || year < 1900) {
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid date. Please enter in MM DD YYYY: ";
		cin >> month >> day >> year;
	}

	cout << "Enter Amount: $";
	cin >> amount;
	while (cin.fail() || amount < 0){
		cin.clear();
		cin.ignore(1000, '\n');
		cout << "Invalid amount. Enter a positive number: $";
		cin >> amount;
	}

	cin.ignore();
	cout << "Enter Category: ";
	getline(cin, category);

	cout << "Enter Description: ";
	getline(cin, description);

	cout << "\nExpense added Successfully!\n";

	return {amount, Date(day, month, year), category, description};
}

void viewExpense(){
	cout << "\n====EXPENSE LIST====\n";
	if (expenses.empty()){
		cout << "No expenses recorded.\n";
		return;
	}

	for (size_t i = 0; i < expenses.size(); i++){
		cout << "\nExpense #" << i + 1 << endl;
		cout << "Date: " << setw(2) << setfill('0') << expenses[i].date.month << "/"
			<< setw(2) << expenses[i].date.day << "/"
			<< expenses[i].date.year << endl;
		cout << "Amount: $" << fixed << setprecision(2) << expenses[i].amount << endl;
		cout << "Category: " << expenses[i].category << endl;
		cout << "Description: " << expenses[i].description << endl;
	}
}

void generateExpense(){
	cout << "\n====EXPENSE REPORT====\n";
	cout << "--------------------------\n";

	double total = 0;
	for (const auto& e : expenses) {
		total += e.amount;
	}
	cout << "Total Expenses: $" << fixed << setprecision(2) << total << endl;
}


//====================================================================
int main() {
	int choice;

	do {
		cout << "\n====PERSONAL BUDGET TRACKER====";
		cout << "\n----------------------------------\n";
		cout << "1. Add New Expense\n";
		cout << "2. View Expense\n";
		cout << "3. Generate Reports\n";
		cout << "4. Exit\n";


		while (true){
			cout << "Enter your choice (1-4)\n";
			cin >> choice;
		
			if (cin.fail()) {
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid input. Please enter a number.\n";
			} else if (choice < 1 || choice > 4) {
				cout << "Please enter a number between 1 and 4.\n";
			} else {
				break;
			}
		}

		switch (choice){
			case 1: expenses.push_back(addExpense());
			break;
			case 2: viewExpense();
			break;
			case 3: generateExpense();
			break;
			case 4: cout << "Now exiting...\n";
			break;
			default: cout << "Invalid. Must enter numbers 1 - 4\n";
			break;
		}

	} while (choice != 4);


	return 0;
}
//====================================================================
