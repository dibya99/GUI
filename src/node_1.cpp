#include<node_1.h>
node_1::node_1(ros::NodeHandle _nh):nh(_nh),it(nh)
{

  sub=nh.subscribe("talk3",1,&node_1::callback, this);
  pub=it.advertise("talk1",1);

}
void node_1::callback(std_msgs::Int32 msg)
{
  if(msg.data==1)
  {
    cv::VideoCapture cap(0);
    cap>>img;
    mg=cv_bridge::CvImage(std_msgs::Header(),"bgr8",img).toImageMsg();
    pub.publish(mg);
     cv::waitKey(0);
  }
}
