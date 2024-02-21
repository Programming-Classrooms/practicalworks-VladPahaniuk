#include <stdexcept>
#include <gtest/gtest.h>
#include "../fraction/Fraction.hpp"

TEST(testCase, testName)
{
    EXPECT_EQ(1,1);
}

TEST(testCaseConstructors, testDefultConstructor)
{
    MyString str;
    EXPECT_EQ(str.Length(), 0);
}
