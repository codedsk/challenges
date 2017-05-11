#include <gtest/gtest.h>

#define TESTING

#include "soln.c"


class SolnTest : public testing::Test {

    public:

        // virtual void Setup() {}

        // virtual void TearDown() {}

};


TEST_F(SolnTest, diagdiff_provided_case) {
    size_t n = 3;

    int arr1[n*n] = { 11,   2,   4,
                       4,   5,   6,
                      10,   8, -12};
    EXPECT_EQ(15, diagdiff(arr1,n));
}

TEST_F(SolnTest, diagdiff_edge_case) {
    size_t n = 1;

    // one value
    int arr1[n*n] = { 11 };
    EXPECT_EQ(0, diagdiff(arr1,n));

    // 4x4, even number of rows/cols
    // negative result turned positive by abs
    n = 4;
    int arr2[n*n] = { 11,   2,   4,   7,
                       4,   5,   6,   2,
                       4,   5,   6,   7,
                      10,   8, -12, -34};
    EXPECT_EQ(40, diagdiff(arr2,n));
}


int main (int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
