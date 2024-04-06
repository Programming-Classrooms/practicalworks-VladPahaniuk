#include "src/FirstSessionStudent/FirstSessionStudent.hpp"
#include "src/SecondSessionStudent/SecondSessionStudent.hpp"
#include "src/Student/Student.hpp"
int main()
{
	size_t firstGrades[] = {10, 7, 8, 10};
	size_t secondGrades[] = {10, 10, 9, 10, 9};
	Student student("Jonson", 1, 7127, 1003);
	FirstSessionStudent firstSessionStudent("Padre", 1, 7127, 1004, firstGrades);
	SecondSessionStudent secondSessionStudent("Padre", 1, 7127, 1004, firstGrades, secondGrades);

	std::cout << "Student:\n"<< student << "\n\n";
	std::cout << "First Session Student:\n" << firstSessionStudent << "\n\n";
	std::cout << "Second Session Student:\n" << secondSessionStudent << "\n\n";
	return 0;
}
