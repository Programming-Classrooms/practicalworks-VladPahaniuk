#include <stdexcept>
#include <gtest/gtest.h>
#include "src/Student/Student.hpp"

// Тесты для конструктора с параметрами
TEST(StudentTest, ParameterizedConstructor) {
    Student student("John Doe", 2, 3, 123456);
    EXPECT_EQ(student.getName(), "John Doe");
    EXPECT_EQ(student.getCourse(), 2);
    EXPECT_EQ(student.getGroup(), 3);
    EXPECT_EQ(student.getRecordBookNumber(), 123456);
}

// Тесты для конструктора копирования
TEST(StudentTest, CopyConstructor) {
    Student student1("Jane Smith", 1, 2, 654321);
    Student student2(student1);
    EXPECT_EQ(student2.getName(), "Jane Smith");
    EXPECT_EQ(student2.getCourse(), 1);
    EXPECT_EQ(student2.getGroup(), 2);
    EXPECT_EQ(student2.getRecordBookNumber(), 654321);
}

// Тесты для гетеров
TEST(StudentTest, Getters) {
    Student student("Alice Brown", 3, 4, 111222);
    EXPECT_EQ(student.getName(), "Alice Brown");
    EXPECT_EQ(student.getCourse(), 3);
    EXPECT_EQ(student.getGroup(), 4);
    EXPECT_EQ(student.getRecordBookNumber(), 111222);
}

// Тесты для сетеров
TEST(StudentTest, Setters) {
    Student student("Bob Green", 2, 3, 333444);
    student.setName("Robert Green");
    student.setCourse(4);
    student.setGroup(5);
    EXPECT_EQ(student.getName(), "Robert Green");
    EXPECT_EQ(student.getCourse(), 4);
    EXPECT_EQ(student.getGroup(), 5);
}

// Тесты для оператора вывода
TEST(StudentTest, OutputOperator) {
    Student student("Eve White", 1, 1, 555666);
    std::ostringstream oss;
    oss << student;
    std::string output = oss.str();
    EXPECT_TRUE(output.find("ID: ") != std::string::npos);
    EXPECT_TRUE(output.find("Name: Eve White") != std::string::npos);
    EXPECT_TRUE(output.find("Course: 1") != std::string::npos);
    EXPECT_TRUE(output.find("Group: 1") != std::string::npos);
    EXPECT_TRUE(output.find("Record Book Number: 555666") != std::string::npos);
}

// Тесты для уникального ID
TEST(StudentTest, UniqueID) {
    Student student1("Student1", 1, 1, 111111);
    Student student2("Student2", 2, 2, 222222);
    EXPECT_NE(student1.getId(), student2.getId());
}