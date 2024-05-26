#include "funcs.hpp"

// Функция для  проверки файла
bool checkFile(std::ifstream& file, std::string path)
{
	if (!file.good()) {
		std::string str = "File not found... Path: ";
		str.append(path); 
		throw std::invalid_argument(str);
	}
	if (!file) {
		std::string str = "File is bad... Path: ";
		str.append(path); 
		throw std::ios_base::failure(str);
	}
	if (file.peek() == EOF) {
		std::string str = "File is empti... Path: ";
		str.append(path); 
		throw std::runtime_error(str);
	}
	return true;
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
	if(checkFile(file, filename)){;
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
