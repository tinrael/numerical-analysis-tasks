#include "Matrix.h"
#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

void powerIteration(const Matrix& A, double eps) {
    Matrix x(A.getRows(), 1);

    for (std::size_t i = 0; i < x.getRows(); i++) {
        x(i, 0) = 1.0;
    }

    Matrix e(A.getRows(), 1);

    e = (1.0 / Matrix::calculateManhattanNorm(x)) * x;
    x = A * e;
    double u_cur = (x.transpose() * e)(0, 0) / (e.transpose() * e)(0, 0);

    double u_prev;

    do {
        e = (1.0 / Matrix::calculateManhattanNorm(x)) * x;
        x = A * e;
        u_prev = u_cur;
        u_cur = (x.transpose() * e)(0, 0) / (e.transpose() * e)(0, 0);
    } while (std::abs(u_cur - u_prev) >= eps);

    cout << "The greatest (in absolute value) eigenvalue: " << u_cur << endl;

    cout << "The corresponding eigenvector: " << endl;
    e.print();
}

int main()
{
    double eps = 0.0001;

    Matrix A(5, 5);
    A(0, 0) = 6.18;
    A(0, 1) = 1.12;
    A(0, 2) = 0.95;
    A(0, 3) = 1.32;
    A(0, 4) = 0.83;

    A(1, 0) = 1.12;
    A(1, 1) = 3.28;
    A(1, 2) = 2.12;
    A(1, 3) = 0.57;
    A(1, 4) = 0.91;

    A(2, 0) = 0.95;
    A(2, 1) = 2.12;
    A(2, 2) = 7.13;
    A(2, 3) = 1.29;
    A(2, 4) = 1.57;

    A(3, 0) = 1.32;
    A(3, 1) = 0.57;
    A(3, 2) = 1.29;
    A(3, 3) = 3.57;
    A(3, 4) = 1.25;

    A(4, 0) = 0.83;
    A(4, 1) = 0.91;
    A(4, 2) = 1.57;
    A(4, 3) = 1.25;
    A(4, 4) = 6.21;

    A.print();

    cout << " ---- ---- ---- ---- ---- " << endl;

    powerIteration(A, eps);

    return 0;
}
