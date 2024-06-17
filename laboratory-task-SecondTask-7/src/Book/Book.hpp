#ifndef BOOK_HPP
#define BOOK_HPP

#include "../AuthorList/AuthorList.hpp"

class Book {
private:

    size_t UDC;
    std::string title;
    size_t year;
    AuthorsList authors;

public:

    // Конструктор по умолчанию
    Book();

    // Конструктор с параметрами
    Book(size_t, const std::string&, size_t, const AuthorsList&);

    // Конструктор копирования
    Book(const Book&);

    // Деструктор
    ~Book() = default;

    // Получение УДК
    size_t getUDC() const;
    
    // Получение названия
    std::string getTitle() const;

    // Получение года издания
    size_t getYear() const;

    // Получение авторов
    AuthorsList getAuthors() const;

    // Установка УДК
    void setUDC(size_t);

    // Установка названия
    void setTitle(const std::string&);

    // Установка года издания
    void setYear(size_t);

    // Установка авторов
    void setAuthors(const AuthorsList&);

    // Оператор меньше
    bool operator<(const Book&) const;

    // Ввод из потока
    friend std::ostream& operator<<(std::ostream&, const Book&);

    // Вывод в поток
    friend std::istream& operator>>(std::istream&, Book&);

    // Добавлние автора
    void addAuthor(const Author&);

    // Удаление автора
    void removeAuthor(const Author&);
    
};

#endif // BOOK_HPP

