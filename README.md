# gauss
Numerical Integration algorithms implemented in C++

Currently for functions of x. (may add support for higher dimensional functions later)

# TODO
CUMTRAPZ, Simpsons Rule (1/3, 3/8), Quadratures, Reimann Sums, Romberg Method.

## TRAPZ
The Trapezoidal rule approximates the definite integral of a function f over an interval [a, b] by summing up the areas of N evenly spaced trapezoids.

Symbolically it is given as:

$$\int_a^bf(x)dx \approx \frac{b-a}{2N} \sum_{n=1}^{N}[f(x_n)+f(x_{n+1})]$$

$$= \frac{b-a}{2N}[f(x_1) + 2f(x_2) + ... + 2f(x_{N-1}) + f(x_{N})]$$

where $x_1 = a < x_2 < x_3 < ... < x_{N-1} < x_{N} = b$
and the spacing between them is $\frac{(b - a)}{N}$

if the spacing between the trapezoids is not a constant the rule is generalized as:
$$\int_a^bf(x)dx \approx \frac{1}{2} \sum_{n=1}^{N}(x_{n+1} - x_n)[f(x_n)+f(x_{n+1})]$$

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
    std:cout << integral << std::endl;
}
```
