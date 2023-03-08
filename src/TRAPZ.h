#ifndef TRAPZ_H
#define TRAPZ_H

// Trapezoidal Approximation
double TRAPZ(double (*f)(double), int, double, double);
// Compute the cummulative integral with the trapezoidal approximation
double* CUMTRAPZ(double (*f)(double), int, double, double);

#endif

