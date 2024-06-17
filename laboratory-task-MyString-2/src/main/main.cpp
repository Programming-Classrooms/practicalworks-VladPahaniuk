#include "src/MyString/MyString.hpp"
int main()
{
    try
    {

        // Конструктор с параметрами
        MyString str2("Hello");
        std::cout << "Constructor with parameters output: " << str2 << std::endl;

        // Конструктор копирования
        MyString str3(str2);
        std::cout << "Copy constructor output: " << str3 << std::endl;

        // Получение строки
        std::cout << "str2 content using getString method: " << str2.getString() << std::endl;

        // Получение длины строки
        std::cout << "Length of str2: " << str2.getLength() << std::endl;

        // Конкатенация строк
        MyString str6(" World!");
        MyString concatenated = str2 + str6;
        std::cout << "Concatenated string: " << concatenated << std::endl;

        // Перегрузка оператора присваивания
        MyString assigned;
        assigned = str2;
        std::cout << "Assigned string: " << assigned << std::endl;

        // operator+=
        MyString appended(" Appended");
        assigned += appended;
        std::cout << "String after append: " << assigned << std::endl;

        // Сравнение строк
        MyString compare1("abc");
        MyString compare2("def");
        if (compare1 == compare2)
        {
            std::cout << "Strings are equal." << std::endl;
        }
        else
        {
            std::cout << "Strings are not equal." << std::endl;
        }

        // operator[] Замена первой буквы
        MyString str7("Testing operator[]");
        str7[0] = 't'; 
        std::cout << "Modified string: " << str7 << std::endl;

        MyString str8;
        std::cout << "Input you string: " << std::endl;
        std::cin >> str8;
        std::cout << "You input: " << str8 << std::endl;
    }
    catch (const std::logic_error &error)
    {
        std::cerr << error.what() << std::endl;
    }
    return 0;
}
