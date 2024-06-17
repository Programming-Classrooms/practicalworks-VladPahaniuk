#include "Student.hpp"

// счетчик для подсчета  ID
size_t Student::counter = 0;

/*================================================================================*/
/*=========================== Конструкторы и Деструктор ==========================*/
/*================================================================================*/

// Конструктор с параметрами
Student::Student(const std::string& name, size_t course, size_t group, const size_t recordBookNumber)
    : id(++counter), name(name), course(course), group(group), recordBookNumber(recordBookNumber) {}

// Конструктор копирования
Student::Student(const Student& other) : id(++counter), name(other.name), course(other.course), group(other.group), recordBookNumber(other.recordBookNumber) {}

// Деструктор
Student::~Student()
{}

/*================================================================================*/


/*================================================================================*/
/*==================================== Гетеры ====================================*/
/*================================================================================*/

// Получение имени
std::string Student::getName() const {
    return name;
}

// Получение ID
size_t Student::getId() const {
    return id;
}

// Получение курса
size_t Student::getCourse() const {
    return course;
}

// Получение группы
size_t Student::getGroup() const {
    return group;
}

// Получение номера зачетной книжки
size_t Student::getRecordBookNumber() const {
    return recordBookNumber;
}

/*================================================================================*/


/*================================================================================*/
/*==================================== Сетеры ====================================*/
/*================================================================================*/

// Установка имени
void Student::setName(const std::string& name) {
    this->name = name;
}

// Устаноака курса
void Student::setCourse(size_t course)
{
    this->course = course;
}
 
// Установка группы
void Student::setGroup(size_t group)
{
    this->group = group;
}

/*================================================================================*/


/*================================================================================*/
/*================== Метод для выывода + перегрузка оператора << =================*/
/*================================================================================*/

// Виртуальный метод для получение информации
void Student::printInfo(std::ostream& os) const
{
    os << "ID: " << id << "\nName: " << name << "\nCourse: " << course << "\nGroup: " << group << "\nRecord Book Number: " << recordBookNumber;
}

// Перегрузка оператора вывода
std::ostream& operator<<(std::ostream& os, const Student& student) {
    student.printInfo(os);
    return os;
}

/*================================================================================*/
