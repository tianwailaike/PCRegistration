#include <iostream>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include "pclviewer.h"
int main(int argc, char **argv) {
    QApplication a(argc,argv);  
    PCLViewer w;
    w.show();
    std::cout << "Hello, world!" << std::endl;
    return a.exec();
}
