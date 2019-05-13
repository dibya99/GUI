#include "node_2.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"Node_2");
    ros::NodeHandle nh;
    QApplication a(argc, argv);
    node_2 w(nh);
    w.show();
    while(ros::ok())
    {
      ros::spinOnce();
      a.processEvents();
    }

}
