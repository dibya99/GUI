#include<node_1.h>
int main(int argc,char **argv)
{

  cv::VideoCapture c(0);
  ros::init(argc,argv,"Node1");
  ros::NodeHandle nh;
  node_1 obj(nh);
  ros::Rate o(5000);
  while(ros::ok())
  {
  if(obj.check())
  {
    //c.open(0);
    c>>obj.img;
    obj.execute();

}
//else
//c.release();

ros::spinOnce();
o.sleep();
}
}
