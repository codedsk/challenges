#include <gtest/gtest.h>

#define TESTING

#include "soln.c"

// http://floating-point-gui.de/errors/comparison/

#include <stdlib.h>
#include <float.h>
#include <math.h>

bool nearlyEqual(float a, float b, float epsilon) {
    float absA = fabsf(a);
    float absB = fabsf(b);
    float diff = fabsf(a - b);

    if (a == b) {
        // shortcut, handles infinities
        return true;
    } else if (a == 0 || b == 0 || diff < FLT_EPSILON) {
        // a or b is zero or both are extremely close to it
        // relative error is less meaningful here
        return diff < epsilon;
    } else {
        // use relative error
        return (diff / fminf((absA + absB), FLT_MAX)) < epsilon;
    }
}


// compare arrays
// https://stackoverflow.com/a/10062016

template<typename T>
::testing::AssertionResult arrays_match(
    const T expected,
    const T actual,
    size_t size) {

    for (size_t i(0); i < size; ++i) {
        if (nearlyEqual(expected[i], actual[i], 0.0001) == false) {
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

#define RESULT_ARR_SIZE 3

TEST_F(SolnTest, plusminus_provided_case) {
    size_t n = 6;
    float actual[3];

    int arr1[n] = { -4, 3, -9, 0, 4, 1};
    float expected[3] = {0.500000, 0.333333, 0.166667};
    plusminus(arr1,n,actual);
    EXPECT_TRUE(arrays_match(expected,actual,RESULT_ARR_SIZE));
}

TEST_F(SolnTest, plusminus_edge_case) {
    size_t n = 1;
    float actual[3];

    // one value, negative
    n = 1;
    int arr1[n] = { -11 };
    float expected1[3] = {0.000000, 1.000000, 0.000000};
    plusminus(arr1,n,actual);
    EXPECT_TRUE(arrays_match(expected1,actual,RESULT_ARR_SIZE));

    // one value, zero
    n = 1;
    int arr2[n] = { 0 };
    float expected2[3] = {0.000000, 0.000000, 1.000000};
    plusminus(arr2,n,actual);
    EXPECT_TRUE(arrays_match(expected2,actual,RESULT_ARR_SIZE));

    // one value, positive
    n = 1;
    int arr3[n] = { 11 };
    float expected3[3] = {1.000000, 0.000000, 0.000000};
    plusminus(arr3,n,actual);
    EXPECT_TRUE(arrays_match(expected3,actual,RESULT_ARR_SIZE));
}

TEST_F(SolnTest, plusminus_more) {
    size_t n = 5;
    float actual[3];

    // all positives
    int arr1[n] = { 1, 2, 3, 4, 5 };
    float expected1[3] = {1.000000, 0.000000, 0.000000};
    plusminus(arr1,n,actual);
    EXPECT_TRUE(arrays_match(expected1,actual,RESULT_ARR_SIZE));

    // all negatives
    int arr2[n] = { -1, -2, -3, -4, -5 };
    float expected2[3] = {0.000000, 1.000000, 0.000000};
    plusminus(arr2,n,actual);
    EXPECT_TRUE(arrays_match(expected2,actual,RESULT_ARR_SIZE));

    // all zeros
    int arr3[n] = { 0, 0, 0, 0, 0 };
    float expected3[3] = {0.000000, 0.000000, 1.000000};
    plusminus(arr3,n,actual);
    EXPECT_TRUE(arrays_match(expected3,actual,RESULT_ARR_SIZE));

    n = 3;

    // 1 pos, 2 negative
    int arr4[n] = { 1, -2, -3 };
    float expected4[3] = {0.333333, 0.666667, 0.000000};
    plusminus(arr4,n,actual);
    EXPECT_TRUE(arrays_match(expected4,actual,RESULT_ARR_SIZE));

    // 1 pos, 2 zeros
    int arr5[n] = { 1, 0, 0 };
    float expected5[3] = {0.333333, 0.000000, 0.666667};
    plusminus(arr5,n,actual);
    EXPECT_TRUE(arrays_match(expected5,actual,RESULT_ARR_SIZE));

    // 2 pos, 1 negative
    int arr6[n] = { 1, 2, -3 };
    float expected6[3] = {0.666667, 0.333333, 0.000000};
    plusminus(arr6,n,actual);
    EXPECT_TRUE(arrays_match(expected6,actual,RESULT_ARR_SIZE));

    // 2 pos, 1 zeros
    int arr7[n] = { 1, 2, 0 };
    float expected7[3] = {0.666667, 0.000000, 0.333333};
    plusminus(arr7,n,actual);
    EXPECT_TRUE(arrays_match(expected7,actual,RESULT_ARR_SIZE));
}

int main (int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
