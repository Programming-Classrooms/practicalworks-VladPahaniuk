#ifndef BOOK_HPP
#define BOOK_HPP

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Book {
private:

    std::string ISBN;
    std::string title;
    std::vector<std::string> authors;
    double price;
    size_t count;

public:

    // Конструктор по умолчанию
    Book()=default;

    // Конструктор с параметрами
    Book(const std::string&,
         const std::string&,
         const std::vector<std::string>&,
         double, size_t);

    // Конструктор копирования
    Book(const Book &other);

     // Деструктор
    ~Book() = default;


/*==========================================================*/
/*=======================Гетеры=============================*/
/*==========================================================*/

    // Получение ИСБН
    std::string getISBN() const;

    // Получение названия
    std::string getTitle() const;

    // Получение авторов
    std::vector<std::string> getAuthors() const;

    // Получение цены
    double getPrice() const;

    // Получение колтичества
    size_t getCount() const;


/*==========================================================*/
/*=======================Cетеры=============================*/
/*==========================================================*/

    // Установка ИСБН
    void setISBN(const std::string&);
    
    // Установка названия
    void setTitle(const std::string&);
    
    // Установка авторов
    void setAuthors(const std::vector<std::string>&);
    
    // Установка цены
    void setPrice(double);
    
    // Получение колтичества
    void setCount(size_t);
    

/*================================================================================*/
/*==================================== Методы ====================================*/
/*================================================================================*/

    // Добавление автора
    void addAuthor(const std::string&);

    // Удаление автора
    void removeAuthor(const std::string&);
};

#endif // BOOK_HPP

