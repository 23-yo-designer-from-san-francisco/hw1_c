#include "gtest/gtest.h"

extern "C" {
    #include "../include/algorithm.h"
}

TEST(test_square, square) {
    EXPECT_TRUE(max_area(NULL, NULL, 1) == NULL);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
