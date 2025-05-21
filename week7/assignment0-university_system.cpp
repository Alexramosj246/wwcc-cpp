#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Course {
private:
	string code;
	string title;
	int creditHours;

public:
	Course(string c, string t, int h) : code(c), title(t), creditHours(h){
	}

	void info() const{
	cout << code << " : " << title << " (" << creditHours << " credits)" << endl; 
	}
};

class Student {
private:
	string name;
	int ID;
	double GPA;

public:
	Student(string n, int d, double g) : name(n), ID(d), GPA(g) {
	}
	void details() const {
		cout << "ID: " << ID << " - " << name << endl;
		cout << "GPA: " << GPA << endl;
		cout << endl;
	}
	void updateGPA(double newGPA) {
		GPA = newGPA;
	}
int getID() const {
	return ID;
}

};

int main(){

	char choice;



	cout << "UNIVERSITY MANAGEMENT SYSTEM\n";
	cout << "----------------------------\n";

	Student person1("Emberly Kahn", 1001, 3.75);
	Student person2("Niko Bellic", 1002, 3.34);
	Student person3("Alder Maxon", 1003, 3.04);

	cout << "Student Information: " << endl;
	cout << fixed << setprecision(2) << endl;
	person1.details();
	person2.details();
	person3.details();

	Course info1("CS101", "Intro to Programming", 3);
	Course info2("MATH201", "Calculus II", 4);

	info1.info();
	info2.info();
	cout << endl;

	cout << "Update Student GPA?" << endl;
	cout << "1. Yes - 2. No  \n";
	cin >> choice;

		if (choice == '1') {
			int studentID;
			double newGPA;

			cout << "Enter Student ID (e.g., 1001): \n";
			cin >> studentID;
			
			cout << "Enter new GPA: ";
			cin >> newGPA;

			while (newGPA < 0.0 || newGPA > 4.0) {
				cout << "Can't be greater than 4.0 - Please enter a value from 0 to 4.0: " << endl;
				cin >> newGPA;
			}

			if (studentID == person1.getID()){
				person1.updateGPA(newGPA);
			} else if (studentID == person2.getID()){
				person2.updateGPA(newGPA);
			} else if (studentID == person3.getID()){
				person3.updateGPA(newGPA);
			} else {
				cout << "Invalid Student ID.\n";
				return 1;
			}

			cout << "Updated student information: \n";
				person1.details();
	 			person2.details();
				person3.details();
		} else {
			cout << "No GPA changes made. \n";
		}
	
	return 0;

}