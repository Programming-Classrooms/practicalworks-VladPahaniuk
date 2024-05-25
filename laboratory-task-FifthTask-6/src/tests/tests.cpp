#include <stdexcept>
#include <gtest/gtest.h>
#include "../Student/Student.hpp"


TEST(testCase, testName) 
{
    EXPECT_EQ(1, 1);
}

TEST(CheckFileInputTest, FileIsEmpty) {
    std::ofstream outfile("empty_file.txt");
    outfile.close();
    std::ifstream file("empty_file.txt");
    EXPECT_THROW(checkFileInput(file), std::runtime_error);
    std::remove("empty_file.txt");
}

TEST(StudentTest, ConstructorInvalidCourse) {
    EXPECT_THROW(Student("John Doe", 0, 1), std::invalid_argument);
}

TEST(StudentTest, ConstructorInvalidGroup) {
    EXPECT_THROW(Student("John Doe", 1, 0), std::invalid_argument);
}

TEST(StudentTest, LessThanOperator) {
    Student student1("Alice", 1, 1);
    Student student2("Bob", 1, 1);
    EXPECT_TRUE(student1 < student2);
}

TEST(SortByCourseGroupTest, SortOrder) {
    Student student1("Alice", 2, 1);
    Student student2("Bob", 1, 2);
    Student student3("Charlie", 1, 1);

    std::vector<Student> students = {student1, student2, student3};
    std::sort(students.begin(), students.end(), sortByCourseGroup);

    EXPECT_EQ(students[0].fullName, "Charlie");
    EXPECT_EQ(students[1].fullName, "Bob");
    EXPECT_EQ(students[2].fullName, "Alice");
}

TEST(ReadStudentsFromFileTest, ReadCorrectly) {
    std::ofstream outfile("students.txt");
    outfile << "Alice 1 1\nBob 2 2\n";
    outfile.close();

    std::vector<Student> students;
    readStudentsFromFile("students.txt", students);

    ASSERT_EQ(students.size(), 2);
    EXPECT_EQ(students[0].fullName, "Alice");
    EXPECT_EQ(students[0].course, 1);
    EXPECT_EQ(students[0].group, 1);
    EXPECT_EQ(students[1].fullName, "Bob");
    EXPECT_EQ(students[1].course, 2);
    EXPECT_EQ(students[1].group, 2);

    std::remove("students.txt");
}

TEST(WriteStudentsByFullNameTest, WriteCorrectly) {
    std::vector<Student> students = {Student("Bob", 2, 2), Student("Alice", 1, 1)};
    writeStudentsByFullName("students_sorted.txt", students);

    std::ifstream infile("students_sorted.txt");
    std::string line;
    std::getline(infile, line);
    EXPECT_EQ(line, "Alice 1 1");
    std::getline(infile, line);
    EXPECT_EQ(line, "Bob 2 2");

    infile.close();
    std::remove("students_sorted.txt");
}

TEST(WriteStudentsByCourseGroupTest, WriteCorrectly) {
    std::vector<Student> students = {Student("Bob", 2, 2), Student("Alice", 1, 1)};
    writeStudentsByCourseGroup("students_sorted_course_group.txt", students);

    std::ifstream infile("students_sorted_course_group.txt");
    std::string line;
    std::getline(infile, line);
    EXPECT_EQ(line, "Alice 1 1");
    std::getline(infile, line);
    EXPECT_EQ(line, "Bob 2 2");

    infile.close();
    std::remove("students_sorted_course_group.txt");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}