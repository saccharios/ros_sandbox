#include <gtest/gtest.h>
#include "ros/ros.h"
#include "../../src/listener_impl.h"
#include <rosconsole/macros_generated.h>
#include "std_msgs/String.h"

TEST(ListenerTest, ListenerTest)
{

    int argc = 0;
    char **argv = nullptr;
    // Mock talker
    ros::NodeHandle n;
    ros::Publisher talker_pub = n.advertise<std_msgs::String>("talker", 1000);
    std_msgs::String expected_msg;
    std::stringstream ss;
    ss << "listener node test";
    expected_msg.data = ss.str();


    ListenerImpl listener(argc, argv);
    talker_pub.publish(expected_msg);
    ros::master::check(); // TODO SF: Why is this needed here?
    ros::spinOnce();
    std::string actual_msg = listener.getMessage();
    EXPECT_EQ(actual_msg, expected_msg.data);
}

class AnyHelper
{
public:
    int _count = 0;
    void cb(std_msgs::String)
    {
        ++_count;
    }
};

TEST(Generic, SelfSubscriber)
{
    ros::NodeHandle nh;
    AnyHelper h;
    ros::Subscriber sub = nh.subscribe("generic", 1000, &AnyHelper::cb, &h);
    ros::Publisher pub = nh.advertise<std_msgs::String>("generic",1000);

    EXPECT_EQ(pub.getNumSubscribers(), 1);
    EXPECT_EQ(sub.getNumPublishers(), 1);

    std_msgs::String expected_msg;
    std::stringstream ss;
    expected_msg.data = ss.str();
    ROS_INFO_STREAM(expected_msg.data.c_str());
    std::cerr << expected_msg.data.c_str() <<"\n";
    pub.publish(expected_msg);

    ros::master::check(); // TODO SF: Why is this needed here?
    ros::spinOnce();

    EXPECT_EQ(h._count, 1);
}


