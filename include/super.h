#pragma once
#include "algorithms/4pcs.h"
#include "algorithms/super4pcs.h"
#include "Eigen/Dense"
#include <Eigen/Core>

#include <fstream>
#include <iostream>
#include <string>

#include "io/io.h"
#include "utils/geometry.h"
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>

// Point Cloud Library
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/io/ply_io.h>
#include <pcl/io/obj_io.h>
#include <pcl/visualization/cloud_viewer.h>
#define sqr(x) ((x) * (x))
  using namespace std;
  using namespace match_4pcs;
  using namespace Super4PCS;
  using PointT = pcl::PointXYZRGB;
  using PointCloud = pcl::PointCloud<PointT>::Ptr;
  using PCSMatrixT = Match4PCSBase::MatrixType;
  using PCSOptions = Match4PCSOptions; 
namespace pcregistration{

class super{

public:
  super();
  ~super();
  static super *singleton_;
  static super *ResetInstance()
	{
		if (singleton_ != NULL)
		{
			delete singleton_;
			singleton_ = NULL;
		}
		return GetInstance();
	}
  static super *GetInstance()
	{
		if(singleton_ == NULL)
			singleton_ = new super();
		return singleton_;
	}
  void init_super(string refpath, string curpath);
  void setDelta(double delta_);
  void setSampleSize(int sample_size_);
  void getArgs(int argc, char **argv);
  PointCloud getrefCloud();
  vector<Point3D>& getref();
  PointCloud getdataCloud();
  vector<Point3D>& getdata();
  PointCloud getResultCloud();
  vector<Point3D>& getResult();
  PointCloud getFusedCloud();
  vector<Point3D>& getFused();
  PCSMatrixT getResults();
  void setParams(PCSOptions options_);
  int run_super(int argc,char** argv);
  PCSMatrixT run_super(vector<Point3D>& ref,vector<Point3D>& data);
  void P3D2PCL(vector<Point3D>& set,PointCloud& pc);
  void init_viewer(pcl::visualization
                  ::PCLVisualizer::Ptr viewer);
  //
  void transform(vector<Point3D>& set1,vector<Point3D>& set2,
		PCSMatrixT transform);
  void saveObject(std::string filepath);
private:
  PCSOptions options;   //params
  PCSMatrixT super_result;   //results
  IOManager iomananger;
  
  vector<Point3D> set1;
  vector<Point3D> set2;
  vector<Point3D> set3;
  vector<Point3D> set4;
  vector<Eigen::Matrix2f> tex_coords1, tex_coords2;
  vector<typename Point3D::VectorType> normals1, normals2;
  vector<tripple> tris1, tris2;
  vector<std::string> mtls1, mtls2;
  PointCloud modelCloud,dataCloud;
  PointCloud resultCloud, fusedCloud;
  

// First input.
  string input1 ;
// Second input.
  string input2;
// Output. The transformed second input.
   string output;
// Default name for the '.obj' output file
   string defaultObjOutput;
// Default name for the '.ply' output file
   string defaultPlyOutput;
// Transformation matrice.
   string outputMat;
// Sampled cloud 1
   string outputSampled1;
// Sampled cloud 2
   string outputSampled2;
//use super4pcs or 4pcs;
   bool use_super4pcs ;
   
   
 
};

}

