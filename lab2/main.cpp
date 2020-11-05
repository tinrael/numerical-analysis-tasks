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
