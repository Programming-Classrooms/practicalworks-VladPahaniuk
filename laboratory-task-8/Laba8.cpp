/*
Словом, входящим в состав строки, назовём непрерывную
последовательность символов, ограниченную символами–разделителями,
началом и концом строки. Символы, относящиеся к разделителям, определяет
пользователь, если иное не сказано в условии задачи. Если решить задачу
невозможно, программа должна выдать соответствующее сообщение.
Вариант 7. Строка состоит из слов, разделенных пробелами.
Поместить в начало строки слова, содержащие только цифры, а затем – все остальные слова.
 Порядок слов внутри заданных групп не должен изменяться.
*/


#include <iostream>
#include <sstream>
#include <cctype>
#include <Windows.h>

std::string getInputString()
{
    std::string input;
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);
    return input;
}

void separateWords(const std::string& input, std::string& wordsWithDigits, std::string& wordsWithoutDigits)
{
    std::istringstream iss(input);
    std::string word;
    while (iss >> word) {
        bool hasDigit = false;
        for (char c : word) {
            if (std::isdigit(c)) {
                hasDigit = true;
                break;
            }
        }
        if (hasDigit) {
            wordsWithDigits += word + ' ';
        }
        else {
            wordsWithoutDigits += word + ' ';
        }
    }
}

std::string createResultString(const std::string& wordsWithDigits, const std::string& wordsWithoutDigits)
{
    std::ostringstream result;
    result << wordsWithDigits << wordsWithoutDigits;
    return result.str();
}

int main() 
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    std::string input = getInputString();
    std::string wordsWithDigits, wordsWithoutDigits;
    separateWords(input, wordsWithDigits, wordsWithoutDigits);
    std::string result = createResultString(wordsWithDigits, wordsWithoutDigits);
    std::cout << "Результат: " << result << std::endl;
    return 0;
}

