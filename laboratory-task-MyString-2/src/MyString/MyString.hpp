#ifndef MYSTRING_HPP
#define MYSTRING_HPP
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>


class MyString
{
private:
  char* str;
  size_t length;
public:
  // Конструкторы
  MyString();
  MyString(const char*);
  MyString(const MyString&);

  // Деструкторы
  ~MyString();

  // Гетеры
  char* getString() const;
  size_t getLength() const;

  // Бинарные операторы
  MyString& operator =(const MyString&);
  MyString operator +(const MyString&);
  MyString& operator+=(const MyString&);

  // Логические операторы
  bool operator==(const MyString&) const;
  bool operator!=(const MyString&) const;
  bool operator<(const MyString&) const;
  bool operator>(const MyString&) const;

  // Поточные операторы
  std::ostream& Print(std::ostream&) const;
  friend std::ostream& operator<<(std::ostream&, const MyString&);
  friend std::istream& operator>>(std::istream&, MyString&);
  
  // operatot[](Замена символа)
  char& operator[](size_t);

};
#endif

