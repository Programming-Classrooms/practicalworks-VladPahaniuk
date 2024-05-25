#include "Student.hpp"

// Функция для проверки файла (чтения)
void checkFileInput(std::ifstream &file)
{
    if (!file.good())
    {
        throw std::invalid_argument("File does not exist!");
    }

    if (!file)
    {
        throw std::ios_base::failure("File is not opened!");
    }

    if (file.peek() == EOF)
    {
        throw std::runtime_error("File is empty!");
    }
}

// Функция для проверки файла (записи)
void checkFileOutput(std::ofstream &file)
{
    if (!file.good())
    {
        throw std::invalid_argument("File does not exist!");
    }

    if (!file)
    {
        throw std::ios_base::failure("File is not opened!");
    }
}


// Конструктор c параметрами
Student::Student(std::string fullName, size_t course, size_t group) : fullName(fullName), course(course), group(group)
{
    if (course <= 0)
    {
        throw std::invalid_argument("Wrong course...");
    }

    this->course = course;

    if (group <= 0)
    {
        throw std::invalid_argument("Wrong group...");
    }
    
    this->group = group;
}

// Перегрузка оператор меньше
bool Student::operator<(const Student &other) const
{
    return fullName < other.fullName;
}

// Вывод в поток
std::ostream &operator<<(std::ostream &os, const Student &student)
{
    os << student.fullName << " " << student.course << " " << student.group << "\n";
}

// Функция для сортировки по курсам и группам
bool sortByCourseGroup(const Student &a, const Student &b)
{
    if (a.course == b.course)
    {
        if (a.group == b.group)
        {
            return a.fullName < b.fullName;
        }
        return a.group < b.group;
    }
    return a.course < b.course;
}

// Функция для чтения из файла
void readStudentsFromFile(const std::string &filename, std::vector<Student> &students)
{
    std::ifstream inputFile(filename);
    checkFileInput(inputFile);

    std::string fullName;
    size_t course = 0, group = 0;

    while (inputFile >> fullName >> course >> group)
    {
        students.push_back({fullName, course, group});
    }

    inputFile.close();
}

// Функция для записи студентов, упорядоченных по  алфавиту
void writeStudentsByFullName(const std::string &filename, const std::vector<Student> &students)
{
    std::vector<Student> sortedStudents = students;
    std::sort(sortedStudents.begin(), sortedStudents.end());

    std::ofstream outputFile(filename);
    checkFileOutput(outputFile);

    for (const auto &student : sortedStudents)
    {
        outputFile << student.fullName << " " << student.course << " " << student.group << "\n";
    }

    outputFile.close();
}

// Функция для записи студентов, упорядоченных по курсам и группам
void writeStudentsByCourseGroup(const std::string &filename, const std::vector<Student> &students)
{
    std::vector<Student> sortedStudents = students;
    std::sort(sortedStudents.begin(), sortedStudents.end(), sortByCourseGroup);

    std::ofstream outputFile(filename);
    checkFileOutput(outputFile);

    for (const auto &student : sortedStudents)
    {
        outputFile << student.fullName << " " << student.course << " " << student.group << "\n";
    }

    outputFile.close();
}