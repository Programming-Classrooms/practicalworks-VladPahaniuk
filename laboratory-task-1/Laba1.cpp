#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;
void main() {
	setlocale(LC_ALL, "Ru");
	int64_t i = 1;
	int64_t k;
	double x, s = 1.0, p;
	cout << "Введите число Х:\n";
	cin >> x;
	cout << "Введите К:\n";
	cin >> k;
	p = -x;
	if (k > 1) {
		while (fabs(p) > pow(10, - k)) {
			s += p;
			p = - p * x / (i + 1);
			i++;
			}
			cout << "e^-x " << exp(-x) << "\ts= " << s;
			}
	else {
				cout << " Пожалуйста, введите К > 1";
	}

	
}