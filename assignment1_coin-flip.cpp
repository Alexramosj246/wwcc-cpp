#include <iostream>
#include <cstdlib>  // For rand() function
#include <ctime>    // For time() function
using namespace std;

int main() {
    srand(time(0));

    int flips;
    int heads = 0;
    int tails = 0;

    cout << "Coin Flip Simulator" << endl;
    cout << "How many flips would you like to simulate? ";
    cin >> flips;

    cout << "Simulating " << flips << " coin flips..." << endl;

    for (int i = 0; i < flips; i++) {
        if (rand() % 2 == 0) {
            heads++;
        } else {
            tails++;
        }
    }

    cout << "Results: \n";
    cout << "Heads: " << heads << endl;
    cout << "Tails: " << tails << endl;

    return 0;
}