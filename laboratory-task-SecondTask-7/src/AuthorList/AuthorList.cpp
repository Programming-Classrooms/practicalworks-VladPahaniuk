#include "AuthorList.hpp"

/*==========================================================*/
/*====================Конструкторы==========================*/
/*==========================================================*/

// Конструктор по умолчанию
AuthorsList::AuthorsList() {}

// Конструктор копирования
AuthorsList::AuthorsList(const AuthorsList& other) : list(other.list) {}

// Конструктор, принимающий ссылку на std::set<Author>
AuthorsList::AuthorsList(std::set<Author>& authors) : list(authors) {}


/*==========================================================*/
/*=======================Гетеры=============================*/
/*==========================================================*/

// Получение размера списка
  size_t AuthorsList::getSize() const
{
    return list.size();
}

    
/*==========================================================*/
/*==========================================================*/
/*=====================Операторы============================*/
/*==========================================================*/
/*==========================================================*/

// Оператор присваивания
AuthorsList& AuthorsList::operator=(const AuthorsList& other) {
    if (this != &other) {
        list = other.list;
    }
    return *this;
}

// Оператор равенства
bool AuthorsList::operator==(const AuthorsList& other) const {
    return list == other.list;
}

// Ввод из потока
std::ostream& operator<<(std::ostream& out, const AuthorsList& authorsList) {
    for (const auto& author : authorsList.list) {
        out << author << std::endl;
    }
    return out;
}

 // Вывод в поток
std::istream& operator>>(std::istream& in, AuthorsList& authorsList) {
    int numAuthors;
    in >> numAuthors;
    for (int i = 0; i < numAuthors; ++i) {
        Author author;
        in >> author;
        authorsList.addAuthor(author);
    }
    return in;
}

/*================================================================================*/
/*==================================== Методы ====================================*/
/*================================================================================*/

// Добавлние автора
void AuthorsList::addAuthor(const Author& author) {
    list.insert(author);
}

// Удоление автора
void AuthorsList::removeAuthor(const Author& author) {
    list.erase(author);
}

// Проверка на нахождение автора в списке
bool AuthorsList::contains(const Author &author)
{
    return list.find(author) != list.end();
}
