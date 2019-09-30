cmake_minimum_required(VERSION 2.8.3)
project(induction_task_lin)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)


## Generate messages in the 'msg' folder
add_message_files(
  FILES
  TurtleInfo.msg
 )

## Generate added messages and services with any dependencies listed here
generate_messages(
   DEPENDENCIES
   std_msgs
)


catkin_package(
  CATKIN_DEPENDS roscpp rospy std_msgs
)


include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(turtle_sub src/turtle_sub.cpp)
target_link_libraries(turtle_sub ${catkin_LIBRARIES})
#add_dependencies(turtle_sub induction_task_lin_generate_message_cpp)

