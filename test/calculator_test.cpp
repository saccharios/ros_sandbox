#include <gtest/gtest.h>
#include "ros/ros.h"
#include <thread>

TEST(Calculator, lowValue)
{

}

TEST(Calculator, highValue)
{

}

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  std::thread t([]{while(ros::ok()) ros::spin();});

  auto result = RUN_ALL_TESTS();

  ros::shutdown();
  return result;
}

