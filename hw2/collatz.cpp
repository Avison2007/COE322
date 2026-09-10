#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return x*x - 2;
}

double deriv(double x) {
    return 2*x;
}

double newton_root() {
    double x = 1;

    while (abs(f(x)) >= 1e-5) {
        cout << x << " " << f(x) << endl;
        x = x - f(x) / deriv(x);
    }

    cout << x << " " << f(x) << endl;

    return x;
}

int main() {
    double x = 1;

    while (abs(f(x)) >= 1e-5) {
        cout << x << " " << f(x) << endl;
        x = x - f(x) / deriv(x);
    }

    cout << x << " " << f(x) << endl;

    cout << "sqrt(2) = " << newton_root() << endl;

    return 0;
}
