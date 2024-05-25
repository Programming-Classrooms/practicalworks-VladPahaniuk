#include <stdexcept>
#include "../TDeque/TDeque.hpp"
#include <gtest/gtest.h>

// Тестирование метода InsFront()
TEST(TDequeTest, InsFront) {
    TDeque<int> deque;
    deque.InsFront(5);
    deque.InsFront(10);
    EXPECT_EQ(deque.GetByIndex(0), 10);
    EXPECT_EQ(deque.GetByIndex(1), 5);
}

// Тестирование метода InsRear()
TEST(TDequeTest, InsRear) {
    TDeque<int> deque;
    deque.InsRear(5);
    deque.InsRear(10);
    EXPECT_EQ(deque.GetByIndex(0), 5);
    EXPECT_EQ(deque.GetByIndex(1), 10);
}

// Тестирование метода DelFront()
TEST(TDequeTest, DelFront) {
    TDeque<int> deque;
    deque.InsRear(5);
    deque.InsRear(10);
    deque.DelFront();
    EXPECT_EQ(deque.GetByIndex(0), 10);
}

// Тестирование метода DelRear()
TEST(TDequeTest, DelRear) {
    TDeque<int> deque;
    deque.InsRear(5);
    deque.InsRear(10);
    deque.DelRear();
    EXPECT_EQ(deque.GetByIndex(0), 5);
}

// Тестирование методов InsFront() и InsRear() с указателями на char
TEST(TDequeTest, CharPtrOperations) {
    TDeque<const char*> deque;
    deque.InsFront("Hello");
    deque.InsRear("World");
    EXPECT_STREQ(deque.GetByIndex(0), "Hello");
    EXPECT_STREQ(deque.GetByIndex(1), "World");
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
