#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void convertTemperature (double value, char unit){
	double C, F, K;
	cout << fixed << setprecision(2);
	
	switch (unit){
		case 'F' :
			C = (value - 32) * 5/9;
			K = (value - 32) * 5/9 + 273.15;
			F = value;
			break;
		case 'C' :
				F = (value * 9/5) + 32;
				K = value + 273.15;
				C = value;
			break;
		case 'K' :
				C = value - 273.15;
				F = (value - 273.15) * 9/5 + 32;
				K = value;
			break;
		default:
			cout << "Please enter F, C or K" << endl;

			return;
		}
		cout << "Celsius: " << C << "°" << endl;
		cout << "Kelvin: " << K << endl;
		cout << "Fahrenheit: " << F << "°" << endl;
}

int main() {

double value, F, C, K;
char unit;

	cout << "Enter a temperature value: " << endl;
	cin >> value;

	cout << "Enter the unit (C for Celsius, F for Fahrenheit, K for Kelvin): " << endl;
	cin >> unit;

	convertTemperature (value, unit);

	return 0;
}