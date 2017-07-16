cmake_minimum_required(VERSION 2.8.3)
project(swerve_description)

find_package(catkin REQUIRED)

catkin_package()

install(
	DIRECTORY launch robot config
	DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
)


