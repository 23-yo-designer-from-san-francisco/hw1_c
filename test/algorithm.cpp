#include "gtest/gtest.h"

extern "C" {
    #include "algorithm.h"
}

TEST(max_area, nullptr) {
    EXPECT_FALSE(get_max_triangle(NULL, NULL, 0));
}

TEST(max_area, wrong_length) {
    double a[] = {1, 2};
    double b[] = {1, 2};

    EXPECT_FALSE(get_max_triangle(&a[0], &b[0], sizeof(a)/sizeof(a[0])));
}

TEST(max_area, result1) {
    double a[] = {0, 0, 1, 0, 2, 3, 5, 6, 7, 8, 1231};
    double b[] = {0, 1, 0, 0, 0, -2, 5, -53, 12, 54, 5424};

    size_t **result = get_max_triangle(a, b, sizeof(a)/sizeof(a[0]));

    EXPECT_EQ(*result[0], 7);
    EXPECT_EQ(*result[1], 9);
    EXPECT_EQ(*result[2], 10);

    free_result(result);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
