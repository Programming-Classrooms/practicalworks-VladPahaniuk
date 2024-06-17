#ifndef FUNCS_HPP
#define FUNCS_HPP

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <set>
#include <string>
#include <algorithm>
#include <exception>

bool checkFile(std::ifstream&, std::string);
std::string toLowercase(const std::string &);
void countWordOccurrences(const std::string &, std::unordered_map<std::string, int> &, std::set<std::string> &);
void printUniqueWords(const std::set<std::string> &);
void printWordCounts(const std::unordered_map<std::string, int> &);

#endif //FUNCS_HPP

