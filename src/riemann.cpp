#include <iostream>
#include <assert.h>

// Right Riemann Sum of f over [a, b] with N Riemann Boxes
double rrie(double (*f)(double), int N, double a, double b) {
    assert(b > a);

    double integral, interval;
    integral = 0.0;
    interval = (b - a) / (double)N;

    for (int i = 0; i < N; i++) {
        integral += f(a + interval*i);
    }

    integral += f(b);

    integral *= interval;

    return integral;
}

// Left Riemann Sum of f over [a, b] with N Riemann Boxes
double lrie(double (*f)(double), int N, double a, double b) {
    assert(b > a);

    double integral, interval;
    integral = 0.0;
    interval = (b - a) / (double)N;

    for (int i = 0; i < N; i++) {
        integral += f(a + interval*i);
    }

    integral += f(b - interval);

    integral *= interval;

    return integral;
}

// Midpoint Rule approximation of f over [a, b] with N Riemann Boxes
double mrie(double (*f)(double), int N, double a, double b) {
    assert(b > a);

    double integral, interval;
    integral = 0.0;
    interval = (b - a) / (double)N;

    for (int i = 1; i < N; i++) {
        integral += f(a + (i - 0.5)*interval);
    }

    integral += f(b - (interval/2.0));

    integral *= interval;

    return integral;
}



double f(double x) {
    return x*x;
}

int main(void) {
    double integral = rrie(&f, 1000, 1, 5);
    std::cout << integral << std::endl;
    integral = lrie(&f, 100, 1, 5);
    std::cout << integral << std::endl;
    integral = mrie(&f, 100, 1, 5);
    std::cout << integral << std::endl;
}

