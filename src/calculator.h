#pragma once
#include <std_msgs/String.h>
#include "ros/ros.h"

class Calculator
{
public:
    Calculator() :
     _nh(),
    _pub()
    {
        _pub = _nh.advertise<std_msgs::String>("topic_name",1);
    }

    int do_some_math(int value);
    void talk(int value);
    ros::NodeHandle _nh;
    ros::Publisher _pub;


};
