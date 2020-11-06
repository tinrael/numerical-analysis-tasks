#include <iostream>
#include <cstddef>
#include <algorithm>
#include <cmath>

const std::size_t columns = 5;
const std::size_t rows = 4;

// argmax(|a[i][k]|), where i from k to columns
std::size_t getMaxRowIndex(double a[][columns], std::size_t k) {
    std::size_t maxRowIndex = k;

    for (std::size_t i = k + 1; i < rows; i++) {
        if (std::abs(a[i][k]) > std::abs(a[maxRowIndex][k])) {
            maxRowIndex = i;
        }
    }

    return maxRowIndex;
}

void swapMatrixRows(double a[][columns], std::size_t rowIndex1, std::size_t rowIndex2) {
    for (std::size_t j = 0; j < columns; j++) {
        std::swap(a[rowIndex1][j], a[rowIndex2][j]);
    }
}

void printMatrix(double a[][columns]) {
    for (std::size_t i = 0; i < rows; i++) {
        for (std::size_t j = 0; j < columns; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void printSolution(double x[]) {
    for (std::size_t i = 0; i < rows; i++) {
        std::cout << "x_{" << i + 1 << "} = " << x[i] << std::endl;
    }
}

void forwardGaussianElimination(double a[][columns]) {
    std::size_t maxRowIndex;
    for (std::size_t k = 0; k < rows; k++) {
        maxRowIndex = getMaxRowIndex(a, k);
        swapMatrixRows(a, k, maxRowIndex);

        for (std::size_t j = k + 1; j < columns; j++) {
            a[k][j] = a[k][j] / a[k][k];
        }

        a[k][k] = 1.0;

        for (std::size_t i = k + 1; i < rows; i++) {
            for (std::size_t j = k + 1; j < columns; j++) {
                a[i][j] = a[i][j] - a[i][k] * a[k][j];
            }

            a[i][k] = 0.0;
        }
    }
}

void backGaussianSubstitution(double a[][columns], double x[]) {
    for (int i = rows - 1; i >= 0; i--) {
        x[i] = a[i][columns - 1];

        for (std::size_t j = i + 1; j < columns - 1; j++) {
            x[i] = x[i] - a[i][j] * x[j];
        }
    }
}

// Gaussian Elimination with Partial Pivoting
void gaussianElimination(double a[][columns], double x[]) {
    forwardGaussianElimination(a);
    backGaussianSubstitution(a, x);
}

double manhattanNorm(double x[], std::size_t numOfElements) {
    double result = 0;

    for (std::size_t i = 0; i < numOfElements; i++) {
        result += std::abs(x[i]);
    }

    return result;
}

void jacobiMethod(double a[][columns], double x[], double eps) {
    double prev[rows];
    double difference[rows];

    std::size_t step = 0;

    do {
        for (std::size_t i = 0; i < rows; i++) {
            prev[i] = x[i];
        }

        for (std::size_t i = 0; i < rows; i++) {
            x[i] = a[i][columns - 1] / a[i][i];

            for (std::size_t j = 0; j < columns - 1; j++) {
                if (i != j) {
                    x[i] = x[i] - a[i][j] / a[i][i] * prev[j];
                }
            }
        }

        for (std::size_t i = 0; i < rows; i++) {
            difference[i] = x[i] - prev[i];
        }

        std::cout << "Step " << step << ": " << std::endl;
        printSolution(x);
        std::cout << std::endl;

        step++;
    } while (manhattanNorm(difference, rows) > eps);
}

int main()
{
    double a[rows][columns] = {
        {3.0, 1.0, -1.0, 2.0, 6.0},
        {-5.0, 1.0, 3.0, -4.0, -12.0},
        {2.0, 0.0, 1.0, -1.0, 1.0},
        {1.0, -5.0, 3.0, -3.0, 3.0}
    };

    double x[rows];

    std::cout << "******** Gaussian Elimination with Partial Pivoting *******" << std::endl;
    std::cout << "-- Initial Matrix ---" << std::endl;
    printMatrix(a);
    std::cout << std::endl << std::endl;

    gaussianElimination(a, x);

    std::cout << "--- After Forward Elimination ---" << std::endl;
    printMatrix(a);
    std::cout << std::endl << std::endl;

    std::cout << "--- Solution ---" << std::endl;
    printSolution(x);

    std::cout << "**********************************" << std::endl << std::endl;;

    double b[rows][columns] = {
        {2.0, 1.0, -1.0, 0.0, 1.0},
        {1.0, 3.0, 0.0, 1.0, -3.0},
        {-1.0, 0.0, 2.0, 1.0, -2.0},
        {0.0, 1.0, 1.0, 4.0, -5.0}
    };

    double t[rows] = {0.0};

    std::cout << "******** Jacobi method ********" << std::endl;
    std::cout << "-- Initial Matrix ---" << std::endl;
    printMatrix(b);
    std::cout << std::endl;

    jacobiMethod(b, t, 0.0001);

    return 0;
}
