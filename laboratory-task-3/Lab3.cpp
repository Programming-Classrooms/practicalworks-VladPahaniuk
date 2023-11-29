#include <iostream>
int get_size() {
	double size_of_arr = 0;
	std::cout << "Number of elements:\n";
	while (size_of_arr <= 0) {
		std::cin >> size_of_arr;
		if (size_of_arr <= 0) {
			std::cout << "Incorrect input";
			continue;
		}
		return size_of_arr;
	}
}
void out_arr(double* arr, const int& n) {
	for (size_t i = 0; i < n; ++i) {
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}
void out_arr1(double* new_arr, const int& n) {
	for (size_t i = 0; i < n; ++i) {
		std::cout << new_arr[i] << ' ';

	}
}
double multiplication(double* arr, const int& n) {
	double res = 1;
	int64_t cnt = 0;
	//exception safety
	try {
		for (size_t i = 0; i < n; ++i) {
			if (arr[i] > 0) {
				res *= arr[i];
				cnt++;
			}
		}
		if (cnt == 0) {
			throw "No positive numbers\n";
		}
	}
	catch (const char* msg) {
		std::cout << msg;
	}
	return res;
}
void input_arr(double* arr, const int& n) {
	for (size_t i = 0; i < n; ++i)
		std::cin >> arr[i];
}
void input_from_keyboard(double* arr, const int& n) {
	std::cout << "Enter array\n";
	input_arr(arr, n);
}
void swap(double& a, double& b) {
	double help = b;
	b = a;
	a = help;
}
void  check_border(double& x, double& y){
	while (x == y) {
		std::cout << "Enter board valuse = ";
		std::cin >> x >> y;
		if (x > y) {
			swap(x, y);
		}
	}
}
void input_random(double* arr, double& x, double& y, const int& n) {
	srand(time(NULL));
	for (size_t i = 0; i < n; ++i) {
		arr[i] = x + rand() * (y - x) / RAND_MAX;
		
	}

}
void filling_arr(double* arr0, double& x, double& y, const int& n0) {
	int64_t condition = 0;
	while (condition != 1 && condition != 2) {
		std::cout << "Enter codition 1 - input keyboard, 2 - random values = ";
		std::cin >> condition;
	}
	switch (condition) {
	case 1:
		input_from_keyboard(arr0, n0);

		break;

	case 2:
		check_border(x, y);
		input_random(arr0, x, y, n0);
		std::cout << "Array generared " << '\n';

	}
	system("cls");
	out_arr(arr0, n0);

	//return multiplication(arr0, n0);

}

void buble_sort(double* arr, const int& n, int g) {
	double temp;
	for (size_t i = g; i < n - 1; i += 2) {//buble sort
		for (size_t j = g; j < n - 2; j += 2) {
			if (arr[j] > arr[j + 2]) {
				temp = arr[j];
				arr[j] = arr[j + 2];
				arr[j + 2] = temp;
			}
		}
	}
}
int min_index(double* arr, const int& n) {
	double min;
	int64_t min_index = 0;
	min = arr[0];
	for (size_t i = 0; i < n; ++i) {
		if (min > arr[i]) {
			min = arr[i];
			min_index = i;
		}
	}

	return min_index;
}


double sum_before_min(double* arr, const int& n, int min_index) {
	double sum = 0;
	try {
		if (arr[0] == arr[min_index]) {
			throw "invalid\n";
		}

		for (size_t i = 0; i < min_index; ++i) { 

			sum += arr[i];

		}
	}
	catch (const char* msg) {
		std::cout << msg;
	}
	return sum;

}

int main() {
	double n = get_size(), res = 1.0;
	double x = 0;
	double y = 0;
	double* arr = new double[n];
	filling_arr(arr, x, y, n);
	int64_t min_ind = min_index(arr, n);


	

	double mult = multiplication(arr, n);
	if (mult != 1) {
		std::cout << "Mulyiplication = " << mult << '\n';
	}

	

	double zuma = sum_before_min(arr, n, min_ind);

	if (zuma != 0) {
		std::cout << "Sum = " << zuma << '\n';
	}
	buble_sort(arr, n, 0);
	buble_sort(arr, n, 1);

	
	
	std::cout << "Sort array\n";
	out_arr(arr, n);
	delete[] arr;
	return 0;
}
