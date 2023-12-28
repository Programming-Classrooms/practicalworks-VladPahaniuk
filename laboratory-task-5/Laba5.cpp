/*
Вычислить значение определенного интеграла с аналитически заданной подынтегральной
функцией с заданной точностью eps
Вариант 7
А) по формуле левых прямоугольников;
Д) по формуле Симпсона (параболических трапеций).
Формула средних прямоугольников:
b
∫f(x)dx ≈ h*[f(x 1 )+ f(x 2 )+…+ f(x n )], где h=(b-a)/n, f(x i )=a+i*h-h/2,
a
где n–число точек деления отрезка [a, b]. Для вычисления первого приближения можно взять
n=4. Чтобы оценить точность, с которой вычислено значение интеграла, необходимо найти второе
приближение. Для этого можно увеличить n в два раза. Если s 1 и s 2 – два соседних приближения и |s 1
– s 2 |&lt;eps, то точность считается достигнутой и s 2 принимается за искомое значение интеграла. В
противном случае надо положить s 1 = s 2 и удвоить число точек деления отрезка [a, b]. После этого
вычисляется новое значение s 2 . Процесс удвоения n и вычисления s 2 надо продолжать до тех пор,
пока модуль разности s 1 и s 2 не станет меньше eps. Остальные формулы посмотреть самим.
Разработать функции, реализующие методы вычислений интеграла, входными параметрами
которых должны быть функция для вычисления значения подынтегрального выражения, пределы
интегрирования и точность вычислений. Головная программа должна вывести результат вычислений
для записанных в задании интегралов по заданным формулам и значение n, при котором достигнута
заданная точность. Для проверки вычислений в таблице приведены значения интегралов.
*/


#define _USE_MATH_DEFINES
#include <iostream> 
#include <cmath> 
#include <functional> 
#include <iomanip> 

// первая подинтегральная функция 
double functionFirst(double x) 
{ 
  return (1 / (1 + sqrt(2*x)));
}

// вторая подинтегральная функция 
double functionSecond(double x) 
{ 
  double e = M_E;
  return (pow(e,x)* sin(x));
}

// третяя подинтегральная функция 
double functionThird(double x) 
{ 
  return (1 / (3 + 2 * cos(x)));
}

// метод левых прямоугольников 
double leftRectangleMethod(const std::function<double(double)>& f, double firstValue, double secondValue, double eps) 
{ 
  uint32_t n = 8;
  double splitStep = 0.0, x = 0.0, squareFirst = 0.0, squareSecond = 0.0;
  splitStep = (secondValue - firstValue) / n;// значение шага  
  for (size_t step = 1; step <= n; ++step) {
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

// вычисление интеграла по методу Симпсона 
double homerSimpsonSumm(const std::function<double(double)>& f, uint32_t n, double firstValue, double secondValue)
{ 
  double splitStep = (secondValue - firstValue) / n;
  double result = f(firstValue) + f(secondValue);
  for (int i = 1; i < n; i += 2) {
    double x = firstValue + i * splitStep;
    result += 4 * f(x);
  }
  for (int i = 2; i < n - 1; i += 2) {
    double x = firstValue + i * splitStep;
    result += 2 * f(x);
  }
  return splitStep / 3.0 * result;
}

double homerSimpsonMethod(const std::function<double(double)>& f, double firstValue, double secondValue, double eps)
{
  uint64_t n = 4;
  double x = 0;
  double squareFirst = 0;
  double squareSecond = homerSimpsonSumm(f, n, firstValue, secondValue);
  n *= 2;
  while (fabs(squareSecond - squareFirst) >= eps) {
    squareFirst = squareSecond;
    squareSecond = homerSimpsonSumm(f, n, firstValue, secondValue);
    n *= 2;
  }
  return squareSecond;
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

double getEps()
{
  double eps = 0;
  std::cout << "Enter eps\n";
  std::cin >> eps;
  while (eps <= 1) {
    throw std::out_of_range("Invalid input.");
  }
  return eps;
}

int main()
{
  try{
    double firstValue = 0;
    double secondValue = 0;
    double (*func[3])(double) = { functionFirst, functionSecond, functionThird };
    for (size_t i = 0; i < 3; ++i) {
      getInterval(firstValue, secondValue);
      double getEpss = getEps();
      double integral = leftRectangleMethod(func[i], firstValue, secondValue, getEpss);
      double integralSecond = homerSimpsonMethod(func[i], firstValue, secondValue, getEpss);
      std::cout<<"leftRectangleMethod:" << std::setprecision(10) << integral << '\n';
      std::cout << "simpsonMethod:" << std::setprecision(10) << integralSecond << '\n';

    }
  }
  catch (const std::exception& e) {
  std::cerr << "Exception: " << e.what() << std::endl;
  }
  return 0;
}
