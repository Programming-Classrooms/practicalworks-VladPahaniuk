#include <iostream>
#include <fstream>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>
#include <exception>

// Функция для  проверки файла
void checkFile(std::ifstream &file)
{
	if (!file.good())
	{
		throw std::invalid_argument("File does not exist!");
	}
	if (!file)
	{
		throw std::ios_base::failure("File is not opened!");
	}
	if (file.peek() == EOF)
	{
		throw std::runtime_error("File is empty!");
	}
}

// Функция для приведения строки к нижнему регистру
std::string toLowercase(const std::string &str)
{
	std::string lowerStr = str;
	std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
	return lowerStr;
}

// Функция для чтения файла и подсчета вхождений слов
void countWordOccurrences(const std::string &filename, std::unordered_map<std::string, int> &wordCounts, std::set<std::string> &uniqueWords)
{
	std::ifstream file(filename);
	checkFile(file);
	std::string word;
	while (file >> word)
	{
		// Приводим слово к нижнему регистру
		word = toLowercase(word);

		// Добавляем слово в контейнер уникальных слов
		uniqueWords.insert(word);

		// Увеличиваем счётчик вхождений для данного слова
		wordCounts[word]++;
	}

	file.close();
}

// Функция для вывода списка уникальных слов
void printUniqueWords(const std::set<std::string> &uniqueWords)
{
	std::cout << "List of unique words:" << std::endl;
	for (const auto &word : uniqueWords)
	{
		std::cout << word << std::endl;
	}
}

// Функция для вывода количества вхождений каждого слова
void printWordCounts(const std::unordered_map<std::string, int> &wordCounts)
{
	std::cout << "Word counts:" << std::endl;
	for (const auto &pair : wordCounts)
	{
		std::cout << pair.first << ": " << pair.second << std::endl;
	}
}

int main()
{
	try
	{

		std::unordered_map<std::string, int> wordCounts;
		std::set<std::string> uniqueWords;

		countWordOccurrences("src/files/file.txt", wordCounts, uniqueWords);
		printUniqueWords(uniqueWords);
		printWordCounts(wordCounts);

		return 0;
	}
	catch (const std::runtime_error &error)
	{
		std::cerr << error.what() << '\n';
	}
	catch (const std::invalid_argument &error)
	{
		std::cerr << error.what() << '\n';
	}
	catch (const std::ios_base::failure &error)
	{
		std::cerr << error.what() << '\n';
	}
}
