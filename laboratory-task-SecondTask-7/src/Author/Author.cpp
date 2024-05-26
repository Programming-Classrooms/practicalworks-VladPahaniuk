#include "Author.hpp"

/*==========================================================*/
/*====================Конструкторы==========================*/
/*==========================================================*/

// Конструктор по умолчанию
Author::Author():surname("null"), firstName("NoName"), patronymic("null")
{}

// Конструктор c параметрами
Author::Author(std::string sname, std::string fname, std::string patronymic) :
surname(sname),
firstName(fname),
patronymic(patronymic)
{}

// Конструктор копирования
Author::Author(const Author & rhs) :
surname(rhs.surname),
firstName(rhs.firstName),
patronymic(rhs.patronymic)
{}

// Деструктор
Author::~Author()
{}


/*==========================================================*/
/*=======================Гетеры=============================*/
/*==========================================================*/

// Получение фамилии
std::string Author::getSurname() const
{
    return surname;
}

// Полученик имени
std::string Author::getfirstName() const
{
    return firstName;
}

// Полученик отчества
std::string Author::getPatronymic() const
{
    return patronymic;
}



/*==========================================================*/
/*==========================================================*/
/*=====================Операторы============================*/
/*==========================================================*/
/*==========================================================*/

// Оператор меньше
bool Author::operator<(const Author& other) const {
   if (surname != other.surname) {
        return surname < other.surname;
    } else if (firstName != other.firstName) {
        return firstName < other.firstName;
    } else {
        return patronymic < other.patronymic;
    }
}

// Оператор равенства
bool Author::operator==(const Author& other) const {
    return (surname == other.surname) &&
           (firstName == other.firstName) &&
           (patronymic == other.patronymic);
}

// Ввод из потока
std::istream& operator>>(std::istream& in, Author& author) {
    in >> author.surname >> author.firstName >> author.patronymic;
    return in;
}

// Вывод в поток
std::ostream& operator<<(std::ostream& out, const Author& author) {
    out << author.getSurname()<< " " << author.getfirstName()<< " " << author.getPatronymic();
    return out;
}

