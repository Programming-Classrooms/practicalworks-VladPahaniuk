#include <stdexcept>
#include <gtest/gtest.h>
#include <cstdio> // Для std::remove

#include "../funcs/funcs.hpp"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}


TEST(CheckFileTest, CheckFileExists) {
    std::string tempFilename = "temp_test_file.txt";
    std::ofstream outfile(tempFilename);
    outfile << "test1" << std::endl;
    outfile.close();

    std::ofstream testFile(tempFilename, std::ios::app);
    EXPECT_NO_THROW(checkFile(testFile, tempFilename));
    testFile.close();

    std::remove(tempFilename.c_str());
}

TEST(WriteToFileTest, WriteToFile) {
    std::string tempFilename = "temp_test_file.txt";
    std::set<std::string> data = {"line1", "line2"};
    writeToFile(tempFilename, data);

    std::ifstream infile(tempFilename);
    std::string line;
    std::set<std::string> readData;
    while (std::getline(infile, line)) {
        readData.insert(line);
    }
    infile.close();

    EXPECT_EQ(readData.size(), 2);
    EXPECT_NE(readData.find("line1"), readData.end());
    EXPECT_NE(readData.find("line2"), readData.end());

    std::remove(tempFilename.c_str());
}

TEST(UnionFishermenTest, UnionSets) {
    std::set<std::string> set1 = {"A", "B", "C"};
    std::set<std::string> set2 = {"B", "C", "D"};
    std::set<std::string> expectedUnion = {"A", "B", "C", "D"};

    EXPECT_EQ(unionFishermen(set1, set2), expectedUnion);
}

TEST(DifferenceTest, DifferenceSets) {
    std::set<std::string> set1 = {"A", "B", "C"};
    std::set<std::string> set2 = {"B", "C", "D"};
    std::set<std::string> expectedDifference = {"A"};

    EXPECT_EQ(difference(set1, set2), expectedDifference);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
