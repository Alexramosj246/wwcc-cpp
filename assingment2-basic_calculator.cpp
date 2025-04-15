#include <iostream>

int main() {
    double num1, num2;

    std::cout << "Enter the first number: ";
    std::cin >> num1;

    std::cout << "Enter the second number: ";
    std::cin >> num2;

    std::cout << "Results:\n";
    std::cout << "Sum: " << num1 + num2 << "\n";
    std::cout << "Difference: " << num1 - num2 << "\n";
    std::cout << "Product: " << num1 * num2 << "\n";
    std::cout << "Quotient: ";

    if (num2 != 0) {
        std::cout << num1 / num2 << "\n";
    } else {
        std::cout << "Undefined (division by zero)\n";
    }

    return 0;
}