#include <iostream>
#include <assert.h>
#include <cmath>
#include <vector>
#include <algorithm>

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

// Approximate the definite integral of a specified set of function values using N trapezoids
// uses unit spacing
// MATLAB equivalent: Q = trapz(pts)
double TRAPZ(std::vector<double> pts) {
    double integral = 0.0;

    for (int ix = 0; ix < pts.size() - 1; ix++) {
        integral += pts.at(ix) + pts.at(ix + 1);
    }

    return integral / 2.0;
}

// Approximate the definite integral over a set of X values for a function f
// assumes non-unit spacing 
// MATLAB equivalent: Q = trapz(X, y), where y = f(X)
double TRAPZ(std::vector<double> X, double (*f)(double)) {
    std::vector<double> Y;
    std::transform(X.begin(), X.end(), Y.begin(), f); // get function values

    double integral = 0.0;

    double spacing; // temp variable for the spacing between points
    for (int ix = 0; ix < X.size() - 1; ix++) {
        spacing = X.at(ix + 1) - X.at(ix);
        integral += spacing * (Y.at(ix) + Y.at(ix + 1));
    }

    return integral / 2.0;
}

double f(double x) {
    return cbrt(sin(x + x)) / exp(x);
}

int main(void) {
    double integral = TRAPZ(&f, 25, -log(2.0), log(2.0));
    std::cout << integral << std::endl;

    std::vector<double> points = {1.0, 4.0, 9.0, 16.0, 25.0};
    integral = TRAPZ(points);
    std::cout << integral << std::endl;


}