#ifndef LIBRARY
#define LIBRARY

#include<set>
#include<iterator>
#include<algorithm>
#include<functional>
#include<fstream>
#include <sstream>

#include"../Book/Book.hpp"

class Library {
private:

    std::set<Book> books;

public:

    // Конструктор по умолчанию
    Library() = default;

    // Конструктор копирования
    Library(const Library&);

    // Деструктор
    ~Library() = default;

    // Добавление книги
    void addBook(const Book&);

    // Удаление книги
    void removeBook(const Book&);

    // Поиск книги по названию
    Book* findBookByTitle(const std::string&);

    // Поиск книги по автору
    std::set<Book> findBooksByAuthor(const Author&);

    // Добавление автора к книге
    void addAuthorToBook(const std::string&, const Author&);

    // Удаление автора в книге
    void removeAuthorFromBook(const std::string&, const Author&);
    
    // Ввод из потока
    friend std::ostream& operator<<(std::ostream&, const Library&);

    // Чтенике из файла
    void readFromFile(const std::string&);

};

// Проверка файла   
void checkFileInput(std::ifstream &);

#endif // LIBRARY_HPP

