#include <gtest/gtest.h>

#define TESTING

#include "soln.c"


class SolnTest : public testing::Test {

    public:

        // virtual void Setup() {}

        // virtual void TearDown() {}

};

#define EPSILON 0.00001

// Regular large numbers - generally not problematic
TEST_F(SolnTest, big) {
    EXPECT_TRUE(nearlyEqual(1000000, 1000001, EPSILON));
    EXPECT_TRUE(nearlyEqual(1000001, 1000000, EPSILON));
    EXPECT_FALSE(nearlyEqual(10000, 10001, EPSILON));
    EXPECT_FALSE(nearlyEqual(10001, 10000, EPSILON));
}

// Negative large numbers
TEST_F(SolnTest, bigNeg) {
    EXPECT_TRUE(nearlyEqual(-1000000, -1000001, EPSILON));
    EXPECT_TRUE(nearlyEqual(-1000001, -1000000, EPSILON));
    EXPECT_FALSE(nearlyEqual(-10000, -10001, EPSILON));
    EXPECT_FALSE(nearlyEqual(-10001, -10000, EPSILON));
}

// Numbers around 1
TEST_F(SolnTest, mid) {
    EXPECT_TRUE(nearlyEqual(1.0000001, 1.0000002, EPSILON));
    EXPECT_TRUE(nearlyEqual(1.0000002, 1.0000001, EPSILON));
    EXPECT_FALSE(nearlyEqual(1.0002, 1.0001, EPSILON));
    EXPECT_FALSE(nearlyEqual(1.0001, 1.0002, EPSILON));
}

// Numbers around -1
TEST_F(SolnTest, midNeg) {
    EXPECT_TRUE(nearlyEqual(-1.0000001, -1.0000002, EPSILON));
    EXPECT_TRUE(nearlyEqual(-1.0000002, -1.0000001, EPSILON));
    EXPECT_FALSE(nearlyEqual(-1.0002, -1.0001, EPSILON));
    EXPECT_FALSE(nearlyEqual(-1.0001, -1.0002, EPSILON));
}

// Numbers between 1 and 0
TEST_F(SolnTest, small) {
    EXPECT_TRUE(nearlyEqual(0.000000001000001, 0.000000001000002, EPSILON));
    EXPECT_TRUE(nearlyEqual(0.000000001000002f, 0.000000001000001f, EPSILON));
    EXPECT_FALSE(nearlyEqual(0.000000000001002f, 0.000000000001001f, EPSILON));
    EXPECT_FALSE(nearlyEqual(0.000000000001001f, 0.000000000001002f, EPSILON));
}

// Numbers between -1 and 0
TEST_F(SolnTest, smallNeg) {
    EXPECT_TRUE(nearlyEqual(-0.000000001000001, -0.000000001000002, EPSILON));
    EXPECT_TRUE(nearlyEqual(0.000000001000002, -0.000000001000001, EPSILON));
    EXPECT_FALSE(nearlyEqual(-0.000000000001002, -0.000000000001001, EPSILON));
    EXPECT_FALSE(nearlyEqual(-0.000000000001001, -0.000000000001002, EPSILON));
}

// Comparisons involving zero
TEST_F(SolnTest, zero) {
    EXPECT_TRUE(nearlyEqual(0.0, 0.0, EPSILON));
    EXPECT_TRUE(nearlyEqual(0.0, -0.0, EPSILON));
    EXPECT_TRUE(nearlyEqual(-0.0, -0.0, EPSILON));
    EXPECT_FALSE(nearlyEqual(0.00000001, 0.0, EPSILON));
    EXPECT_FALSE(nearlyEqual(0.0, 0.00000001, EPSILON));
    EXPECT_FALSE(nearlyEqual(-0.00000001, 0.0, EPSILON));
    EXPECT_FALSE(nearlyEqual(0.0, -0.00000001, EPSILON));

    EXPECT_TRUE(nearlyEqual(0.0, 1e-40, 0.01));
    EXPECT_TRUE(nearlyEqual(1e-40, 0.0, 0.01));
    EXPECT_FALSE(nearlyEqual(1e-40, 0.0, 0.000001));
    EXPECT_FALSE(nearlyEqual(0.0, 1e-40, 0.000001));

    EXPECT_TRUE(nearlyEqual(0.0, -1e-40, 0.01));
    EXPECT_TRUE(nearlyEqual(-1e-40, 0.0, 0.01));
    EXPECT_FALSE(nearlyEqual(-1e-40, 0.0, 0.000001));
    EXPECT_FALSE(nearlyEqual(0.0, -1e-40, 0.000001));
}

// Comparisons involving extreme values (overflow potential)
TEST_F(SolnTest, extremeMax) {
    EXPECT_TRUE(nearlyEqual(FLT_MAX,FLT_MAX, EPSILON));
    EXPECT_FALSE(nearlyEqual(FLT_MAX, -FLT_MAX, EPSILON));
    EXPECT_FALSE(nearlyEqual(-FLT_MAX, FLT_MAX, EPSILON));
    EXPECT_FALSE(nearlyEqual(FLT_MAX, FLT_MAX/2, EPSILON));
    EXPECT_FALSE(nearlyEqual(FLT_MAX, -FLT_MAX/2, EPSILON));
    EXPECT_FALSE(nearlyEqual(-FLT_MAX, FLT_MAX/2, EPSILON));
}

// Comparisons involving infinities
TEST_F(SolnTest, infinities) {
    EXPECT_TRUE(nearlyEqual(INFINITY, INFINITY, EPSILON));
    EXPECT_TRUE(nearlyEqual(-INFINITY, -INFINITY, EPSILON));
    EXPECT_FALSE(nearlyEqual(-INFINITY, INFINITY, EPSILON));
    EXPECT_FALSE(nearlyEqual(INFINITY, FLT_MAX, EPSILON));
    EXPECT_FALSE(nearlyEqual(-INFINITY, -FLT_MAX, EPSILON));
}

// Comparisons involving NaN
TEST_F(SolnTest, nan) {
    EXPECT_FALSE(nearlyEqual(NAN, NAN, EPSILON));
    EXPECT_FALSE(nearlyEqual(NAN, 0.0, EPSILON));
    EXPECT_FALSE(nearlyEqual(-0.0, NAN, EPSILON));
    EXPECT_FALSE(nearlyEqual(NAN, -0.0, EPSILON));
    EXPECT_FALSE(nearlyEqual(0.0, NAN, EPSILON));
    EXPECT_FALSE(nearlyEqual(NAN, INFINITY, EPSILON));
    EXPECT_FALSE(nearlyEqual(INFINITY, NAN, EPSILON));
    EXPECT_FALSE(nearlyEqual(NAN, -INFINITY, EPSILON));
    EXPECT_FALSE(nearlyEqual(-INFINITY, NAN, EPSILON));
    EXPECT_FALSE(nearlyEqual(NAN, FLT_MAX, EPSILON));
    EXPECT_FALSE(nearlyEqual(FLT_MAX, NAN, EPSILON));
    EXPECT_FALSE(nearlyEqual(NAN, -FLT_MAX, EPSILON));
    EXPECT_FALSE(nearlyEqual(-FLT_MAX, NAN, EPSILON));
    EXPECT_FALSE(nearlyEqual(NAN, FLT_MIN, EPSILON));
    EXPECT_FALSE(nearlyEqual(FLT_MIN, NAN, EPSILON));
    EXPECT_FALSE(nearlyEqual(NAN, -FLT_MIN, EPSILON));
    EXPECT_FALSE(nearlyEqual(-FLT_MIN, NAN, EPSILON));
}

// Comparisons of numbers on opposite sides of 0
TEST_F(SolnTest, opposite) {
    EXPECT_FALSE(nearlyEqual(1.000000001, -1.0, EPSILON));
    EXPECT_FALSE(nearlyEqual(-1.0, 1.000000001, EPSILON));
    EXPECT_FALSE(nearlyEqual(-1.000000001, 1.0, EPSILON));
    EXPECT_FALSE(nearlyEqual(1.0, -1.000000001, EPSILON));
    EXPECT_TRUE(nearlyEqual(10 * FLT_MIN, 10 * -FLT_MIN, EPSILON));
    EXPECT_FALSE(nearlyEqual(10000 * FLT_MIN, 10000 * -FLT_MIN, EPSILON));
}

// The really tricky part - comparisons of numbers very close to zero
TEST_F(SolnTest, ulp) {
    EXPECT_TRUE(nearlyEqual(FLT_MIN, FLT_MIN, EPSILON));
    EXPECT_TRUE(nearlyEqual(FLT_MIN, -FLT_MIN, EPSILON));
    EXPECT_TRUE(nearlyEqual(-FLT_MIN, FLT_MIN, EPSILON));
    EXPECT_TRUE(nearlyEqual(FLT_MIN, 0, EPSILON));
    EXPECT_TRUE(nearlyEqual(0, FLT_MIN, EPSILON));
    EXPECT_TRUE(nearlyEqual(-FLT_MIN, 0, EPSILON));
    EXPECT_TRUE(nearlyEqual(0, -FLT_MIN, EPSILON));

    EXPECT_FALSE(nearlyEqual(0.000000001, -FLT_MIN, EPSILON));
    EXPECT_FALSE(nearlyEqual(0.000000001, FLT_MIN, EPSILON));
    EXPECT_FALSE(nearlyEqual(FLT_MIN, 0.000000001, EPSILON));
    EXPECT_FALSE(nearlyEqual(-FLT_MIN, 0.000000001, EPSILON));
}


int main (int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
