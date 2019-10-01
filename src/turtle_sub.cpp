/*
*--**--..--**--..--**--..--**--..--**--..--**--..--**--..--**--..--**--
* "Subscribe to turtle information from turtle_pub.py" 
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


void turtleTalkCallback(const induction_task_lin::TurtleInfo::ConstPtr& turtle_info)
{
	if(turtle_info->quality >= 7){
		ROS_INFO("Turtle index:  [%d] \t Turtle quality: [%d] \n ",turtle_info->index \
                ,turtle_info->quality);
	}else{
		ROS_INFO("Turtle index:  [%d] \t Turtle quality does not meet the criteria",turtle_info->index );
	}

}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "turtle_sub");
	ros::NodeHandle n;
	ros::Subscriber sub = n.subscribe("/induction_task_lin/turtle_talk", 1000, turtleTalkCallback);
	ros::spin();

	return 0;
}

