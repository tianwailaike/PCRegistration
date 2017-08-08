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
  //stacked_widget = new QStackedWidget(this);
  mainWidget = new QWidget(this);
  icpviewer = new ICPViewer(mainWidget);
  QHBoxLayout* hlayout = new QHBoxLayout();
  hlayout->addWidget(icpviewer);
  mainWidget->setLayout(hlayout);
  setCentralWidget(mainWidget);
  //stacked_widget->addWidget(icpviewer);
  
  
  
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
  
}

void
PCLViewer::icp_slot()
{
  
  
}

bool 
PCLViewer::loadpc_slot()
{
  QStringList new_add_files = QFileDialog::getOpenFileNames(this, tr("Please Select Two objects"), ".", tr("PointCloud(*.ply *.obj)"));
	if (new_add_files.empty()||new_add_files.size()<2)
		return false;
	tmp = new_add_files;
	icprefine* icp =  icprefine::GetInsance();
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
	return true;
}

PCLViewer::~PCLViewer ()
{
  //delete ui;
}