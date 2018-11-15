#include <gtest/gtest.h>
#include "ros/ros.h"
#include "../src/listener_impl.h"

//TEST(ListenerTest, Listen)
//{
//
//    int argc = 0;
//    char **argv = nullptr;
//    // Mock talker
//    ros::NodeHandle n;
//    ros::Publisher talker_pub = n.advertise<std_msgs::String>("talker", 1000);
//    std_msgs::String expected_msg;
//    std::stringstream ss;
//    ss << "listener node test";
//    expected_msg.data = ss.str();
//
//
//    ListenerImpl listener(argc, argv)
//    ros::spinOnce();
//    talker_pub.publish(expected_msg);
//    ros::spinOnce();
//    std::string actual_msg = listener.getMessage();
//    EXPECT_EQ(actual_msg, expected_msg.data);
//
//}

class AnyHelper
{
public:
    int _count = 0;
    void cb(std_msgs::String)
    {
        ++_count;
    }
};

TEST(Generic, Do)
{
    ros::NodeHandle nh;
    AnyHelper h;
    ros::Subscriber sub = nh.subscribe("generic", 0, &AnyHelper::cb, &h);
    ros::Publisher pub = nh.advertise<std_msgs::String>("generic",0);

    EXPECT_EQ(pub.getNumSubscribers(), 1);
    EXPECT_EQ(sub.getNumPublishers(), 1);

    std_msgs::String expected_msg;
    std::stringstream ss;
    ss << "generic test";
    expected_msg.data = ss.str();
    pub.publish(expected_msg);
    ros::spinOnce();

    EXPECT_EQ(h._count, 1);
}


int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);

  ros::init(argc, argv, "tester");
  ros::NodeHandle node_handle;

  return RUN_ALL_TESTS();
}

