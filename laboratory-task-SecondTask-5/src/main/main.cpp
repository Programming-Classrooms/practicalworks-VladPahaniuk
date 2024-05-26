#include "../Tree/Tree.hpp"

int main()
{
    try
    {
        // Создаем дерево книг
        Tree<Book> library;

        // Добавляем книги в дерево
        library.insert(Book("001", "The Lord of the Rings", "J.R.R. Tolkien"));
        library.insert(Book("002", "Harry Potter and the Philosopher's Stone", "J.K. Rowling"));
        library.insert(Book("003", "To Kill a Mockingbird", "Harper Lee"));

        // Выводим содержимое дерева
        library.print();

        // Получаем книгу по шифру
        std::cout << "Book title for cipher '002': " << library["002"].title << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
