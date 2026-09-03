#include <iostream>
using namespace std;

int main() {
    long long longest = 0;

    for (long long start = 1; start <= 1000; start++) {
        long long n = start;
        long long length = 1;

        // Generate the Collatz sequence until reaching 1
        while (n != 1) {
            if (n % 2 == 0) {
                n = n / 2;
            } else {
                n = 3 * n + 1;
            }

            length++;
        }

        // If this is the longest sequence so far
        if (length > longest) {
            longest = length;
            cout << start << endl;
        }
    }

    return 0;
}
