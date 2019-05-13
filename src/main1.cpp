#include<node_1.h>
int main(int argc,char **argv)
{
  ros::init(argc,argv,"Node1");
  ros::NodeHandle nh;
  node_1 obj(nh);
  ros::spin();
}
