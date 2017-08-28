#pragma once
#ifndef ICPREFINE_H
#define ICPREFINE_H
#include <pcl/features/normal_3d_omp.h>
#include <pcl/point_types.h>
#include <sstream>
#include "eigentools.hpp"
#include "icp.hpp"
#include "error_point_to_point.hpp"
#include "error_point_to_plane.hpp"
#include "mestimator_hubert.hpp"
#include "logging.hpp"

#include <pcl/common/transforms.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/features/normal_3d.h>
namespace pcregistration{
using PointT = pcl::PointXYZRGB; //when adding data without rgb ,icprefine 
//will return pc with rgb(0,0,0) ,which is black
using PointCloud = pcl::PointCloud<PointT>::Ptr;
//#define POINT2PLANE
//#define P2P
#define P2PC

//bool toggle = true;
class icprefine{
public:
  icprefine();
  ~ icprefine();
  static icprefine *singleton_;
  static icprefine *ResetInstance()
	{
		if (singleton_ != NULL)
		{
			delete singleton_;
			singleton_ = NULL;
		}
		return GetInstance();
	}
  static icprefine *GetInstance()
	{
		if(singleton_ == NULL)
			singleton_ = new icprefine();
		return singleton_;
	}
  std::string getsuffix(std::string file);
  int init_icp(std::string refpath,std::string datapath);
  icp::IcpResults run_icp(PointCloud modelCloud,PointCloud dataCloud);
  PointCloud getref();
  PointCloud getdata();
  PointCloud getResultCloud();
  PointCloud getFusedCloud();
  icp::IcpResults getResult();
  pcl::visualization::PCLVisualizer::Ptr init_viewer();
  void init_viewer(pcl::visualization::PCLVisualizer::Ptr viewer);
  void setParams(icp::IcpParameters);
  void setDistance(double dist_);
  void setNiter(int max_iter_);
  static void keyboard_callback(const pcl::visualization::KeyboardEvent& event);
  static void pp_callback (const pcl::visualization::PointPickingEvent &event);
  void saveObject(std::string filepath);
private:
  PointCloud modelCloud,dataCloud;
  PointCloud resultCloud,fusedCloud;
 // pcl::visualization::PCLVisualizer::Ptr viewer;
  icp::IcpParameters icp_param_sim3;
  icp::IcpResults icp_results;
};
#endif //ICPREFINE_H
};