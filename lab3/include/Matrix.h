#ifndef MATRIX_H
#define MATRIX_H

#include <cstddef>

class Matrix
{
    public:
        Matrix(std::size_t rows, std::size_t columns);
        virtual ~Matrix();

        double& operator()(std::size_t i, std::size_t j);

        void print();

    protected:

    private:
        std::size_t rows;
        std::size_t columns;
        double** a;
};

#endif // MATRIX_H
