#include <gtest/gtest.h>
#include "ros/ros.h"
#include "../src/calculator.h"
#include <thread>

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    ros::init(argc, argv, "subscribe_star");
    return RUN_ALL_TESTS();
}
