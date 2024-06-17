#include "Person.hpp"

// Конструтор с параметрами
Person::Person(const char* name) {
    fullName = new char[strlen(name) + 1];
    strcpy(fullName, name);
}

// Деструктор
Person::~Person() {
    delete[] fullName;
}

// Получение ФИО
const char* Person::getFullName() const {
    return fullName;
}

// Установка ФИО
void Person::setFullName(const char* name) {
    delete[] fullName;
    fullName = new char[strlen(name) + 1];
    strcpy(fullName, name);
}

// Вывод
void Person::print() const {
    std::cout << "ФИО: " << fullName << std::endl;
}
