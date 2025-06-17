#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


// A class for managing a bank account
class Account {
private:
	string customerName;
	double amount;
	bool isOpen;
	int accountNumber;
	string type;

		const double SAVINGS_INTEREST = 1.03;
		const double CHECKING_INTEREST = 1.01;
		const double BUSINESS_INTEREST = 1.005;

public:
	Account(const string& n, double a, int acc, const string& t) 
	: customerName(n), amount(a), isOpen(true), accountNumber(acc), type(t) {}

	string getName() const {return customerName; }
	double getAmount() {return amount; }
	bool getAcountIsOpen() {return isOpen; }
	int getAccountNumber() {return accountNumber; }
	string getType() {return type; }

	void deposit(double x) {
		if (!isOpen) {
			cout << "Cannot deposit into a closed account.\n";
			return;
		}

		if (x > 0) amount += x;
		else cout << "Invalid deposit amount.\n";
	}

	void withdraw(double x) {
		if (!isOpen){
			cout << "Cannot withdraw from a closed account.\n";
			return;
		}

		if (x > 0 && x <= amount) amount -= x;
		else cout << "Invalid withdrawal amount.\n";
	}

	void addInterest() {
		if(!isOpen) return;

		if (type == "Savings") {
			amount *= SAVINGS_INTEREST;
		} else if (type == "Checking") {
			amount * CHECKING_INTEREST;
		} else if (type == "Business") {
			amount * BUSINESS_INTEREST;
		} else {
			cout << "Unknown account type. No interest applied.\n";
		}
	}



	void print() {
		cout << "\nAccount Number: " << accountNumber << endl;
		cout << "Customer Name: " << customerName << endl;
		cout << "Balance: $" << amount << endl;
		cout << "Account Type: " << type << endl;
		cout << "Status: " << (isOpen ? "Open" : "Closed") << endl;
		cout << endl;
	}

	void close() {
		isOpen = false;
	}
};


int main(){

	cout << "\n====Metropolis Mutual====\n";

	Account person1("Mark Johnson", 1000.00, 123456, "Savings");

	cout << fixed << setprecision(2) << endl;
	person1.deposit(500.00);
	person1.withdraw(700.00);
	person1.addInterest();

	person1.print();
	person1.close();

	return 0;

}