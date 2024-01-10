/*
Вычислить значение определенного интеграла с аналитически заданной подынтегральной
функцией с заданной точностью eps
А) по формуле левых прямоугольников;
Д) по формуле Симпсона (параболических трапеций).*/


#define _USE_MATH_DEFINES
#include <iostream> 
#include <cmath> 
#include <functional> 
#include <iomanip> 

double functionFirst(double x) { 
  return (1 / (1 + sqrt(2*x)));
}

double functionThird(double x) { 
  return (1 / (3 + 2 * cos(x)));
}

double functionSecond(double x) { 
  double e = M_E;
  
  return (pow(e,x)* sin(x));
}

double leftRectangleMethod(const std::function<double(double)>& f, double firstValue, double secondValue, double eps) { // метод левых прямоугольников 
  uint32_t n = 8;
  double splitStep = 0.0, x = 0.0, squareFirst = 0.0, squareSecond = 0.0;
  splitStep = (secondValue - firstValue) / n;
  for (int step = 1; step <= n; ++step) {
    x = firstValue + (step - 1) * splitStep;
    squareSecond += splitStep * f(x);
  }
  while (fabs(squareFirst - squareSecond) >= eps) {
    squareFirst = squareSecond;
    squareSecond = 0.0;
    n *= 2;
    splitStep /= 2;
    for (int step = 1; step <= n; ++step) {
      x = firstValue + (step - 1) * splitStep;
      squareSecond += splitStep * f(x);
    }
  }
  return squareSecond;
}

double homerSimpsonSumm(const std::function<double(double)>& f, uint32_t n, double firstValue, double secondValue) {
  double splitStep = (secondValue - firstValue) / n;
  double result = f(firstValue) + f(secondValue);

  for (int i = 1; i < n; ++i) {
    if (i % 2 == 1) {
    double x = firstValue + i * splitStep;
    result += 4 * f(x);
    }
    else {
      if (i == n - 1) {
        double x = firstValue + i * splitStep;
        result += f(x);
      }
      else {
        double x = firstValue + i * splitStep;
        result += 2 * f(x);
      }
    }
  }
  return splitStep / 3.0 * result;
}

double homerSimpsonMethod(const std::function<double(double)>& f, double firstValue, double secondValue, double eps) {
  uint64_t n = 4;
  double x = 0;
  double squareFirst = 0;
  double squareSecond = homerSimpsonSumm(f, n, firstValue, secondValue);
  n *= 2;
  while (fabs(squareSecond - squareFirst) > eps) {
    squareFirst = squareSecond;
    squareSecond = homerSimpsonSumm(f, n, firstValue, secondValue);
    n *= 2;
  }
  return squareSecond;
}

void getInterval(double& firstValue, double& secondValue) {
  std::cout << "Enter first value = ";
  std::cin >> firstValue;
  std::cout << "Enter second value = ";
  std::cin >> secondValue;
  if (firstValue > secondValue)
    std::swap(firstValue, secondValue);
}

double getEps() {
  double eps = 0;
  std::cout << "Enter eps\n";
  std::cin >> eps;
  while (eps <= 0) {
    throw std::out_of_range("A negative number has been entered.");
  }
  return eps;
}

int main() {
  try
  {
    double firstValue = 0;
    double secondValue = 0;
    double (*func[3])(double) = { functionFirst, functionSecond, functionThird };
    for (size_t i = 0; i < 3; ++i) {
      getInterval(firstValue, secondValue);
      double getEpss = getEps();
      std::cout << "leftRectangleMethod:" << std::setprecision(10) << leftRectangleMethod(func[i], firstValue, secondValue, getEpss);
      std::cout << "simpsonMethod:" << std::setprecision(10) << homerSimpsonMethod(func[i], firstValue, secondValue, getEpss);
    }
  }catch (const std::exception& e) {
  std::cerr << "Exception: " << e.what() << std::endl;
  }
  return 0;
}

