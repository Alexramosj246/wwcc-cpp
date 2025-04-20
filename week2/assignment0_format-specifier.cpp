#include <iostream>
#include <cstdio>   // For printf function
using namespace std;

int main() {
    int integer_value = 42;
    float float_value = 3.14159265f;
    double double_value = 3.14159265;
    char char_value = 'X';
    const char* string_value = "Hello, World!";

    printf("Format Specifier Practice\n");
    printf("------------------------\n\n");

    // Interger Formats

    printf("Interger formats:\n");
    printf("Decimal: %d\n", integer_value); // prints decimal using %d 
    printf("Hexadecimal: %x\n", integer_value); // prints Hexadecimal using %x
    printf("Octal: %o\n", integer_value); // prints octal using %o
    printf("With width (5):|%5d|\n", integer_value); // using "5" for # of spaces by inside the % and d
    printf("Left-Alingned:|%-5d|\n\n",integer_value); // prints %-5d to left align with spaces in front

    // Float Formats

    printf("Float formats:\n"); 
    printf("Default: %f\n", float_value); // used float/double decimal specifier
    printf("With precision (2): %.2f\n", float_value); //used .2 to output decimal precision 
    printf("Scientific: %e\n", float_value); // used the float/double Scientific notation specifier
    printf("Fixed with precision (4):%.4f\n\n", float_value); // //used .4 to output decimal precision

    //Charecter and Strings
    printf("Character and Strings formats:\n");
    printf("Character: %c\n", char_value); // used single character specifier
    printf("String: %s\n", string_value); // used string of characters specifier
    printf("String with width (20):|%20s|\n", string_value); // using "20" for # of spaces by inside the % and s

    return 0;
}
