#ifndef STUDENT_HPP
#define STUDENT_HPP
#include "src/Person/Person.hpp"

class Student : public Person {
private:
    size_t course;
    size_t group;
public:
    // Конструтор с параметрами
    Student(const char*, size_t, size_t);

    // Получение курса студента
    size_t getCourse() const;
    
    // Установка курса студента
    void setCourse(size_t );

    // Получение группы студента
    size_t getGroup() const;
    
    // Установка группы студента
    void setGroup(size_t );

    // Вывод
    void print() const override;
};

#endif
