#include "node_3.h"
#include "ui_node_3.h"

node_3::node_3(ros::NodeHandle _nh,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::node_3),nh(_nh),it(_nh)
{
    ui->setupUi(this);
    sub=it.subscribe("talk2",1000,&node_3::callback,this);
    pub=nh.advertise<std_msgs::Int32>("talk3",1000);
}

node_3::~node_3()
{
    delete ui;
}
void node_3::callback(const sensor_msgs::ImageConstPtr& msg)
{
  cv::Mat img=cv_bridge::toCvShare(msg,"mono8")->image;
  pix=QPixmap::fromImage(QImage((const unsigned char*)(img.data),img.cols,img.rows,img.step,QImage::Format_Indexed8));
  int w=ui->label->width();
  int h=ui->label->height();
  ui->label->setPixmap(pix.scaled(w,h,Qt::AspectRatioMode));
  //.scaled(w,h),Qt::KeepAspectRatio


}



void node_3::on_checkBox_clicked(bool checked)
{
  std_msgs::Int32 msg;
   if(checked)
   {



     msg.data=1;
     pub.publish(msg);
   }
   else
   {
    msg.data=0;
    pub.publish(msg);
   }




}
