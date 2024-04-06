#include "FirstSessionStudent.hpp"

/*================================================================================*/
/*=========================== Конструкторы и Деструктор ==========================*/
/*================================================================================*/

// Конструктор с параметрами
FirstSessionStudent::FirstSessionStudent(const std::string& name, size_t course, size_t group, const size_t recordBookNumber, const size_t* grades)
    : Student(name, course, group, recordBookNumber), firstSessionGrades(new size_t[4]) {
    for (size_t i = 0; i < 4; ++i) {
        this->firstSessionGrades[i] = grades[i];
    }
}

// Конструктор копирования
FirstSessionStudent::FirstSessionStudent(const FirstSessionStudent& other):Student(other), firstSessionGrades(new size_t[4]){
        for (int i = 0; i < 4; i++) {
            firstSessionGrades[i] = other.firstSessionGrades[i];
        }
}

// Деструктор
FirstSessionStudent::~FirstSessionStudent()
{
    delete[] firstSessionGrades;
}

/*================================================================================*/


/*================================================================================*/
/*==================================== Гетеры ====================================*/
/*================================================================================*/

// Получение оценок 
const size_t* FirstSessionStudent::getGrades() const {
    return firstSessionGrades;
}

/*================================================================================*/


/*================================================================================*/
/*==================================== Сетеры ====================================*/
/*================================================================================*/

// Установка оценок
void FirstSessionStudent::setGrades(const size_t* grades) {
    for (size_t i = 0; i < 4; ++i) {
        this->firstSessionGrades[i] = grades[i];
    }
}

/*================================================================================*/


/*================================================================================*/
/*================================== Доп. метод ==================================*/
/*================================================================================*/

// Вычисление средней оценки за 1 семестр
double FirstSessionStudent::calculateAverageGrade() const {
    double sum = std::accumulate(firstSessionGrades, firstSessionGrades + 4, 0.0);
    return sum / 4.0;
}

/*================================================================================*/


/*================================================================================*/
/*================== Метод для выывода + перегрузка оператора << =================*/
/*================================================================================*/

// Метод для вывода информации
void FirstSessionStudent::printInfo(std::ostream& os) const
{
    Student::printInfo(os);
    os << "\nGrades: ";
    for (size_t i = 0; i < 4; ++i) {
        os << firstSessionGrades[i] << " ";
    }
    os << "\nAverage Grade: " << calculateAverageGrade() << std::endl;
}

// Перегрузка оператора вывода для класса FirstSessionStudent
std::ostream& operator<<(std::ostream& os, const FirstSessionStudent& student) {
    student.printInfo(os);
    return os;
}
/*================================================================================*/