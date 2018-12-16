#include <rosconsole/macros_generated.h>
#include "ros/ros.h"
#include "std_msgs/String.h"

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


    void talkerCallback(const std_msgs::String::ConstPtr& msg)
    {
        _message = msg->data.c_str();
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

