#include <gtest/gtest.h>
#include "ros/ros.h"
#include <thread>
#include "../src/calculator.h"


TEST(Calculator, CalculatorLowValue)
{
    Calculator calculator;
    int init_value = 3;
    int value = calculator.do_some_math(init_value);
    EXPECT_EQ(value, init_value + 5);
}

TEST(Calculator, CalculatorHighValue)
{
    Calculator calculator;
    int init_value = 42;
    int value = calculator.do_some_math(init_value);
    EXPECT_EQ(value, 0);

}

//int main(int argc, char **argv)
//{
//  testing::InitGoogleTest(&argc, argv);
//  std::thread t([]{while(ros::ok()) ros::spin();});
//
//  ros::init(argc, argv, "Integration_Test_Node");
//  auto result = RUN_ALL_TESTS();
//
//  ros::shutdown();
//  return result;
//}
//
