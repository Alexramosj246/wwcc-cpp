#include <iostream>
#include <iomanip>
using namespace std;


class Rectangle{
	private:
		int length;
		int width;

	public:
		int getLength() const {return length;}
		int getWidth()const {return width;}
		
		Rectangle(int l, int w) : length(l), width(w){
		} 

		double area () const {
			 return length * width;
		}

		void area (int& result) const {
			result = length * width;
			}

			Rectangle& resize(int newLength, int newWidth){
				this->length = newLength;
				this->width = newWidth;
				return *this;
			}
		
		void print();
};

class Circle{

	private:
		double radius;

	public:
		const double pi = 3.14159;
		Circle(double r) : radius(r){}
		double getRadius() const {return radius;}

		double area() const {
			return pi * radius * radius;
		}
		double circumference() const {
			return pi * radius * 2.0;
		}
		void print(); 
		void print (bool details);
};

void Rectangle::print() {
			cout << "Rectangle (Length: " << length << ", Width: " << width << ")" << endl;
			cout << "Area: " << length * width << endl;
			int result = 0;
			area(result);
			cout << "Passing by reference: " << area() << endl;

}

void Circle::print() {
			cout << "\nCircle (Radius: " << radius << ")" << endl;
			cout << fixed << setprecision(2);			
			cout << "Area: " << area() << endl;
			cout << "Circumference: " << circumference() << endl;
}

void Circle::print (bool details) {
	if (true) {
			double a = area();
			double c = circumference();
			cout << "Circle Details: \n";
			cout << "Radius: " << radius << endl;
			cout << fixed << setprecision(2);
			cout << "Area: π x radius^2 = 3.14159 x " << (radius * radius) << " = " << a << endl;
			cout << "Circumference: 2 x π x radius = 2 x 3.14159 x " << radius << " = " << c << endl << endl;
	}
}

int main(){

	cout << "\nSHAPE CALCULATOR" << endl;
	cout << "-------------------" << endl;

	Rectangle shape1(5,3);
	Circle shape2(4);

	shape1.print();
	shape2.print();
	cout << endl;
	shape2.print(true);

	cout << "Method chaining demonstration: " << endl;
	cout << "Original rectangle: Length = " << shape1.getLength() << ", Width = " << shape1.getWidth() << endl;
	shape1.resize(10, 6);
	cout << "After resizing: Length = " << shape1.getLength() << ", Width = " << shape1.getWidth() << endl;

	return 0;
}