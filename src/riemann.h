#ifndef RIEMANN_H
#define RIEMANN_H

// Reimann Sum approximations to definite integrals

// Left Reimann Sum 
double lrie(double (*f)(double), int, double, double);
// Right Reimann Sum 
double rrie(double (*f)(double), int, double, double);
// Midpoint Rule (Middle Reimann Sum)
double mrie(double (*f)(double), int, double, double);

#endif