#include "src/Book/Book.hpp"
#include "src/Library/Library.hpp"

// Функция для отображения списка книг
void printBooks(const Library &library)
{
	std::cout << "Список книг в библиотеке:" << std::endl;
	for (const Book &book : library.viewBooks())
	{
		std::cout << "ISBN: " << book.getISBN() << ", Название: " << book.getTitle() << ", Авторы: ";
		for (const std::string &author : book.getAuthors())
		{
			std::cout << author << " ";
		}
		std::cout << ", Цена: " << book.getPrice() << ", Количество: " << book.getCount() << std::endl;
	}
}

// Функция для поиска книги по ISBN
void findBookByISBN(Library &library, const std::string &isbn)
{
	Book *foundBook = library.findBook(isbn);
	if (foundBook)
	{
		std::cout << "Поиск книги по ISBN " << isbn << ": " << foundBook->getTitle() << std::endl << std::endl;
	}
	else
	{
		std::cout << "Книга со следующим ISBN " << isbn << " не найдена." << std::endl;
	}
}

// Функция для добавления автора к книге
void addAuthorToBook(Library &library, const std::string &isbn, const std::string &author)
{
	library.addAuthor(isbn, author);
}

// Функция для удаления автора из книги
void removeAuthorFromBook(Library &library, const std::string &isbn, const std::string &author)
{
	library.removeAuthor(isbn, author);
}

// Функция для удаления книги по ISBN
void removeBookByISBN(Library &library, const std::string &isbn)
{
	library.removeBook(isbn);
}

// Функция для сортировки книг по ISBN
void sortBooksByISBNAndDisplay(Library &library)
{
	library.sortBooksByISBN();
	std::cout << "Книги сортированные по ISBN:" << std::endl;
	printBooks(library);
	std::cout << std::endl;

}

// Функция для сортировки книг по названию
void sortBooksByTitleAndDisplay(Library &library)
{
	library.sortBooksByTitle();
	std::cout << "Книги сортированные по названию:" << std::endl;
	printBooks(library);
	std::cout << std::endl;
}

int main()
{
	try
	{
		Library library;

		Book book1("1", "C++ Programming", {"Bjarne Stroustrup"}, 59.02, 10);
		Book book2("3", "The C Programming Language", {"Brian W. Kernighan", "Dennis M. Ritchie"}, 45.00, 5);
		Book book3("2", "Introduction to Algorithms", {"Thomas H. Cormen", "Charles E. Leiserson", "Ronald L. Rivest", "Clifford Stein"}, 100.07, 3);

		// Добавление книг в библиотеку
		library.addBook(book1);
		library.addBook(book2);
		library.addBook(book3);

		printBooks(library);

		std::cout << std::endl;

		findBookByISBN(library, "1");

		addAuthorToBook(library, "3", "Новый автор");

		removeAuthorFromBook(library, "2", "Ronald L. Rivest");

		removeBookByISBN(library, "1");

		sortBooksByISBNAndDisplay(library);

		sortBooksByTitleAndDisplay(library);
	}
	catch (const std::invalid_argument &e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
