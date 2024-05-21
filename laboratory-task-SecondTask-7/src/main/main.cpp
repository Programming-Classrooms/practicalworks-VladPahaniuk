#include "../Library/Library.hpp"

int main()
{
    try
    {
        Library library;

        // Загрузка данных из файла
        library.loadFromFile("src/file/file.txt");

        // Вывод библиотеки
        std::cout << "Library contents:\n"
                  << library << std::endl;

std::cout << "*********************************\n";

        // Поиск книги по названию
        Book *foundBook = library.findBookByTitle("The Great Gatsby");
        if (foundBook)
        {
            std::cout << "Found book:\n"
                      << *foundBook << std::endl;
        }
        else
        {
            std::cout << "Book not found!" << std::endl;
        }
std::cout << "*********************************\n";

        // Добавление автора к книге
        library.addAuthorToBook("The Great Gatsby", Author("Smith", "John", "Doe"));

        // Удаление автора из книги
        library.removeAuthorFromBook("The Great Gatsby", Author("Smith", "John", "Doe"));
 
        // Вывод библиотеки после изменений
        std::cout << "Library contents after modifications:\n"
                  << library << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << e.what() << std::endl;
    }
     catch (const std::ios_base::failure &e)
    {
        std::cerr << e.what() << std::endl;
    }
     catch (const std::runtime_error &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}
