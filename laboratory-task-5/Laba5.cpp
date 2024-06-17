/*
Вычислить значение определенного интеграла с аналитически заданной подынтегральной
функцией с заданной точностью eps
А) по формуле левых прямоугольников;
Д) по формуле Симпсона (параболических трапеций).
*/


#define _USE_MATH_DEFINES
#include <iostream> 
#include <cmath> 
#include <functional> 
#include <iomanip> 

double functionFirst(double x)
{ 
  return (1 / (1 + sqrt(2*x)));
}

double functionThird(double x)
{ 
  return (1 / (3 + 2 * cos(x)));
}

double functionSecond(double x) { 
  double e = M_E;
  
  return (pow(e,x)* sin(x));
}

double getEps() 
{
  double eps = 0;
  std::cout << "Enter eps\n";
  std::cin >> eps;
  while (eps <= 0) {
    throw std::out_of_range("A negative number has been entered or 0.");
  }
  return eps;
}

void getInterval(double& firstValue, double& secondValue)
{
  std::cout << "Enter first value = ";
  std::cin >> firstValue;
  std::cout << "Enter second value = ";
  std::cin >> secondValue;
  if (firstValue > secondValue)
    std::swap(firstValue, secondValue);
}

double leftRectangleMethod(const std::function<double(double)>& f,double firstValue, double secondValue, double eps)
{
  uint32_t n = 8;
  double splitStep = 0.0, squareFirst = 0.0, squareSecond = 0.0;
  while (true) {
    squareSecond = squareFirst;
    squareFirst = 0.0;
    splitStep = (secondValue - firstValue) / n;
    for (size_t i = 0; i < n; i++) {
      double x = firstValue + i * splitStep;
      squareFirst += f(x);
    }
    squareFirst *= splitStep;
    n *= 2;
    if (std::fabs(squareFirst - squareSecond) <= eps) {
      break;
    }
  }
  return squareFirst;
}

double homerSimpsonMethod(const std::function<double(double)>& f, double firstValue, double secondValue, double eps)
{
  uint32_t n = 4;
  double squareFirst = 0.0, squareSecond = 0.0, splitStep = 0.0;
  while (true) {
    squareSecond = squareFirst;
    squareFirst = 0.0;
    splitStep = (secondValue - firstValue) / n;
    for (size_t i = 1; i < n; ++i) {
      if (i % 2 == 1) {
        double x = firstValue + i * splitStep;
        squareFirst += 4 * f(x);
      }
      else {
        if (i == n - 1) {
          double x = firstValue + i * splitStep;
          squareFirst += f(x);
        }
        else {
          double x = firstValue + i * splitStep;
          squareFirst += 2 * f(x);
        }
      }
    }
    squareFirst += f(firstValue) + f(secondValue);
    squareFirst *= splitStep / 3.0;
    if (std::fabs(squareFirst - squareSecond) <= eps) {
      break;
    }
    n *= 2;
  }
  return squareFirst;
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
      std::cout << "Intergtal of " << i + 1 << " leftRectangleMethod : " << leftRectangleMethod(func[i], firstValue, secondValue, getEpss) << std::endl;
      std::cout << "Intergtal of " << i + 1 << " homerSimpsonMethod : " << homerSimpsonMethod(func[i], firstValue, secondValue, getEpss) << std::endl;
    }
  }catch (const std::exception& e) {
  std::cerr << "Exception: " << e.what() << std::endl;
  }
  return 0;
}
