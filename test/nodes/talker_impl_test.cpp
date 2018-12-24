#include <gtest/gtest.h>
#include "ros/ros.h"
#include "talker_impl.h"
#include "beginner_tutorials/Text.h"

class AnyHelper
{
public:
    beginner_tutorials::Text  _received_msg;
    void cb(beginner_tutorials::Text msg)
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
    EXPECT_EQ(h._received_msg.text, std::string("hello world 1"));
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    ros::init(argc, argv, "talker_test_node");
    return RUN_ALL_TESTS();
}
