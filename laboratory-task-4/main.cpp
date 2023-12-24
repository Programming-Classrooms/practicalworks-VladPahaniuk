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
  std::string row, col;
  while (rows != cols) {
    std::cout << "Enter number of rows: ";
    std::cin >> row;
    rows = static_cast<size_t>(std::stoi(row));
    std::cout << "Enter number of cols: ";
    std::cin >> col;
    cols = static_cast<size_t>(std::stoi(col));
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
  for (size_t i = 0; i < rows; ++i){
    for (size_t j = 0; j < cols; ++j) {
      std::cin >> mtr[i][j];
    }
  }
}

double GenerateRandomValuesInInterval(double& leftborder, double& rightborder)
{
  double randomValue = leftborder + rand() * (rightborder - leftborder) / RAND_MAX;
  return randomValue;
}

void fillMtrInRandom(double** mtr, size_t rows, size_t cols, double& leftborder, double& rightborder)
 {
  for (size_t i = 0; i < rows; ++i){
    for (size_t j = 0; j < cols; ++j) {
      mtr[i][j] = GenerateRandomValuesInInterval(leftborder, rightborder);
    }
  }
}

void printMtr(double**& mtr, size_t rows, size_t cols) 
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j) {
      std::cout << std::setw(10) << mtr[i][j] << " ";
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

void fillingMtr(double** mtr, size_t rows, size_t cols, double& leftborder, double& rightborder)
{
  uint32_t choice = selectInputType();
  if (choice != 1 && choice != 2){
    throw std::exception("Invalid choice.");
  }
  if (choice == 1){
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

void findRowWithMinIndex(double** mtr, size_t rows, size_t cols, size_t& minRow, double& minElement)
 {
  for (size_t i = 0; i < rows; ++i) {
    for (size_t j = 0; j < cols; ++j) {
      if (mtr[i][j] < minElement) {
        minElement = mtr[i][j];
        minRow = i;
      }
    }
  }
}

void findColWithMaxIndex(double** mtr, size_t rows, size_t cols, size_t& maxCol, double& maxElement)
 {
  for (size_t i = 0; i < rows; ++i){
    for (size_t j = 0; j < cols; ++j) {
      if (mtr[i][j] > maxElement) {
        maxElement = mtr[i][j];
        maxCol = j;
      }
    }
  }
}

double scalarMultiplication(double** mtr, size_t rows,
  size_t& maxCol, size_t& minRow, double& resultOfScalarMultiplication)
{
  for (size_t i = 0; i < rows; i++){
    resultOfScalarMultiplication += mtr[minRow][i] * mtr[i][maxCol];
  }
  return  resultOfScalarMultiplication;
}

double findMinK(double** mtr, const size_t rows, const size_t cols)
{
  double minK = mtr[0][0];
  // Инициализация переменной minK значением первого элемента матрицы
  for (int j = 1; j < cols; ++j) {
    if (mtr[0][j] > minK) {
      minK = mtr[0][j];
    }
  }
  // Находим минимум из максимальных элементов в каждой строке матрицы
  for (int i = 1; i < rows; ++i) {
    double maxInRow = mtr[i][0]; // Инициализация переменной maxInRow значением первого элемента строки
    // Находим максимальный элемент в текущей строке
    for (int j = 1; j < cols; ++j) {
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

void deleteMtr(double** mtr, const size_t rows) 
{
  for (size_t i = 0; i < rows; i++){
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
  double resultOfScalarMultiplication = 0;
  size_t minRow = 0;
  size_t maxCol = 0;
  double minElement = 0;
  double maxElement = 0;
  try {
    getRowsAndColumns(rows, cols);
    mtrDefine(mtr, rows, cols);
    fillingMtr(mtr, rows, cols, leftborder, rightborder);
    findRowWithMinIndex(mtr, rows, cols, minRow, minElement);
    findColWithMaxIndex(mtr, rows, cols, maxCol, maxElement);
    std::cout << "The result of the dot product is: " << scalarMultiplication(mtr, rows, maxCol, minRow, resultOfScalarMultiplication) << std::endl;
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

