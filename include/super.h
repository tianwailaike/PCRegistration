#pragma once
#include "algorithms/4pcs.h"
#include "algorithms/super4pcs.h"
#include "Eigen/Dense"

#include <fstream>
#include <iostream>
#include <string>

#include "io/io.h"
#include "utils/geometry.h"
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#define sqr(x) ((x) * (x))
  using namespace std;
  using namespace match_4pcs;
  using namespace Super4PCS;
  using PointT = pcl::PointXYZRGB;
  using PointCloud = pcl::PointCloud<PointT>::Ptr;
  
namespace pcregistration{

class super{
  using PCSMatrixT = Match4PCSBase::MatrixType;
  using PCSOptions = Match4PCSOptions; 
public:
  super();
  ~super();
  void init_super(string refpath, string curpath);
  void setDelta(double delta_);
  void getArgs(int argc, char **argv);
  PCSMatrixT getResults();
  void setParams(PCSOptions options_);
  int run_super(int argc,char** argv);
  int run_super();
  void P3D2PCL(vector<Point3D>& set,PointCloud& pc);
private:
  PCSOptions options;   //params
  PCSMatrixT result;   //results
  
  
  vector<Point3D> set1, set2;
  vector<Eigen::Matrix2f> tex_coords1, tex_coords2;
  vector<typename Point3D::VectorType> normals1, normals2;
  vector<tripple> tris1, tris2;
  vector<std::string> mtls1, mtls2;


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

