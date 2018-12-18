#include <gtest/gtest.h>
#include "ros/ros.h"
#include <thread>

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    ros::init(argc, argv, "unit_test_node");
    return RUN_ALL_TESTS();
}
