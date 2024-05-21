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

    Student(std::string, size_t, size_t);
    ~Student() {}

    bool operator<(const Student& other) const;

    friend std::ostream& operator<<(std::ostream&, const Student&);
};

bool sortByCourseGroup(const Student& a, const Student& b);

void readStudentsFromFile(const std::string& filename, std::vector<Student>& students);
void writeStudentsByFullName(const std::string& filename, const std::vector<Student>& students);
void writeStudentsByCourseGroup(const std::string& filename, const std::vector<Student>& students);
void checkFileInput(std::ifstream &);
void checkFileOutput(std::ofstream &);



#endif /* STUDENTS_HPP */
