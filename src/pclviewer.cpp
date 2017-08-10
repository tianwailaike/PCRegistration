#include "pclviewer.h"
//#include "../build/ui_pclviewer.h"
#include <boost/make_shared.hpp>
using namespace pcregistration;
PCLViewer::PCLViewer (QWidget *parent) :
  QMainWindow (parent)
{
  setWindowTitle ("PCL viewer");
  resize(966, 499);
  setMinimumSize(QSize(0, 0));
  setMaximumSize(QSize(5000, 5000));
  createMainWidget();

}
void
PCLViewer::createMainWidget()
{
  createMenus();
  createActions();
  stacked_widget = new QStackedWidget(this);
  //mainWidget = new QWidget(this);
  icpviewer = new ICPViewer();
  superviewer = new superViewer();
  //QHBoxLayout* hlayout = new QHBoxLayout();
  //hlayout->addWidget(icpviewer);
  //mainWidget->setLayout(hlayout);
  //setCentralWidget(mainWidget);
  stacked_widget->addWidget(icpviewer);
  //stacked_widget->insertWidget(0,icpviewer);
  stacked_widget->addWidget(superviewer);
  //stacked_widget->insertWidget(1,superviewer);
  stacked_widget->setCurrentIndex(0);
  setCentralWidget(stacked_widget);
  
  
  
  
}
void
PCLViewer::createMenus()
{
  file_menu = new QMenu(tr("File"),this);
  tool_menu = new QMenu(tr("Tool"),this);
  
  menuBar()->addMenu(file_menu);
  menuBar()->addMenu(tool_menu);
  
}
void
PCLViewer::createActions()
{
  supereg_action = new QAction(tr("Global registration(&G)"),this);
  connect(supereg_action,SIGNAL(triggered()),this,SLOT(supereg_slot()));
  icprefine_action = new QAction(tr("ICP refine(&I)"),this);
  connect(icprefine_action,SIGNAL(triggered()),this,SLOT(icp_slot()));
  loadpcs_action = new QAction(tr("Load objects"),this);
  connect(loadpcs_action,SIGNAL(triggered()),this,SLOT(loadpc_slot()));
  tool_menu->addAction(supereg_action);
  tool_menu->addAction(icprefine_action);
  tool_menu->addAction(loadpcs_action);
}
void 
PCLViewer::initialize()
{
  
       
	

}

void 
PCLViewer::supereg_slot()
{
    std::cout<<"icpviewer current index is :"<<stacked_widget->indexOf(icpviewer)<<std::endl;
    stacked_widget->setCurrentIndex(1);
   // stacked_widget->removeWidget(superviewer);
    //stacked_widget->insertWidget(1,superviewer);
    std::cout<<"switch superviewer!"<<std::endl;
    std::cout<<"superviewer current index is :"<<stacked_widget->indexOf(superviewer)<<std::endl;

}

void
PCLViewer::icp_slot()
{
    std::cout<<"superviewer current index is :"<<stacked_widget->indexOf(superviewer)<<std::endl;
    stacked_widget->setCurrentIndex(0);
   // stacked_widget->removeWidget(icpviewer);
   // stacked_widget->insertWidget(0,icpviewer);
    std::cout<<"switch icpviewer!"<<std::endl;
    std::cout<<"icpviewer current index is :"<<stacked_widget->indexOf(icpviewer)<<std::endl;  
}

bool 
PCLViewer::loadpc_slot()
{
  QStringList new_add_files = QFileDialog::getOpenFileNames(this, tr("Please Select Two objects"), ".", tr("PointCloud(*.ply *.obj)"));
	if (new_add_files.empty()||new_add_files.size()<2)
		return false;
	tmp = new_add_files;
	int cur_index = stacked_widget->currentIndex();
	   if(cur_index == 0)
	{
	   icprefine* icp =  icprefine::GetInstance();
           icp->init_icp(tmp[0].toStdString(),tmp[1].toStdString());
	   icp->run_icp(icp->getref(),icp->getdata());
	   std::cout<<"1"<<std::endl;
 	   icpviewer->init_viewer();
	   icpviewer->viewer->updatePointCloud(icp->getResultCloud(),"registered_cloud");
           icp::IcpResults tem = icp->run_icp(icp->getref(),icp->getResultCloud());
           std::stringstream r;
           r << tem;
           icpviewer->viewer->updateText(r.str(),0,0,"show_result");
           icpviewer->qvtkWidget->update();
	}
	 else
	{
	   super* super_ = super::GetInstance();
	   super_->init_super(tmp[0].toStdString(),tmp[1].toStdString());
	   super_->run_super(super_->getref(),super_->getdata());
	   std::cout<<"1"<<std::endl;
 	   superviewer->init_viewer();
	   superviewer->viewer->updatePointCloud(super_->getResultCloud(),"registered_cloud");
           PCSMatrixT tem = super_->run_super(super_->getref(),super_->getResult());
           std::stringstream r;
           r << tem;
           superviewer->viewer->updateText(r.str(),0,0,"show_result");
           superviewer->qvtkWidget->update();
	  
	}
	return true;
}

PCLViewer::~PCLViewer ()
{
  //delete ui;
}