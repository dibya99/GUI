#ifndef NODE_2_H
#define NODE_2_H

#include <QMainWindow>
#include<ros/ros.h>
#include<opencv2/opencv.hpp>
#include<image_transport/image_transport.h>
#include<cv_bridge/cv_bridge.h>
#include<QPixmap>
namespace Ui {
class node_2;
}

class node_2 : public QMainWindow
{
    Q_OBJECT

public:
     node_2(ros::NodeHandle _nh,QWidget *parent=0 );
    ~node_2();
    void callback(const sensor_msgs::ImageConstPtr& msg);



private slots:
    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_4_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

    void on_horizontalSlider_5_valueChanged(int value);

    void on_horizontalSlider_3_valueChanged(int value);

    void on_horizontalSlider_6_valueChanged(int value);

private:
    int h,hmax,s,smax,v,vmax;
    Ui::node_2 *ui;
    ros::NodeHandle nh;
    image_transport::ImageTransport it;
    image_transport::Publisher pub;
    image_transport::Subscriber sub;
    QPixmap pix;


};

#endif // NODE_2_H
