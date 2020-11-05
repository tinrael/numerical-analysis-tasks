#include <iostream>
#include <cstddef>

const std::size_t columns = 5;
const std::size_t rows = 4;

void printMatrix(double a[][columns]) {
    for (std::size_t i = 0; i < rows; i++) {
        for (std::size_t j = 0; j < columns; j++) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{


    double a[rows][columns] = {
        {3.0, 1.0, -1.0, 2.0, 6.0},
        {-5.0, 1.0, 3.0, -4.0, -12.0},
        {2.0, 0.0, 1.0, -1.0, 1.0},
        {1.0, -5.0, 3.0, -3.0, 3.0}
    };

    printMatrix(a);

    return 0;
}
