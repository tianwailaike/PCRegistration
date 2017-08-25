#include "ICPViewer.h"
#include <boost/make_shared.hpp>
ICPViewer::ICPViewer(QWidget *parent):
  QWidget(parent)
{
  finaltrans = Eigen::Matrix4f::Identity();
  modelpath = "/home/ubuntu/lyc2017/pcp/icptest/models/bunny.obj";
        //std::string modelpath = "/home/ubuntu/points1.ply";
        //std::string datapath = "/home/ubuntu/points2.ply";
  datapath  = "/home/ubuntu/lyc2017/pcp/icptest/models/bunny_data.obj";
  icp = icprefine::GetInstance();
  //icp->init_icp(modelpath,datapath);
  is_viewer_initiate = false;
  createMainWidget();


}
ICPViewer::~ICPViewer()
{
  //delete ui;
}
void
ICPViewer::createMainWidget()
{
 
    initialize();
  //init_viewer();
  
  
}
void 
ICPViewer::init_viewer()
{
  if(is_viewer_initiate==false)
  {
    viewer.reset (new pcl::visualization::PCLVisualizer ("viewer", false)); 
    std::cout<<"I am initialized!"<<std::endl;
    is_viewer_initiate = true;
  icp->init_viewer(viewer);
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
   viewer->updatePointCloud(icp->getref(),"original_cloud");
  viewer->updatePointCloud(icp->getref(),"reference_cloud");
  viewer->updatePointCloud(icp->getdata(),"current_cloud");
  viewer->updatePointCloud(icp->getResultCloud(),"registered_cloud");
  
  std::stringstream r;
  r << 0;
  viewer->updateText(r.str(),0,0,"show_result");
  qvtkWidget->update();
  }
}

void
ICPViewer::createActions()
{
  
}
void
ICPViewer::createSliders()
{
        hSlider_distance = new QSlider(panelWidget);
	hSlider_distance->setFixedSize(QSize(160,30));
        hSlider_distance->setMaximum(20);
	hSlider_distance->setMinimum(1);
        hSlider_distance->setValue(4);
        hSlider_distance->setOrientation(Qt::Horizontal);
	
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
	
	lcdNumber_distance = new QLCDNumber(panelWidget);
        lcdNumber_distance->setDigitCount(3);
	lcdNumber_distance->setFixedSize(QSize(80,40));
        lcdNumber_distance->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_distance->setProperty("intValue", QVariant(4));
        
	lcdNumber_npoints = new QLCDNumber(panelWidget);
        lcdNumber_npoints->setFixedSize(QSize(80,40));;
	lcdNumber_npoints->setDigitCount(3);
        lcdNumber_npoints->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_npoints->setProperty("intValue", QVariant(128));
	
	lcdNumber_pcsize = new QLCDNumber(panelWidget);
        lcdNumber_pcsize->setFixedSize(QSize(80,40));;
	lcdNumber_pcsize->setDigitCount(3);
        lcdNumber_pcsize->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_pcsize->setProperty("intValue", QVariant(2));

	lcdNumber_error = new QLCDNumber(panelWidget);
        lcdNumber_error->setFixedSize(QSize(180,40));
	lcdNumber_error->setDigitCount(8);
        lcdNumber_error->setSegmentStyle(QLCDNumber::Flat);
        lcdNumber_error->setProperty("doubleValue", QVariant(static_cast<double>(3.0000)));
        
	label_distance = new QLabel(panelWidget);
        label_distance->setFixedSize(QSize(191, 31));
	label_distance->setText(tr("Distance"));
	label_distance->setAlignment(Qt::AlignHCenter);
        QFont font;
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        label_distance->setFont(font);
	
        label_npoits = new QLabel(panelWidget);
        label_npoits->setFixedSize(QSize(191, 31));
	label_npoits->setText(tr("N_Points"));
	label_npoits->setAlignment(Qt::AlignHCenter);
	label_npoits->setFont(font);
     
	label_pcsize = new QLabel(panelWidget);
        label_pcsize->setFixedSize(QSize(191, 31));
	label_pcsize->setText(tr("Point Cloud Size"));
	label_pcsize->setAlignment(Qt::AlignHCenter);
	label_pcsize->setFont(font);
	
	label_error = new QLabel(panelWidget);
	label_error->setFixedSize(QSize(191, 31));
	label_error->setText(tr("Final Error"));
	label_error->setAlignment(Qt::AlignHCenter);
        label_error->setFont(font);
	
	
}

void
ICPViewer::createBtns()
{
  
        QFont font;
        font.setPointSize(16);
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        btnicp = new QPushButton(panelWidget);
        btnicp->setText(tr("Icp Refine"));
        btnicp->setFixedSize(QSize(201, 81));
        //btnicp->setCheckable();
	btnicp->setFont(font);
	
	btnsave = new QPushButton(panelWidget);
        btnsave->setText(tr("Save"));
        btnsave->setFixedSize(QSize(201, 81));
        //btnicp->setCheckable();
	btnsave->setFont(font);
}
void 
ICPViewer::initialize()
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
	
	
	//setCentralWidget(mainWidget);
	createSliders();
	createBtns();
	
	slider_layout1->addWidget(label_distance);
	slider_layout1->addWidget(hSlider_distance);
	slider_layout1->addWidget(label_npoits);
	slider_layout1->addWidget(hSlider_npoints);
	slider_layout1->addWidget(label_pcsize);
	slider_layout1->addWidget(hSlider_pcsize);
	
	slider_layout2->addWidget(lcdNumber_distance);
	slider_layout2->addWidget(lcdNumber_npoints);
	slider_layout2->addWidget(lcdNumber_pcsize);
	
	error_layout->addWidget(label_error);
	error_layout->addWidget(lcdNumber_error);
	
	display_layout->addLayout(slider_layout1);
	display_layout->addLayout(slider_layout2);
	
	btn_layout->addWidget(btnicp,Qt::AlignCenter);
	btn_layout->addWidget(btnsave,Qt::AlignCenter);
	left_main_layout->addLayout(display_layout);
	left_main_layout->addLayout(btn_layout);
	left_main_layout->addLayout(error_layout);
	
	main_layout->addLayout(panel_layout);
	main_layout->addLayout(QVTKWidget_layout);
	setLayout(main_layout);
	

        QObject::connect(hSlider_distance, SIGNAL(sliderMoved(int)), lcdNumber_distance, SLOT(display(int)));
        QObject::connect(hSlider_npoints, SIGNAL(sliderMoved(int)), lcdNumber_npoints, SLOT(display(int)));
        QObject::connect(hSlider_pcsize, SIGNAL(sliderMoved(int)), lcdNumber_pcsize, SLOT(display(int)));

	QObject::connect(this,SIGNAL(errorChanged(double)),lcdNumber_error,SLOT(display(double)));
	
	 // Connect "random" button and the function
  connect (btnicp,  SIGNAL (clicked ()), this, SLOT (randomButtonPressed ()));

  // Connect R,G,B sliders and their functions
  connect (hSlider_distance, SIGNAL (valueChanged (int)), this, SLOT (distance_ValueChanged(double)));
  connect (hSlider_npoints, SIGNAL (valueChanged (int)), this, SLOT (npoints_ValueChanged(int)));
  connect (hSlider_pcsize, SIGNAL (valueChanged (int)), this, SLOT (pcsize_ValueChanged(int)));
  connect (hSlider_distance, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));
  connect (hSlider_npoints, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));
  connect (hSlider_pcsize, SIGNAL (sliderReleased ()), this, SLOT (RGBsliderReleased ()));

  
  //Connect the save button;
  connect (btnsave,  SIGNAL (clicked ()), this, SLOT (saveButtonPressed()));
	

}


void
ICPViewer::randomButtonPressed()
{
  printf ("Random button was pressed\n");
  printf ("ICP refine .............\n");
  if(icp->getref()==nullptr)
    std::cout<<"this is null"<<std::endl;
  icp::IcpResults tem = icp->run_icp(icp->getref(),icp->getResultCloud());
  emit errorChanged(static_cast<double>(tem.registrationError[tem.registrationError.size() - 1]));
  finaltrans = finaltrans*tem.transformation;
  std::cout<<"This is the final mat result:\n"<<finaltrans<<std::endl;
  printf ("DONE\n");
  //PointCloud tem = icp.getResultCloud();
  viewer->updatePointCloud(icp->getResultCloud(),"registered_cloud");
  
  std::stringstream r;
  r << tem;
  viewer->updateText(r.str(),0,0,"show_result");
  qvtkWidget->update();

  
}
void ICPViewer::saveButtonPressed()
{
  
  //save the final transformation
  std::ofstream save;
  save.open("./finaltans.txt",std::ios::out|std::ios::trunc);
  std::stringstream r;
  r<<finaltrans;
  save<<r.str();
  save.close();
  std::cout<<"save done!"<<std::endl;
  std::string filepath = "./result.ply";
  icp->saveObject(filepath);
}
void ICPViewer::distance_ValueChanged(double value)
{
  distance = value;
  printf ("distanceSliderValueChanged: [%d]\n", distance);
}

void ICPViewer::npoints_ValueChanged(int value)
{
  npoints = value;
  printf ("npointsSliderValueChanged: [%d]\n",npoints);
}
void
ICPViewer::pcsize_ValueChanged (int value)
{
  if(!icp->getref()->empty())
  {
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, value, "original_cloud");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, value, "reference_cloud");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, value, "registered_cloud");
  viewer->setPointCloudRenderingProperties (pcl::visualization::PCL_VISUALIZER_POINT_SIZE, value, "current_cloud");
  qvtkWidget->update ();
  }
}

void
ICPViewer::RGBsliderReleased ()
{
  qvtkWidget->update ();
}