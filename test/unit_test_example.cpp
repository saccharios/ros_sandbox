#include <gtest/gtest.h>
//#include "ros/ros.h"

TEST(TestSuite, testCase1)
{
    int i = 1;
    int j = 3;
    EXPECT_EQ(4, i + j);
}

TEST(TestSuite, testCase2)
{
    int i = 1;
    int j = 3;
    EXPECT_EQ(5, i + j);
}


int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);

//
//  ros::init(argc, argv, "tester");
//  ros::NodeHandle node_handle;



  return RUN_ALL_TESTS();
}
