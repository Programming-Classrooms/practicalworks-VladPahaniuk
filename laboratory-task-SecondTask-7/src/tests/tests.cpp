#include <stdexcept>
#include <gtest/gtest.h>

#include "../Book/Book.hpp"

TEST(BookTest, DefaultConstructor) {
    Book book;
    EXPECT_EQ(book.getUDC(), 0);
    EXPECT_EQ(book.getTitle(), "");
    EXPECT_EQ(book.getYear(), 0);
    EXPECT_TRUE(book.getAuthors().getSize() == 0);
}

TEST(BookTest, Setters) {
    Book book;
    book.setUDC(123);
    book.setTitle("Test Title");
    book.setYear(2020);

    Author author("Smith", "John", "A.");
    AuthorsList authors;
    authors.addAuthor(author);
    book.setAuthors(authors);

    EXPECT_EQ(book.getUDC(), 123);
    EXPECT_EQ(book.getTitle(), "Test Title");
    EXPECT_EQ(book.getYear(), 2020);
    EXPECT_TRUE(book.getAuthors().contains(author));
}

TEST(BookTest, SetTitleInvalid) {
    Book book;
    EXPECT_THROW(book.setTitle(""), std::invalid_argument);
    EXPECT_THROW(book.setTitle(std::string(101, 'a')), std::invalid_argument);
}

TEST(BookTest, SetYearInvalid) {
    Book book;
    EXPECT_THROW(book.setYear(1199), std::invalid_argument);
    EXPECT_THROW(book.setYear(2025), std::invalid_argument);
}

TEST(BookTest, SetAuthorsInvalid) {
    Book book;
    AuthorsList authors;
    EXPECT_THROW(book.setAuthors(authors), std::invalid_argument);
}

TEST(BookTest, OperatorLessThan) {
    Book book1;
    book1.setTitle("A Title");
    Book book2;
    book2.setTitle("B Title");

    EXPECT_TRUE(book1 < book2);
    EXPECT_FALSE(book2 < book1);
}

TEST(BookTest, AddRemoveAuthor) {
    Author author("Smith", "John", "A.");
    Book book;
    book.addAuthor(author);

    EXPECT_TRUE(book.getAuthors().contains(author));

    book.removeAuthor(author);
    EXPECT_FALSE(book.getAuthors().contains(author));
}
