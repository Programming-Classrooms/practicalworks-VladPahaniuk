#include "../Function/Function.hpp"

MyString::MyString()
{
  str = nullptr;
  length = 0;
}

MyString::MyString(const char* str)
{

  length = strlen(str);
  this->str = new char[length + 1]; //для 0-терминатора используем +1;

  for (size_t i = 0; i < length; i++)
  {
    this->str[i] = str[i];
  }

  this->str[length] = '\0';//закрытие строки 0-терм.
} 

MyString::~MyString() 
{
  delete[] this->str;
}

std::ostream& MyString::Print(std::ostream& os) const
{
  return os << str;
}

// нет функции
std::ostream& operator << (std::ostream& os, const MyString& str) {
  return str.Print(os);
} 
// Конструктор копирования. Нужен для создания точной копиии объекта в другой области памяти 
//MyString::MyString(const MyString& other)
//{
//  length = strlen(other.str);
//  this->str = new char[length + 1]; //для 0-терминатора;
//
//  for (size_t i = 0; i < length; i++)
//  {
//    this->str[i] = other.str[i];
//  }
//
//  this->str[length] = '\0';
//}

MyString& MyString::operator =(const MyString& other) {
  if (this->str != nullptr) {
    delete[] str;
  }
  length = strlen(other.str);
  this->str = new char[length + 1]; //для 0-терминатора;

  for (size_t i = 0; i < length; i++)
  {
    this->str[i] = other.str[i];
  }

  this->str[length] = '\0';
  return *this;
}

MyString MyString::operator+(const MyString& other)
{
  MyString newStr;
  size_t thisLength = strlen(this->str);
  size_t otherLength = strlen(other.str);
  newStr.length = thisLength + otherLength;
  newStr.str = new char[thisLength + otherLength + 1];
  size_t i = 0;
  for (; i < thisLength; i++)
  {
    newStr.str[i] = this->str[i];
  }
  for (size_t j = 0; j < otherLength; j++, i++)
  {
    newStr.str[i] = other.str[j];
  }
  newStr.str[thisLength + otherLength] = '\0';
  return newStr;
}

size_t MyString::Length() const
{
  return length;
}

bool MyString::operator ==(const MyString& other) 
{
  if (this->length != other.length) {
    return false;
  }
  for (size_t i = 0; i < this->length; i++)
  {
    if (this->str[i] != other.str[i]) {
      return false;
    }
  }
  return true;
}

bool MyString::operator !=(const MyString& other) {
  return !(this->operator==(other));
}

char& MyString::operator[](size_t index)
{
  return this->str[index];
}

// MyString::MyString( MyString &&other)
//{
//   this->length = other.length;
//   this->str = other.str;
//   other.str = nullptr;// запрет на стирание данных
//}

//  std::istream& operator>>(std::istream& input, MyString& s) {
//   input >> s.str;
//   return input;
// }
