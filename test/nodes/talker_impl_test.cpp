#include <gtest/gtest.h>
#include "ros/ros.h"
#include "../../src/talker_impl.h"


class AnyHelper
{
public:
    std_msgs::String  _received_msg;
    void cb(std_msgs::String msg)
    {
        _received_msg = msg;
    }
};
TEST(TalkerTest, TalkerTest)
{
    // Mock listener
    ros::NodeHandle n;
    AnyHelper h;
    ros::Subscriber _sub = n.subscribe("talker", 1000, &AnyHelper::cb, &h);

    int argc = 0;
    char **argv = nullptr;
    Talker talker(argc, argv);
    talker.talk(1);
    ros::master::check(); // TODO SF: Why is this needed here?
    ros::spinOnce();
    EXPECT_EQ(h._received_msg.data, std::string("hello world 1"));
}


