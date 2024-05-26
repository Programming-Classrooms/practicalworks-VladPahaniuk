#include "Library.hpp"

/*==========================================================*/
/*====================Конструкторы==========================*/
/*==========================================================*/

// Конструктор копирования
Library::Library(const Library& other) : books(other.books) 
{}


/*================================================================================*/
/*==================================== Методы ====================================*/
/*================================================================================*/

// Добавление книги
void Library::addBook(const Book& book) {
    books.insert(book);
}

// Удаление книги
void Library::removeBook(const Book& book) {
    books.erase(book);
}

// Поиск книги по названию
Book* Library::findBookByTitle(const std::string& title) {
    auto it = std::find_if(books.begin(), books.end(),
                           [&title](const Book& book) { return book.getTitle() == title; });
    if (it != books.end()) {
        return &const_cast<Book&>(*it); 
    }
    return nullptr;
}

// Поиск книг по автору
std::set<Book> Library::findBooksByAuthor(const Author& author) {
    std::set<Book> result;
    for (const auto& book : books) {
        AuthorsList authors = book.getAuthors();
        if (authors.contains(author)) {
            result.insert(book);
        }
    }
    return result;
}

// Добавление автора к книге
void Library::addAuthorToBook(const std::string& title, const Author& author) {
    Book* book = findBookByTitle(title);
    if (book) {
        book->addAuthor(author);
    }
}

// Удаление автора в книге
void Library::removeAuthorFromBook(const std::string& title, const Author& author) {
    Book* book = findBookByTitle(title);
    if (book) {
        book->removeAuthor(author);
    }
}

// Ввод из потока
std::ostream& operator<<(std::ostream& out, const Library& library) {
    for (const auto& book : library.books) {
        out << book << "\n";
    }
    return out;
}
    
// Чтенике из файла
void Library::readFromFile(const std::string& filename) {
    
    std::ifstream file(filename);
    checkFileInput(file);

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        size_t udc;
        std::string surname, firstName, title, word;
        size_t year;
        AuthorsList authors;

        iss >> udc;
        iss.ignore(1, ';'); 

        std::getline(iss, surname, ';');

        std::getline(iss, firstName, ';');

        title.clear();
        while (std::getline(iss, word, ';')) {
            if (isdigit(word[0])) {
                year = std::stoul(word);
                break;
            }
            if (!title.empty()) {
                title += " ";
            }
            title += word;
        }

        Author author(surname, firstName, "");
        authors.addAuthor(author);

        Book book(udc, title, year, authors);
        addBook(book);
    }
    file.close();
}


/*================================================================================*/
/*==================================== Функции ===================================*/
/*================================================================================*/

// Проверка файла   
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

