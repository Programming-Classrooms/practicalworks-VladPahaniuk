#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <exception>

// Функция для проверки файла
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

// Функция для печати вектора строк
void printVector(const std::vector<std::string> &vec)
{
    for (const auto &str : vec)
    {
        std::cout << str << std::endl;
    }
}

// Функция для удаления элементов списка на заданную букву
void removeWordsStartingWithLetter(std::vector<std::string> &vec, char letter)
{
    vec.erase(std::remove_if(vec.begin(), vec.end(), [letter](const std::string &str)
                             { return str.front() == letter; }),
              vec.end());
}

int main()
{
    try
    {
        std::vector<std::string> words;

        std::ifstream inputFile("src/files/words.txt");
        checkFile(inputFile);

        std::string word = "\0";
        while (inputFile >> word)
        {
            words.push_back(word);
        }
        inputFile.close();

        std::sort(words.begin(), words.end());

        std::cout << "Отсортированный список:" << std::endl;
        printVector(words);

        char letter = '\0';
        std::cout << "Введите букву для печати списка на заданную букву: ";
        std::cin >> letter;
        std::cout << "Слова, начинающиеся на букву '" << letter << "':" << std::endl;
        for (const auto &str : words)
        {
            if (str.front() == letter)
            {
                std::cout << str << std::endl;
            }
        }
        removeWordsStartingWithLetter(words, letter);
        std::cout << "Список после удаления слов, начинающихся на букву '" << letter << "':" << std::endl;
        printVector(words);
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
    return 0;
}
