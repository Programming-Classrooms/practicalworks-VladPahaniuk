#ifndef FUNCS_H
#define FUNCS_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <algorithm>
#include <stdexcept>

struct Employee
{
  std::string surename{};
  size_t children{};
  	~Employee();
};

bool checkFile(std::ifstream& );

std::string readFromFile(std::string);

bool isDigit(std::string);

void fillArrayOfDigit(int32_t*, std::string, std::string);
void printArrayofDigit(int32_t*, size_t);



void copySortEvenOddArrays(int32_t*, int32_t*, size_t);

std::string getDelimiters(std::string);

bool isWord(std::string);

size_t getSizeForArrNumbers(std::string, std::string);
size_t getSizeForArrSurenames(std::string, std::string);

void fillArraySurnames(std::string*, std::string, std::string);
void printArrayOfSurnames(std::string*, size_t);

std::string toUpper(std::string);

bool compStrings(std::string, std::string);

void qsortString(std::string*, size_t, size_t);

template<typename T>
void universalQsort(T*, size_t, size_t, bool comp(T, T));

size_t inputChildren(std::string);

void fillingArrOfStruct(Employee*, int32_t*, std::string*, size_t, size_t);
void printArrayOfStruct(Employee*, size_t);

bool compForStructToLower(Employee, Employee);
bool compForStructToUpper(Employee, Employee);

void writeArrOfStruct(std::string, Employee*, size_t);
void writeArrOfStructToBin(std::string, Employee*, size_t);
void variantOfSort(Employee*, size_t);

size_t getPoiterLast(std::ifstream&, struct Employee&, struct Employee&);
void swapLinesInBinareFile(std::ofstream&, size_t, struct Employee, struct Employee);
#endif