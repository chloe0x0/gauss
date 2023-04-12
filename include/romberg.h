#ifndef ROMB_H
#define ROMB_H

// Romberg Integration
//              f(x)            steps  epsilon  a       b
double romb(double (*f)(double), int, double, double, double);

#endif