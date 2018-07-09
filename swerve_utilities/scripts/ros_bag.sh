#!/bin/bash
## @file ros_bag.sh
#  @brief Creates a ROS bag of everything on ROS network using current time/day as file name
#  @author Frederick Wachter - wachterfreddy@gmail.com
#  @date Created: 2017-11-26

BAG_DIR=$1
FILE_NAME=$BAG_DIR/bags/`date '+%Y-%m-%d_%H-%M-%S.bag'`

echo "[ROS BAG] Recording ROS bag of all data at: $FILE_NAME"
rosbag record -O $FILE_NAME -a


