#include <math.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include "../include/romberg.h"

void printVec(std::vector<double> v, int j) {
    for (int i = 0; i < j - 1; i++) {
        std::cout << v.at(i) << " ";
    }
    std::cout << v.at(j) << std::endl;
}

double romb(double (*f)(double), int steps, double epsilon, double a, double b) {
    // the length of each sub-interval
    double h = (b - a);
    // buffers to which approximations will be stored 
    // Romberg integration returns a triangular array of increasingly accurate estimates to the integral
    // for computational purposes we only need the last 2 rows.
    // R0 is the previous row, whereas R1 is the current row
    std::vector<double> R0, R1;
    R0 = std::vector<double> (steps, 0.0);
    R1 = std::vector<double> (steps, 0.0);
    // The first entry in the matrix is the trapezoidal approximation with n=1
    R0[0] = (1.0/2.0) * (f(a) + f(b));

    for (int j = 1; j < steps; j++) {
        // the length of each sub-interval is halved
        h /= 2.;

        // the approximation for R(j,0)
        double rj0 = 0;
        // from 1 to 2^(n-1)
        for (size_t i = 1; i <= (1 << (j - 1)); i++) 
            rj0 += f(a + (2*i-1)*h);
        R1[0] = 0.5*R0[0] + h*rj0;
        
        // R(j,i)
        double power;
        for (size_t i = 1; i <= j; i++) {
            power = pow(4, i);
            R1[i] = (power*R1[i-1] - R0[i-1]) / (power - 1);
        }

        printVec(R1, j);

        // check if the current best approximation R(j,j) is within some epsilon of R(j-1,j-1)
        if (fabs(R0[j-1] - R1[j]) <= epsilon) {
            return R1[j];
        }

        // swap the two rows
        R0.swap(R1);
    }

    // the final approximation (Error of O(2*steps))
    return R0[steps - 1];
}

double f(double x) {
    return exp(-(x*x));
}

int main(void) {
    double integral = romb(&f, 10, 0.00001, 0, 1);
}