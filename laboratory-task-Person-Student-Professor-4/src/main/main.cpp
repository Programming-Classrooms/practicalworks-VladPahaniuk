#include "src/Student/Student.hpp"
#include "src/Professor/Professor.hpp"
#include "src/Person/Person.hpp"

int main()
{
	try
	{
		std::cout << "Введите размерность списка студентов!";
		size_t maxSizeOfPersons;
		std::cin >> maxSizeOfPersons;
		if (maxSizeOfPersons <= 0) {
			throw::std::invalid_argument("List cannot be empty or size of list cannot be negative...");
		}
		
		Person *persons[maxSizeOfPersons];
		size_t numPersons = 0;
		size_t choice = 0;

		while (choice != 5)
		{
			std::cout << "Меню:\n";
			std::cout << "1. Ввести студента\n";
			std::cout << "2. Ввести прeподавателя\n";
			std::cout << "3. Вывести список студентов\n";
			std::cout << "4. Вывести список преподавателей\n";
			std::cout << "5. Выход\n";
			std::cout << "Введите что хотите сделать: ";
			std::cin >> choice;
			switch (choice)
			{
			case 1:
			{
				char name[100];
				size_t course, group;
				std::cout << "Введите ФИО студента: ";
				std::cin.ignore();
				std::cin.getline(name, 100);
				std::cout << "Введите курс студента: ";
				std::cin >> course;
				if (!std::cin>>course)
				{
					throw std::invalid_argument("The course must consist of numbers...");
				}
				std::cout << "Введитее группу студента: ";
				std::cin >> group;

				persons[numPersons] = new Student(name, course, group);
				numPersons++;
				break;
			}
			case 2:
			{
				char name[100];
				char department[100];
				std::cout << "Введите ФИО преподавателя: ";
				std::cin.ignore();
				std::cin.getline(name, 100);
				std::cout << "Введите кафедру преподавателя: ";
				std::cin.getline(department, 100);

				persons[numPersons] = new Professor(name, department);
				numPersons++;
				break;
			}
			case 3:
			{
				std::cout << "Список студентов:\n";
				for (size_t i = 0; i < numPersons; i++)
				{
					if (Student *student = dynamic_cast<Student *>(persons[i]))
					{
						student->print();
					}
				}
				break;
			}
			case 4:
			{
				std::cout << "Список преподавателей:\n";
				for (size_t i = 0; i < numPersons; i++)
				{
					if (Professor *professor = dynamic_cast<Professor *>(persons[i]))
					{
						professor->print();
					}
				}
				break;
			}
			case 5:
				std::cout << "Выход...\n";
				break;
			default:
				std::cout << "Неправильный. Пожалуйста, попробуйте ещё раз...\n";
			}
		}

		for (size_t i = 0; i < numPersons; i++)
		{
			delete persons[i];
		}
	}
	catch (const std::invalid_argument &error)
	{
		std::cerr<< "Exception: " << error.what() << '\n';
	}
	return 0;
}