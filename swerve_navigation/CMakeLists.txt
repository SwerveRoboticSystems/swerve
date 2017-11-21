cmake_minimum_required(VERSION 2.8.3)
project(swerve_navigation)

find_package(
	catkin REQUIRED COMPONENTS
	tf
	nav_msgs
)

catkin_package()

include_directories(
	${catkin_INCLUDE_DIRS}
)

install(
	DIRECTORY config launch
	DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)

# Odom Publisher Node
add_executable(odom_pub src/odom_pub.cpp)
target_link_libraries(odom_pub ${catkin_LIBRARIES})
add_dependencies(odom_pub [package_name]_generate_messages_cpp)


