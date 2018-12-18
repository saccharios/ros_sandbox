#pragma once
#include "ros/ros.h"
#include "std_msgs/String.h"

#include <sstream>

class Talker
{
public:
    Talker(int argc, char **argv) :
        _n()
{
       _pub = _n.advertise<std_msgs::String>("talker", 1000);
}

    void talk(int num)
    {
        std_msgs::String msg;
        std::stringstream ss;
        ss << "hello world " << num;
        msg.data = ss.str();
        ROS_INFO("%s", msg.data.c_str());
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
