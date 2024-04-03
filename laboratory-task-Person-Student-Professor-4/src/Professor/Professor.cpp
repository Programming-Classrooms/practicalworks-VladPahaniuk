#include "Professor.hpp"
    
// Конструтор с параметрами
Professor::Professor(const char* name, const char* dep) : Person(name) {
    department = new char[strlen(dep) + 1];
    strcpy(department, dep);
}

// Деструктор
Professor::~Professor() {
    delete[] department;
}

// Полученние кафедры преподавателя
const char* Professor::getDepartment() const {
    return department;
}

// Установка кафедры преподавателя
void Professor::setDepartment(const char* dep) {
    delete[] department;
    department = new char[strlen(dep) + 1];
    strcpy(department, dep);
}

// Вывод
void Professor::print() const {
    std::cout << "Преподаватель: " << getFullName() << ", Кафедра: " << department << std::endl;
}