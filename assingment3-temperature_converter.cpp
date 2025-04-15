#include <iostream>
#include <string>
using namespace std;

int main () {
    double temperature;
    char unit;

    cout<< "Temperature Converter" << endl;
    cout<< "Enter temperature value: ";
    cin >> temperature;
    cout<< "Enter unit (C for celsius, F for Fahrenheit): ";
    cin >> unit;
    double C = (temperature - 32) * 5.0 / 9.0;
    cout<< C << "C";
    double F = (temperature * 9.0 / 5.0) + 32;
    cout<< F << "F";
   
    return 0;

}