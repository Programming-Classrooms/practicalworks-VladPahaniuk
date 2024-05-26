#ifndef AUTHORSLIST_HPP
#define AUTHORSLIST_HPP

#include<set>
#include<iterator>
#include<algorithm>

#include"../Author/Author.hpp"

class AuthorsList
{
private:

    std::set<Author> list;

public:

    // Конструктор по умолчанию
    AuthorsList();

    // Конструктор копирования
    AuthorsList(const AuthorsList&);

    // Конструктор, принимающий ссылку на std::set<Author>
    AuthorsList(std::set<Author>&);

    // Деструктор
    ~AuthorsList() = default;

    // Получение размера списка
    size_t getSize() const;
    
    // Оператор присваивания
    AuthorsList& operator=(const AuthorsList&);

    // Оператор равенства
    bool operator==(const AuthorsList&) const;

    // Ввод из потока
    friend std::ostream& operator<<(std::ostream&, const AuthorsList&);

    // Вывод в поток
    friend std::istream& operator>>(std::istream&, AuthorsList&);

    // Добавлние автора
    void addAuthor(const Author& author);

    // Удоление автора
    void removeAuthor(const Author& author);

    // Проверка на нахождение автора в списке
    bool contains(const Author& author);

    // Получение размера списка
    size_t size() const;

};

#endif 
