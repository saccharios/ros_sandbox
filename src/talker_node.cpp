#include "ros/ros.h"
#include "talker_impl.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");
  Talker talker(argc, argv);
  talker.run();
  return 0;
}

