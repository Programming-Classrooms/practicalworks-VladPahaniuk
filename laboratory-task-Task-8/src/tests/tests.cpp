#include <stdexcept>
#include <gtest/gtest.h>

#include "../Book/Book.hpp"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(BookTest, SetGetISBN) {
    Book book;
    book.setISBN("123");
    EXPECT_EQ(book.getISBN(), "123");
}

TEST(BookTest, SetGetTitle) {
    Book book;
    book.setTitle("Test Title");
    EXPECT_EQ(book.getTitle(), "Test Title");

    // Проверка некорректных значений заголовка
    EXPECT_THROW(book.setTitle(""), std::invalid_argument);
    EXPECT_THROW(book.setTitle(std::string(101, 'A')), std::invalid_argument);
}

TEST(BookTest, SetGetAuthors) {
    Book book;
    std::vector<std::string> authors = {"Author1", "Author2"};
    book.setAuthors(authors);
    EXPECT_EQ(book.getAuthors(), authors);
    EXPECT_THROW(book.setAuthors({}), std::invalid_argument);
}

TEST(BookTest, SetGetPrice) {
    Book book;
    book.setPrice(19.99);
    EXPECT_DOUBLE_EQ(book.getPrice(), 19.99);
    EXPECT_THROW(book.setPrice(-10), std::invalid_argument);
}

TEST(BookTest, AddRemoveAuthors) {
    Book book;
    book.setAuthors({"Author1"});

    book.addAuthor("Author2");
    std::vector<std::string> expectedAuthors = {"Author1", "Author2"};
    EXPECT_EQ(book.getAuthors(), expectedAuthors);

    book.removeAuthor("Author1");
    expectedAuthors = {"Author2"};
    EXPECT_EQ(book.getAuthors(), expectedAuthors);

    book.removeAuthor("Author3");
    EXPECT_EQ(book.getAuthors(), expectedAuthors);
}
