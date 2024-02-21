#ifndef FUNCTION_HPP
#define FUNCTION_HPP
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>


class MyString
{
public:
  MyString();
  MyString(const char*);
  ~MyString();
  size_t Length() const;
  std::ostream& Print(std::ostream&) const;
  friend std::ostream& operator << (std::ostream&, const MyString&); // нет функции
  //MyString(const MyString&);
  MyString& operator =(const MyString&);
  MyString operator +(const MyString&);
  bool operator ==(const MyString&);
  bool operator !=(const MyString&);
  char& operator [](size_t);
  //MyString(MyString&&);//конструктор перемещения
  //friend std::istream& operator>>(std::istream&, MyString&);
private:
  char* str;
  size_t length;

};
#endif
