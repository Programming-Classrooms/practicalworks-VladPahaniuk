#ifndef STUDENT_HPP
#define STUDENT_HPP
#include <string>
#include <iostream>
#include <numeric>

class Student {
protected:
    const size_t id; 
    std::string name;
    size_t course;
    size_t group;
    const size_t recordBookNumber; 
    static size_t counter;
public:

    // Конструктор по умолчанию
    Student() = delete;

    // Конструктор с параметрами
    Student(const std::string&, size_t, size_t, const size_t);

    // Конструктор копирования
    Student(const Student&);

    // Деструктор
    ~Student();



    // Получение имени
    std::string getName() const;

    // Получение ID
    size_t getId() const;

    // Получение курса
    size_t getCourse() const;

    // Получение группы
    size_t getGroup() const;

    // Получение номера зачетной книжки
    size_t getRecordBookNumber() const;



    // Установка имени
    void setName(const std::string&);

    // Устаноака курса
    void setCourse(size_t);

    // Установка группы
    void setGroup(size_t);



    // Виртуальный метод для вывода информации
    virtual void printInfo(std::ostream&) const;

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream&, const Student&);
};
#endif
