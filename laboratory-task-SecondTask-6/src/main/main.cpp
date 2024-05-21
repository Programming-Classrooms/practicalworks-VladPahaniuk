#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {

    std::vector<int> numbers;
    int num = 0;

    std::cout << "Введите числа (для завершения введите 1001):" << std::endl;
    while (std::cin >> num) {
        numbers.push_back(num);
        if (num == 1001) {
            break; 
        }
    }

    // Вычисляем сумму чисел и общее количество чисел
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);
    int count = numbers.size();

    std::cout << "Сумма чисел: " << sum << std::endl;
    std::cout << "Общее количество чисел: " << count << std::endl;

    // Подсчитываем количество чисел, равных заданному
    int target = 0;
    std::cout << "Введите число для подсчета его количества: ";
    std::cin >> target;
    int countTarget = std::count(numbers.begin(), numbers.end(), target);
    std::cout << "Количество чисел, равных " << target << ": " << countTarget << std::endl;

    // Подсчитываем количество чисел, больших заданного числа n
    int n = 0;
    std::cout << "Введите число n для подсчета количества чисел больше него: ";
    std::cin >> n;
    int countGreaterN = std::count_if(numbers.begin(), numbers.end(), [n](int x) { return x > n; });
    std::cout << "Количество чисел, больших " << n << ": " << countGreaterN << std::endl;

    // Заменяем все нули средним арифметическим (целая часть)
    double average = static_cast<double>(sum) / count;
    for (int& num : numbers) {
        if (num == 0) {
            num = static_cast<int>(average);
        }
    }
    std::cout << "Вектор после замены нулей средним арифметическим:" << std::endl;
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // Добавляем к каждому элементу вектора сумму чисел из заданного интервала
    int start = 0, end = 0;
    std::cout << "Введите начало и конец интервала (индексы вектора): ";
    std::cin >> start >> end;
    int intervalSum = std::accumulate(numbers.begin() + start, numbers.begin() + end + 1, 0);

    for (int& num : numbers) {
        num += intervalSum;
    }
    std::cout << "Вектор после добавления суммы чисел из интервала:" << std::endl;
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // Заменяем все числа, модуль которых есть четное число, на разность максимального и минимального элемента
    int maxNum = *std::max_element(numbers.begin(), numbers.end());
    int minNum = *std::min_element(numbers.begin(), numbers.end());
    for (int& num : numbers) {
        if (std::abs(num) % 2 == 0) {
            num = maxNum - minNum;
        }
    }
    std::cout << "Вектор после замены чисел с четным модулем:" << std::endl;
    for (int n : numbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    // Удаляем из последовательности все равные по модулю числа, кроме первого из них
    std::vector<int> uniqueNumbers;
    for (int num : numbers) {
        if (std::find(uniqueNumbers.begin(), uniqueNumbers.end(), std::abs(num)) == uniqueNumbers.end()) {
            uniqueNumbers.push_back(std::abs(num));
        }
    }
    std::cout << "Уникальные числа по модулю:" << std::endl;
    for (int n : uniqueNumbers) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    return 0;
}
