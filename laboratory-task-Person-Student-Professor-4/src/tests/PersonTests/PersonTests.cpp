#include <stdexcept>
#include <gtest/gtest.h>
#include "src/Person/Person.hpp"

// Тесты для конструктора с параметрами
TEST(PersonTest, ParameterizedConstructor) {
    Person person("John Doe");
    EXPECT_STREQ(person.getFullName(), "John Doe");
}

// Тесты для деструктора
TEST(PersonTest, Destructor) {
    Person* person = new Person("Jane Smith");
    delete person;
    SUCCEED();  // Проверка, что удаление прошло без сбоев
}

// Тесты для метода getFullName
TEST(PersonTest, GetFullName) {
    Person person("Alice Brown");
    EXPECT_STREQ(person.getFullName(), "Alice Brown");
}

// Тесты для метода setFullName
TEST(PersonTest, SetFullName) {
    Person person("Bob Green");
    person.setFullName("Robert Green");
    EXPECT_STREQ(person.getFullName(), "Robert Green");
}

// Тесты для метода print
TEST(PersonTest, Print) {
    Person person("Eve White");
    testing::internal::CaptureStdout(); //перенаправляет стандартный поток вывода (stdout) в буфер. Это позволяет захватывать вывод, который обычно направляется в консоль,
    person.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("ФИО: Eve White"), std::string::npos);
}
