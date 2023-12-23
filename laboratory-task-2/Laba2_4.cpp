/*
Написать программу, которая для заданного натурального числа:
4. добавляет в запись числа слева и справа центральную цифру,
если число содержит нечётное количество цифр и не изменяет
число в противном случае;
*/


#include <iostream> 
using namespace std;

uint64_t myPow(const int& x, const int& y) {
		uint64_t resalt = static_cast<uint64_t>(x);
		for (size_t i = 1; i < y; ++i) {
			resalt *= static_cast<uint64_t>(x);
		}
		return resalt;
	}

int main() 
{
	int64_t num = 0;
	while (num <= 0) {
		cout << "Enter number = ";
		cin >> num;
		cout << '\n';
	}
	int64_t digitInNumber = 0;
	int64_t temp = num;
	while (temp != 0) {
		temp /= 10;
		digitInNumber++;
	}
	cout << "Number of digits in a number = " << digitInNumber << '\n';
	if ((digitInNumber % 2) != 0) {
		int64_t central_num = static_cast<int>(num / myPow(10, digitInNumber/2) % 10);
		cout << "central_num = " << central_num << '\n';
		int64_t result = central_num * pow(10, digitInNumber + 1) + num * 10 + central_num;
		cout << "Result = " << result;
	}
	else {
		cout << "It's even";
	}
	return 0;
}
