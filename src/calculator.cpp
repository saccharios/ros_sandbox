#include "calculator.h"
#include <std_msgs/String.h>

int Calculator::do_some_math(int value)
{
    return value<10?(value + 5):0;
}
void Calculator::talk(int value)
{
    std_msgs::String msg;
    std::stringstream ss;
    ss<<"hello world "<< value;
    msg.data = ss.str();
    _pub.publish(msg);
    ROS_INFO_STREAM( "I publish: " << msg);
}
