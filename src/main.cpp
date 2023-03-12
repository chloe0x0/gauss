#include "gauss.h"
#include <iostream>

double f(double x) {
    return x*x;
}

int main(void) {
    double integral = trapz(&f, 25, 1, 5);
    std::cout << integral;
}