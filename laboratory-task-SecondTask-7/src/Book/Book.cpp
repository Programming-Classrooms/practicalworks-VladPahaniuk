#include "Book.hpp"
#include "Book.hpp"

// Конструктор по умолчанию
Book::Book() : UDC(0), title(""), year(0), authors() {}

// Конструктор с параметрами
Book::Book(size_t udc, const std::string& title, size_t year, const AuthorsList& author)
    : UDC(udc), title(title), year(year), authors(author) {}

// Конструктор копирования
Book::Book(const Book& other)
    : UDC(other.UDC), title(other.title), year(other.year), authors(other.authors) {}

// Геттеры
size_t Book::getUDC() const {
    return UDC;
}

std::string Book::getTitle() const {
    return title;
}

size_t Book::getYear() const {
    return year;
}

AuthorsList Book::getAuthors() const {
    return authors;
}

// Сеттеры
void Book::setUDC(size_t udc) {
    this->UDC = udc;
}

void Book::setTitle(const std::string& title) {
    this->title = title;
}

void Book::setYear(size_t year) {
    this->year = year;
}

void Book::setAuthors(const AuthorsList& author) {
    this->authors = author;
}

// Методы для управления авторами
void Book::addAuthor(const Author& author) {
    authors.addAuthor(author);
}

void Book::removeAuthor(const Author& author) {
    authors.removeAuthor(author);
}


// Оператор сравнения
bool Book::operator<(const Book& other) const {
    return title < other.title;
}

// Оператор вывода
std::ostream& operator<<(std::ostream& out, const Book& book) {
    out << "UDC: " << book.UDC << "\n"
        << "Title: " << book.title << "\n"
        << "Year: " << book.year << "\n"
        << "Authors: " << book.authors;
    return out;
}

// Оператор ввода
std::istream& operator>>(std::istream& in, Book& book) {
    in >> book.UDC;
    in.ignore();  // Игнорировать пробел или символ новой строки
    std::getline(in, book.title);
    in >> book.year;
    AuthorsList authors;
    in >> authors;
    book.setAuthors(authors);
    return in;
}
