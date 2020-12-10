#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>

class Matrix
{
    public:
        Matrix(std::size_t rows, std::size_t columns);
        Matrix(const Matrix& b);
        virtual ~Matrix();

        Matrix& operator=(const Matrix& b);
        double& operator()(std::size_t i, std::size_t j) const;
        Matrix operator*(const Matrix& rhs) const;

        Matrix transpose() const;

        void print() const;

        std::size_t getRows() const;
        std::size_t getColumns() const;

        friend Matrix operator*(double lhs, const Matrix& rhs);

    protected:

    private:
        std::size_t rows;
        std::size_t columns;
        double** a;
};

#endif // MATRIX_H
