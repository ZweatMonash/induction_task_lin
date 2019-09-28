#include "ros/ros.h"
#include "std_msgs/String.h"
#include "induction_task_lin/turtle_info.h"

/**
 * This tutorial demonstrates simple receipt of messages over the ROS system.
 */
void chatterCallback(const induction_task_lin::turtle_info::ConstPtr& info_of_turtle)
{
  ROS_INFO("Turtle index:  [%d] \nTurtle quality: [%d] \n ",info_of_turtle->index \
							   ,info_of_turtle->quality_of_turtle);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("/turtle_talk", 1000, chatterCallback);
  ros::spin();

  return 0;
}

