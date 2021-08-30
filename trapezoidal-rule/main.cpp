#include <iostream>
#include <cmath>
#include "trapeze.h"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

using std::cout;
using std::endl;

int main() {
    // f(x)=e^(x^2)
    cout << trapeze::integrate([](double x) -> double {
        return exp(x * x);
    }, 0.0f, 1.0f, 100) << endl;

    // f(x)=sen^2(x)
    cout << trapeze::integrate([](double x) -> double {
        return pow(sin(x), 2);
    }, 0.0f, M_PI / 3, 100) << endl;

    cout << trapeze::integrate([](double x) -> double {
        return 0.2 + 25 * x - 200 * pow(x, 2) + 675 * pow(x, 3) - 900 * pow(x, 4) + 400 * pow(x, 5);
    }, 0.0f, 0.8f, 100) << endl;

    // f(x)=sen(x)
    cout << trapeze::integrate([](double x) -> double {
        return sin(x);
    }, 0.0f, M_PI, 100) << endl;

    // f(x)=1/x
    cout << trapeze::integrate([](double x) -> double {
        return 1/x;
        }, 1.0f, exp(1.0), 100) << endl;

    return 0;
}
