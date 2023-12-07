#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <Windows.h>
/*Словом, входящим в состав строки, назовём непрерывную
последовательность символов, ограниченную символами–разделителями,
началом и концом строки. Символы, относящиеся к разделителям, определяет
пользователь, если иное не сказано в условии задачи. Если решить задачу
невозможно, программа должна выдать соответствующее сообщение.
Вариант 7. Строка состоит из слов, разделенных пробелами.
Поместить в начало строки слова, содержащие только цифры, а затем – все остальные слова.
 Порядок слов внутри заданных групп не должен изменяться.
*/
std::string getInputString() {
    std::string input;
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);
    return input;
}

std::vector<std::string> splitStringIntoWords(const std::string& input) {
    std::istringstream iss(input);
    std::vector<std::string> words;
    std::string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}
bool allStringIsDigit(const std::string& word) {
    for (const auto& x : word)
    {
        if (!isdigit(x)) {
            return false;
        }
    }
    return true;
}

// Разделение слов на две группы: с цифрами и без
void categorizeWords(const std::vector<std::string>& words,
    std::vector<std::string>& wordsWithDigits,
    std::vector<std::string>& wordsWithoutDigits) {
    for (const auto& w : words) {
        if (allStringIsDigit(w)) {
                wordsWithDigits.push_back(w);   
        }
        else {
            wordsWithoutDigits.push_back(w);
        }
    }
}

std::string createResultString(const std::vector<std::string>& wordsWithDigits,
    const std::vector<std::string>& wordsWithoutDigits) {
    std::ostringstream result;
    for (const auto& w : wordsWithDigits) {
        result << w << ' ';
    }
    for (const auto& w : wordsWithoutDigits) {
        result << w << ' ';
    }
    return result.str();
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::string input = getInputString();

    // Разделение строки на слова
    std::vector<std::string> words = splitStringIntoWords(input);

    // Разделение слов на две группы: с цифрами и без
    std::vector<std::string> wordsWithDigits, wordsWithoutDigits;
    categorizeWords(words, wordsWithDigits, wordsWithoutDigits);

    // Формирование новой строки
    std::string result = createResultString(wordsWithDigits, wordsWithoutDigits);
    std::cout << "Результат: " << result << std::endl;

    return 0;
}
