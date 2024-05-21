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

void writeToFile(const std::string &filename, const std::set<std::string> &data)
{
	std::ofstream outFile(filename, std::ios::app);
	if (checkFile(outFile)) {
		for (const auto &item : data) {
			outFile << item << std::endl;
		}
	}

	outFile.close();
}

int main()
{
	// Создаем множества для каждого рыбака
	std::set<std::string> fishermanIvan = {"окунь", "щука", "карась"};
	std::set<std::string> fishermanVadim = {"щука", "сом", "краснопёрка"};
	std::set<std::string> fishermanVasy = {"окунь", "карась", "карп"};

	// Выводим виды рыб у каждого рыбака
	std::cout << "Рыбак-Иван: ";
	for (const auto &fish : fishermanIvan)
	{
		std::cout << fish << " ";
	}
	std::cout << std::endl;

	std::cout << "Рыбак-Вадим: ";
	for (const auto &fish : fishermanVadim)
	{
		std::cout << fish << " ";
	}
	std::cout << std::endl;

	std::cout << "Рыбак-Вася: ";
	for (const auto &fish : fishermanVasy)
	{
		std::cout << fish << " ";
	}
	std::cout << std::endl;

	// Находим рыбаков, которые поймали хотя бы одну рыбу
	std::set<std::string> caughtFishermen;
	set_union(fishermanIvan.begin(), fishermanIvan.end(), fishermanVadim.begin(), fishermanVadim.end(), inserter(caughtFishermen, caughtFishermen.end()));
	set_union(caughtFishermen.begin(), caughtFishermen.end(), fishermanVasy.begin(), fishermanVasy.end(), inserter(caughtFishermen, caughtFishermen.end()));

	std::cout << "Выловленные рыбы хотя бы одного вида: ";
	for (const auto &fisherman : caughtFishermen)
	{
		std::cout << fisherman << " ";
	}
	std::cout << std::endl;

	// Создаем множество всех видов рыб в озере
	std::set<std::string> allFish = {"окунь", "щука", "карась", "сом", "краснопёрка", "плотва"};

	// Находим рыбы, которые есть в озере, но не пойманы ни одним рыбаком
	std::set<std::string> notCaughtFish;
	set_difference(allFish.begin(), allFish.end(), caughtFishermen.begin(), caughtFishermen.end(), inserter(notCaughtFish, notCaughtFish.end()));

	std::cout << "Рыбы, которые есть в озере, но не в улове рыбаков: ";
	for (const auto &fish : notCaughtFish)
	{
		std::cout << fish << " ";
	}
	std::cout << std::endl;

	// Записываем данные в файлы
	writeToFile("fishermen.txt", fishermanIvan);
	writeToFile("fishermen.txt", fishermanVadim);
	writeToFile("fishermen.txt", fishermanVasy);
	writeToFile("fishermen.txt", caughtFishermen);
	writeToFile("notCaughtFish.txt", notCaughtFish);

	return 0;
}
