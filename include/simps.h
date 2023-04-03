#ifndef SIMP_H
#define SIMP_H

// Numerically integrate a function over an interval [a, b] with Simpson's 1/3 Rule 
double simp13(double (*f)(double), int, double, double);
// Numerically integrate a function over an interval [a, b] with Simpson's 3/8 Rule
double simp38(double (*f)(double), int, double, double);

#endif