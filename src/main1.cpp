#include<node_1.h>
int main(int argc,char **argv)
{

  cv::VideoCapture c;
  ros::init(argc,argv,"Node1");
  ros::NodeHandle nh;
  node_1 obj(nh,&c);
  ros::Rate o(10);
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
