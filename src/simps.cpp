#include <iostream>
#include <assert.h>
#include "../include/simps.h"

#define EPSILON 1E-3

double simp13(double (*f)(double), int N, double a, double b) {
    assert(N % 2 == 0);

    double integral = f(a);
    double interval = (b - a) / N;

    for (int i = 1; i <= N-1; i++) {
        double x_i = a + i*interval;
        double coef = (i % 2 == 0)*2.0 + (i % 2 != 0)*4.0;
        integral += f(x_i) * coef;
    }
    
    integral += f(b);

    return integral * (interval / 3);
}

double simp38(double (*f)(double), int N, double a, double b) {
    assert(N % 2 == 0);

    double integral = f(a);
    double interval = (b - a) / N;

    for (int i = 1; i <= N; i++) {
        double x_i = a + i*interval;
        double coef = (i % 3 == 0) ? 2.0 : 3.0;
        integral += f(x_i) * coef;
    }

    integral += f(b);

    return integral * ((3.0*interval)/8.0);
}