#include "AuthorList.hpp"

AuthorsList::AuthorsList() {}

AuthorsList::AuthorsList(const AuthorsList& other) : list(other.list) {}

AuthorsList::AuthorsList(std::set<Author>& authors) : list(authors) {}

void AuthorsList::addAuthor(const Author& author) {
    list.insert(author);
}

void AuthorsList::removeAuthor(const Author& author) {
    list.erase(author);
}

std::ostream& operator<<(std::ostream& out, const AuthorsList& authorsList) {
    for (const auto& author : authorsList.list) {
        out << author << std::endl;
    }
    return out;
}

bool AuthorsList::operator==(const AuthorsList& other) const {
    return list == other.list;
}

AuthorsList& AuthorsList::operator=(const AuthorsList& other) {
    if (this != &other) {
        list = other.list;
    }
    return *this;
}

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
bool AuthorsList::contains(const Author &author)
{
    return list.find(author) != list.end();

}
