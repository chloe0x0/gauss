#include <iostream>
#include <assert.h>

// Right Reimann Sum of f over [a, b] with N Reimann Boxes
double rrei(double (*f)(double), int N, double a, double b) {
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

// Left Reimann Sum of f over [a, b] with N Reimann Boxes
double lrei(double (*f)(double), int N, double a, double b) {
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

// Midpoint Rule approximation of f over [a, b] with N Reimann Boxes
double mrei(double (*f)(double), int N, double a, double b) {
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
    double integral = rrei(&f, 1000, 1, 5);
    std::cout << integral << std::endl;
    integral = lrei(&f, 100, 1, 5);
    std::cout << integral << std::endl;
    integral = mrei(&f, 100, 1, 5);
    std::cout << integral << std::endl;
}

