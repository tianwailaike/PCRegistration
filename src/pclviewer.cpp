#include "pclviewer.h"
//#include "../build/ui_pclviewer.h"
#include <boost/make_shared.hpp>
using namespace pcregistration;
PCLViewer::PCLViewer (QWidget *parent) :
  QMainWindow (parent)
 // ui (new Ui::PCLViewer)
{
  //ui->setupUi (this);
  setWindowTitle ("PCL viewer");
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
  
  
  initialize();
  
  
  viewer.reset (new pcl::visualization::PCLVisualizer ("viewer", false)); 
  icp.init_viewer(viewer);
  std::cout<<"0"<<std::endl;
  qvtkWidget->SetRenderWindow(viewer->getRenderWindow ());
  std::cout<<"1"<<std::endl;
  if(qvtkWidget->GetInteractor()==nullptr)
    std::cout<<"Interactor"<<std::endl;
  if(qvtkWidget->GetRenderWindow ()==nullptr)
    std::cout<<"renderwindow"<<std::endl;
  viewer->setupInteractor (qvtkWidget->GetInteractor(), qvtkWidget->GetRenderWindow ());
  std::cout<<"1.5"<<std::endl;
  qvtkWidget->update ();
  std::cout<<"2"<<std::endl;
  
  
  // Connect "random" button and the function
  connect (btnicp,  SIGNAL (clicked ()), this, SLOT (randomButtonPressed ()));

  // Connect R,G,B sliders and their functions
  connect (hSlider_delta, SIGNAL (valueChanged (int)), this, SLOT (redSliderValueChanged (int)));
  connect (hSlider_npoints, SIGNAL (valueChanged (int)), this, SLOT (greenSliderValueChanged (int)));
  connect (horizontalSlider_B, SIGNAL (valueChanged (int)), this, SLOT (blueSliderValueChanged (int)));
  connect (hSlider_delta, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));
  connect (hSlider_npoints, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));
  connect (horizontalSlider_B, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));

  // Connect point size slider
  connect (horizontalSlider_p, SIGNAL (valueChanged (int)), this, SLOT (pSliderValueChanged (int)));

 // viewer->addPointCloud (cloud, "cloud");
  pSliderValueChanged (2);
  viewer->resetCamera ();
  qvtkWidget->update ();
  leftwidth = 160;
}

void 
PCLViewer::initialize()
{
        QHBoxLayout* main_layout = new QHBoxLayout();
        QVBoxLayout* left_main_layout = new QVBoxLayout();
	QHBoxLayout* display_layout = new QHBoxLayout();
	QVBoxLayout* slider_layout1 = new QVBoxLayout();
	QVBoxLayout* slider_layout2 = new QVBoxLayout();
	QVBoxLayout* btn_layout = new QVBoxLayout();
	QVBoxLayout* QVTKWidget_layout = new QVBoxLayout();
	
        resize(966, 499);
        setMinimumSize(QSize(0, 0));
        setMaximumSize(QSize(5000, 5000));
        centralwidget = new QWidget(this);
	setCentralWidget(centralwidget);
	
        qvtkWidget = new QVTKWidget(centralwidget);
	qvtkWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        QVTKWidget_layout->addWidget(qvtkWidget);
	
	hSlider_delta = new QSlider(centralwidget);
	hSlider_delta->setFixedSize(QSize(160,30));
        hSlider_delta->setMaximum(0.2);
	hSlider_delta->setMinimum(0.01);
        hSlider_delta->setValue(0.04);
        hSlider_delta->setOrientation(Qt::Horizontal);
	
	hSlider_npoints = new QSlider(centralwidget);
        hSlider_npoints->setFixedSize(QSize(160,30));;
	hSlider_npoints->setMaximum(250);
	hSlider_npoints->setMinimum(150);
        hSlider_npoints->setValue(200);
        hSlider_npoints->setOrientation(Qt::Horizontal);
        
	horizontalSlider_B = new QSlider(centralwidget);
	horizontalSlider_B->setFixedSize(QSize(160,30));;
        horizontalSlider_B->setMaximum(255);
        horizontalSlider_B->setValue(128);
        horizontalSlider_B->setOrientation(Qt::Horizontal);
        
	lcdNumber_delta = new QLCDNumber(centralwidget);
        lcdNumber_delta->setDigitCount(3);
	lcdNumber_delta->setFixedSize(QSize(80,40));
        lcdNumber_delta->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_delta->setProperty("intValue", QVariant(128));
        
	lcdNumber_npoints = new QLCDNumber(centralwidget);
        lcdNumber_npoints->setFixedSize(QSize(80,40));;
	lcdNumber_npoints->setDigitCount(3);
        lcdNumber_npoints->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_npoints->setProperty("intValue", QVariant(128));
	
        lcdNumber_B = new QLCDNumber(centralwidget);
        lcdNumber_B->setFixedSize(QSize(80,40));
	lcdNumber_B->setDigitCount(3);
        lcdNumber_B->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_B->setProperty("intValue", QVariant(128));
        
	horizontalSlider_p = new QSlider(centralwidget);
        horizontalSlider_p->setFixedSize(QSize(160,30));
        horizontalSlider_p->setMinimum(1);
        horizontalSlider_p->setMaximum(6);
        horizontalSlider_p->setValue(2);
        horizontalSlider_p->setOrientation(Qt::Horizontal);
        
	lcdNumber_p = new QLCDNumber(centralwidget);
        lcdNumber_p->setObjectName(QStringLiteral("lcdNumber_p"));
        lcdNumber_p->setFixedSize(QSize(80,40));;
        lcdNumber_p->setDigitCount(1);
        lcdNumber_p->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_p->setProperty("intValue", QVariant(2));
        
	label = new QLabel(centralwidget);
        label->setFixedSize(QSize(191, 31));
	label->setText(tr("Delta"));
	label->setAlignment(Qt::AlignHCenter);
        QFont font;
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label->setFont(font);
	
        label_2 = new QLabel(centralwidget);
        label_2->setFixedSize(QSize(191, 31));
	label_2->setText(tr("N_Points"));
	label_2->setAlignment(Qt::AlignHCenter);
	label_2->setFont(font);
	
        label_3 = new QLabel(centralwidget);
        label_3->setFixedSize(QSize(191, 31));
	label_3->setText(tr(""));
	label_3->setAlignment(Qt::AlignHCenter);
	label_3->setFont(font);
        
	label_4 = new QLabel(centralwidget);
	label_4->setFixedSize(QSize(191, 31));
	label_4->setText(tr("Point Size"));
	label_4->setAlignment(Qt::AlignHCenter);
        label_4->setFont(font);

        btnicp = new QPushButton(centralwidget);
        btnicp->setText(tr("Icp Refine"));
        btnicp->setFixedSize(QSize(201, 81));
        setCentralWidget(centralwidget);
	btnicp->setFont(font);
	
	slider_layout1->addWidget(label);
	slider_layout1->addWidget(hSlider_delta);
	slider_layout1->addWidget(label_2);
	slider_layout1->addWidget(hSlider_npoints);
	slider_layout1->addWidget(label_3);
	slider_layout1->addWidget(horizontalSlider_B);
	slider_layout1->addWidget(label_4);
	slider_layout1->addWidget(horizontalSlider_p);
	
	slider_layout2->addWidget(lcdNumber_delta);
	slider_layout2->addWidget(lcdNumber_npoints);
	slider_layout2->addWidget(lcdNumber_B);
	slider_layout2->addWidget(lcdNumber_p);
	
	display_layout->addLayout(slider_layout1);
	display_layout->addLayout(slider_layout2);
	
	btn_layout->addWidget(btnicp);
	
	left_main_layout->addLayout(display_layout);
	left_main_layout->addLayout(btn_layout);
	
	main_layout->addLayout(left_main_layout);
	main_layout->addLayout(QVTKWidget_layout);
	centralwidget->setLayout(main_layout);
	

        QObject::connect(hSlider_delta, SIGNAL(sliderMoved(int)), lcdNumber_delta, SLOT(display(int)));
        QObject::connect(hSlider_npoints, SIGNAL(sliderMoved(int)), lcdNumber_npoints, SLOT(display(int)));
        QObject::connect(horizontalSlider_B, SIGNAL(sliderMoved(int)), lcdNumber_B, SLOT(display(int)));
        QObject::connect(horizontalSlider_p, SIGNAL(sliderMoved(int)), lcdNumber_p, SLOT(display(int)));

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
  qvtkWidget->update ();
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
  qvtkWidget->update ();
}

void
PCLViewer::pSliderValueChanged (int value)
{
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, value, "cloud");
  qvtkWidget->update ();
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
  //delete ui;
}