cmake_minimum_required(VERSION 2.8.3)
project(swerve_utilities)

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

# <exec_name> Node
# add_executable([exec_name] src/[file_1].cpp src/[file_2].cpp)
# target_link_libraries([exec_name] ${catkin_LIBRARIES})
# add_dependencies([exec_name] [package_name]_generate_messages_cpp)


