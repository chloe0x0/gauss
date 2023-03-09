#ifndef TRAPZ_H
#define TRAPZ_H

#include <vector>

// Trapezoidal Approximation given an integrand, a number of trapezoids, and integration bounds
double TRAPZ(double (*f)(double), int, double, double);
// Trapezoidal aproximation given a set of points [f(a), f(x1), ..., f(x_n-1), f(b)] with unit spacing
// equivalent to MATLAB's Q = trapz(X)
double TRAPZ(std::vector<double>);
// Trapezoidal approximation given a set of X values and a function
// equivalent to MATLAB's Q = trapz(X, Y), where Y = f(X)
double TRAPZ(std::vector<double>, double (*f)(double));
// Compute the cummulative integral with the trapezoidal approximation
std::vector<double> CUMTRAPZ(double (*f)(double), int, double, double);
// Computes the cummulative integral of a discrete dataset with the trapezoidal approximation
std::vector<double> CUMTRAPZ(std::vector<double>);

#endif