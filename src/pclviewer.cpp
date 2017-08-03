#include "pclviewer.h"
#include "../build/ui_pclviewer.h"
#include <boost/make_shared.hpp>
using namespace pcregistration;
PCLViewer::PCLViewer (QWidget *parent) :
  QMainWindow (parent),
  ui (new Ui::PCLViewer)
{
  ui->setupUi (this);
  this->setWindowTitle ("PCL viewer");
  /*
  //cloud.reset (new PointCloudT);
//   vtkSmartPointer<vtkPLYReader> reader =vtkSmartPointer<vtkPLYReader>::New();
//   reader->SetInputData(cloud);
//   vtkSmartPointer<vtkPolyDataMapper> map = vtkSmartPointer<vtkPolyDataMapper>::New();
//   //vtkSmartPointer<vtkPolyData> plydata = vtkSmartPointer<vtkPolyData>::New();
//   //plydata->seti(reader->GetOutput());
//   map->SetInputData(reader->GetOutput());
//   vtkSmartPointer<vtkLODActor> actor = vtkSmartPointer<vtkLODActor>::New();
//   actor->SetMapper(map);
   //if (pcl::io::loadPLYFile("/home/ubuntu/lyc2017/EFusion/carbadtop.ply",*cloud)==-1)
//    if(pcl::io::loadPLYFile("/home/ubuntu/lyc2017/EFusion/carbadtop.ply",*cloud)==-1)
// 	{
// 		PCL_ERROR("Couldn't read file test_points1.ply \n"); //文件不存在时，返回错误，终止程序。
// 		//return (-1);
// 	}
// 	std::cout << "Loaded "
// 		<< cloud->width * cloud->height
// 		<< " data points from points1.ply with the following fields: "
// 		<< std::endl;
//   // Setup the cloud pointer
//   cloud.reset (new PointCloudT);
//   // The number of points in the cloud
//   cloud->points.resize (200);
// 
//   // The default color
//   red   = 128;
//   green = 128;
//   blue  = 128;
// 
//   // Fill the cloud with some points
//   for (size_t i = 0; i < cloud->points.size (); ++i)
//   {
//     cloud->points[i].x = 1024 * rand () / (RAND_MAX + 1.0f);
//     cloud->points[i].y = 1024 * rand () / (RAND_MAX + 1.0f);
//     cloud->points[i].z = 1024 * rand () / (RAND_MAX + 1.0f);
// 
//     cloud->points[i].r = red;
//     cloud->points[i].g = green;
//     cloud->points[i].b = blue;
//   }
*/
  
  std::string modelpath = "/home/ubuntu/lyc2017/pcp/icptest/models/bunny.obj";
  
  std::string datapath  = "/home/ubuntu/lyc2017/pcp/icptest/models/bunny_data.obj";
  icp.init_icp(modelpath,datapath);
  icp.run_icp();
  /*
//   pcl::visualization::PCLVisualizer viewer = icp.init_viewer();
//    while (!viewer.wasStopped()) { 
// //    if(toggle)
// //   {
// //   viewer.addPointCloud(dataCloud, transformed_cloud_color_handler,
// //                        "transformed_cloud");
// //   viewer.updatePointCloud(dataCloud,"transformed_cloud");
// //   toggle = !toggle;
// //   }
//     viewer.spinOnce();
  // Set up the QVTK window
//   pcl::visualization::PCLVisualizer::Ptr viewer_ = 
//   icp.init_viewer();
*/
  viewer.reset (new pcl::visualization::PCLVisualizer ("viewer", false)); 
  icp.init_viewer(viewer);
  std::cout<<"0"<<std::endl;
  ui->qvtkWidget->SetRenderWindow (viewer->getRenderWindow ());
  std::cout<<"1"<<std::endl;
  if(ui->qvtkWidget->GetInteractor()==nullptr)
    std::cout<<"Interactor"<<std::endl;
  if(ui->qvtkWidget->GetRenderWindow ()==nullptr)
    std::cout<<"renderwindow"<<std::endl;
  viewer->setupInteractor (ui->qvtkWidget->GetInteractor(), ui->qvtkWidget->GetRenderWindow ());
  std::cout<<"1.5"<<std::endl;
  ui->qvtkWidget->update ();
  std::cout<<"2"<<std::endl;

  // Connect "random" button and the function
  connect (ui->pushButton_random,  SIGNAL (clicked ()), this, SLOT (randomButtonPressed ()));

  // Connect R,G,B sliders and their functions
  connect (ui->horizontalSlider_R, SIGNAL (valueChanged (int)), this, SLOT (redSliderValueChanged (int)));
  connect (ui->horizontalSlider_G, SIGNAL (valueChanged (int)), this, SLOT (greenSliderValueChanged (int)));
  connect (ui->horizontalSlider_B, SIGNAL (valueChanged (int)), this, SLOT (blueSliderValueChanged (int)));
  connect (ui->horizontalSlider_R, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));
  connect (ui->horizontalSlider_G, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));
  connect (ui->horizontalSlider_B, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));

  // Connect point size slider
  connect (ui->horizontalSlider_p, SIGNAL (valueChanged (int)), this, SLOT (pSliderValueChanged (int)));

 // viewer->addPointCloud (cloud, "cloud");
  pSliderValueChanged (2);
  viewer->resetCamera ();
  ui->qvtkWidget->update ();
}

void 
PCLViewer::initialize()
{
  
}
void 
PCLViewer::readPLY(std::string filename)
{
  std::string inputfilename = filename;
  vtkSmartPointer<vtkPLYReader> reader = vtkSmartPointer<vtkPLYReader>::New();
  reader->SetFileName(filename.c_str());
  
  //PCL_VISUALIZER
  vtkSmartPointer<vtkPolyDataMapper> mapper = vtkSmartPointer<vtkPolyDataMapper>::New();
  mapper->SetInputConnection(reader->GetOutputPort());
  
  vtkSmartPointer<vtkActor> actor = vtkSmartPointer<vtkActor>::New();
  actor->SetMapper(mapper);
  
  vtkSmartPointer<vtkRenderer> renderer = vtkSmartPointer<vtkRenderer>::New();
  renderer->AddActor(actor);
  renderer->SetBackground(0.1804,0.5451,0.3412); //sea green
  
  vtkSmartPointer<vtkRenderWindow> renderwindow = vtkSmartPointer<vtkRenderWindow>::New();
  renderwindow->AddRenderer(renderer);
  
  vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor = 
  vtkSmartPointer<vtkRenderWindowInteractor>::New();
  renderWindowInteractor->SetRenderWindow(renderwindow);
  
  renderwindow->Render();
  renderWindowInteractor->Start();
}

void
PCLViewer::randomButtonPressed ()
{
  printf ("Random button was pressed\n");

  // Set the new color
  PointCloud tem = icp.getref();
  for (size_t i = 0; i < tem->size(); i++)
  {
    tem->points[i].x = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
    tem->points[i].y = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
    tem->points[i].z = 255 *(1024 * rand () / (RAND_MAX + 1.0f));
  }
  viewer->updatePointCloud (tem, "original_cloud");
  ui->qvtkWidget->update ();
}

void
PCLViewer::RGBsliderReleased ()
{
  // Set the new color
//   for (size_t i = 0; i < cloud->size (); i++)
//   {
//     cloud->points[i].r = red;
//     cloud->points[i].g = green;
//     cloud->points[i].b = blue;
//   }
  viewer->updatePointCloud (cloud, "cloud");
  ui->qvtkWidget->update ();
}

void
PCLViewer::pSliderValueChanged (int value)
{
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, value, "cloud");
  ui->qvtkWidget->update ();
}

void
PCLViewer::redSliderValueChanged (int value)
{
  red = value;
  printf ("redSliderValueChanged: [%d|%d|%d]\n", red, green, blue);
}

void
PCLViewer::greenSliderValueChanged (int value)
{
  green = value;
  printf ("greenSliderValueChanged: [%d|%d|%d]\n", red, green, blue);
}

void
PCLViewer::blueSliderValueChanged (int value)
{
  blue = value;
  printf("blueSliderValueChanged: [%d|%d|%d]\n", red, green, blue);
}

PCLViewer::~PCLViewer ()
{
  delete ui;
}