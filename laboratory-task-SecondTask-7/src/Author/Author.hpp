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

	// Конструктор по умолчанию
	Author();

	// Конструктор c параметрами
	Author(std::string, std::string, std::string);

	// Конструктор копирования
	Author(const Author&);

	// Деструктор
	~Author();

	// Получение фамилии
	std::string getSurname() const;

	// Полученик имени
	std::string getfirstName() const;

	// Полученик отчества
	std::string getPatronymic() const;

	// Установка фамилии
	void setSurname(const std::string& sname);

	// Установка имени
	void setFirstName(const std::string&);
	
	// Установка отчества
    void setPatronymic(const std::string& отчества);

	// Оператор меньше
	bool  operator<(const Author&) const;

	// Оператор равенства
	bool operator==(const Author&) const;

	// Ввод из потока
	friend std::istream& operator>>(std::istream&, Author&);

	// Вывод в поток
	friend std::ostream& operator<<(std::ostream&, const Author&);


};

#endif
