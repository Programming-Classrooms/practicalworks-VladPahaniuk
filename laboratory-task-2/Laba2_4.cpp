/*
Написать программу, которая для заданного натурального числа:
4. добавляет в запись числа слева и справа центральную цифру,
если число содержит нечётное количество цифр и не изменяет
число в противном случае;
*/


#include <iostream> 
using namespace std;

uint64_t myPow(const int& x, const int& y) 
{
		uint64_t resalt = static_cast<uint64_t>(x);
		for (size_t i = 0; i < y - 1; ++i) {
			resalt *= static_cast<uint64_t>(x);
		}
		return resalt;
}

int main() 
{
	int32_t num = 0;
	while (num <= 0) {
		cout << "Enter number = ";
		cin >> num;
		cout << '\n';
	}
	int32_t digitInNumber = 0;
	int32_t temp = num;
	while (temp != 0) {
		temp /= 10;
		digitInNumber++;
	}
	cout << "Number of digits in a number = " << digitInNumber << '\n';
	if ((digitInNumber % 2) != 0) {
		int32_t central_num = static_cast<int32_t>(num / myPow(10, digitInNumber/2) % 10);
		cout << "central_num = " << central_num << '\n';
		int32_t result = central_num * pow(10, digitInNumber + 1) + num * 10 + central_num;
		cout << "Result = " << result;
	}
	else {
		cout << "It's even\n";
	}
	return 0;
}
