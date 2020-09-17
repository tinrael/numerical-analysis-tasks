#include <iostream>
#include <cmath>
#include <cstddef>

double f(double x) {
    return (x * x * x * x + 2.0 * x - 1.0); // x^4 + 2x - 1
}

// derivative of f(x) = x^4 + 2x - 1
double df(double x) {
    return (4.0 * x * x * x + 2.0); // 4x^3 + 2
}

void modifiedNewtonMethod(double initialValue, double eps) {
    std::cout << "n = 0: " << std::endl;
    std::cout << "\tx_{0} = " << initialValue << std::endl;
    std::cout << "\tf(x_{0}) = " << f(initialValue) << std::endl;

    double derivativeAtInitialPoint = df(initialValue);

    double previousValue = initialValue; // x_{n-1}
    double currentValue = previousValue - f(previousValue) / derivativeAtInitialPoint; // x_{n}
    std::size_t n = 1;

    std::cout << "n = " << n << ": " << std::endl;
    std::cout << "\tx_{" << n << "} = " << currentValue << std::endl;
    std::cout << "\tf(x_{" << n << "}) = " << f(currentValue) << std::endl;

    while(std::fabs(currentValue - previousValue) >= eps) {
        previousValue = currentValue;
        currentValue = previousValue - f(previousValue) / derivativeAtInitialPoint;
        n++;

        std::cout << "n = " << n << ": " << std::endl;
        std::cout << "\tx_{" << n << "} = " << currentValue << std::endl;
        std::cout << "\tf(x_{" << n << "}) = " << f(currentValue) << std::endl;
    }
}

double phi(double x) {
    return ((1.0 - x * x * x * x) / 2.0); // (1 - x^4) / 2
}

void fixedPointIteration(double initialValue, double eps) {
    std::cout << "n = 0: " << std::endl;
    std::cout << "\tx_{0} = " << initialValue << std::endl;

    double previousValue = initialValue; // x_{n-1}
    double currentValue = phi(initialValue); // x_{n}
    std::size_t n = 1;

    std::cout << "n = " << n << ": " << std::endl;
    std::cout << "\tx_{" << n << "} = " << currentValue << std::endl;
    std::cout << "\tx_{" << n - 1 << "} - x_{" << n << "} = " << previousValue - currentValue << std::endl;

    while(std::fabs(currentValue - previousValue) >= eps) {
        previousValue = currentValue;
        currentValue = phi(previousValue);
        n++;

        std::cout << "n = " << n << ": " << std::endl;
        std::cout << "\tx_{" << n << "} = " << currentValue << std::endl;
        std::cout << "\tx_{" << n - 1 << "} - x_{" << n << "} = " << previousValue - currentValue << std::endl;
    }
}

int main()
{
    const double eps = 0.0001;
    const double initialValue = 0.5;

    std::cout << "Fixed-point iteration: " << std::endl;
    fixedPointIteration(initialValue, eps);

    std::cout << std::endl;

    std::cout << "Modified Newton method: " << std::endl;
    modifiedNewtonMethod(initialValue, eps);

    return 0;
}
