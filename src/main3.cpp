#include "node_3.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    ros::init(argc,argv,"Node_3");
    ros::NodeHandle nh;
    QApplication a(argc, argv);
    node_3 w(nh);
    w.show();

    while(ros::ok())
    {
      ros::spinOnce();
      a.processEvents();
    }
}
