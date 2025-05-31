#include <iostream>
#include <fstream>
#include <ctime>
#include <limits>
#include <string>
using namespace std;

void addEntry() {
	ofstream file("journal.txt", ios::app);
	if (!file){
		cout << "Error opening file..." << endl;
		return;
	}

	string entry, line;
	cin.ignore();
	cout << "ADD NEW JOURNAL ENTRY\n--------------------\n";
	cout << "Enter your journal entry (press Enter twice to finish):" << endl;
	while (true) {
		getline(cin, line);
		if (line.empty()) break;
		entry += line + "\n";
	}

	time_t now = time(0);
	string timestamp = ctime(&now);
	timestamp.pop_back();

	file << "[" << timestamp << "]\n" << entry << "\n------------------------\n";
	file.close();

	cout << "Entry saved successfully!" << endl;
}

void viewEntries(){
	ifstream file ("journal.txt");
	if (!file){
		cout << "No entries found!\n";
		return;
	}

	string line;
	cout << "JOURNAL ENTRIES\n-----------------" << endl;
	while (getline(file, line)){
		cout << line << endl;
	}
	// cout << "-----------------------------" << endl;
	file.close();
}

void searchEntries(){
	ifstream file("journal.txt");
	if (!file) {
		cout << "No entries to search\n" << endl;
		return;
	}
	
	string keyword;
	cout << "SEARCH JOURNAL ENTRIES\n----------------------\n";
	cout << "Enter search keyword: " << endl;
	cin >> keyword;

	string line;
	bool found = false;

	while (getline(file, line)) {
		if (line.find(keyword) != string::npos) {
			if (!found){ 
				cout << "\nFound matching entry!" << endl;
			}
			cout << line << endl;
			found = true;
		}
	}

	if (!found) {
		cout << "No entries matched your search.\n";
	}
	cout << "-----------------------------\n" << endl;
	file.close();

}



int main(){
	int choice;

	do {
		cout << "\nPERSONAL JOURNAL SYSTEM\n------------------------\n";
		cout << "1. Add New Entry" << endl;
		cout << "2. View All Entries" << endl;
		cout << "3. Search Entries" << endl;
		cout << "4. Exit\n" << endl;
		cout << "Enter your choice: ";
		cin >> choice;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input! Enter number 1 - 4." << endl;
			continue;
		}


		switch (choice) {
			case 1: addEntry();
				break;
			case 2: viewEntries(); 
				break;
			case 3: searchEntries(); 
				break;
			case 4: cout << "Now exiting..." << endl; 
				break;
			default: 
				cout << "Invalid Choice! (must enter number from 1-4)" << endl;
		}
	} while (choice != 4);

	return 0;
}