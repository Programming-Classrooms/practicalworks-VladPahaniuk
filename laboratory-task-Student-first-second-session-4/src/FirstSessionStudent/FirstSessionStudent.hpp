#ifndef FIRSTSESSIONSTUDENT_HPP
#define FIRSTSESSIONSTUDENT_HPP

#include "src/Student/Student.hpp"

class FirstSessionStudent : public Student {
protected:
    size_t *firstSessionGrades; 
public:

    // Конструктор по умолчанию
    FirstSessionStudent() = delete;

    // Конструктор с параметрами
    FirstSessionStudent(const std::string&, size_t, size_t, const size_t, const size_t*);

    // Конструктор копирования
    FirstSessionStudent(const FirstSessionStudent& other); 

    // Деструктор
    ~FirstSessionStudent();


    // Получение оценок
    const size_t* getGrades() const;

    // Установка оценок
    void setGrades(const size_t*);

    // Вычисление средней оценки
    double calculateAverageGrade() const;

    // Метод для вывода информации
    void printInfo(std::ostream&) const override;

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream&, const FirstSessionStudent&);
};

#endif

