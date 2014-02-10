// Program to move the arms of our Three_Robot_Arm Robot //
// Luiz Felipe Santos Vecchietti and Cho Kang Un//

#include "ros/ros.h"
#include "std_msgs/Float64.h"

int main(int argc, char **argv)
{
  //const float ANGLE_RAD = 0.1;

  //Initialize the node
  ros::init(argc, argv, "move_arm_2");
  ros::NodeHandle node;
  ros::NodeHandle node2; // Node to second motor
  ros::NodeHandle node3; // Node to third motor

  //A publisher for the movement data
  ros::Publisher pub = node.advertise<std_msgs::Float64>("first_motor_controller/command",10);
  
  ros::Publisher pub2 = node2.advertise<std_msgs::Float64>("second_motor_controller/command",10); // Publisher for second motor

  ros::Publisher pub3 = node3.advertise<std_msgs::Float64>("third_motor_controller/command",10); // Publisher for third motor


 //Move the robot to the desirable angle


  std_msgs::Float64 msg;
  msg.data = 0.1;

  //Loop at 10Hz, publishing messages until shut down
  ros::Rate rate(0.3);
  ROS_INFO("Starting to move");
  while (ros::ok()){
    pub.publish(msg);
    rate.sleep();
    pub2.publish(msg);
    rate.sleep();
    pub3.publish(msg);
    msg.data = msg.data*(-1);
    rate.sleep();
  }
  return 0;
}

