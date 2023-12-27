/*
Условие лабораторной работы
Вариант 16
В массиве, состоящем из п вещественных элементов, вычислить:
произведение положительных элементов массива;
сумму элементов массива, расположенных до первого минимального элемента.
Упорядочить по возрастанию отдельно элементы с четными номерами и элементы с
нечетными номерами.
*/


#include <iostream>
#include <ctime>

size_t getSize()
{
  size_t sizeOfArr = 0;
  std::cout << "Number of elements:\n";
  while (sizeOfArr <= 0) {
    std::cin >> sizeOfArr;
    if (sizeOfArr <= 0) {
      std::cout << "Incorrect input";
      continue;
    }
    return sizeOfArr;
  }
}

void outArr(double* arr, const size_t& n)
{
  for (size_t i = 0; i < n; ++i) {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
}

double multiplication(double* arr, const size_t& n)
{
  double res = 1.0;
  size_t cnt = 0;
    for (size_t i = 0; i < n; ++i) {
      if (arr[i] > 0) {
        res *= arr[i];
        cnt++;
      }
    }
    if (cnt == 0) {
      throw "No positive numbers\n";
    }
  return res;
}

void inputArr(double* arr, const size_t& n)
{
  for (size_t i = 0; i < n; ++i)
    std::cin >> arr[i];
}

void inputFromKeyboard(double* arr, const size_t& n)
{
  std::cout << "Enter array\n";
  inputArr(arr, n);
}

void swap(double& a, double& b)
{
  double help = b;
  b = a;
  a = help;
}

void  checkBorder(double& x, double& y)
{
  while (x == y) {
    std::cout << "Enter board valuse = ";
    std::cin >> x >> y;
    if (x > y) {
      swap(x, y);
    }
  }
}

void inputRandom(double* arr, double& x, double& y, const size_t& n)
{
  srand(time(NULL));
  for (size_t i = 0; i < n; ++i) {
    arr[i] = x + rand() * (y - x) / RAND_MAX;
  }
}

void fillingArr(double* arr, double& x, double& y, const size_t& n) 
{
  char condition = 0;
  while (condition != '1' && condition != '2') {
    std::cout << "Enter codition 1 - input keyboard, 2 - random values = ";
    std::cin >> condition;
  }
  switch (condition) {
  case '1':
    inputFromKeyboard(arr, n);
    break;
  case '2':
    checkBorder(x, y);
    inputRandom(arr, x, y, n);
    std::cout << "Array generared " << '\n';
  }
  system("cls");
  outArr(arr, n);
}

void selectionSortEven(double* arr, const size_t& n)
{
    size_t i, j, minIdx;
    for (i = 0; i < n - 1; i+=2) {
        minIdx = i;
        for (j = i + 1; j < n; j+=2) {
            if (arr[j] < arr[minIdx]){
                minIdx = j;
            }
        }
        if (minIdx != i){
            swap(arr[minIdx], arr[i]);
        }
    }
}

void selectionSortOdd(double* arr, const size_t& n)
{
    int i, j, min_idx;
    for (i = 1; i < n - 1; i+=2) {
        min_idx = i;
        for (j = i + 1; j < n; j+=2) {
            if (arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        if (min_idx != i){
            swap(arr[min_idx], arr[i]);
        }
    }
}

size_t minIndex(double* arr, const size_t& n)
{
  double min;
  size_t minIndex = 0;
  min = arr[0];
  for (size_t i = 0; i < n; ++i) {
    if (min > arr[i]) {
      min = arr[i];
      minIndex = i;
    }
  }
  return minIndex;
}

double sumBeforeMin(double* arr, const size_t& n, size_t minIndex) 
{
  double sum = 0;
    if (arr[0] == arr[minIndex]) {
      throw "invalid\n";
    }
    for (size_t i = 0; i < minIndex; ++i) {
      sum += arr[i];
    }
  return sum;
}

int main()
 {
  size_t n = getSize();
  double res = 1.0;
  double x = 0;
  double y = 0;
  double* arr = new double[n];
  fillingArr(arr, x, y, n);
  size_t minInd = minIndex(arr, n);
  try {
    double mult = multiplication(arr, n);
    std::cout << "Mulyiplication = " << mult << '\n';
  }
  catch (const char* msg) {
    std::cout << msg;
  }
  try{
    double suma = sumBeforeMin(arr, n, minInd);
    std::cout << "Sum = " << suma << '\n';
  }
  catch (const char* msg) {
    std::cout << msg;
  }
  selectionSortEven(arr, n);
  selectionSortOdd(arr, n);
  std::cout << "Sort array\n";
  outArr(arr, n);
  delete[] arr;
  return 0;
}

