#include <gtest/gtest.h>
#include "ros/ros.h"
#include "../src/calculator.h"
#include <thread>

int main(int argc, char **argv)
{
//  testing::InitGoogleTest(&argc, argv);
//  ros::Rate loop_rate(10);
//  std::thread t([&]{
//          while(ros::ok())
//          {
//              ros::spinOnce();
//              std::cout<< "hello\n";
//              loop_rate.sleep();
//          }
//  });
//
//  ros::init(argc, argv, "Node_Unit_Test_Node");
//  auto result = RUN_ALL_TESTS();
//
//  ros::shutdown();
//  return result;

    testing::InitGoogleTest(&argc, argv);
    ros::init(argc, argv, "subscribe_star");
    ros::NodeHandle nh;
    ros::master::check();
    return RUN_ALL_TESTS();
}
