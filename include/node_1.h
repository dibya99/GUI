#ifndef NOD_1
#define NOD_1

#include<ros/ros.h>
#include<opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include<image_transport/image_transport.h>
#include<cv_bridge/cv_bridge.h>
#include<iostream>
#include<std_msgs/Int32.h>
class node_1
{
private:
  cv::Mat img;
  ros::NodeHandle nh;
  image_transport::ImageTransport it;
  image_transport::Publisher pub;
  ros::Subscriber sub;
  sensor_msgs::ImagePtr mg;
public:
  node_1(ros::NodeHandle _nh);
  void callback(std_msgs::Int32 msg);

};
#endif
