#include "Matrix.h"

#include <iostream>
#include <cmath>

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

Matrix::Matrix(const Matrix& b) : rows(b.rows), columns(b.columns)
{
    a = new double*[rows];
    for (std::size_t i = 0; i < rows; i++) {
        a[i] = new double[columns];
    }

    for (std::size_t i = 0; i < rows; i++) {
        for (std::size_t j = 0; j < columns; j++) {
            a[i][j] = b(i, j);
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

    if (this->rows != b.rows || this->columns != b.columns) {
        throw std::invalid_argument( "Matrices are not the same size." );
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

Matrix Matrix::operator*(const Matrix& rhs) const {
    if (columns != rhs.rows) {
        throw std::invalid_argument( "The number of columns in the first matrix must be equal to the number of rows in the second matrix." );
    }

    Matrix result(rows, rhs.columns);

    for (std::size_t i = 0; i < result.rows; i++) {
        for (std::size_t j = 0; j < result.columns; j++) {
            for (std::size_t r = 0; r < columns; r++) {
                result(i, j) += a[i][r] * rhs(r, j);
            }
        }
    }

    return result;
}

Matrix Matrix::operator-(const Matrix& rhs) const {
    if (rows != rhs.rows || columns != rhs.columns) {
        throw std::invalid_argument( "Two matrices must have an equal number of rows and columns to be subtracted." );
    }

    Matrix result(rows, columns);

    for (std::size_t i = 0; i < result.rows; i++) {
        for (std::size_t j = 0; j < result.columns; j++) {
            result(i, j) = a[i][j] - rhs(i, j);
        }
    }

    return result;
}

Matrix Matrix::transpose() const {
    Matrix result(columns, rows);

    for (std::size_t i = 0; i < rows; i++) {
        for (std::size_t j = 0; j < columns; j++) {
            result(j, i) = a[i][j];
        }
    }

    return result;
}

void Matrix::print() const {
    for (std::size_t i = 0; i < rows; i++) {
        for (std::size_t j = 0; j < columns; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

std::size_t Matrix::getRows() const {
    return rows;
}

std::size_t Matrix::getColumns() const {
    return columns;
}

double Matrix::calculateManhattanNorm(Matrix v) {
    if (v.rows != 1 && v.columns != 1) {
        throw std::invalid_argument( "The argument is not a vector." );
    }

    double result = 0;

    if (v.columns == 1) {
        for (std::size_t i = 0; i < v.rows; i++) {
            result += std::abs(v(i, 0));
        }
    } else {
        for (std::size_t i = 0; i < v.columns; i++) {
            result += std::abs(v(0, i));
        }
    }

    return result;
}

Matrix operator*(double lhs, const Matrix& rhs) {
    Matrix result(rhs.rows, rhs.columns);

    for (std::size_t i = 0; i < result.rows; i++) {
        for (std::size_t j = 0; j < result.columns; j++) {
            result(i, j) = lhs * rhs(i, j);
        }
    }

    return result;
}
