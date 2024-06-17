#include "funcs.hpp"

// Провека файла
bool checkFile(std::ofstream &file, std::string path)
{
    if (!file.good())
    {
        std::string str = "File not found... Path: ";
        str.append(path);
        throw std::invalid_argument(str);
    }
    if (!file)
    {
        std::string str = "File is bad... Path: ";
        str.append(path);
        throw std::ios_base::failure(str);
    }
    return true;
}

// Запись данных в файл
void writeToFile(const std::string &filename, const std::set<std::string> &data)
{
    std::ofstream outFile(filename, std::ios::app);
    if (checkFile(outFile, filename))
    {
        for (const auto &item : data)
        {
            outFile << item << std::endl;
        }
    }
    outFile.close();
}

// Вывод множества
void print(const std::string &title, const std::set<std::string> &data)
{
    std::cout << title;
    for (const auto &item : data)
    {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

// Объединение множеств рыбаков
std::set<std::string> unionFishermen(const std::set<std::string> &set1, const std::set<std::string> &set2)
{
    std::set<std::string> resultSet;
    std::set_union(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(resultSet, resultSet.end()));
    return resultSet;
}

// Разница
std::set<std::string> difference(const std::set<std::string> &set1, const std::set<std::string> &set2)
{
    std::set<std::string> resultSet;
    std::set_difference(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(resultSet, resultSet.end()));
    return resultSet;
}
