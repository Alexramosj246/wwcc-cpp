#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
	const int DAYS = 7;
	double temp[DAYS];

	cout << "Temperature Tracker" << endl;
	cout << "------------------" << endl;

	cout << "Enter Temperature for days 1-7; " << endl;
	for (int i = 0; i < DAYS; ++i) {
		cout << "Day " << i + 1 << ": ";
		cin >> temp[i];
	}
	double sum = 0;
	double min = temp[0], max = temp[0];
	int minDay = 1, maxDay = 1;

	for (int i = 0; i < DAYS; i++) {
		sum += temp[i];
		if (temp[i] < min) {
			min = temp[i];
			minDay = i + 1;
		}
		if (temp[i] > max ) {
			max = temp[i]; 
			maxDay = i + 1;
	} 

}
	double avg = static_cast<double>(sum) / DAYS;

	cout << fixed << setprecision(2) << endl;

	cout << "Temperature Analysis: \n";
	cout << "Highest temperature: " << max << "°F (Day) " << maxDay << ")" << endl;
	cout << "Lowest temperature: " << min << "°F (Day) " << minDay << ")" << endl;
	cout << "Average temperature: " << avg << "°F" <<endl;
	cout << endl;
	
	int aboveAvg = 0;
	for (int i = 0; i < DAYS; i++){
		if (temp[i] > avg) aboveAvg++;
	}
	cout << "Days with above-average temperatures: " << aboveAvg << endl;

	cout << endl;

	return 0;
}