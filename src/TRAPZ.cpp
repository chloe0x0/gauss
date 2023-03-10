#include <iostream>
#include <assert.h>
#include <math.h>
#include <vector>
#include <algorithm>

#define EPSILON 1E-3

// Approximate the definite integral from a to b of f(x) via the Trapezoidal rule using N trapezoids
double TRAPZ(double (*f)(double), int trapz, double a, double b) {
    if (a == b)
        return 0.0;

    double interval, integral;

    interval = (b - a) / (double)trapz;
    integral = f(a);

                        // x_i != b was being fucky (comparing floating point nums)
                        // std::numeric_limits<double>::epsilon() doesnt work, using 1e-3 for now bc it doesnt have these issues
    for (double x_i = a+interval; fabs(x_i - b) > EPSILON; x_i += interval) {
        integral += 2.0 * f(x_i);
    }

    integral += f(b);

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
    Y.resize(X.size());
    std::transform(X.begin(), X.end(), Y.begin(), f); // get function values

    double integral = 0.0;

    double spacing; // temp variable for the spacing between points
    for (int ix = 0; ix < X.size() - 1; ix++) {
        spacing = X.at(ix + 1) - X.at(ix);
        integral += spacing * (Y.at(ix) + Y.at(ix + 1));
    }

    return integral / 2.0;
}

// Compute the Cumulative Integral of f from a to b using N trapezoids
std::vector<double> CUMTRAPZ(double (*f)(double), int trapz, double a, double b) {
    std::vector<double> cums;
    cums.reserve(std::abs(b - a));

    // since inc is -1 | 1 we dont need any epsilon check for equality
    // this is because precision wont be an issue and std::numeric_limits<double>::epsilon() should be enough
    double inc = b > a ? 1 : -1;
    for (double b_ = a; b_ != b+inc; b_+=inc) {
        cums.push_back(TRAPZ(f, trapz, a, b_));
    }

    return cums;
}

// Compute the Cumulative Integral via the trapezoidal method given a set of function values (with unit spacing)
std::vector<double> CUMTRAPZ(std::vector<double> X) {
    std::vector<double> cums;
    cums.reserve(X.size());

    double cum;
    for (int i = X.size() - 1; i >= 0; i--) {
        cum = TRAPZ(std::vector<double>(X.begin(), X.end() - i));
        cums.push_back(cum);
    }

    return cums;
}
