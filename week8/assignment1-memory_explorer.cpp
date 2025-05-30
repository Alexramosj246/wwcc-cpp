#include <iostream>
#include <iomanip>

using namespace std;

int example1(int a);
double example2(double b);
char example3(char c);


int main(){
	int a = 0;
	double b = 0.0;
	char c = ' ';
	int x = 10, y = 20;
	int arr[5] = {1, 2, 3, 4, 5};


	cout << "\nMEMORY ADDRESS EXPLORER\n------------------------\n";
	cout << "\nPART 1: Variable Memory Locations\n----------------------------------\n";
	cout << "Integer variable: " << example1(a) << " at address " << &a << endl;
	cout << "Double variable: " << example2(b) << " at address " << &b << endl;
	cout << "Character variable: " << example3(c) << " at address " << static_cast<void*>(&c) << endl;
	cout << endl;

	cout << "PART 2: Reference Demonstration\n--------------------------------\n";
	cout << "Before reference function: x = " << x << " , y = " << y << endl;
	int& ref1 = x;
	ref1 = 100;
	int& ref2 = y;
	ref2 = 200;
	cout << "After reference function: x = " << x << " , y = " << y << endl;
	cout << "(References allow direct modification of original variables)" << endl;
	cout << endl;

	cout << "PART 3: Pointer Demonstration\n-----------------------------\n";
	int i = 5, j = 15;
	int* ptr1 = &i;
	int* ptr2 = &j;
	cout << "Before pointer function: i = " << i << " , j = " << j << endl;
	cout << "Pointer address: i at " << ptr1 << " , j at " << ptr2 << endl;
	i = 50; 
	j = 150;
	cout << "After pointer function: i = " << *ptr1 << " , j = " << *ptr2 << endl;
	cout << "(Pointers access original variables through their addresses)" << endl;
	cout << endl;

	cout << "PART 4: Array and Pointer Relationship\n----------------------------------------\n";
	cout << "Array: [";
	for (int k = 0; k < 5; k++){
		cout << arr[k];
		if (k < 4) cout << ", ";
	}
	cout << "]" << endl;
	cout << "Array name address: "<< arr << endl;
	cout << "First element address: " << &arr[0] << " (same as array name!)" << endl;
	cout << "Second element via pointer arithmetic: " << *(arr + 1) << endl;
	cout << "Third element via pointer arithmetic: " << *(arr + 2) << endl;
	return 0;
}

int example1(int a){
		return  42;
	}

	double example2(double b){
		return 3.14;
	} 
	char example3(char c){
		return 'A';
	} 