#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello, " << name << "!"  " Welcome to C++!" << endl;
    string password;
    cout << "Enter your password: ";
    cin >> password;
    cout << "Thanks " << name << "!" " Now I can hack you! " << endl; 
    return 0;
}