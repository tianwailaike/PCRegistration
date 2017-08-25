#pragma once 
#ifndef SUPERVIEWER_H
#define SUPERVIEWER_H
#include <iostream>

// Qt
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStackedWidget>
#include "QVTKWidget.h"

// Point Cloud Library
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/io/ply_io.h>
#include <pcl/io/obj_io.h>
#include <pcl/visualization/cloud_viewer.h>

// Visualization Toolkit (VTK)
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkActor.h>
#include <vtkLODActor.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkPLYReader.h>
// typedef pcl::PointXYZRGBA PointT;
// typedef pcl::PointCloud<PointT> PointCloudT;
using PointT = pcl::PointXYZRGB;
using PointCloudT = pcl::PointCloud<PointT>;
#include "super.h"
using namespace pcregistration;


//TODO:1,refactor the ui and add some button and sliders for adjusting params
//     2,add the slots and integrate the super4pcs
class superViewer : public QWidget
{
   Q_OBJECT

public:
  explicit superViewer (QWidget *parent = 0);
  ~superViewer ();
  void createMainWidget();
  void createBtns();
  void createSliders();
  void createLCDNumbers();
  void createMenus();
  void createActions();
  void init_viewer();
  boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
  QVTKWidget* qvtkWidget;
  
public Q_SLOTS:
  void
  superButtonPressed ();

  void
  RGBsliderReleased ();

  void
  delta_ValueChanged (int value);

  void
  npoints_ValueChanged (int value);

  void
  pcsize_ValueChanged (int value);
  
  void
  saveButtonPressed ();
  
signals:
  void
  errorChanged(double value);
protected:
  
  //pcl::visualization::PCLVisualizer::Ptr viewer;
  //boost::shared_ptr<pcl::visualization::CloudVierer> viewer;
  PointCloudT::Ptr cloud;

  unsigned int red;
  unsigned int green;
  unsigned int blue;
 
private:
  std::string referencepath;
  std::string currentpath;
  QWidget* centralwidget;
  QWidget* panelWidget;
  
  void initialize();
  super* super_;
  QSlider *hSlider_delta;
    QSlider *hSlider_npoints;
    QSlider *hSlider_pcsize;
    QLCDNumber *lcdNumber_delta;
    QLCDNumber *lcdNumber_npoints;
    QLCDNumber *lcdNumber_pcsize;
    QLabel *label_delta;
    QLabel *label_npoints;
    QLabel *label_pcsize;
    QPushButton *btnsuper;
    QPushButton *btnsave;
    Eigen::Matrix<float,4,4> finaltrans;
    PointCloud finalCloud;
    int npoints;

};

#endif // SUPERVIEWER_H
