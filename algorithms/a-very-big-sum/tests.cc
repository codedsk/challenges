#include <gtest/gtest.h>

#define TESTING

#include "soln.c"


class SolnTest : public testing::Test {

    public:

        // virtual void Setup() {}

        // virtual void TearDown() {}

};


TEST_F(SolnTest, bigsum_provided_case) {
    size_t n = 5;

    long long arr1[n] = {1000000001, 1000000002, 1000000003,
                         1000000004, 1000000005};
    EXPECT_EQ(5000000015, bigsum(arr1,n));
}

TEST_F(SolnTest, bigsum_edge_cases) {
    size_t n = 5;

    // high end edge case
    n = 10;
    long long arr1[n] = {10000000000, 10000000000, 10000000000,
                         10000000000, 10000000000, 10000000000,
                         10000000000, 10000000000, 10000000000,
                         10000000000};
    EXPECT_EQ(100000000000, bigsum(arr1,n));

    // low end edge case
    n = 1;
    long long arr2[n] = {0};
    EXPECT_EQ(0, bigsum(arr2,n));
}


int main (int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
