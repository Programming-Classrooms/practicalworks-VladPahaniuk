#include "src/Student/Student.hpp"

int main()
{
	try
	{
		std::vector<Student> students;
		readStudentsFromFile("src/files/Student.txt", students);
		writeStudentsByFullName("src/files/Fio.txt", students);
		writeStudentsByCourseGroup("src/files/Groups.txt", students);
	}
	catch (const std::invalid_argument &error)
	{
		std::cerr << error.what() << '\n';
	}
	catch (const std::ios_base::failure &error)
	{
		std::cerr << error.what() << '\n';
	}
	catch (const std::runtime_error &error)
	{
		std::cerr << error.what() << '\n';
	}

	return 0;
}