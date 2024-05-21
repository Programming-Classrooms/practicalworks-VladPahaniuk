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

    Book();
    Book(size_t, const std::string&, size_t, const AuthorsList&);
    Book(const Book&);
    ~Book() = default;

    size_t getUDC() const;
    std::string getTitle() const;
    size_t getYear() const;
    AuthorsList getAuthors() const;

    void setUDC(size_t);
    void setTitle(const std::string&);
    void setYear(size_t);
    void setAuthors(const AuthorsList&);

    void addAuthor(const Author&);

    void removeAuthor(const Author&);
    
    bool operator<(const Book&) const;
    friend std::ostream& operator<<(std::ostream&, const Book&);
    friend std::istream& operator>>(std::istream&, Book&);

};

#endif // BOOK_HPP

