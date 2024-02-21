/*
Задан текстовый файл input.txt.
Требуется определить строки этого  файла, содержащие максимальную по длине подстроку, состоящую только из  цифр.
Если таких строк несколько, найти первые 10.
Результат вывести на  консоль в форме, удобной для чтения.
*/


#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

void checkFile(std::ifstream& fin)
{
  if (!fin.good()) {
    throw std::exception("File does not exist.\n");
  }
  if (!fin) {
    throw std::exception("File is not opened.\n");
  }
  if (fin.peek() == EOF) {
    throw std::exception("File is empty.\n");
  }
}

std::string findMaxDigitSubstring(const std::string& line)
{
  std::string digitSubstring;
  std::string maxDigitSubstring;
  bool inDigitSubstring = false;
  for (char c : line) {
    if (std::isdigit(c)) {
      digitSubstring += c;
      inDigitSubstring = true;
    }
    else {
      inDigitSubstring = false;
      digitSubstring.clear();
    }
  }
  if (digitSubstring.length() > maxDigitSubstring.length()) {
    maxDigitSubstring = digitSubstring;
  }
  return maxDigitSubstring;
}

void processFile(const std::string& fin)
{
  std::ifstream inputFile(fin);
  checkFile(inputFile);
  std::string maxLine;
  std::string maxDigitSubstring;
  std::string line;
  while (std::getline(inputFile, line)) {
    std::string digitSubstring = findMaxDigitSubstring(line);
    if (digitSubstring.length() > maxDigitSubstring.length()) {
      maxLine = line;
      maxDigitSubstring = digitSubstring;
    }
  }
  inputFile.close();
  if (!maxDigitSubstring.empty()) {
    std::cout << "Line: " << maxLine << std::endl;
    std::cout << "Max digit substring: " << maxDigitSubstring << std::endl;
  }
  else {
    std::cout << "No digit substrings found." << std::endl;
  }
}

int main()
{
  try
  {
    std::string fin;
    std::cout << "";
    getline(std::cin, fin);
    processFile(fin);
  }
  catch (const std::exception& error)
  {
    std::cerr << error.what();
  }
  return 0;
}
