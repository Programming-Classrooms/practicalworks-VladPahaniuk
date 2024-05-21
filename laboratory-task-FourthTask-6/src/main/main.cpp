#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <exception>

// Функция для заполнения матрицы случайными значениями
void fillMatrix(std::vector<std::vector<double>> &matrix, double minVal, double maxVal)
{
    srand(time(nullptr));
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            matrix[i][j] = (maxVal - minVal) * ((double)rand() / RAND_MAX) + minVal;
        }
    }
}

// Функция для нахождения индексов максимального элемента матрицы
std::pair<size_t, size_t> findMaxElementIndex(const std::vector<std::vector<double>> &matrix)
{
    double maxElement = matrix[0][0];
    std::pair<size_t, size_t> maxIndex = {0, 0};
    for (size_t i = 0; i < matrix.size(); i++)
    {
        for (size_t j = 0; j < matrix[i].size(); j++)
        {
            if (matrix[i][j] > maxElement)
            {
                maxElement = matrix[i][j];
                maxIndex = {i, j};
            }
        }
    }
    return maxIndex;
}
 // Функция для вывода матрицы
void printMtr(std::vector<std::vector<double>> &matrix){
    for (const auto &row : matrix)
        {
            for (double elem : row)
            {
                std::cout << elem << '\t';
            }
            std::cout << '\n';
        }

}
// Функция для удаления строки и столбца по индексам
void deleteRowAndCol(std::vector<std::vector<double>> &matrix, size_t row, size_t col)
{
    matrix.erase(matrix.begin() + row);
    for (size_t i = 0; i < matrix.size(); i++)
    {
        matrix[i].erase(matrix[i].begin() + col);
    }
}

// Функция для суммирования элементов строки
double sumRow(const std::vector<double> &row)
{
    double sum = 0.0;
    for (double elem : row)
    {
        sum += elem;
    }
    return sum;
}

// Функция для упорядочивания строк матрицы по сумме элементов
void sortRowsBySum(std::vector<std::vector<double>> &matrix)
{
    for (size_t i = 0; i < matrix.size() - 1; i++)
    {
        for (size_t j = 0; j < matrix.size() - i - 1; j++)
        {
            if (sumRow(matrix[j]) > sumRow(matrix[j + 1]))
            {
                std::swap(matrix[j], matrix[j + 1]);
            }
        }
    }
}


int main()
{
    try
    {
        size_t numRows = 0, numCols = 0;
        double minVal = 0.0, maxVal = 0.0;
        std::cout << "Введите количество строк и столбцов матрицы: ";
        std::cin >> numRows >> numCols;

        if (numRows <= 0 || numCols <= 0)
        {
            throw std::invalid_argument("Nagative value!!!");
        }

        std::cout << "Введите минимальное и максимальное значение элементов матрицы: ";
        std::cin >> minVal >> maxVal;

         if (minVal > maxVal)
        {
            std::swap(minVal, maxVal);
        }

        std::vector<std::vector<double>> matrix(numRows, std::vector<double>(numCols));
        fillMatrix(matrix, minVal, maxVal);

        std::cout << "Исходная матрица:\n";
        printMtr(matrix);

        std::pair<size_t, size_t> maxIndex = findMaxElementIndex(matrix);
        deleteRowAndCol(matrix, maxIndex.first, maxIndex.second);

        std::cout << "\nМатрица после удаления строки и столбца:\n";
        printMtr(matrix);

        sortRowsBySum(matrix);

        std::cout << "\nОтсортированная матрица:\n";
        printMtr(matrix);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
