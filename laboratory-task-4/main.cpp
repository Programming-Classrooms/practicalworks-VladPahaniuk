/*Вариант7.В квадратной матрице найти:
- скалярное произведение строки с наименьшим элементом матрицы и столбца с
наибольшим элементом;
- наименьшее целое число K, для которого хотя бы в одной строке матрицы все
элементы ее будут меньше этого числа.*/


#include <iostream>
#include <ctime>
#include <iomanip>
#include <Windows.h>
#include <string>

void getRowsAndColumns(size_t& rows, size_t& cols)
{
  while (rows != cols) {
    std::cout << "Enter number of rows: ";
    std::cin >> rows;
    std::cout << "Enter number of cols: ";
    std::cin >> cols;
  }
}

/*Пишу так как, я присваиваю значение не локальной mtr, а глобальной mtr(которая определена в main) */
void mtrDefine(double**& mtr, size_t rows, size_t cols)
{
  mtr = new double* [rows];
  for (size_t i = 0; i < rows; ++i) {
    mtr[i] = new double[cols];
  }
}

void inputBorder(double& leftborder, double& rightborder)
{
  std::cout << "Enter boundaries = ";
  std::cin >> leftborder;
  std::cin >> rightborder;
  if (leftborder > rightborder)
  {
    std::swap(leftborder, rightborder);
  }
}

void inputMtrFromKeyboard(double** mtr, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      std::cin >> mtr[i][j];
    }
  }
}

double generateRandomValuesInInterval(double& leftborder, double& rightborder)
{
  double randomValue = leftborder + rand() * (rightborder - leftborder) / RAND_MAX;
  return randomValue;
}

void fillMtrInRandom(double** mtr, size_t rows, size_t cols, double& leftborder, double& rightborder)
{
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      mtr[i][j] = generateRandomValuesInInterval(leftborder, rightborder);
    }
  }
}

void printMtr(double** mtr, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j) {
      std::cout << std::setw(10) << mtr[i][j];
    }
    std::cout << std::endl;
  }
}

double selectInputType()
{
  std::int32_t condition = 0;
  std::cout << "How you want to enter 1 - by hand, 2 - randomly";
  std::cin >> condition;
  return condition;
}

void fillMtr(double** mtr, size_t rows, size_t cols, double& leftborder, double& rightborder)
{
  uint32_t choice = selectInputType();
  if (choice != 1 && choice != 2) {
    throw std::exception("Invalid choice.");
  }
  if (choice == 1) {
    inputMtrFromKeyboard(mtr, rows, cols);
  }
  if (choice == 2)
  {
    inputBorder(leftborder, rightborder);
    fillMtrInRandom(mtr, rows, cols, leftborder, rightborder);
  }
  system("cls");
  printMtr(mtr, rows, cols);
}

size_t findRowWithMinIndex(double** mtr, size_t rows, size_t cols)
{
  size_t minRow = 0;
  double minElement = 0;
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      if (mtr[i][j] < minElement) {
        minElement = mtr[i][j];
        minRow = i;
      }
    }
  }
  return minRow;
}

size_t findColWithMaxIndex(double** mtr, size_t rows, size_t cols)
{
  size_t maxCol = 0;
  double maxElement = 0;
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      if (mtr[i][j] > maxElement) {
        maxElement = mtr[i][j];
        maxCol = j;
      }
    }
  }
  return maxCol;
}

double scalarMultiplication(double** mtr, size_t rows, size_t cols)
{
  double resultOfScalarMultiplication = 0;
  size_t minRows = findRowWithMinIndex(mtr, rows, cols);
  size_t maxCols = findColWithMaxIndex(mtr, rows, cols);
  for (size_t i = 0; i < rows; i++) {
    resultOfScalarMultiplication += mtr[minRows][i] * mtr[i][maxCols];
  }
  return  resultOfScalarMultiplication;
}
double findMinK(double** mtr, const size_t rows, const size_t cols)
{
  // Найти максимальный элемент в каждой строке и увеличить его на единицу
  double* maxElements = new double[rows];
  for (size_t i = 0; i < rows; ++i) {
    double maxInRow = mtr[i][0];
    for (int j = 0; j < cols; ++j) {
      if (mtr[i][j] > maxInRow) {
        maxInRow = mtr[i][j];
      }
    } 
    // Увеличиваем максимальный элемент на единицу
    maxElements[i] = (maxInRow + 1);
  }
  int32_t minK = maxElements[0];
  for (size_t i = 1; i < rows; ++i) {
    if (maxElements[i] < minK) {
      minK = maxElements[i];
    }
  }
  return minK;
}

void deleteMtr(double**& mtr, const size_t rows)
{
  for (size_t i = 0; i < rows; i++) {
    delete[] mtr[i];
  }
  delete[] mtr;
}

int main()
{
  srand(time(NULL));
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);
  double** mtr = nullptr;
  double rightborder = 0;
  double leftborder = 0;
  size_t rows = 1;
  size_t cols = 0;
  try {
    getRowsAndColumns(rows, cols);
    mtrDefine(mtr, rows, cols);
    fillMtr(mtr, rows, cols, leftborder, rightborder);
    std::cout << "The result of the dot product is: " << scalarMultiplication(mtr, rows, cols) << std::endl;
    double result = findMinK(mtr, rows, cols);
    std::cout << "Smallest number K: " << result << std::endl;
    deleteMtr(mtr, rows);
  }
  catch (const std::exception e) {
    std::cerr << "An exception occurred: " << e.what();
    deleteMtr(mtr, rows);
  }
  return 0;
}
