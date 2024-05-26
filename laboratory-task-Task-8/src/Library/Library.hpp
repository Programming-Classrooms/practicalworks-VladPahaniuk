#ifndef LIBRARY_HPP
#define LIBRARY_HPP

#include <vector>
#include <string>
#include"../Book/Book.hpp"

class Library {
private:
    std::vector<Book> books;

public:

    // Конструктор по умолчанию
    Library() = default;

    // Деструктор
    ~Library() = default;

    // Добавление книги
    void addBook(const Book&);

    // Поиск книги по ИСБН
    Book* findBook(const std::string&);

    // Удаление книги
    bool removeBook(const std::string&);

    // Просмотр книг
    std::vector<Book> viewBooks() const;
    
    // Добавление автора
    void addAuthor(const std::string& isbn, const std::string& author);

    // Удаление автора
    void removeAuthor(const std::string& isbn, const std::string& author);
    
    // Сортировка книг по ИСБН
    void sortBooksByISBN();

    // Сортировка книг по названию
    void sortBooksByTitle();

};

#endif // LIBRARY_HPP
