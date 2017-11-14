/** @file odom_pub.cpp
 *  @brief Publishes transform between the world and odometry frame
 *  @author Frederick Wachter - wachterfreddy@gmail.com
 *  @date Created: 2017-11-13
 */

#include <nav_msgs/Odometry.h>
#include <ros/ros.h>
#include <tf/transform_broadcaster.h>

#define QUEUE_SIZE 100 /**< set queue size for publisher and subscribers */

void odomSubscriber(const nav_msgs::Odometry::ConstPtr&);
/** @fn void odomSubscriber(const nav_msgs::Odometry::ConstPtr&)
 *  @brief Subscriber for odometry of robot
 *  @author Frederick Wachter - wachterfreddy@gmail.com
 *  @date Created: 2017-11-13
 */

#ifndef DOXYGEN_SKIP // don't skip main function
int main(int argc, char** argv){

  ros::init(argc, argv, "odometry_publisher");
  ros::NodeHandle node_handle;

  ROS_INFO("[ODOM] World odometry publisher started");
  ros::Subscriber tf_sub = node_handle.subscribe("/odom", QUEUE_SIZE, &odomSubscriber);

  ros::spin();
  return 0;

}
#endif /* DOXYGEN_SKIP */

void odomSubscriber(const nav_msgs::Odometry::ConstPtr& odom_msg) {
/** @param odom_msg - incoming odometry message of robot
 */
  
  ROS_INFO("[ODOM] Received odom");
  
  static tf::TransformBroadcaster odom_broadcaster;
  tf::Transform transform;

  transform.setOrigin(tf::Vector3(odom_msg->pose.pose.position.x, odom_msg->pose.pose.position.y, 
      odom_msg->pose.pose.position.z));
  tf::Quaternion quaternion(odom_msg->pose.pose.orientation.x, odom_msg->pose.pose.orientation.y, 
      odom_msg->pose.pose.orientation.z, odom_msg->pose.pose.orientation.w);
  transform.setRotation(quaternion);

  odom_broadcaster.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", "odom"));

}


