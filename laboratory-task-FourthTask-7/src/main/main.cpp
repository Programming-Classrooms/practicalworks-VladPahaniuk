#include <iostream>
#include <fstream>
#include <set>
#include <string>
#include <algorithm>

bool checkFile(std::ofstream &filename)
{
	if (!filename.good())
	{
		throw std::invalid_argument("File not found...");
	}

	if (!filename)
	{
		throw std::ios_base::failure("Error reading file... ");
	}

	return true;
}

// Запись данных в файл
void writeToFile(const std::string &filename, const std::set<std::string> &data) {
    std::ofstream outFile(filename, std::ios::app);
    if (checkFile(outFile)) {
        for (const auto &item : data) {
            outFile << item << std::endl;
        }
    }
    outFile.close();
}

// Вывод
void print(const std::string &title, const std::set<std::string> &data) {
    std::cout << title;
    for (const auto &item : data) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

// Объединение множеств рыбаков
std::set<std::string> unionFishermen(const std::set<std::string> &set1, const std::set<std::string> &set2) {
    std::set<std::string> resultSet;
    std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(resultSet, resultSet.end()));
    return resultSet;
}

// Разница
std::set<std::string> difference(const std::set<std::string> &set1, const std::set<std::string> &set2) {
    std::set<std::string> resultSet;
    std::set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(resultSet, resultSet.end()));
    return resultSet;
}

int main() {

    std::set<std::string> fishermanIvan = {"окунь", "щука", "карась"};
    std::set<std::string> fishermanVadim = {"щука", "сом", "краснопёрка"};
    std::set<std::string> fishermanVasy = {"окунь", "карась", "карп"};

    print("Рыбак-Иван: ", fishermanIvan);
    print("Рыбак-Вадим: ", fishermanVadim);
    print("Рыбак-Вася: ", fishermanVasy);

    // Находим рыбаков, которые поймали хотя бы одну рыбу
    std::set<std::string> caughtFishermen = unionFishermen(fishermanIvan, fishermanVadim);
    caughtFishermen = unionFishermen(caughtFishermen, fishermanVasy);
    print("Выловленные рыбы хотя бы одного вида: ", caughtFishermen);

    // Создаем множество всех видов рыб в озере
    std::set<std::string> allFish = {"окунь", "щука", "карась", "сом", "краснопёрка", "плотва"};

    std::set<std::string> notCaughtFish = difference(allFish, caughtFishermen);
    print("Рыбы, которые есть в озере, но не в улове рыбаков: ", notCaughtFish);

    // Записываем данные в файлы
    writeToFile("fishermen.txt", fishermanIvan);
    writeToFile("fishermen.txt", fishermanVadim);
    writeToFile("fishermen.txt", fishermanVasy);
    writeToFile("fishermen.txt", caughtFishermen);
    writeToFile("notCaughtFish.txt", notCaughtFish);

    return 0;
}

