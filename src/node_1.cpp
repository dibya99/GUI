#include<node_1.h>
node_1::node_1(ros::NodeHandle _nh):nh(_nh),it(nh)
{

  sub=nh.subscribe("talk3",1,&node_1::callback, this);
  pub=it.advertise("talk1",1);
  checker=0;
}
void node_1::callback(std_msgs::Int32 msg)
{
  cv::VideoCapture cap(0);
  if(msg.data==1)
  checker=1;
  else
  checker=0;
  while(1)
  {
  if(checker==1)
  {

    cap>>img;
    mg=cv_bridge::CvImage(std_msgs::Header(),"bgr8",img).toImageMsg();
    pub.publish(mg);
     cv::waitKey(0);
     ros::spinOnce();
   }
   else
   break;
}
}
