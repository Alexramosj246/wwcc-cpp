#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

struct Student {
	string studentID;
	string firstName;
	string lastName;
	vector<double> scores;
	double average;


	double calculateAverage(){
		if (scores.empty()) return 0.0;
		double sum = 0;
		for (int score : scores) {
			sum += score;
		}
		average = sum / scores.size();
		return average;
	}

};

int main(){
	ifstream inputFile("grades.txt");
	if (!inputFile) {
		cerr << "Error: Cannot open grades.txt" << endl;
		return 1;
	}

	vector<Student> students;
	string line;
	int lineNumber = 0;
	int errorCount = 0;

	while (getline(inputFile, line)) {
		lineNumber++;

		if (line.empty() || line[0] == '#') {
			continue;
		}

		stringstream ss(line);
		Student student;

		if (!(ss >> student.studentID >> student.firstName >> student.lastName)) {
			cerr << "Warning: Invalid format at line " << lineNumber << endl;
			errorCount++;
			continue;
		}

		string courseData;
		while (ss >> courseData) {
			size_t colonPos = courseData.find(':');
			if (colonPos != string::npos) {
				try {
					double score = stod(courseData.substr(colonPos + 1));
					if (score < 0.0 || score > 4.0){
					cerr << "Warning: Invalid GPA score " << score << " at line " <<lineNumber << endl;
					errorCount++;
				} else {
					student.scores.push_back(score);
				}
				
		} catch (...) {
			cerr << "Warning: Unable to parse score in \"" << courseData << "\" at line " << lineNumber << endl;
			errorCount++;
		}
	} else {
			cerr << "Warning: Invalid course format \"" << courseData << "\" at line " << lineNumber << endl;
			errorCount++;
 		}
	}
	if (!student.scores.empty()) {
			student.calculateAverage();
			students.push_back(student);
	}
}

	inputFile.close();


	cout << "\nSTUDENT ACADEMIC RECORD PROCESSOR\n---------------------------------\n";
	cout << "Reading student records from input file...\n" << endl;
	cout << "STUDENT GRADE REPORT\n---------------------\n";

	cout << left << setw(10) << "ID"
	<< setw(20) << "Name"
	<< setw(15) << "Courses Taken"
	<< setw(10) << "GPA" << endl;
	cout << string(55, '-') << endl;

	double totalGPA = 0.0;
	int totalCourses = 0;
	double highestGPA = -1.0;
	double lowestGPA = 5.0;
	string highestStudent = "";
	string lowestStudent = "";

	for (const Student& student : students){
		cout << left << setw(10) << student.studentID
		<< setw(20) << student.firstName + " " + student.lastName
		<< setw(15) << student.scores.size()
		<< fixed << setprecision(2) << setw(10) << student.average  << endl;

		totalGPA += student.average;
		totalCourses += student.scores.size();
		if (student.average > highestGPA){
			 highestGPA = student.average;
			 highestStudent = student.firstName + " " + student.lastName;
		}
		if (student.average < lowestGPA) {
		 	lowestGPA = student.average;
			lowestStudent = student.firstName + " " + student.lastName;
		}
	}

	cout << "\nCLASS STATISTICS\n--------------------\n";
	cout << "Total Students: " << students.size() << endl;
	cout << "Total Courses Taken: " << totalCourses <<endl;
	cout << "Class Average: " << fixed << setprecision(2) << (students.empty() ? 0.0 : totalGPA / students.size()) << endl;

	cout << "Highest GPA: " << highestStudent << " (" << fixed << setprecision(2) << highestGPA << ")" << endl;
	cout << "Lowest GPA: " << lowestStudent << " (" << fixed << setprecision(2) << lowestGPA << ")" << endl;
	

	cout << "\nTotal valid student records: " << students.size() << endl;
	cout << "Total warnings/errors: " << errorCount << endl;
	cout << "\nSummary report written to output file successfully.\n" << endl;

	return 0;
}