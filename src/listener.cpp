/*
 *--**--..--**--..--**--..--**--..--**--..--**--..--**--..--**--..--**--
 * <Subscribe to turtle information from talker.py>. 
 *
 * Author: Zwe Lin Htet
 *
 * Date last updated: 28/9/2019 by Zwe Lin Htet
 *
 * Purpose: receipt of turtle information and check if turtle quality
 *          meets the criteria
 * 
 * Subscribed topic/s: 
 *     /induction_task_lin/turtle_talk
 
 *--..--**--..--**--..--**--..--**--..--**--..--**--..--**--..--**--..--
 */

#include "ros/ros.h"
#include "std_msgs/String.h"
#include "induction_task_lin/TurtleInfo.h"


void chatterCallback(const induction_task_lin::TurtleInfo::ConstPtr& info_of_turtle)
{
  if(info_of_turtle->quality_of_turtle >= 7){
  ROS_INFO("Turtle index:  [%d] \t Turtle quality: [%d] \n ",info_of_turtle->index \
							   ,info_of_turtle->quality_of_turtle);
  }else{
  ROS_INFO("Turtle index:  [%d] \t Turtle quality does not meet the criteria");
  }

}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "listener");
  ros::NodeHandle n;
  ros::Subscriber sub = n.subscribe("/induction_task_lin/turtle_talk", 1000, chatterCallback);
  ros::spin();

  return 0;
}

