#ifndef NODE_3_H
#define NODE_3_H

#include<ros/ros.h>
#include<opencv2/opencv.hpp>
#include<image_transport/image_transport.h>
#include<cv_bridge/cv_bridge.h>
#include<std_msgs/Int32.h>
#include <QMainWindow>
#include<QPixmap>
namespace Ui {
class node_3;
}

class node_3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit node_3(ros::NodeHandle _nh,QWidget *parent = 0);
    ~node_3();
    void callback(const sensor_msgs::ImageConstPtr& msg);


private slots:
    void on_checkBox_clicked(bool checked);

private:
    Ui::node_3 *ui;
    ros::NodeHandle nh;
    image_transport::ImageTransport it;
    image_transport::Subscriber sub;
    ros::Publisher pub;
    QPixmap pix;
};

#endif // NODE_3_H
