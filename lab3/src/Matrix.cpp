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
