#!/usr/bin/env python
# license removed for brevity

"""
<One sentence description>.

Author: Zwe Lin Htet

Date last updated: 28/9/2019 by Zwe Lin Htet

Purpose: Publish turtle information

Subscribed topic/s: 
    _______
    _______

 Published topic/s:
    /induction_task_lin/turtle_talk

"""

import rospy
import numpy as np
from std_msgs.msg import String
from induction_task_lin.msg import TurtleInfo

def talker():
    pub = rospy.Publisher('/induction_task_lin/turtle_talk', TurtleInfo, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(5) #  5 Hz
    index = 0
    info_of_turtle = TurtleInfo()
    while not rospy.is_shutdown():

        info_of_turtle.index = index
	info_of_turtle.quality_of_turtle = np.random.randint(10) 
	
	rospy.loginfo(info_of_turtle)
        pub.publish(info_of_turtle)
    	index = index +1
        rate.sleep()

if __name__ == '__main__':
    try:
        talker()
    except rospy.ROSInterruptException:
        pass
