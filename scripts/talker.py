#!/usr/bin/env python
# license removed for brevity
import rospy
import numpy as np
from std_msgs.msg import String
from induction_task_lin.msg import turtle_info

def talker():
    pub = rospy.Publisher('/turtle_talk', turtle_info, queue_size=10)
    rospy.init_node('talker', anonymous=True)
    rate = rospy.Rate(5) #  1 Hz
    index = 0
    info_of_turtle = turtle_info()
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
