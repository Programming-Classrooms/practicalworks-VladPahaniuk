#include "Library.hpp"
#include <algorithm>

/*================================================================================*/
/*==================================== Методы ====================================*/
/*================================================================================*/

// Добавление книги
void Library::addBook(const Book& book) {
    books.push_back(book);
}

// Поиск книги по ISBN
Book* Library::findBook(const std::string& isbn) {
    auto it = std::find_if(books.begin(), books.end(), [&isbn](const Book& book) {
        return book.getISBN() == isbn;
    });
    if (it != books.end()) {
        return &(*it);
    }
    return nullptr;
}

// Удаление книги по ISBN
bool Library::removeBook(const std::string& isbn) {
    auto it = std::remove_if(books.begin(), books.end(), [&isbn](const Book& book) {
        return book.getISBN() == isbn;
    });
    if (it != books.end()) {
        books.erase(it, books.end());
        return true;
    }
    return false;
}

// Просмотр списка книг
std::vector<Book> Library::viewBooks() const {
    return books;
}

// Добавление автора по ISBN книги
void Library::addAuthor(const std::string& isbn, const std::string& author) {
    Book* book = findBook(isbn);
    if (book) {
        book->addAuthor(author);
    }
}

// Удаление автора по ISBN книги
void Library::removeAuthor(const std::string& isbn, const std::string& author) {
    Book* book = findBook(isbn);
    if (book) {
        book->removeAuthor(author);
    }
}

// Сортировка списка книг по ISBN
void Library::sortBooksByISBN() {
    std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.getISBN() < b.getISBN();
    });
}

// Сортировка списка книг по названию
void Library::sortBooksByTitle() {
    std::sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.getTitle() < b.getTitle();
    });
}
