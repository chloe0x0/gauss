#ifndef RIEMANN_H
#define RIEMANN_H

// Riemann Sum approximations to definite integrals

// Left Riemann Sum 
double lrie(double (*f)(double), int, double, double);
// Right Riemann Sum 
double rrie(double (*f)(double), int, double, double);
// Midpoint Rule (Middle Riemann Sum)
double mrie(double (*f)(double), int, double, double);

#endif