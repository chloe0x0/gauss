#ifndef REIMANN_H
#define REIMANN_H

// Reimann Sum approximations to definite integrals

// Left Reimann Sum 
double lrei(double (*f)(double), int, double, double);
// Right Reimann Sum 
double rrei(double (*f)(double), int, double, double);
// Midpoint Rule (Middle Reimann Sum)
double mrei(double (*f)(double), int, double, double);

#endif