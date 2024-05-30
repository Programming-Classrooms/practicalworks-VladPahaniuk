#include <gtest/gtest.h>
#include "../funcs/funcs.hpp"
#include <stdexcept>


TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(TestCheckFile, FileIsNotOpen) {
  std::ifstream fin("worstFile.txt");
  EXPECT_ANY_THROW(checkFile(fin));
}

TEST(TestCheckFile, FileIsNotExist) {
  std::ifstream fin("NotExistFile.txt");
  EXPECT_ANY_THROW(checkFile(fin));
}

TEST(TestCheckFile, FileIsEmpty) {
  std::ifstream fin("emptytFile.txt");
  EXPECT_ANY_THROW(checkFile(fin));
}

TEST(TestCheckFile, goodFile) {
  std::ifstream fin("src/files/Numbers.txt");
  ASSERT_NO_THROW(checkFile(fin));
}

TEST(TestReadTextFromFile, goodWayOut) {
  std::string path = "src/files/Numbers.txt";
  EXPECT_NO_THROW(readFromFile(path));
}

TEST(TesIsDigit, goodWayOutNumber) {
  std::string word = "5556";
  EXPECT_TRUE(isDigit(word));
}

TEST(TestIsDigit, badWayOutNotNumber) {
  std::string word = "string";
  EXPECT_FALSE(isDigit(word));
}


TEST(TestGetDelimiters, goodWayOut) {
  std::string path = "src/files/Numbers.txt";
  EXPECT_NO_THROW(getDelimiters(path));
}

TEST(TestCopySortEvenOddArrays, workFunction) {
  const size_t size = 6;
  int32_t mainArr[6] = { 12, 3, 4, 5, 9, 7 };
  int32_t sortArr[6] = {0, 1, 2, 3, 4, 6 };
  copySortEvenOddArrays(mainArr, sortArr, size);
  EXPECT_EQ(sortArr[0], 12);
  EXPECT_EQ(sortArr[1], 4);
  EXPECT_EQ(sortArr[2], 3);
  EXPECT_EQ(sortArr[3], 5);
  EXPECT_EQ(sortArr[4], 9);
  EXPECT_EQ(sortArr[5], 7);
}


TEST(TestIsWord, CheckWord) {
  EXPECT_TRUE(isWord("Apple"));
  EXPECT_TRUE(isWord("Banana"));
  EXPECT_TRUE(isWord("Cherry"));
  EXPECT_FALSE(isWord("123"));
  EXPECT_FALSE(isWord("123Apple"));
  EXPECT_FALSE(isWord("apple"));
  EXPECT_FALSE(isWord(""));
  EXPECT_TRUE(isWord("A"));
}

TEST(TestGetSizeForArrNumbers, CheckSize) {
  EXPECT_EQ(getSizeForArrNumbers("", ", "), 0);
  EXPECT_EQ(getSizeForArrNumbers("Hello, world!", ", "), 0);
  EXPECT_EQ(getSizeForArrNumbers("123", ", "), 1);
  EXPECT_EQ(getSizeForArrNumbers("1, 2, 3, 4, 5", ", "), 5);
  EXPECT_EQ(getSizeForArrNumbers("The answer is 42!", " ,!"), 1);
  EXPECT_EQ(getSizeForArrNumbers("1;2;3;4;5", ";"), 5);
}

TEST(GetSizeForArrSurenamesTest, EmptyString) {
  std::string text = "";
  std::string delimiters = " ";
  size_t result = getSizeForArrSurenames(text, delimiters);
  EXPECT_EQ(result, 0);
}

TEST(GetSizeForArrSurenamesTest, SingleWord) {
  std::string text = "Hello";
  std::string delimiters = " ";
  size_t result = getSizeForArrSurenames(text, delimiters);
  EXPECT_EQ(result, 1);
}

TEST(GetSizeForArrSurenamesTest, MultipleWords) {
  std::string text = "Hello World";
  std::string delimiters = " ";
  size_t result = getSizeForArrSurenames(text, delimiters);
  EXPECT_EQ(result, 2);
}

TEST(GetSizeForArrSurenamesTest, WordsWithDelimiters) {
  std::string text = "Hello, World!";
  std::string delimiters = " ,!";
  size_t result = getSizeForArrSurenames(text, delimiters);
  EXPECT_EQ(result, 2);
}

TEST(GetSizeForArrSurenamesTest, WordsWithMultipleDelimiters) {
  std::string text = "Hello, World!";
  std::string delimiters = ",!";
  size_t result = getSizeForArrSurenames(text, delimiters);
  EXPECT_EQ(result, 1);
}

TEST(GetSizeForArrSurenamesTest, WordsWithCustomDelimiters) {
  std::string text = "Hello;World;Greetings";
  std::string delimiters = ";";
  size_t result = getSizeForArrSurenames(text, delimiters);
  EXPECT_EQ(result, 3);
}

TEST(FillArrayTest, EmptyString) {
  std::vector<std::string> arr(10);
  std::string text = "";
  std::string delims = " ";
  fillArraySurnames(arr.data(), text, delims);
  for (const auto& word : arr) {
    EXPECT_EQ(word, "");
  }
}

TEST(FillArrayTest, SingleWord) {
  std::vector<std::string> arr(10);
  std::string text = "Hello";
  std::string delims = " ";
  fillArraySurnames(arr.data(), text, delims);
  ASSERT_EQ(arr[0], "Hello");
}

TEST(FillArrayTest, MultipleWords) {
  std::vector<std::string> arr(10);
  std::string text = "Hello World";
  std::string delims = " ";
  fillArraySurnames(arr.data(), text, delims);
  ASSERT_EQ(arr[0], "Hello");
  ASSERT_EQ(arr[1], "World");
}

TEST(FillArrayTest, WordsWithDelimiters) {
  std::vector<std::string> arr(10);
  std::string text = "Hello, World!";
  std::string delims = " ,!";
  fillArraySurnames(arr.data(), text, delims);
  ASSERT_EQ(arr[0], "Hello");
  ASSERT_EQ(arr[1], "World");
}

TEST(ToUpperTest, EmptyString) {
  std::string result = toUpper("");
  EXPECT_EQ(result, "");
}

TEST(ToUpperTest, AllLowercase) {
  std::string result = toUpper("hello");
  EXPECT_EQ(result, "HELLO");
}

TEST(ToUpperTest, MixedCase) {
  std::string result = toUpper("HeLlO");
  EXPECT_EQ(result, "HELLO");
}

TEST(FillingArrayTest, FillingArrOfStruct) {
  std::vector<Employee> employees(3);
  std::vector<int32_t> children = { 3, 2, 1 };
  std::vector<std::string> surenames = { "John", "Alice", "Bob" };

  fillingArrOfStruct(employees.data(), children.data(), surenames.data(), surenames.size(), children.size());

  ASSERT_EQ(employees[0].surename, "John");
  ASSERT_EQ(employees[0].children, 3);
  ASSERT_EQ(employees[1].surename, "Alice");
  ASSERT_EQ(employees[1].children, 2);
  ASSERT_EQ(employees[2].surename, "Bob");
  ASSERT_EQ(employees[2].children, 1);
}

TEST(WriteArrOfStructTest, WriteArrOfStruct) {
  std::vector<Employee> employees = { {"John", 3}, {"Alice", 2}, {"Bob", 1} };
  size_t size = employees.size();

  writeArrOfStruct("employees.txt", employees.data(), size);

  std::ifstream fin("employees.txt");
  std::string line;
  std::getline(fin, line); 
  ASSERT_EQ(line, "John 3"); 

  std::getline(fin, line); 
  ASSERT_EQ(line, "Alice 2"); 

  std::getline(fin, line); 
  ASSERT_EQ(line, "Bob 1"); 
}
 //Идет бесконечный тест
// TEST(WriteArrOfStructToBinTest, WriteArrOfStructToBin) {
//   std::vector<Employee> employees = { {"John", 3}, {"Alice", 2}, {"Bob", 1} };

//   writeArrOfStructToBin("employees.bin", employees.data(), employees.size());

//   std::ifstream fin("employees.bin", std::ios::binary);
  
//   ASSERT_TRUE(fin.is_open()) << "Failed to open file.";

//   std::vector<Employee> records(employees.size());
//   fin.read(reinterpret_cast<char*>(records.data()), sizeof(Employee) * records.size());

//    ASSERT_FALSE(fin.fail()) << "Failed to read from file.";

//   for (size_t i = 0; i < employees.size(); ++i) {
//     ASSERT_EQ(records[i].children, employees[i].children) << "Mismatch in children count for record " << i;
//   }
// }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}