#pragma once
#include "ros/ros.h"
#include <sstream>
#include "beginner_tutorials/Text.h"

class Talker
{
public:
    Talker(int argc, char **argv) :
        _n()
{
       _pub = _n.advertise<beginner_tutorials::Text>("talker", 1000);
}

    void talk(int num)
    {
        beginner_tutorials::Text msg;
        std::stringstream ss;
        ss << "hello world " << num;
        msg.text = ss.str();
        ROS_INFO("%s", msg.text.c_str());
        _pub.publish(msg);
    }

    void run()
    {
        ros::Rate loop_rate(10);
        while (ros::ok())
        {
            talk(_count);
            loop_rate.sleep();
            ++_count;
        }
    }

private:
    ros::NodeHandle _n;
    ros::Publisher _pub;
    int _count = 0;

};
