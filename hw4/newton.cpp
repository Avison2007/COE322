#include <iostream>
#include <functional>
#include <cmath>

using namespace std;

double newton_root(function<double(double)> f,
                   function<double(double)> fprime) {

    double x = 1.0;

    for (int i = 0; i < 20; i++) {
        x = x - f(x) / fprime(x);
    }

    return x;
}

int main() {

    double n;
    cin >> n;

    if (n ==0) {
      cout << 0 << endl;
      return 0;
    }
    auto f = [n](double x) {
        return x * x - n;
    };

    auto fprime = [n](double x) {
        return 2 * x;
    };

    double root = newton_root(f, fprime);

    cout << root << endl;

    return 0;
}
