#ifndef FUNCS_HPP
#define FUNCS_HPP

#include<iostream>
#include <fstream>
#include <iostream>
#include <set>
#include <string>
#include <stdexcept>
#include <algorithm>

// Проверка файла
bool checkFile(std::ofstream &, const std::string);

// Запись данных в файл
void writeToFile(const std::string &, const std::set<std::string> &);

// Вывод множества
void print(const std::string &, const std::set<std::string> &);

// Объединение множеств рыбаков
std::set<std::string> unionFishermen(const std::set<std::string> &, const std::set<std::string> &);

// Разница множеств
std::set<std::string> difference(const std::set<std::string> &, const std::set<std::string> &);
#endif //FUNCS_HPP
