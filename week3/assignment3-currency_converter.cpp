#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


double dollarToEuro (double amount);
double dollarToPound (double amount);
double dollarToYen (double amount);
int getConversionCount (int count);

int main () {


	cout << fixed << setprecision(2);
	char number;
	double amount;
	int conversionCount = 0;

	cout << "CURRENCY CONVERTER: " << endl;
	cout << "---------------------" << endl;
	cout << "1. Convert USD to Euro (EUR)" << endl;
	cout << "2. Convert USD to British Pound (GBP)" << endl;
	cout << "3. Convert USD to Japanese Yen (JPY)" << endl;
	cout << "4. Exit" << endl;
	cout << "Enter your choice (1-4): " << endl;
	cin >> number;
	
	
	if (number == '4') {
		cout << "Thank you for using the Currency Converter!" << endl;
		return 0;
	}

	cout << "Enter amount in USD: " << endl;
	cin >> amount;

	switch (number){
	case '1':
	cout << amount << " USD = " << dollarToEuro (amount) << " EUR" << endl;
	break;
	case '2':
	cout << amount << " USD = " << dollarToPound (amount) << " GBP" << endl;
	break;
	case '3':
	cout << amount << " USD = " << dollarToYen (amount) << " JPY" << endl;
	break;
	default:
	cout << "Please Enter a number between 1-4. " << endl;
}

return 0;

}


double dollarToEuro (double amount){
	return amount * 0.85;
}
double dollarToPound (double amount) {
	return amount * 0.74;
}
double dollarToYen (double amount){
	return amount * 110.33;
}