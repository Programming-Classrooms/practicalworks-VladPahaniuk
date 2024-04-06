#include "SecondSessionStudent.hpp"

/*================================================================================*/
/*=========================== Конструкторы и Деструктор ==========================*/
/*================================================================================*/

// Конструктор с параметрами
SecondSessionStudent::SecondSessionStudent(const std::string& name, size_t course, size_t group, const size_t recordBookNumber, const size_t* grades, const size_t* newGrades)
    : FirstSessionStudent(name, course, group, recordBookNumber, grades), newGrades(new size_t[5]) {

    for (size_t i = 0; i < 5; i++)
    {
        this->newGrades[i] = newGrades[i];
    }
}

// Конструктор копирования
SecondSessionStudent::SecondSessionStudent(const SecondSessionStudent& other)
    :FirstSessionStudent(other), newGrades(new size_t [5]) {

    for (size_t i = 0; i < 5; i++) {
        this->newGrades[i] = other.newGrades[i]; 
    }

}

// Деструктор
SecondSessionStudent::~SecondSessionStudent()
{
    delete[] newGrades;
}

/*================================================================================*/


/*================================================================================*/
/*==================================== Гетеры ====================================*/
/*================================================================================*/

// Получения оценок за 2 семестр 
const size_t* SecondSessionStudent::getNewGrades() const {
    return newGrades;
}

/*================================================================================*/


/*================================================================================*/
/*==================================== Сетеры ====================================*/
/*================================================================================*/

// Установка оценок за 2 семестр
void SecondSessionStudent::setNewGrades(const size_t* newGrades) {
    for (size_t i = 0; i < 5; ++i) {
        this->newGrades[i] = newGrades[i];
    }
}

/*================================================================================*/


/*================================================================================*/
/*================================== Доп. метод ==================================*/
/*================================================================================*/

// Вычисление средней оценки за год
double SecondSessionStudent::calculateAverageNewGrades() const
{
    double sumFirst = std::accumulate(firstSessionGrades, firstSessionGrades + 4, 0.0);
    double sumSecond = std::accumulate(newGrades, newGrades + 5, 0.0);
    return (sumFirst + sumSecond) / 9.0;
}

/*================================================================================*/


/*================================================================================*/
/*================== Метод для выывода + перегрузка оператора << =================*/
/*================================================================================*/

// Метод для вывода информации
void SecondSessionStudent::printInfo(std::ostream& os) const
{
    FirstSessionStudent::printInfo(os);

    os << "\nNew grades: ";
    for (size_t i = 0; i < 5; ++i) {
        os << newGrades[i] << " ";
    }
    os << "\nAverage Grade for the year: " << calculateAverageNewGrades() << std::endl;

}

// Перегрузка оператора вывода для класса SecondSessionStudent
std::ostream& operator<<(std::ostream& os, const SecondSessionStudent& student) {
    student.printInfo(os);
    return os;
}

/*================================================================================*/