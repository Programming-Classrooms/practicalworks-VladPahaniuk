/*
Лабораторная работа №7
Вариант 7.
Строка состоит из слов.За один просмотр символов строки найти все
слова, начинающиеся с гласных букв, и занести их в новую строку, заменяя
первую букву каждого слова на прописную.Слова в новой строке должны
разделяться ровно одним пробелом.
Тема: Строки
При написании программ использовать нуль–терминированные строки
и работать только с типом char* .Длина каждой строки не превосходит 300
символов.Словом, входящим в состав строки, назовём непрерывную
последовательность символов, ограниченную символами–разделителями,
началом и концом строки.Символы, относящиеся к разделителям, определяет
пользователь, если иное не сказано в условии задачи.Если решить задачу
невозможно, программа должна выдать соответствующее сообщение.
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <cstring>
#include <Windows.h>

void getDelimiters(char* delimiters, int32_t& maxStringLength) 
{
  std::cout << "Enter delimiters: ";
  std::cin.getline(delimiters, maxStringLength);
  if (strlen(delimiters) == 0) {
    throw std::invalid_argument("Input string cannot be empty");
  }
}

bool exceptionForInvaluedArgument(char* inputString) 
{
  size_t len = strlen(inputString);
  for (size_t i = 0; i < len; ++i) {
    if (std::isalpha(inputString[i])) {
      return true;
    }
  }
  return false;
}

void getInputString(char* inputString, int32_t& maxStringLength)
 { 
  std::cout << "Enter a string: ";
  std::cin.getline(inputString, maxStringLength);
  if (strlen(inputString) == 0) {
    throw std::invalid_argument("Input string cannot be empty");
  }
  if (!exceptionForInvaluedArgument(inputString)) {
    throw std::invalid_argument("The line does not contain words that begin with a vowel.");
  }
}

bool vowelTest(char* word, char* key) 
{
  char temp;
  size_t lenKey = strlen(key);
  for (size_t i = 0; i < lenKey; ++i) {
    if (key[i] == word[0]) {
      temp = word[0];
      temp = std::toupper(temp);
      word[0] = temp;
      return true;
    }
  }
  return false;
}

void capitalizeVowelWords(char* inputString, char* delimiters, char* key, char* outputString, char* inputStringForSeparate, char* word) 
{
  strcpy(inputStringForSeparate, inputString);
  word = strtok(inputStringForSeparate, delimiters);
  bool temp = false;
  while (word != NULL) {
    if (exceptionForInvaluedArgument(word)) {
      if (vowelTest(word, key)) {
        strcat(outputString, word);
        strcat(outputString, " ");
        temp = true;
      }
    }
    word = strtok(NULL, delimiters);
  }
  if (!temp) {
    throw std::invalid_argument("The line does not contain words that begin with a vowel.");
  }
}

int main() 
{
  try {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int32_t maxStringLength = 300;
    char inputString[maxStringLength];
    char inputStringForSeparate[maxStringLength];
    char outputString[maxStringLength] = { NULL };
    char word[maxStringLength];
    char key[] = "aeoiuyEYUIOA";
    char delimiters[maxStringLength];
    getDelimiters(delimiters, maxStringLength);
    getInputString(inputString, maxStringLength);
    capitalizeVowelWords(inputString, delimiters, key, outputString, inputStringForSeparate, word);
    std::cout << outputString;
  }
  catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
  }
  return 0;
}

