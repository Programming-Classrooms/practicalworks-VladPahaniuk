#include "src/List/List.hpp"
void printElement(const size_t& value) {
  std::cout << value << " ";
}
int main() {
  try
  {
    List<Student> studentList;
    Student student1{ "Padro", {4, 4, 4, 5, 6}, 1001 };
    Student student2{ "Pedro", {10, 2, 3, 4, 7}, 1002 };
    Student student3{ "ElRoky", {4, 10, 10, 10, 10}, 1003 };
    Student student4{ "ElPoco", {3, 5, 7, 8, 10}, 1004 };

    studentList.push_back(student2);
    studentList.push_back(student3);
    studentList.push_back(student4);
    studentList.push_front(student1);
    studentList.push_front(student1);
    studentList.push_back(student1);
    studentList.push_back(student1);
    studentList.pop_back();
    studentList.pop_front();

    // Содержимое списка студентов
    std::cout << "Students in the list:" << std::endl;
    for (size_t i = 0; i < studentList.getSize(); ++i) {
      const Student& student = studentList[i];
      std::cout << "Student ID: " << student.studentID << ", Last Name: " << student.lastName << std::endl;
      std::cout << "Grades:";
      for (size_t grade : student.grades) {
        std::cout << " " << grade;
      }
      std::cout << std::endl;
    }

    // Удаление элемента по значению (student2)
    studentList.removeByValue(student2);

    // Поиск элемента по значению (student1)
    std::cout << "Number of comparisons to find student1: " << studentList.searchWithValue(student1) << std::endl;

    // Использование callback-функции для вывода номеров зачетных книжек студентов
    std::cout << "Student IDs in the list:";
    studentList.forEach([](const Student& student) {
      std::cout << " " << student.studentID;
      });
    std::cout << std::endl;

  }
  catch (const std::out_of_range& error)
  {
    std::cerr << "Exception: " << error.what() << std::endl;
  }
  return 0;
}
