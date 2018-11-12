#include <gtest/gtest.h>
#include "ros/ros.h"
#include "../src/listener_impl.h"

TEST(ListenerTest, Listen)
{

    int argc = 0;
    char **argv = nullptr;
    ros::init(argc, argv, "tester");
    // Mock talker
    ros::NodeHandle n;
    ros::Publisher talker_pub = n.advertise<std_msgs::String>("talker", 1000);
    std_msgs::String expected_msg;
    std::stringstream ss;
    ss << "listener node test";
    expected_msg.data = ss.str();
    talker_pub.publish(expected_msg);


    ListenerImpl listener(argc, argv);
    ros::spinOnce();
    std::string actual_msg = listener.getMessage();
    EXPECT_EQ(actual_msg, expected_msg.data);

}


int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);

//  ros::init(argc, argv, "tester");
//  ros::NodeHandle node_handle;

  return RUN_ALL_TESTS();
}

