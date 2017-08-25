#include "superViewer.h"
#include <boost/make_shared.hpp>
using namespace pcregistration;

superViewer::superViewer(QWidget *parent) :
  QWidget(parent)
{

  finaltrans = Eigen::Matrix4f::Identity();
  referencepath = "/home/ubuntu/lyc2017/pcp/icptest/models/bunny.obj";
  //std::string modelpath = "/home/ubuntu/points1.ply";
  //std::string datapath = "/home/ubuntu/points2.ply";
  is_viewer_initiate = false;
  delta_ = 50;//slider control
  sample_size_ = 200;//slider control
  currentpath  = "/home/ubuntu/lyc2017/pcp/icptest/models/bunny_data.obj";
  super_ = super::GetInstance();
  createMainWidget();
  
}
superViewer::~superViewer ()
{
  //delete ui;
}
void
superViewer::createMainWidget()
{
    initialize();
  
}

void 
superViewer::init_viewer()
{
   if(is_viewer_initiate==false)
  {
    viewer.reset (new pcl::visualization::PCLVisualizer ("viewer", false)); 
    std::cout<<"I am initialized!"<<std::endl;
     super_->init_viewer(viewer);
     is_viewer_initiate = true;
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
     viewer->resetCamera ();
     qvtkWidget->update ();
  }
  else
  {
     finaltrans = Eigen::Matrix4f::Identity();
     std::cout<<"This is the final mat result:\n"<<finaltrans<<std::endl;
     printf ("DONE\n");
  //PointCloud tem = icp.getResultCloud();
     viewer->updatePointCloud(super_->getrefCloud(),"original_cloud");
     viewer->updatePointCloud(super_->getrefCloud(),"reference_cloud");
     viewer->updatePointCloud(super_->getdataCloud(),"current_cloud");
     viewer->updatePointCloud(super_->getResultCloud(),"registered_cloud");
     std::stringstream r;
     r << 0;
     viewer->updateText(r.str(),0,0,"show_result");
     qvtkWidget->update();
  }
  
//   if(is_viewer_initiate==false)
//   {
//     viewer.reset (new pcl::visualization::PCLVisualizer ("viewer1", false)); 
//     super_->init_viewer(viewer);
//     std::cout<<"0"<<std::endl;
//     qvtkWidget->SetRenderWindow(viewer->getRenderWindow ());
//     std::cout<<"1"<<std::endl;
//     if(qvtkWidget->GetInteractor()==nullptr)
//       std::cout<<"Interactor"<<std::endl;
//     if(qvtkWidget->GetRenderWindow ()==nullptr)
//       std::cout<<"renderwindow"<<std::endl;
//     viewer->setupInteractor (qvtkWidget->GetInteractor(), qvtkWidget->GetRenderWindow ());
//     std::cout<<"1.5"<<std::endl;
//     qvtkWidget->update ();
//     std::cout<<"2"<<std::endl;
//     viewer->resetCamera ();
//     qvtkWidget->update ();
//   }
}
void
superViewer::createSliders()
{
        hSlider_delta = new QSlider(panelWidget);
	hSlider_delta->setFixedSize(QSize(160,30));
        hSlider_delta->setMaximum(200);
	hSlider_delta->setMinimum(1);
        hSlider_delta->setValue(40);
        hSlider_delta->setOrientation(Qt::Horizontal);
	
	hSlider_npoints = new QSlider(panelWidget);
        hSlider_npoints->setFixedSize(QSize(160,30));;
	hSlider_npoints->setMaximum(250);
	hSlider_npoints->setMinimum(150);
        hSlider_npoints->setValue(200);
        hSlider_npoints->setOrientation(Qt::Horizontal);
        
        hSlider_pcsize = new QSlider(panelWidget);
        hSlider_pcsize->setFixedSize(QSize(160,30));;
	hSlider_pcsize->setMaximum(6);
	hSlider_pcsize->setMinimum(1);
        hSlider_pcsize->setValue(2);
        hSlider_pcsize->setOrientation(Qt::Horizontal);
        
	lcdNumber_delta = new QLCDNumber(panelWidget);
        lcdNumber_delta->setDigitCount(3);
	lcdNumber_delta->setFixedSize(QSize(80,40));
        lcdNumber_delta->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_delta->setProperty("intValue", QVariant(4));
        
	lcdNumber_npoints = new QLCDNumber(panelWidget);
        lcdNumber_npoints->setFixedSize(QSize(80,40));;
	lcdNumber_npoints->setDigitCount(3);
        lcdNumber_npoints->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_npoints->setProperty("intValue", QVariant(128));
	
	lcdNumber_pcsize = new QLCDNumber(panelWidget);
        lcdNumber_pcsize->setFixedSize(QSize(80,40));
	lcdNumber_pcsize->setDigitCount(3);
        lcdNumber_pcsize->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_pcsize->setProperty("intValue", QVariant(3.0000));
        
	label_delta = new QLabel(panelWidget);
        label_delta->setFixedSize(QSize(191, 31));
	label_delta->setText(tr("Delta"));
	label_delta->setAlignment(Qt::AlignHCenter);
        QFont font;
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_delta->setFont(font);
	
        label_npoints = new QLabel(panelWidget);
        label_npoints->setFixedSize(QSize(191, 31));
	label_npoints->setText(tr("N_Points"));
	label_npoints->setAlignment(Qt::AlignHCenter);
	label_npoints->setFont(font);
     
	
	label_pcsize = new QLabel(panelWidget);
	label_pcsize->setFixedSize(QSize(191, 31));
	label_pcsize->setText(tr("Point Size"));
	label_pcsize->setAlignment(Qt::AlignHCenter);
        label_pcsize->setFont(font);
	
	
}

void
superViewer::createBtns()
{
  
        QFont font;
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        btnsuper = new QPushButton(panelWidget);
        btnsuper->setText(tr("Global Refine"));
        btnsuper->setFixedSize(QSize(201, 81));
        //btnicp->setCheckable();
	btnsuper->setFont(font);
	
	btnsave = new QPushButton(panelWidget);
        btnsave->setText(tr("Save"));
        btnsave->setFixedSize(QSize(201, 81));
        //btnicp->setCheckable();
	btnsave->setFont(font);
}
void 
superViewer::initialize()
{
        
        QHBoxLayout* main_layout = new QHBoxLayout();
	QHBoxLayout* panel_layout = new QHBoxLayout();
        QVBoxLayout* left_main_layout = new QVBoxLayout();
	QHBoxLayout* display_layout = new QHBoxLayout();
	QVBoxLayout* slider_layout1 = new QVBoxLayout();
	QVBoxLayout* slider_layout2 = new QVBoxLayout();
	QVBoxLayout* btn_layout = new QVBoxLayout();
	QVBoxLayout* QVTKWidget_layout = new QVBoxLayout();
	QVBoxLayout* error_layout = new QVBoxLayout();
	
        resize(966, 499);
        setMinimumSize(QSize(0, 0));
        setMaximumSize(QSize(5000, 5000));
       
	
	panelWidget = new QWidget(this);
	panelWidget->setLayout(left_main_layout);
	panelWidget->setSizePolicy(QSizePolicy::Fixed,
	                           QSizePolicy::Expanding);
	panel_layout->addWidget(panelWidget);
	
        qvtkWidget = new QVTKWidget(this);
	qvtkWidget->setSizePolicy(QSizePolicy::Expanding,
				  QSizePolicy::Expanding);
        QVTKWidget_layout->addWidget(qvtkWidget);
	
	createBtns();
	createSliders();
	
	slider_layout1->addWidget(label_delta);
	slider_layout1->addWidget(hSlider_delta);
	slider_layout1->addWidget(label_npoints);
	slider_layout1->addWidget(hSlider_npoints);
	slider_layout1->addWidget(label_pcsize);
	slider_layout1->addWidget(hSlider_pcsize);
	
	slider_layout2->addWidget(lcdNumber_delta);
	slider_layout2->addWidget(lcdNumber_npoints);
	slider_layout2->addWidget(lcdNumber_pcsize);
	
// 	error_layout->addWidget(label_error);
// 	error_layout->addWidget(lcdNumber_error);
// 	
	display_layout->addLayout(slider_layout1);
	display_layout->addLayout(slider_layout2);
	
	btn_layout->addWidget(btnsuper,Qt::AlignCenter);
	btn_layout->addWidget(btnsave,Qt::AlignCenter);
	left_main_layout->addLayout(display_layout);
	left_main_layout->addLayout(btn_layout);
// 	left_main_layout->addLayout(error_layout);
	
	main_layout->addLayout(panel_layout);
	main_layout->addLayout(QVTKWidget_layout);
	setLayout(main_layout);
	

        QObject::connect(hSlider_delta, SIGNAL(sliderMoved(int)), lcdNumber_delta, SLOT(display(int)));
        QObject::connect(hSlider_npoints, SIGNAL(sliderMoved(int)), lcdNumber_npoints, SLOT(display(int)));
        QObject::connect(hSlider_pcsize, SIGNAL(sliderMoved(int)), lcdNumber_pcsize, SLOT(display(int)));    
// 	QObject::connect(this,SIGNAL(errorChanged(double)),lcdNumber_error,SLOT(display(double)));
	
	 // Connect "random" button and the function
  connect (btnsuper,  SIGNAL (clicked ()), this, SLOT (superButtonPressed ()));

  // Connect R,G,B sliders and their functions
  connect (hSlider_delta, SIGNAL (valueChanged (int)), this, SLOT (delta_ValueChanged (int)));
  connect (hSlider_npoints, SIGNAL (valueChanged (int)), this, SLOT (npoints_ValueChanged (int)));
  connect (hSlider_pcsize, SIGNAL (valueChanged (int)), this, SLOT (pcsize_ValueChanged (int)));
  connect (hSlider_delta, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));
  connect (hSlider_npoints, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));
  connect (hSlider_pcsize, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));
  
  //Connect the save button;
  connect (btnsave,  SIGNAL (clicked ()), this, SLOT (saveButtonPressed()));
	

}


void
superViewer::superButtonPressed ()
{
  printf ("Super button was pressed\n");
  printf ("Global refine .............\n");
//  PCSMatrixT tem = super_->run_super(super_->getref(),
//				     super_->getResult());//continously refine 
  //may not be a good solution as global registration tends to get bad results if not 
  //properly set
  //emit errorChanged(static_cast<double>(tem.registrationError[tem.registrationError.size() - 1]));
  PCSMatrixT tem = super_->run_super(super_->getref(),
				     super_->getdata());//refine once 
  //finaltrans = finaltrans*tem; //continously refine
  finaltrans = tem;//refine once
  std::cout<<"This is the final mat result:\n"<<finaltrans<<std::endl;
  printf ("DONE\n");
  //PointCloud tem = icp.getResultCloud();
  viewer->updatePointCloud(super_->getResultCloud(),"registered_cloud");
  
  std::stringstream r;
  r << tem;
  viewer->updateText(r.str(),0,0,"show_result");
  qvtkWidget->update();

  
}

void 
superViewer::saveButtonPressed()
{
  
  //save the final transformation
  std::ofstream save;
  save.open("./super_finaltans.txt",std::ios::out|std::ios::trunc);
  std::stringstream r;
  r<<super_->getResults();
  save<<r.str();
  save.close();
  std::cout<<"save done!"<<std::endl;
  std::string filepath = "./super_result.ply";
  super_->saveObject(filepath);
}
void
superViewer::RGBsliderReleased ()
{
  // Set the new color
//   for (size_t i = 0; i < cloud->size (); i++)
//   {
//     cloud->points[i].r = red;
//     cloud->points[i].g = green;
//     cloud->points[i].b = blue;
//   }
 // viewer->updatePointCloud(super_->getResultCloud(), "regitsterd_cloud");
 // viewer->updatePointCloud(super_->getdataCloud(),"current_cloud");
  super_->setDelta((double)delta_/1000);
  std::cout<<"delta_ is : "<<(double)delta_/100<<std::endl;
  super_->setSampleSize(sample_size_);
  std::cout<<"sample_size_ is : "<<sample_size_<<std::endl;
}

void
superViewer::pcsize_ValueChanged (int value)
{
  if(!super_->getrefCloud()->empty())
  {
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, value, "original_cloud");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, value, "reference_cloud");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, value, "registered_cloud");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, value, "current_cloud");
  qvtkWidget->update ();
  }
}

void
superViewer::delta_ValueChanged (int value)
{
  delta_ = value;
  printf ("deltaValueChanged: [%d|%d|%d]\n", delta_, sample_size_, blue);
}

void
superViewer::npoints_ValueChanged (int value)
{
  sample_size_ = value;
  printf ("samplesizeValueChanged: [%d|%d|%d]\n",delta_,sample_size_, blue);
}


