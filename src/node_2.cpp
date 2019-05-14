#include "node_2.h"
#include "ui_node_2.h"

node_2::node_2(ros::NodeHandle _nh,QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::node_2),nh(_nh),it(nh)
{
    ui->setupUi(this);
    sub=it.subscribe("talk1",1000,&node_2::callback,this);
    pub=it.advertise("talk2",1000);
    h=0;
    hmax=0;
    s=0;
    smax=0;
    v=0;
    vmax=0;


}

node_2::~node_2()
{
    delete ui;
}

void node_2::on_horizontalSlider_valueChanged(int value)
{
h=value;
}

void node_2::on_horizontalSlider_4_valueChanged(int value)
{
hmax=value;
}

void node_2::on_horizontalSlider_2_valueChanged(int value)
{
s=value;
}

void node_2::on_horizontalSlider_5_valueChanged(int value)
{
smax=value;
}

void node_2::on_horizontalSlider_3_valueChanged(int value)
{
v=value;
}

void node_2::on_horizontalSlider_6_valueChanged(int value)
{
vmax=value;
}
void node_2::callback(const sensor_msgs::ImageConstPtr& msg)
{
  cv::Mat img=cv_bridge::toCvShare(msg,"bgr8")->image;
  cv::Mat img2;
  cv::cvtColor(img,img2,CV_BGR2HSV);
  cv::inRange(img2,cv::Scalar(h,s,v),cv::Scalar(hmax,smax,vmax),img2);
  cv::cvtColor(img2,img2,CV_GRAY2RGB);
  sensor_msgs::ImagePtr mg=cv_bridge::CvImage(std_msgs::Header(),"rgb8",img2).toImageMsg();
  pub.publish(mg);
  cv::cvtColor(img,img,CV_BGR2RGB);
// pix=QPixmap::fromImage(QImage(img2.data,img2.cols,img2.rows,img2.step,QImage::Format_Indexed8));
pix=QPixmap::fromImage(QImage(img.data,img.cols,img.rows,img.step,QImage::Format_RGB888));
 int w=ui->label_8->width();
  int h=ui->label_8->height();
  ui->label_8->setPixmap(pix.scaled(300,300,Qt::KeepAspectRatio));

}
