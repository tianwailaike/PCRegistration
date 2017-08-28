#pragma once 
#ifndef ICPVIEWER_H
#define ICPVIEWER_H
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

#include "icprefine/icprefine.h"
using PointT = pcl::PointXYZRGB;
using PointCloudT = pcl::PointCloud<PointT>;
using namespace pcregistration;

//TODO:1,refactor the ui and add some button and sliders for adjusting params
//     2,add the slots and integrate the super4pcs
// namespace Ui
// {
//   class PCLViewer;
// }
class ICPViewer:public QWidget
{
  Q_OBJECT

public:
  explicit ICPViewer (QWidget *parent = 0);
  ~ICPViewer ();
  void createMainWidget();
  void createBtns();
  void createSliders();
  void createLCDNumbers();
  void createActions();
  void init_viewer();
  void initialize();
  icprefine* icp;
  boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
  QVTKWidget* qvtkWidget;
public Q_SLOTS:
  void
  randomButtonPressed ();

  void
  distance_ValueChanged (int value);

  void
  npoints_ValueChanged (int value);

  void 
  pcsize_ValueChanged(int value);
  
  void
  saveButtonPressed ();
  
  void RGBsliderReleased();
  
signals:
  void
  errorChanged(double value);
protected:
  
  //pcl::visualization::PCLVisualizer::Ptr viewer;
  //boost::shared_ptr<pcl::visualization::CloudVierer> viewer;
  PointCloudT::Ptr cloud;
 
private:
 // Ui::PCLViewer *ui;
  std::string modelpath;
  std::string datapath;
   
  QWidget* panelWidget;
  
  QAction* open_file_action;
  QAction* save_file_action;
  QAction* icprefine_action;
  QSlider *hSlider_distance;
  QSlider *hSlider_npoints;
  QSlider *hSlider_pcsize;
  QLCDNumber *lcdNumber_distance;
  QLCDNumber *lcdNumber_npoints;
  QLCDNumber *lcdNumber_error;
  QLCDNumber *lcdNumber_pcsize;
  QLabel *label_distance;
    QLabel *label_npoits;
    QLabel *label_error;
    QLabel *label_pcsize;
    QPushButton *btnicp;
    QPushButton *btnsave;
    Eigen::Matrix<float,4,4> finaltrans;
    PointCloud finalCloud;
    
  double distance;
  int npoints;
  bool is_viewer_initiate;
 // QPushButton 

};

#endif // ICPVIEWER_H
