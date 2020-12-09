#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>

class Matrix
{
    public:
        Matrix(std::size_t rows, std::size_t columns);
        virtual ~Matrix();

        Matrix& operator=(const Matrix& b);
        double& operator()(std::size_t i, std::size_t j) const;

        void print() const;

        std::size_t getRows() const;
        std::size_t getColumns() const;

    protected:

    private:
        std::size_t rows;
        std::size_t columns;
        double** a;
};

#endif // MATRIX_H
