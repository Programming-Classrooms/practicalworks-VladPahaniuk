#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "../funcs/funcs.hpp"

int main()
{
    try {
        std::string pathToSurenames = "src/files/Strings.txt";
        std::string pathToNumbers = "src/files/Numbers.txt";
        std::string pathToOutInTxt = "src/files/result.txt";
        std::string pathToOutInBin = "src/files/result.bin";

        std::string delimsToSurenames = getDelimiters(pathToSurenames);
        std::string surenames = readFromFile(pathToSurenames);
        size_t sizeArrToSurename = getSizeForArrSurenames(surenames, delimsToSurenames);

        if (sizeArrToSurename == 0) {
            throw std::invalid_argument("Exception: sizeArrToSurename is 0\n");
        }

        std::vector<std::string> allSurenames(sizeArrToSurename);
        fillArraySurnames(allSurenames.data(), surenames, delimsToSurenames);
        printArrayOfSurnames(allSurenames.data(), sizeArrToSurename);
        qsortString(allSurenames.data(), 0, sizeArrToSurename - 1);
        printArrayOfSurnames(allSurenames.data(), sizeArrToSurename);

        std::string delimToNumber = getDelimiters(pathToNumbers);
        std::string numbers = readFromFile(pathToNumbers);
        size_t sizeArrToNumbers = getSizeForArrNumbers(numbers, delimToNumber);

        if (sizeArrToNumbers == 0) {
            throw std::invalid_argument("Task not have solution\n");
        }

        std::vector<int32_t> allNumbers(sizeArrToNumbers);
        std::vector<int32_t> allSortNumbers(sizeArrToNumbers);
        fillArrayOfDigit(allNumbers.data(), numbers, delimToNumber);
        printArrayofDigit(allNumbers.data(), sizeArrToNumbers);
        copySortEvenOddArrays(allNumbers.data(), allSortNumbers.data(), sizeArrToNumbers);
        printArrayofDigit(allSortNumbers.data(), sizeArrToNumbers);

        std::vector<Employee> employees(sizeArrToSurename);
        fillingArrOfStruct(employees.data(), allNumbers.data(), allSurenames.data(), sizeArrToSurename, sizeArrToNumbers);
        printArrayOfStruct(employees.data(), sizeArrToSurename);
        variantOfSort(employees.data(), sizeArrToSurename);
        printArrayOfStruct(employees.data(), sizeArrToSurename);

        writeArrOfStruct(pathToOutInTxt, employees.data(), sizeArrToSurename);
        writeArrOfStructToBin(pathToOutInBin, employees.data(), sizeArrToSurename);
        
      

			std::ifstream fin(pathToOutInBin, std::ios::binary);

			Employee employeeLast, employeeFirst;
			size_t pointerToLast = getPoiterLast(fin, employeeLast, employeeFirst);
			fin.close();

			std::ofstream fout(pathToOutInBin, std::ios::binary | std::ios::app);
			swapLinesInBinareFile(fout, pointerToLast, employeeLast, employeeFirst);
			fout.close();

    } catch (const std::invalid_argument& e) {
        std::cerr << "Exception: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
