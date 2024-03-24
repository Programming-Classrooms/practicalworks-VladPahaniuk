#include <stdexcept>
#include <gtest/gtest.h>
#include "src/Fraction/Fraction.hpp"

TEST(testFraction, testDefultConstructor)
{
    Fraction fraction;
    EXPECT_EQ(fraction.getNumerator(), 0);

}