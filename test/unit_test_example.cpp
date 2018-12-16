#include <gtest/gtest.h>

TEST(TestSuite, testCase1)
{
    int i = 1;
    int j = 3;
    EXPECT_EQ(4, i + j);
}

TEST(TestSuite, testCase2)
{
    int i = 2;
    int j = 3;
    EXPECT_EQ(5, i + j);
}


int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
