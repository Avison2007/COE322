#include <iostream>
#include "collatz.h"

using namespace std;

int main() {

    long long start;

    // Read the starting value from the user.
    cin >> start;

    // Calculate and print the Collatz sequence length.
    cout << collatz_length(start) << endl;

    return 0;
}
