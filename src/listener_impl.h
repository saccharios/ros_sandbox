#pragma once
#include <rosconsole/macros_generated.h>
#include "ros/ros.h"
#include "beginner_tutorials/Text.h"
class ListenerImpl
{
public:
    ListenerImpl(int argc, char **argv) :
        _n(),
        _sub(),
        _message()
    {
        _sub = _n.subscribe("talker", 1000, &ListenerImpl::talkerCallback, this);
    }


    void talkerCallback(const beginner_tutorials::TextConstPtr & msg)
    {
        _message = msg->text;
        ROS_INFO_STREAM( "I heard: " << _message);
    }

    std::string getMessage() const
    {
        return _message;
    }

private:
    ros::NodeHandle _n;
    ros::Subscriber _sub;
    std::string _message;



};

