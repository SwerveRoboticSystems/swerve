cmake_minimum_required(VERSION 2.8.3)
project(swerve_gazebo)

find_package(
	catkin REQUIRED COMPONENTS
)

catkin_package()

include_directories(
	${catkin_INCLUDE_DIRS}
)

install(
	DIRECTORY config launch
	DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)


