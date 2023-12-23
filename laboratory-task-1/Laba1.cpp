/*Задания к лабораторной работе №1 :
Разработать консольное приложение для вычисления приближённого значения функции,
используя представление ее в виде ряда Тейлора.
Вычисления заканчивать, когда очередное слагаемое окажется по модулю меньше заданного числа 𝑒𝑝𝑠𝑖𝑙𝑜𝑛,
 где 0 < 𝑒𝑝𝑠𝑖𝑙𝑜𝑛 < 10^-𝑘, 𝑘 – натуральное число, 𝑘 >1. Сравнить полученный результат со значением, вычисленным с помощью стандартных функций.
Значение 𝑥 и 𝑘 ввести по запросу.
𝑒^-x = 1 - x / 1!+ x ^ 2 / 2!...
*/


#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

double calculation(int32_t x, int32_t k)
{
  int32_t i = 1;
  double sum = 1.0, temp;
  int32_t eps = pow(10, -k);
  temp = -x;
  while (fabs(temp) > eps){
          sum += temp;
          temp = -temp * x / (i + 1);
          i++;
  }
  return sum;
}

int main()
{
  try{
      int32_t k;
      double x;
      cout << "Input X:\n";
      cin >> x;
      cout << "Input K:\n";
      cin >> k;
      if (k < 1){
          throw std::exception("k must be a natural number\n");
      }
      double summ = calculation(x, k);
      cout << "e^-x " << exp(-x) << "\tsum= " << summ;
  }
  catch (const std::exception &e){
          std::cerr << "Exception: " << e.what() << std::endl;
  }
  return 0;
}
