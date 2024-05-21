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

    AuthorsList();

    AuthorsList(const AuthorsList&);

    AuthorsList(std::set<Author>&);

    ~AuthorsList() = default;

    void addAuthor(const Author& author);
    void removeAuthor(const Author& author);

    friend std::ostream& operator<<(std::ostream&, const AuthorsList&);
    friend std::istream& operator>>(std::istream&, AuthorsList&);

    bool operator==(const AuthorsList&) const;
    AuthorsList& operator=(const AuthorsList&);

    bool contains(const Author& author);
};


#endif 