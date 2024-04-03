#ifndef PROFESSOR_HPP
#define PROFESSOR_HPP
#include "src/Person/Person.hpp"

class Professor : public Person {
private:
    char* department;

public:
    // Конструтор с параметрами
    Professor(const char*, const char*);

    // Деструктор
    ~Professor() override;

    // Получение кафедры преподавателя
    const char* getDepartment() const;

    // Установка кафедры преподавателя
    void setDepartment(const char*);
    
    // Вывод
    void print() const override;
};
#endif
