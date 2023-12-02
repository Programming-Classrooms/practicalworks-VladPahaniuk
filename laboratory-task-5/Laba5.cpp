#define _USE_MATH_DEFINES
#include <iostream> 
#include <cmath> 
#include <functional> 
#include <iomanip> 
 /*Вариант 7 А, Д
 Вычислить значение определенного интеграла с аналитически заданной подынтегральной
функцией с заданной точностью eps
А) по формуле левых прямоугольников;
Б) по формуле правых прямоугольников;
В) по формуле средних прямоугольников;
Г) по формуле трапеций;
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
Номер задания равен вашему индивидуальному номеру. */

double firstFunction(double x) { 
	return (1 / (1 + sqrt(2*x)));
}

double secondFunction(double x) { 
	double e = M_E;
	
	return (pow(e,x)* sin(x));
}

double thirdFunction(double x) { 
	return (1 / (3 + 2 * cos(x)));
}

double leftIntegral(const std::function<double(double)>& f, double a, double b, double eps) { 
	uint64_t n = 8;
	double h = 0.0;
	double x = 0.0;
	double s1 = 0.0;
	double s2 = f(b) * (b - a);
	while (fabs(s1 - s2) >= eps) {
		s1 = s2;
		s2 = 0.0;
		n *= 2;
		h = (b - a) / n;
		for (int step = 1; step <= n; ++step) {
			x = a + (step - 1) * h;
			s2 += h * f(x);
		}
	}
	return s2;
}

double summIntegral(const std::function<double(double)>& f, uint64_t n, double a, double b) {  
	double h = (b - a) / n;
	double sumEven = 0;
	double sumUnEven = 0;
	for (uint64_t i = 1; i < n; ++i) {
		if ((i % 2) == 0) {
			sumEven += (2 * f(a + i * h));
		}
		else {
			sumUnEven += (4 * f(a + i * h));
		}
	}
	double result = h / 3 * ((sumEven)+(sumUnEven)+f(n * h));
	return result;
}




double simpsonMethod(const std::function<double(double)>& f, double a, double b, double eps) {
	uint64_t n = 4;
	double x = 0;
	double s1 = 0;
	double s2 = summIntegral(f, n, a, b);
	n *= 2;
	while (fabs(s2 - s1) > eps) {
		s1 = s2;
		s2 = summIntegral(f, n, a, b);
		n *= 2;
	}
	return s2;
}

void getAandB(double& a, double& b) {
	std::cout << "Enter a = ";
	std::cin >> a;
	std::cout << "Enter b = ";
	std::cin >> b;
	if (a > b)
		std::swap(a, b);
}
double getEps() {
	double eps = 0;
	while (eps <= 0) {
		std::cout << "Epsselont must be natural: ";
		std::cin >> eps;
	}
	return eps;
}




void main() {
		double a = 0;
		double b = 0;
		double (*func[3])(double) = { firstFunction, secondFunction, thirdFunction };
		for (size_t i = 0; i < 3; ++i) {
			getAandB(a, b);
			double Integral = leftIntegral(func[i], a, b, getEps());
			std::cout << std::setprecision(10) << Integral << '\n';
		}
}