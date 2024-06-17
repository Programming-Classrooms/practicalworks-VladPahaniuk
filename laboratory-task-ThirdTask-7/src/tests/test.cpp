#include <stdexcept>
#include <gtest/gtest.h>

#include "../funcs/funcs.hpp"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(FuncsTest, ToLowercase) {
    ASSERT_EQ(toLowercase("HELLO"), "hello");
    ASSERT_EQ(toLowercase("HeLLo"), "hello");
    ASSERT_EQ(toLowercase("hello"), "hello");
}

TEST(FuncsTest, PrintUniqueWords) {
    std::set<std::string> uniqueWords = {"hello", "world", "apple"};
    testing::internal::CaptureStdout(); // Захватываем вывод на консоль
    printUniqueWords(uniqueWords);
    std::string output = testing::internal::GetCapturedStdout(); // Получаем захваченный вывод

    ASSERT_NE(output.find("hello"), std::string::npos);
    ASSERT_NE(output.find("world"), std::string::npos);
    ASSERT_NE(output.find("apple"), std::string::npos);
}

TEST(FuncsTest, PrintWordCounts) {
    std::unordered_map<std::string, int> wordCounts = {{"hello", 2}, {"world", 1}, {"apple", 1}};
    testing::internal::CaptureStdout();
    printWordCounts(wordCounts);
    std::string output = testing::internal::GetCapturedStdout();

    ASSERT_NE(output.find("hello: 2"), std::string::npos);
    ASSERT_NE(output.find("world: 1"), std::string::npos);
    ASSERT_NE(output.find("apple: 1"), std::string::npos);
}
