#include <stdexcept>
#include <gtest/gtest.h>

#include "../Book/Book.hpp"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(BookTest, DefaultConstructor) {
    Book book;
    ASSERT_EQ(book.getUDC(), 0);
    ASSERT_EQ(book.getTitle(), "");
    ASSERT_EQ(book.getYear(), 0);
}

// Тест для проверки корректности конструктора с параметрами
TEST(BookTest, ParameterizedConstructor) {
    AuthorsList authors;
    Author author("John", "Doe", "");
    authors.addAuthor(author);
    Book book(12345, "Title", 2022, authors);
    ASSERT_EQ(book.getUDC(), 12345);
    ASSERT_EQ(book.getTitle(), "Title");
    ASSERT_EQ(book.getYear(), 2022);
    ASSERT_EQ(book.getAuthors().getSize(), 1);
}
