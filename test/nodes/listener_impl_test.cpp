#include <gtest/gtest.h>
#include "ros/ros.h"
#include "listener_impl.h"
#include <rosconsole/macros_generated.h>
#include "beginner_tutorials/Text.h"

TEST(ListenerTest, ListenerTest)
{

    // Mock talker
    ros::NodeHandle n;
    ros::Publisher talker_pub = n.advertise<beginner_tutorials::Text>("talker", 1000);
    beginner_tutorials::Text expected_msg;
    std::stringstream ss;
    ss << "listener node test";
    expected_msg.text = ss.str();


    int argc = 0;
    char **argv = nullptr;
    ListenerImpl listener(argc, argv);
    talker_pub.publish(expected_msg);
    ros::master::check(); // TODO SF: Why is this needed here?
    ros::spinOnce();
    std::string actual_msg = listener.getMessage();
    EXPECT_EQ(actual_msg, expected_msg.text);
}

class AnyHelper
{
public:
    int _count = 0;
    void cb(beginner_tutorials::Text)
    {
        ++_count;
    }
};

TEST(Generic, SelfSubscriber)
{
    ros::NodeHandle nh;
    AnyHelper h;
    ros::Subscriber sub = nh.subscribe("generic", 1000, &AnyHelper::cb, &h);
    ros::Publisher pub = nh.advertise<beginner_tutorials::Text>("generic",1000);

    EXPECT_EQ(pub.getNumSubscribers(), 1);
    EXPECT_EQ(sub.getNumPublishers(), 1);

    beginner_tutorials::Text expected_msg;
    std::stringstream ss;
    expected_msg.text = ss.str();
    ROS_INFO_STREAM(expected_msg.text);
    std::cerr << expected_msg.text <<"\n";
    pub.publish(expected_msg);

    ros::master::check(); // TODO SF: Why is this needed here?
    ros::spinOnce();

    EXPECT_EQ(h._count, 1);
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    ros::init(argc, argv, "listener_test_node");
    return RUN_ALL_TESTS();
}
