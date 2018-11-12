#include "ros/ros.h"
#include "std_msgs/String.h"
#include "listener_impl.h"

int main(int argc, char **argv)
{
    ListenerImpl listener(argc, argv);
    ros::spin();
    return 0;
}
