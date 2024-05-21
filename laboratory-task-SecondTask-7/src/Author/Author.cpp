#include "Author.hpp"

Author::Author():surname("null"), firstName("NoName"), patronymic("null")
{}

Author::Author(std::string sname, std::string fname, std::string patronymic) :
surname(sname),
firstName(fname),
patronymic(patronymic)
{}

Author::Author(const Author & rhs) :
surname(rhs.surname),
firstName(rhs.firstName),
patronymic(rhs.patronymic)
{}

Author::~Author()
{}

std::string Author::getSurname() const
{
    return surname;
}

std::string Author::getfirstName() const
{
    return firstName;
}

std::string Author::getPatronymic() const
{
    return patronymic;
}

bool Author::operator<(const Author& other) const {
   if (surname != other.surname) {
        return surname < other.surname;
    } else if (firstName != other.firstName) {
        return firstName < other.firstName;
    } else {
        return patronymic < other.patronymic;
    }
}

std::istream& operator>>(std::istream& in, Author& author) {
    in >> author.surname >> author.firstName >> author.patronymic;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Author& author) {
    out << author.getSurname()<< " " << author.getfirstName()<< " " << author.getPatronymic();
    return out;
}

bool Author::operator==(const Author& other) const {
    return (surname == other.surname) &&
           (firstName == other.firstName) &&
           (patronymic == other.patronymic);
}



