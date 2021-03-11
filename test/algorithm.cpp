#include <gtest/gtest.h>

extern "C" {
    #include "../include/algorithm.h"
}

TEST(test_square, square) {
    ASSERT_EQ(1, 1);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}