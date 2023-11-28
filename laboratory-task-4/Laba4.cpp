#include<iostream>
#include<ctime>
#include<iomanip>
#include<Windows.h>
void getN_M(size_t& n, size_t& m) {
    while (n!= m ){
    std::cout << "Введите количесто строк: ";
    std::cin >> n;
    std::cout << "Введите количество столбцов: ";
    std::cin >> m;
    }
}
void mtrDefine(double**& mtr, const size_t n, const size_t m) {
    mtr = new double* [n];
    for (size_t i = 0; i < n; ++i) {
        mtr[i] = new double[m];
    }
}

void checkborder(double& leftborder, double& rightborder)
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

void input_mtr_your_own(double** mtr, const size_t n, const size_t m) {
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j) {
            std::cin >> mtr[i][j];
        }
    }
}
void fill_matrix_in_random(double** mtr, const size_t n, const size_t m, double& leftborder, double& rightborder) {
    srand(time(NULL));
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j) {
            mtr[i][j] = leftborder + rand() * (rightborder - leftborder) / RAND_MAX;
        }
    }
}
void output_mtr(double**& mtr, const size_t n, const size_t m) {
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j) {
            std::cout << std::setw(10) << mtr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
void get_user_input_type(double** mtr, const size_t n, const size_t m, double& leftborder, double& rightborder)
{
    std::int64_t condition = 0;

    std::cout << "Как хотите ввести 1 - руками, 2 - рандомом  ";
    std::cin >> condition;
    if (condition != 1 && condition != 2)
    {
        throw std::exception("Invalid choice.");
    }
    if (condition == 1)
    {
        input_mtr_your_own(mtr, n, m);
    }
    if (condition == 2)
    {
        checkborder(leftborder, rightborder);
        fill_matrix_in_random(mtr, n, m, leftborder, rightborder);

    }
    system("cls");
    output_mtr(mtr, n, m);
}
void find_row_with_min_element(double** mtr, const size_t n, const size_t m, size_t& minRow, double& minElement) {
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j) {
            if (mtr[i][j] < minElement) {
                minElement = mtr[i][j];
                minRow = i;

            }
        }
    }
}
void find_col_with_max_element(double** mtr, const size_t n, const size_t m, size_t& maxCol, double& maxElement) {
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < m; ++j) {
            if (mtr[i][j] > maxElement) {
                maxElement = mtr[i][j];
                maxCol = j;

            }
        }
    }
}
double scalar_proisved(double** mtr, const size_t n,
    size_t& maxCol, size_t& minRow, double& result_of_scalar_proizved) {

    for (size_t i = 0; i < n; i++)
    {
        result_of_scalar_proizved += mtr[minRow][i] * mtr[i][maxCol];

    }
    return  result_of_scalar_proizved;


}
double findMinK(double** mtr, const size_t n, const size_t m) {
    double minK = mtr[0][0]; 
    for (int j = 1; j < m; ++j) {
        if (mtr[0][j] > minK) {
            minK = mtr[0][j];
        }
    }


    //  Находим минимум из максимальных элементов в каждой строке матрицы
    for (int i = 1; i < n; ++i) {
        double maxInRow = mtr[i][0]; 

        // Обновляем minK, если текущий максимальный элемент меньше текущего значения minK
        for (int j = 1; j < m; ++j) {
            if (mtr[i][j] > maxInRow) {
                maxInRow = mtr[i][j];
            }
        }

        // Обновляем minK, если текущий максимальный элемент меньше текущего значения minK
        if (maxInRow < minK) {
            minK = maxInRow;
        }
    }

    return minK;
}

void delete_mtr(double** mtr, const size_t n) {
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
    double result_of_scalar_proizved = 0;
    size_t minRow = 0;
    size_t maxCol = 0;
    double minElement = 0;
    double maxElement = 0;
    try
    {
        getN_M(n, m);
        mtrDefine(mtr, n, m);
        get_user_input_type(mtr, n, m, leftborder, rightborder);
        find_row_with_min_element(mtr, n, m, minRow, minElement);
        find_col_with_max_element(mtr, n, m, maxCol, maxElement);
        std::cout << "Результат сколярного произведения равен:: " << scalar_proisved(mtr, n, maxCol, minRow, result_of_scalar_proizved) << std::endl;
        double result = findMinK(mtr, n, m);
        std::cout << "Наименьшее число K: " << result << std::endl;
    }
    catch (const std::exception e)
    {
        std::cout << "An exception occurred: " << e.what();
        delete_mtr(mtr, n);
    }
    return 0;
}
