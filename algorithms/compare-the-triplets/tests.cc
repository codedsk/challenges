#include <gtest/gtest.h>
#include <string.h>

#define TESTING

#include "soln.c"


// compare arrays
// https://stackoverflow.com/a/10062016

template<typename T>
::testing::AssertionResult arrays_match(
    const T expected,
    const T actual,
    size_t size) {

    for (size_t i(0); i < size; ++i) {
        if (expected[i] != actual[i]) {
            return ::testing::AssertionFailure() <<
                "actual[" << i << "] (" << actual[i] << ") " <<
                "!= " <<
                "expected[" << i << "] (" << expected[i] << ")";
        }
    }

    return ::testing::AssertionSuccess();
}


class SolnTest : public testing::Test {

    public:

        // virtual void Setup() {}

        // virtual void TearDown() {}

};


TEST_F(SolnTest, int_cmp_a_less_b) {
    EXPECT_EQ(-1, int_cmp(-5,-1));
    EXPECT_EQ(-1, int_cmp(-5,0));
    EXPECT_EQ(-1, int_cmp(-5,5));
    EXPECT_EQ(-1, int_cmp(0,5));
    EXPECT_EQ(-1, int_cmp(5,10));
}

TEST_F(SolnTest, int_cmp_a_equals_b) {
    EXPECT_EQ(0, int_cmp(-5,-5));
    EXPECT_EQ(0, int_cmp(0,0));
    EXPECT_EQ(0, int_cmp(5,5));
}

TEST_F(SolnTest, int_cmp_a_greater_b) {
    EXPECT_EQ(1, int_cmp(-5,-10));
    EXPECT_EQ(1, int_cmp(0,-5));
    EXPECT_EQ(1, int_cmp(5,-5));
    EXPECT_EQ(1, int_cmp(5,0));
    EXPECT_EQ(1, int_cmp(5,1));
}

TEST_F(SolnTest, solve) {
    int result_size = 2;
    int *expected = NULL;
    int *actual = NULL;

    expected = (int*) calloc((size_t)result_size,sizeof(int));

    expected[0] = 3;
    expected[1] = 0;
    actual = solve(5,6,7,3,3,3,&result_size);
    EXPECT_TRUE(arrays_match(expected,actual,result_size));
    free(actual);
    actual = NULL;

    expected[0] = 2;
    expected[1] = 1;
    actual = solve(5,6,7,3,3,10,&result_size);
    EXPECT_TRUE(arrays_match(expected,actual,result_size));
    free(actual);
    actual = NULL;

    expected[0] = 2;
    expected[1] = 1;
    actual = solve(5,6,7,3,10,3,&result_size);
    EXPECT_TRUE(arrays_match(expected,actual,result_size));
    free(actual);
    actual = NULL;

    expected[0] = 1;
    expected[1] = 2;
    actual = solve(5,6,7,3,10,10,&result_size);
    EXPECT_TRUE(arrays_match(expected,actual,result_size));
    free(actual);
    actual = NULL;

    expected[0] = 2;
    expected[1] = 1;
    actual = solve(5,6,7,10,3,3,&result_size);
    EXPECT_TRUE(arrays_match(expected,actual,result_size));
    free(actual);
    actual = NULL;

    expected[0] = 1;
    expected[1] = 2;
    actual = solve(5,6,7,10,3,10,&result_size);
    EXPECT_TRUE(arrays_match(expected,actual,result_size));
    free(actual);
    actual = NULL;

    expected[0] = 1;
    expected[1] = 2;
    actual = solve(5,6,7,10,10,3,&result_size);
    EXPECT_TRUE(arrays_match(expected,actual,result_size));
    free(actual);
    actual = NULL;

    expected[0] = 0;
    expected[1] = 3;
    actual = solve(5,6,7,10,10,10,&result_size);
    EXPECT_TRUE(arrays_match(expected,actual,result_size));
    free(actual);
    actual = NULL;

    expected[0] = 0;
    expected[1] = 2;
    actual = solve(5,6,7,10,10,7,&result_size);
    EXPECT_TRUE(arrays_match(expected,actual,result_size));
    free(actual);
    actual = NULL;

    expected[0] = 0;
    expected[1] = 2;
    actual = solve(5,6,7,10,6,10,&result_size);
    EXPECT_TRUE(arrays_match(expected,actual,result_size));
    free(actual);
    actual = NULL;

    expected[0] = 0;
    expected[1] = 1;
    actual = solve(5,6,7,10,6,7,&result_size);
    EXPECT_TRUE(arrays_match(expected,actual,result_size));
    free(actual);
    actual = NULL;

    expected[0] = 0;
    expected[1] = 2;
    actual = solve(5,6,7,5,10,10,&result_size);
    EXPECT_TRUE(arrays_match(expected,actual,result_size));
    free(actual);
    actual = NULL;

    expected[0] = 0;
    expected[1] = 1;
    actual = solve(5,6,7,5,10,7,&result_size);
    EXPECT_TRUE(arrays_match(expected,actual,result_size));
    free(actual);
    actual = NULL;

    expected[0] = 0;
    expected[1] = 1;
    actual = solve(5,6,7,5,6,10,&result_size);
    EXPECT_TRUE(arrays_match(expected,actual,result_size));
    free(actual);
    actual = NULL;

    expected[0] = 0;
    expected[1] = 0;
    actual = solve(5,6,7,5,6,7,&result_size);
    EXPECT_TRUE(arrays_match(expected,actual,result_size));
    free(actual);
    actual = NULL;


    free(expected);
    expected = NULL;
}


int main (int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
