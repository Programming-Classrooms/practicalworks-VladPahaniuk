#ifndef LIBRARY
#define LIBRARY
#include<set>
#include<iterator>
#include<algorithm>
#include<functional>
#include<fstream>
#include <sstream>
#include"../Book/Book.hpp"



class Library {
private:
    std::set<Book> books;

public:

    Library() = default;
    Library(const Library&);
    ~Library() = default;

    void addBook(const Book&);
    void removeBook(const Book&);
    Book* findBookByTitle(const std::string&);
    std::set<Book> findBooksByAuthor(const Author&);
    void addAuthorToBook(const std::string&, const Author&);
    void removeAuthorFromBook(const std::string&, const Author&);
    

    friend std::ostream& operator<<(std::ostream&, const Library&);
    void loadFromFile(const std::string&);

};

void checkFileInput(std::ifstream &);

#endif // LIBRARY_HPP
