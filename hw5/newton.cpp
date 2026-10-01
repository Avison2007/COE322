#include <iostream>
#include <cmath>
#include <functional>

using namespace std;

double newton_root(
    function<double(double)> f,
    function<double(double)> fprime
)
{
    double x = 1.0;

    for (int i = 0; i < 20; i++)
    {
        double fx = f(x);
        double fpx = fprime(x);

        x = x - fx / fpx;
    }

    return x;
}


double newton_root(function<double(double)> f)
{
    double h = 1e-6;

    auto fprime = [f, h](double x)
    {
        return (f(x + h) - f(x)) / h;
    };

    return newton_root(f, fprime);
}


int main()
{
    double n;
    cin >> n;

    auto f = [n](double x)
    {
        return x * x - n;
    };

    double root = newton_root(f);

    cout << root << '\n';

    return 0;
}
