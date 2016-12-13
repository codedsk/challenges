#include "box.cc"
#include <gtest/gtest.h>


class BoxTest : public testing::Test {

    public:
        Box b1;

        // virtual void Setup() {}

        // virtual void TearDown() {}

};


TEST_F(BoxTest, ConstructorDefault) {
    Box b2;
    EXPECT_EQ(0, b2.getLength());
    EXPECT_EQ(0, b2.getBreadth());
    EXPECT_EQ(0, b2.getHeight());
}

TEST_F(BoxTest, ConstructorIntIntInt) {
    Box b3(2,3,4);
    EXPECT_EQ(2, b3.getLength());
    EXPECT_EQ(3, b3.getBreadth());
    EXPECT_EQ(4, b3.getHeight());
}

TEST_F(BoxTest, ConstructorCopy) {
    Box b4(Box(5,6,7));
    EXPECT_EQ(5, b4.getLength());
    EXPECT_EQ(6, b4.getBreadth());
    EXPECT_EQ(7, b4.getHeight());
}

int main (int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
