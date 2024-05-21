#ifndef AUTHOR_HPP
#define AUTHOR_HPP

#include <iostream>
#include <string>

class Author
{
protected:

	std::string surname;
	std::string firstName;
	std::string patronymic;

public:

	Author();
	Author(std::string, std::string, std::string);
	Author(const Author&);
	~Author();

	std::string getSurname() const;
	std::string getfirstName() const;
	std::string getPatronymic() const;

	bool  operator<(const Author&) const;
	friend std::istream& operator>>(std::istream&, Author&);
	friend std::ostream& operator<<(std::ostream&, const Author&);
	bool operator==(const Author&) const;


};

#endif
