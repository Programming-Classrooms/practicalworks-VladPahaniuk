#include <stdexcept>
#include <gtest/gtest.h>
#include "src/Matrix/Matrix.hpp"

TEST(MatrixTest, DefaultConstructor) {
    Matrix mat;
    EXPECT_EQ(mat.getRow(), 0);
    EXPECT_EQ(mat.getCol(), 0);
}

TEST(MatrixTest, ParameterizedConstructor) {
    Matrix mat(2, 3);
    EXPECT_EQ(mat.getRow(), 2);
    EXPECT_EQ(mat.getCol(), 3);
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            EXPECT_EQ(mat(i, j), 0.0);
        }
    }
}

TEST(MatrixTest, ParameterizedConstructorWithValue) {
    Matrix mat(2, 3, 5.0);
    EXPECT_EQ(mat.getRow(), 2);
    EXPECT_EQ(mat.getCol(), 3);
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            EXPECT_EQ(mat(i, j), 5.0);
        }
    }
}

TEST(MatrixTest, CopyConstructor) {
    Matrix mat1(2, 3, 5.0);
    Matrix mat2(mat1);
    EXPECT_EQ(mat2.getRow(), 2);
    EXPECT_EQ(mat2.getCol(), 3);
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            EXPECT_EQ(mat2(i, j), 5.0);
        }
    }
}

TEST(MatrixTest, AssignmentOperator) {
    Matrix mat1(2, 3, 5.0);
    Matrix mat2;
    mat2 = mat1;
    EXPECT_EQ(mat2.getRow(), 2);
    EXPECT_EQ(mat2.getCol(), 3);
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            EXPECT_EQ(mat2(i, j), 5.0);
        }
    }
}

TEST(MatrixTest, EqualityOperator) {
    Matrix mat1(2, 3, 5.0);
    Matrix mat2(2, 3, 5.0);
    Matrix mat3(2, 3, 3.0);
    EXPECT_TRUE(mat1 == mat2);
    EXPECT_FALSE(mat1 == mat3);
}

TEST(MatrixTest, InequalityOperator) {
    Matrix mat1(2, 3, 5.0);
    Matrix mat2(2, 3, 5.0);
    Matrix mat3(2, 3, 3.0);
    EXPECT_FALSE(mat1 != mat2);
    EXPECT_TRUE(mat1 != mat3);
}

TEST(MatrixTest, AdditionOperator) {
    Matrix mat1(2, 3, 5.0);
    Matrix mat2(2, 3, 3.0);
    Matrix result = mat1 + mat2;
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            EXPECT_EQ(result(i, j), 8.0);
        }
    }
}

TEST(MatrixTest, SubtractionOperator) {
    Matrix mat1(2, 3, 5.0);
    Matrix mat2(2, 3, 3.0);
    Matrix result = mat1 - mat2;
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            EXPECT_EQ(result(i, j), 2.0);
        }
    }
}

TEST(MatrixTest, MultiplicationOperator) {
    Matrix mat1(2, 2);
    mat1.setElement(0, 0, 1.0);
    mat1.setElement(0, 1, 2.0);
    mat1.setElement(1, 0, 3.0);
    mat1.setElement(1, 1, 4.0);

    Matrix mat2(2, 2);
    mat2.setElement(0, 0, 2.0);
    mat2.setElement(0, 1, 0.0);
    mat2.setElement(1, 0, 1.0);
    mat2.setElement(1, 1, 2.0);

    Matrix result = mat1 * mat2;

    EXPECT_EQ(result(0, 0), 4.0);
    EXPECT_EQ(result(0, 1), 4.0);
    EXPECT_EQ(result(1, 0), 10.0);
    EXPECT_EQ(result(1, 1), 8.0);
}

TEST(MatrixTest, ScalarMultiplicationOperator) {
    Matrix mat(2, 3, 2.0);
    Matrix result = mat * 3.0;
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            EXPECT_EQ(result(i, j), 6.0);
        }
    }
}

TEST(MatrixTest, ScalarDivisionOperator) {
    Matrix mat(2, 3, 6.0);
    Matrix result = mat / 2.0;
    for (size_t i = 0; i < 2; ++i) {
        for (size_t j = 0; j < 3; ++j) {
            EXPECT_EQ(result(i, j), 3.0);
        }
    }
}