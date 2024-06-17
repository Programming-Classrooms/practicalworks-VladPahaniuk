#include "Student.hpp"
// Конструтор с параметрами
Student::Student(const char* name, size_t course, size_t group) : Person(name), course(course), group(group) {}

// Получение курса студента
size_t Student::getCourse() const {
    return course;
}

// Установка курса студента
void Student::setCourse(size_t course) {
    this->course = course;
}

// Получение группы студента
size_t Student::getGroup() const {
    return group;
}

// Установка группы студента
void Student::setGroup(size_t group) {
    this->group = group;
}

// Вывод
void Student::print() const {
    std::cout << "Студент: " << getFullName() << ", Курс: " << course << ", Группа: " << group << std::endl;
}