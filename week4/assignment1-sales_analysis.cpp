#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main () {
const int DAYS = 7;
string dayNames[DAYS] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
double sales [DAYS];

	cout << "WEEKLY SALES ANALYSIS" << endl;
	cout << "---------------------" << endl;

	for (int i = 0; i < DAYS; i++) {
		cout << "Enter sales for " << dayNames[i] << ": ";
		cin >> sales[i];
	}

	double total = 0;
	double best = sales[0], worst = sales[0];
	int bestDay = 0, worstDay = 0;
	int aboveAvgDays = 0;
	double weekendSales = 0;

	for (int i = 0; i < DAYS; i++){
		total += sales[i];
		if (sales[i] > best) {
			best = sales[i];
			bestDay = i;
		}
	if (sales[i] < worst) {
		worst = sales[i];
		worstDay = i;
		}
	}

	double avgSales = total / DAYS;

	for (int i = 0; i < DAYS; i++){
		if (sales[i] > avgSales){
			aboveAvgDays++;
		}
	}

	weekendSales = sales[5] + sales[6];
	double weekendPercent = (weekendSales/ total) * 100;

	cout << fixed << setprecision(2) << endl;
	cout << "Sales Summary: " << endl;
	cout << "Total Sales: $" << total << endl;
	cout << "Average Daily Sales: $" << avgSales << endl;
	cout << endl;
	cout << "Best Day: " << dayNames[bestDay] << " with $" << best << endl;
	cout << "Worst Day: " << dayNames[worstDay] << " with $" << worst << endl;
	cout << endl;
	cout << "Days above average: " << aboveAvgDays << endl;
	cout << "Weekend sales: $" << weekendSales << " (" << fixed <<setprecision(1) << weekendPercent << "% of total)" << endl; 

	return 0;
	
}