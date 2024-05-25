#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// Функция для чтения чисел из ввода
std::vector<int> readNumbers() {
    std::vector<int> numbers;
    int num = 0;

    std::cout << "Введите числа (для завершения введите 1001):" << std::endl;
    while (std::cin >> num) {
        numbers.push_back(num);
        if (num == 1001) {
            break; 
        }
    }

    return numbers;
}

// Функция для вычисления суммы чисел
int calculateSum(const std::vector<int>& numbers) {
    return std::accumulate(numbers.begin(), numbers.end(), 0);
}

// Функция для подсчета количества чисел
int countNumbers(const std::vector<int>& numbers) {
    return numbers.size();
}

// Функция для подсчета чисел, равных заданному
int countTargetNumber(const std::vector<int>& numbers, int target) {
    return std::count(numbers.begin(), numbers.end(), target);
}

// Функция для подсчета чисел, больших заданного
int countGreaterNumbers(const std::vector<int>& numbers, int n) {
    return std::count_if(numbers.begin(), numbers.end(), [n](int x) { return x > n; });
}

// Функция для замены нулей средним арифметическим
void replaceZerosWithAverage(std::vector<int>& numbers, double average) {
    for (int& num : numbers) {
        if (num == 0) {
            num = static_cast<int>(average);
        }
    }
}

// Функция для добавления к каждому элементу вектора суммы чисел из заданного интервала
void addIntervalSum(std::vector<int>& numbers, int start, int end) {
    int intervalSum = std::accumulate(numbers.begin() + start, numbers.begin() + end + 1, 0);
    for (int& num : numbers) {
        num += intervalSum;
    }
}

// Функция для замены всех чисел, модуль которых четное число, на разность максимального и минимального элемента
void replaceEvenModuloNumbers(std::vector<int>& numbers, int maxNum, int minNum) {
    for (int& num : numbers) {
        if (std::abs(num) % 2 == 0) {
            num = maxNum - minNum;
        }
    }
}

// Функция для удаления всех равных по модулю чисел, кроме первого из них
std::vector<int> removeDuplicateByModulo(const std::vector<int>& numbers) {
    std::vector<int> uniqueNumbers;
    for (int num : numbers) {
        if (std::find(uniqueNumbers.begin(), uniqueNumbers.end(), std::abs(num)) == uniqueNumbers.end()) {
            uniqueNumbers.push_back(std::abs(num));
        }
    }
    return uniqueNumbers;
}

int main() {
    std::vector<int> numbers = readNumbers();

    int sum = calculateSum(numbers);
    int count = countNumbers(numbers);

    std::cout << "Сумма чисел: " << sum << std::endl;
    std::cout << "Общее количество чисел: " << count << std::endl;

    int target = 0;
    std::cout << "Введите число для подсчета его количества: ";
    std::cin >> target;
    int countTarget = countTargetNumber(numbers, target);
    std::cout << "Количество чисел, равных " << target << ": " << countTarget << std::endl;

    int n = 0;
    std::cout << "Введите число n для подсчета количества чисел больше него: ";
    std::cin >> n;
    int countGreaterN = countGreaterNumbers(numbers, n);
    std::cout << "Количество чисел, больших " << n << ": " << countGreaterN << std::endl;

    double average = static_cast<double>(sum) / count;
    replaceZerosWithAverage(numbers, average);
    std::cout << "Вектор после замены нулей средним арифметическим:" << std::endl;
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    int start = 0, end = 0;
    std::cout << "Введите начало и конец интервала (индексы вектора): ";
    std::cin >> start >> end;
    addIntervalSum(numbers, start, end);
    std::cout << "Вектор после добавления суммы чисел из интервала:" << std::endl;
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    int maxNum = *std::max_element(numbers.begin(), numbers.end());
    int minNum = *std::min_element(numbers.begin(), numbers.end());
    replaceEvenModuloNumbers(numbers, maxNum, minNum);
    std::cout << "Вектор после замены чисел с четным модулем:" << std::endl;
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    std::vector<int> uniqueNumbers = removeDuplicateByModulo(numbers);
    std::cout << "Уникальные числа по модулю:" << std::endl;
    for (int n : uniqueNumbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}