/*
Написать программу, которая для заданного натурального числа:
7. вычисляет Т пар близнецов.
*/


#include <iostream>

bool prime(const int64_t& n) 
{
	for (size_t i = 2; i < n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}

int main() 
{
	int64_t number = 0;
	int64_t primeDist = 0;
	int64_t numPair = 0;
	std::cout << "Enter T pair of bliznecov\n";
	std::cin >> number;
	while (number <= 0) {
		std::cout << "Enter natural number\n";
		std::cin >> number;
	}
	for (size_t i = 2; numPair < number; ++i) {
		if (prime(i)) {
			if (primeDist == 1) {
				std::cout << i - 2 << ' ' << i << '\n';
				++numPair;
			}
			primeDist = 0;
		}
		else {
			++primeDist;
		}
	}
	return 0;
}

