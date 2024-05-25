#ifndef STUDENTS_HPP
#define STUDENTS_HPP

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <exception>

struct Student {
    
    std::string fullName;
    size_t course;
    size_t group;

    // Конструктор c параметрами
    Student(std::string, size_t, size_t);

    // Деструктор
    ~Student() {}

    // Перегрузка оператор меньше
    bool operator<(const Student& other) const;

    // Вывод в поток
    friend std::ostream& operator<<(std::ostream&, const Student&);
};

// Функция для сортировки по курсам и группам
bool sortByCourseGroup(const Student&, const Student&);

// Функция для чтения из файла
void readStudentsFromFile(const std::string&, std::vector<Student>&);

// Функция для записи студентов, упорядоченных по  алфавиту
void writeStudentsByFullName(const std::string&, const std::vector<Student>&);

// Функция для записи студентов, упорядоченных по курсам и группам
void writeStudentsByCourseGroup(const std::string&, const std::vector<Student>&);

// Функция для проверки файла (чтения)
void checkFileInput(std::ifstream &);

// Функция для проверки файла (записи)
void checkFileOutput(std::ofstream &);

#endif /* STUDENTS_HPP */
