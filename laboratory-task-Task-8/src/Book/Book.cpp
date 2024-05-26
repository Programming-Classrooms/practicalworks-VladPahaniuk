#include "Book.hpp"


/*==========================================================*/
/*====================Конструкторы==========================*/
/*==========================================================*/

// Конструктор с параметрами
Book::Book(const std::string& isbn,
           const std::string& title,
           const std::vector<std::string>& authors,
           double price, size_t count)
{
    setISBN(isbn);
    setTitle(title);
    setAuthors(authors);
    setPrice(price);
    setCount(count);
}

// Конструктор копирования
Book::Book(const Book &other) :
    ISBN(other.ISBN),
    title(other.title),
    authors(other.authors),
    price(other.price),
    count(other.count)
{}

std::string Book::getISBN() const {
    return ISBN;
}

std::string Book::getTitle() const {
    return title;
}

std::vector<std::string> Book::getAuthors() const {
    return authors;
}

double Book::getPrice() const {
    return price;
}

size_t Book::getCount() const {
    return count;
}
void Book::setISBN(const std::string& isbn) {
    ISBN = isbn;
}

void Book::setPrice(double price) {

     if (price < 0.0) {
            throw std::invalid_argument("Цена не может быть отрицательной ...");
        }
    this->price = price;
}

void Book::setCount(size_t count) {
    
     if (count < 0 ) {
            throw std::invalid_argument("Количество не может быть отрицательным...");
        }
    this->count = count;
}

void Book::setTitle(const std::string &title)
{
     if (title.length() < 1 || title.length() > 100) {
            throw std::invalid_argument("Заголовок должен быть длиной от 1 до 100 символов.");
        }
        this->title = title;
}

// Установка авторов
void Book::setAuthors(const std::vector<std::string>& authors)
{
      if (authors.size() < 1 ) {
            throw std::invalid_argument("Список авторов не должен быть пустым.");
        }
        this->authors = authors;
}

void Book::addAuthor(const std::string& author) {
    authors.push_back(author);
}

void Book::removeAuthor(const std::string& author) {
    auto it = std::find(authors.begin(), authors.end(), author);
    if (it != authors.end()) {
        authors.erase(it);
    }
}
    