#include <gtest/gtest.h>
#include "ros/ros.h"
#include "../src/calculator.h"

int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
//  std::thread t([]{while(ros::ok()) ros::spin();});
//
  ros::init(argc, argv, "Node_Unit_Test_Node");
//  auto result = RUN_ALL_TESTS();
//
//  ros::shutdown();
  return RUN_ALL_TESTS();
}
