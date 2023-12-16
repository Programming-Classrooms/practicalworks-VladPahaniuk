/*Написать программу, которая для заданного натурального числа:
4. добавляет в запись числа слева и справа центральную цифру,
если число содержит нечётное количество цифр и не изменяет
число в противном случае;*/


#include <iostream> 
using namespace std;


uint64_t my_pow(const int& x, const int& y) {
		uint64_t resalt = static_cast<uint64_t>(x);
		for (size_t i = 1; i < y; ++i) {
			resalt *= static_cast<uint64_t>(x);
		}
		return resalt;
	}
	
	
int main() {
	int64_t num = 0;
	while (num <= 0) {
		cout << "Enter num = ";
		cin >> num;
		cout << '\n';
	}
	int64_t num_of_numbers = 0;
	int64_t temp = num;
	while (temp != 0) {
		temp /= 10;
		num_of_numbers++;
	}
	cout << "num_of_numbers = " << num_of_numbers << '\n';
	if ((num_of_numbers % 2) != 0) {
		int64_t central_num = static_cast<int>(num / my_pow(10, num_of_numbers/2) % 10);
		cout << "central_num = " << central_num << '\n';
		int64_t result = central_num * pow(10, num_of_numbers + 1) + num * 10 + central_num;
		cout << "Result = " << result;
	}
	else {
		cout << "It's even";
	}
	return 0;
}
