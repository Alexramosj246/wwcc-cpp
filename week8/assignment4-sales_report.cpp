#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <vector>
#include <chrono>
#include <string>
using namespace std;



struct Product{
	string name;
	string category;
	int unitSold;
	double unitPrice;
};

string trim(const string& str){
	size_t start = str.find_first_not_of(" \t");
	size_t end = str.find_last_not_of(" \t");
	return (start == string::npos) ? "" : str.substr(start, end - start + 1);
}

int main(){

	ifstream file ("salesReport.txt");
	if (!file) {
		cerr << "Error: Could not open salesReport.txt" << endl;
		return 1;
	}

	ofstream reportFile("sales_summary.txt");
	if (!reportFile) {
		cerr << "Error: Could not create sales_summary.txt" << endl;
		return 1;
	}

	vector<Product> products;
	string line;

	while (getline(file, line)) {

		Product p;
		size_t pos;

		pos = line.find("Product:");
		if (pos == string::npos) continue;
		size_t start = pos + 8;
		size_t end = line.find("Category:", start);
		p.name = trim(line.substr(start, end - start));

		pos = line.find("Category:", end);
		if (pos == string::npos) continue;
		start = pos + 9;
		end = line.find("Units sold:", start);
		p.category = trim(line.substr(start, end - start));

		pos = line.find("Units sold:", end);
		if (pos == string::npos) continue;
		start = pos + 11;
		end = line.find("Price:", start);
		p.unitSold = stoi(trim(line.substr(start, end - start)));

		pos = line.find("Price:", end);
		if (pos == string::npos) continue;
		start = pos + 6;
		p.unitPrice = stod(trim(line.substr(start)));

		products.push_back(p);
	}

	file.close();



	reportFile << "SALES SUMMARY REPORT" << endl;
	auto now = std::chrono::system_clock::now();
	std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);
	std::tm* local_time = std::localtime(&now_time_t);

	reportFile << "Generated: " << std::put_time(local_time, "%Y-%m-%d %H:%M:%S") << endl;

	reportFile << "=================================\n" << endl;
	reportFile << left << setw(20)<< "Product"
		<< setw(15) << "Category"
		<< right << setw(12) << "Units Sold"
		<< right << setw(12) << "Unit Price"
		<< right << setw(12) << "Total Revenue" << endl;

	reportFile << string(74,'-') << endl;

	double totalRevenue = 0.0;
	for (const auto& p : products) {
		double revenue = p.unitSold * p.unitPrice;
		totalRevenue += revenue;

		reportFile << left << setw(20) << p.name
					<< setw(15) << p.category
					<< right << setw(12) << p.unitSold
					<< right << setw(12) << fixed << setprecision(2) << p.unitPrice
					<< right << setw(14) << fixed << setprecision(2) << revenue << endl;
	}

	reportFile << string(73, '-') << endl;
	reportFile << right << setw(59) << "TOTAL REVENUE: "
				<< setw(14) << fixed << setprecision(2) << totalRevenue << endl;
	

	reportFile.close();
	cout << "Report saved to sales_summary.txt" << endl;

	return 0;

}