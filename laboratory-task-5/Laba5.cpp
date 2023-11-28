#define _USE_MATH_DEFINES
#include <iostream> 
#include <cmath> 
#include <functional> 
#include <iomanip> 

double root(double x) { // первая подинтегральная функция 
	return (1 / (1 + sqrt(2*x)));
}

double eps_in_step(double x) { // вторая подинтегральная функция 
	double e = M_E;
	
	return (pow(e,x)* sin(x));
}

double integ_cos(double x) { // третяя подинтегральная функция 
	return (1 / (3 + 2 * cos(x)));
}

double leftIntegral(const std::function<double(double)>& f, double a, double b, double eps) { // метод левых прямоугольников 
	uint64_t n = 8;
	double h = 0.0;
	double x = 0.0;
	double s1 = 0.0;
	double s2 = f(b) * (b - a);
	while (fabs(s1 - s2) >= eps) {
		s1 = s2;
		s2 = 0.0;
		n *= 2;
		h = (b - a) / n;// значение шага	
		for (int step = 1; step <= n; ++step) {
			x = a + (step - 1) * h;
			s2 += h * f(x);
		}
	}
	return s2;
}

double summIntegral(const std::function<double(double)>& f, uint64_t n, double a, double b) { // вычисление интеграла по методу Симпсона 
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




int main() {
		double a = 0;
		double b = 0;
		double (*func[3])(double) = { root, eps_in_step, integ_cos };
		for (size_t i = 0; i < 3; ++i) {
			getAandB(a, b);
			double Integral = leftIntegral(func[i], a, b, getEps());
			std::cout << std::setprecision(10) << Integral << '\n';
		}
        return 0;
}