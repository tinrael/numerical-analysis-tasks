#include "Matrix.h"

#include <iostream>

Matrix::Matrix(std::size_t rows, std::size_t columns) : rows(rows), columns(columns)
{
    a = new double*[rows];
    for (std::size_t i = 0; i < rows; i++) {
        a[i] = new double[columns];
    }

    for (std::size_t i = 0; i < rows; i++) {
        for (std::size_t j = 0; j < columns; j++) {
            a[i][j] = 0.0;
        }
    }
}

Matrix::~Matrix()
{
    for (std::size_t i = 0; i < rows; i++) {
        delete[] a[i];
    }

    delete[] a;
}

Matrix& Matrix::operator=(const Matrix& b) {
    if (this == &b) {
        return *this;
    }

    for (std::size_t i = 0; i < rows; i++) {
        for (std::size_t j = 0; j < columns; j++) {
            a[i][j] = b(i, j);
        }
    }

    return *this;
}

double& Matrix::operator()(std::size_t i, std::size_t j) const {
    if (i >= this->rows || j >= this->columns) {
        throw std::invalid_argument( "out-of-bounds" );
    }

    return a[i][j];
}

void Matrix::print() const {
    for (std::size_t i = 0; i < rows; i++) {
        for (std::size_t j = 0; j < columns; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
