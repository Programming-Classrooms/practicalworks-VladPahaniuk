#ifndef SECONDSESSIONSTUDENT_HPP
#define SECONDSESSIONSTUDENT_HPP
#include "src/FirstSessionStudent/FirstSessionStudent.hpp"

class SecondSessionStudent : public FirstSessionStudent {
private:
    size_t* newGrades;
    //Конструктор по умолчанию 
    SecondSessionStudent();
public:

    // Конструктор с параметрами
    SecondSessionStudent(const std::string&, size_t, size_t, const size_t, const size_t*, const size_t*);

    // Конструктор копирования
    SecondSessionStudent(const SecondSessionStudent&);

    // Деструктор
    ~SecondSessionStudent(); 



    // Получение оценок за 2 семестр
    const size_t* getNewGrades() const;

    // Установка оценок за 2 семестр
    void setNewGrades(const size_t*);

    // Вычисление средней оценки за год
    double calculateAverageNewGrades() const;

    // Метод для вывода информации
    void printInfo(std::ostream&) const override;

    // Перегрузка оператора вывода
    friend std::ostream& operator<<(std::ostream& os, const SecondSessionStudent& student);
};
#endif
