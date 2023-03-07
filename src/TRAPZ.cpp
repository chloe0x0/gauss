#include <iostream>
#include <assert.h>

// Approximate the definite integral from a to b of f(x) via the Trapezoidal rule using N trapezoids
double TRAPZ(double (*f)(double), int trapz, double a, double b) {
    if (a == b)
        return 0.0;

    assert(a < b);

    double interval, integral, coeff;

    interval = (b - a) / (double)trapz;
    integral = 0.0;

    for (double x_i = a; x_i <= b; x_i += interval) {
        coeff = x_i == a || x_i == b ? 1.0 : 2.0;
        integral += coeff * f(x_i);
    }

    integral *= (b - a)/(2*trapz);

    return integral;
}

double f(double x) {
    return x*x;
}

int main(void) {
    double integral = TRAPZ(&f, 80000, 1, 5);
    std::cout << integral << std::endl;
}