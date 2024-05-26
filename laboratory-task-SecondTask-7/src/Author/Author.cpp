#include "Author.hpp"

/*==========================================================*/
/*====================Конструкторы==========================*/
/*==========================================================*/

// Конструктор по умолчанию
Author::Author() : surname("null"), firstName("NoName"), patronymic("null")
{}

// Конструктор c параметрами
Author::Author(std::string sname, std::string fname, std::string patronymic) : surname(sname),
                                                                               firstName(fname),
                                                                               patronymic(patronymic)
{}

// Конструктор копирования
Author::Author(const Author &rhs) : surname(rhs.surname),
                                    firstName(rhs.firstName),
                                    patronymic(rhs.patronymic)
{}

// Деструктор
Author::~Author()
{
}


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
/*=======================Cетеры=============================*/
/*==========================================================*/

// Установка фамилии
void Author::setSurname(const std::string &sname)
{
    if (sname.length() < 2 || sname.length() > 50)
    {
        throw std::invalid_argument("Фамилия должна быть длиной от 2 до 50 символов.");
    }
    surname = sname;
}

// Установка имени
void Author::setFirstName(const std::string &fname)
{
    if (fname.length() < 2 || fname.length() > 50)
    {
        throw std::invalid_argument("Имя должно быть длиной от 2 до 50 символов.");
    }
    firstName = fname;
}

// Установка имени
void Author::setPatronymic(const std::string &patronymic)
{
    if (patronymic.length() < 2 || patronymic.length() > 50)
    {
        throw std::invalid_argument("Отчество должно быть длиной от 2 до 50 символов.");
    }
    this->patronymic = patronymic;
}


/*==========================================================*/
/*==========================================================*/
/*=====================Операторы============================*/
/*==========================================================*/
/*==========================================================*/

// Оператор меньше
bool Author::operator<(const Author &other) const
{
    if (surname != other.surname)
    {
        return surname < other.surname;
    }
    else if (firstName != other.firstName)
    {
        return firstName < other.firstName;
    }
    else
    {
        return patronymic < other.patronymic;
    }
}

// Оператор равенства
bool Author::operator==(const Author &other) const
{
    return (surname == other.surname) &&
           (firstName == other.firstName) &&
           (patronymic == other.patronymic);
}

// Ввод из потока
std::istream &operator>>(std::istream &in, Author &author)
{
    in >> author.surname >> author.firstName >> author.patronymic;
    return in;
}

// Вывод в поток
std::ostream &operator<<(std::ostream &out, const Author &author)
{
    out << author.getSurname() << " " << author.getfirstName() << " " << author.getPatronymic();
    return out;
}
