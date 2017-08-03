#pragma once 
#ifndef PCLVIEWER_H
#define PCLVIEWER_H
#include <iostream>

// Qt
#include <QtWidgets/QMainWindow>
//#include <QPushButton>

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
#include "icprefine/icprefine.h"
using namespace pcregistration;


//TODO:1,refactor the ui and add some button and sliders for adjusting params
//     2,add the slots and integrate the super4pcs
namespace Ui
{
  class PCLViewer;
}
class PCLViewer : public QMainWindow
{
  Q_OBJECT

public:
  explicit PCLViewer (QWidget *parent = 0);
  ~PCLViewer ();
  void readPLY(std::string filename);
  

public Q_SLOTS:
  void
  randomButtonPressed ();

  void
  RGBsliderReleased ();

  void
  pSliderValueChanged (int value);

  void
  redSliderValueChanged (int value);

  void
  greenSliderValueChanged (int value);

  void
  blueSliderValueChanged (int value);

protected:
  boost::shared_ptr<pcl::visualization::PCLVisualizer> viewer;
  //pcl::visualization::PCLVisualizer::Ptr viewer;
  //boost::shared_ptr<pcl::visualization::CloudVierer> viewer;
  PointCloudT::Ptr cloud;

  unsigned int red;
  unsigned int green;
  unsigned int blue;

private:
  Ui::PCLViewer *ui;
  void initialize();
  icprefine icp;
  
 // QPushButton 

};

#endif // PCLVIEWER_H
