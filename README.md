# gauss
Numerical Integration algorithms implemented in C++

Currently for functions of x. (may add support for higher dimensional functions later)

## Motivation
Why would one wish to numerically compute an integral? 

* Some integrals cannot be expressed in terms of elementary functions.

* It would be very difficult to write a program to attempt to integrate like a human does

* Related to the above reason, it is generally faster to numerically solve integrals (for a computer)

### An example

consider the integral 
$$\int_{-ln(2)}^{ln(2)}\frac{sin(x + x)^\frac{1}{3}}{e^x}dx$$

this integrand is unlikely to have a closed form solution for its anti-derivative, let alone a convinient one. 

Lets use a trapezoidal approximation from gauss to see what this integral is.

First we will need to define the integrand as a C++ function which takes a double, x, and returns a double

There is a catch, however, if we implement it as 

```C++
#include <cmath>

double f(double x) {
    return std::pow(sin(x + x), 1.0/3.0) / exp(x);
}
```

the approximation will fail. Upon further inspection you will notice that for negative arguments the function returns nan. This is because sin(x + x) will be negative. std::pow() returns NaN when the base is negative and the exponent is not an integer. 

To get around this we can just take the cube root of sin(x + x)

and the implementation is then 

```C++
#include <cmath>

double f(double x) {
    return cbrt(sin(x + x)) / exp(x);
}
```

For an approximation using gauss

```C++
#include <TRAPZ.h>

// f is assumed to be already defined elsewhere as the above function

int main(void) {
    double integral = TRAPZ(&f, 25, -log(2.0), log(2.0));
    std::cout << integral << std::endl;
}
```

the integral is then approximately -0.46573.

# TODO
CUMTRAPZ, Simpsons Rule (1/3, 3/8), Quadratures, Reimann Sums, Romberg Method.

## TRAPZ
The Trapezoidal rule approximates the definite integral of a function f over an interval [a, b] by summing up the areas of N trapezoids.

Symbolically it is given as:

$$\int_a^bf(x)dx \approx \frac{b-a}{2N} \sum_{n=1}^{N}[f(x_n)+f(x_{n+1})]$$

$$= \frac{b-a}{2N}[f(x_1) + 2f(x_2) + ... + 2f(x_{N-1}) + f(x_{N})]$$

where $x_1 = a < x_2 < x_3 < ... < x_{N-1} < x_{N} = b$
and the spacing between them is $\frac{(b - a)}{N}$

if the spacing between the trapezoids is not a constant the rule is generalized as:
$$\int_a^bf(x)dx \approx \frac{1}{2} \sum_{n=1}^{N}(x_{n+1} - x_n)[f(x_n)+f(x_{n+1})]$$

the C++ implementation uses a constant spacing of $\frac{(b - a)}{N}$

this may be changed later.

### Using TRAPZ.cpp
```cpp
#include <iostream>
#include <TRAPZ.h>

// Integrate x^2 from 1 to 5 (exact result is 41 * 1/3)
double f(x) {
    return x*x;
}

int main(void) {
    // Trapezoidal approximation using 8 trapezoids
    double integral = TRAPZ(&f, 8, 1, 5);
    std::cout << integral << std::endl;
}
```
