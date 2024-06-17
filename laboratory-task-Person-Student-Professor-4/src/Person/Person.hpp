#ifndef PERSON_HPP
#define PERSON_HPP
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <exception>

class Person {
protected:
    char* fullName;

public:
    // Конструтор с параметрами
    Person(const char*);

    // Деструктор
    virtual ~Person();

    // Получение ФИО
    const char* getFullName() const;

    // Установка ФИО
    void setFullName(const char*);
    
    // Вывод
    virtual void print() const;
};

#endif
