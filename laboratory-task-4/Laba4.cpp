#include<iostream>
#include<ctime>
#include<iomanip>
#include<Windows.h>
#include<string>


void getNandM(size_t& n, size_t& m) {
    std::string ns, ms;
    while (n != m) {
        std::cout << "Введите количество строк: ";
        std::cin >> ns;
        n = static_cast<size_t>(std::stoi(ns));
        std::cout << "Введите количество столбцов: ";
        std::cin >> ms;
        m = static_cast<size_t>(std::stoi(ms));

       
    }
}


void mtrDefine(double**& mtr, const size_t n, const size_t m) {
    mtr = new double* [n];
    for (size_t i = 0; i < n; ++i) {
        mtr[i] = new double[m];
    }
}

void checkBorder(double& leftborder, double& rightborder)
{
    std::cout << "Введите границы = ";
    std::cin >> leftborder >> rightborder;
    if (leftborder > rightborder)
    {
        std::swap(leftborder, rightborder);
    }
    if (leftborder == rightborder)
    {
        throw std::exception("Invalid choice.");

    }
}

void inputMtrYourOwn(double** mtr, const size_t n, const size_t m) {
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j) {
            std::cin >> mtr[i][j];
        }
    }
}
void fillMatrixInRandom(double** mtr, const size_t n, const size_t m, double leftborder, double rightborder) {
    srand(time(NULL));
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j) {
            mtr[i][j] = leftborder + rand() * (rightborder - leftborder) / RAND_MAX;
        }
    }
}
void outputMtr(double** mtr, const size_t n, const size_t m) {
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j) {
            std::cout << std::setw(10) << mtr[i][j];
        }
        std::cout << std::endl;
    }
}
void getUserInputType(double** mtr, const size_t n, const size_t m, double leftborder, double rightborder)
{
    std::int64_t condition = 0;

    std::cout << "Как хотите ввести 1 - руками 2 - рандомом  ";
    std::cin >> condition;
    if (condition != 1 && condition != 2)
    {
        throw std::exception("Invalid choice.");
    }
    if (condition == 1)
    {
        inputMtrYourOwn(mtr, n, m);
    }
    if (condition == 2)
    {
        checkBorder(leftborder, rightborder);
        fillMatrixInRandom(mtr, n, m, leftborder, rightborder);

    }
    system("cls");
    outputMtr(mtr, n, m);
}
size_t findRowWithMinElement(double** mtr, const size_t n, const size_t m) {
    size_t minRow = 0;
    double minElement = 0;
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j) {
            if (mtr[i][j] < minElement) {
                minElement = mtr[i][j];
                minRow = i;

            }
        }
    }
    return minRow;
}
size_t findColWithMaxElement(double** mtr, const size_t n, const size_t m) {
    size_t maxCol = 0;
    double maxElement = 0;
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j) {
            if (mtr[i][j] > maxElement) {
                maxElement = mtr[i][j];
                maxCol = j;

            }
        }
    }
    return maxCol;
}
double scalarMultiplication(double** mtr, const size_t n, size_t maxCol, size_t minRow) {
    double resultOfScalarProizved = 0;

    for (size_t i = 0; i < n; i++)
    {
        resultOfScalarProizved += mtr[minRow][i] * mtr[i][maxCol];

    }
    return  resultOfScalarProizved;


}
double FindMinK(double** mtr, const size_t n, const size_t m) {
    double minK = mtr[0][0]; 
    for (int j = 1; j < m; ++j) {
        if (mtr[0][j] > minK) {
            minK = mtr[0][j];
        }
    }

    for (int i = 1; i < n; ++i) {
        double maxInRow = mtr[i][0]; 

        
        for (int j = 1; j < m; ++j) {
            if (mtr[i][j] > maxInRow) {
                maxInRow = mtr[i][j];
            }
        }

        if (maxInRow < minK) {
            minK = maxInRow;
        }
    }

    return minK;
}

void deleteMtr(double**& mtr, const size_t n) {
    for (size_t i = 0; i < n; i++)
    {
        delete[] mtr[i];
    }
    delete[] mtr;
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double** mtr = nullptr;
    double rightborder = 0;
    double leftborder = 0;
    size_t n = 1;
    size_t m = 0;
    try
    {
        getNandM(n, m);
        mtrDefine(mtr, n, m);
        getUserInputType(mtr, n, m, leftborder, rightborder);
        size_t minRow = findRowWithMinElement(mtr, n, m);
        size_t maxCol = findColWithMaxElement(mtr, n, m);
        std::cout << "Результат скалярного произведения равен: " << scalarMultiplication(mtr, n, maxCol, minRow) << std::endl;
        double result = FindMinK(mtr, n, m);
        std::cout << "Наименьшее число K: " << result << std::endl;
    }
    catch (std::invalid_argument)
    {
        std::cout << "An exception occurred: ";
        deleteMtr(mtr, n);
    }
    return 0;
}
