/*Написать программу, которая для заданного натурального числа:
7. вычисляет Т пар близнецов.*/

#include <iostream>


bool prime(const int64_t& n) {
	for (int64_t i = 2; i < n; i++) {
		if (n % i == 0)
			return false;
	}
	return true;
}



int main() {
	int64_t number = 0, prime_dist = 0, num_pair = 0;
	std::cout << "Enter T pair of bliznecov\n";
	std::cin >> number;
	while (number <= 0) {
		std::cout << "Enter natural number\n";
		std::cin >> number;
	}
	for (size_t i = 2; num_pair < number; ++i) {
		if (prime(i)) {
			if (prime_dist == 1) {
				std::cout << i - 2 << ' ' << i << '\n';
				++num_pair;
			}
			prime_dist = 0;
		}
		else {
			++prime_dist;
		}
	}
	return 0;
}
