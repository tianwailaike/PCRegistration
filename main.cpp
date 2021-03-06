#include <pcl/common/transforms.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/features/normal_3d.h>
#include <pcl/features/normal_3d_omp.h>
#include <pcl/point_types.h>
#include <sstream>
#include "eigentools.hpp"
#include "icp.hpp"
#include "error_point_to_point.hpp"
#include "error_point_to_plane.hpp"
#include "mestimator_hubert.hpp"
#include "logging.hpp"
using PointT = pcl::PointXYZ;
using PointCloud = pcl::PointCloud<PointT>::Ptr;
//#define POINT2PLANE
#define P2P
/**
 * @brief Point picker callback
 *
 * @param event
 */
void pp_callback (const pcl::visualization::PointPickingEvent &event);
void keyboard_callback(const pcl::visualization::KeyboardEvent& event);
bool toggle = true;
int main(int argc, char *argv[]) {
  // Initialize Google's logging library.
#if GLOG_ENABLED
  google::InitGoogleLogging(argv[0]);
#endif

  std::cout << "Starting ICP program";
  bool point2plane = true;
  /*
     Loads test point cloud
     */
  std::cout << "Loading Model pointcloud";
  PointCloud modelCloud(
    new pcl::PointCloud<PointT>());
  PointCloud dataCloud(
    new pcl::PointCloud<PointT>());
  //std::string model = "../models/ladder_robot/ladder_jr13_arnaud.pcd";
//   std::string model = "../models/shen_office-Cloud.obj";
//   std::string data = "../models/shen_office-Cloud2.obj";
   std::string model = argv[1];
  std::string data = argv[2];
  if (pcl::io::loadOBJFile<PointT> (model.c_str(), *modelCloud) == -1) {
    std::cout << "Could't read file " << model;
    return (-1);
  }
  if (pcl::io::loadOBJFile<PointT> (data.c_str(), *dataCloud) == -1) {
    std::cout << "Could't read file " << model;
    return (-1);
  }
  std::cout<< "Model Point cloud has " << modelCloud->points.size()
            << " points"<<std::endl;  
    std::cout<< "Model Point cloud has " << dataCloud->points.size()
            << " points"<<std::endl;

/*
     //-------------Creating a second transformed pointcloud---------------
     
//   Eigen::Matrix4f transformation
//     = eigentools::createTransformationMatrix(0.f,
//         0.05f,
//         0.f,
//         static_cast<float>(M_PI) / 10.f,
//         static_cast<float>(M_PI) / 10.f,
//         static_cast<float>(M_PI) / 10.f);
//   std::cout << "Transformation:\n" << transformation;
// 
//   // Executing the transformation
//   pcl::PointCloud<pcl::PointXYZ>::Ptr dataCloud
//   (new pcl::PointCloud<pcl::PointXYZ>());
//   // Generates a data point cloud to be matched against the model
//   pcl::transformPointCloud(*modelCloud, *dataCloud, transformation);

*/

  PointCloud resultCloud(new pcl::PointCloud<PointT>());
  PointCloud fusedCloud(new pcl::PointCloud<PointT>());
/*
  
  //------------ Define parameters for the ICP----------------
    
  //Do it step by step (i has to be set to max_iter param)
  //for (int i = 0; i < 5; i++) {
  //icp::IcpParametersXYZ icp_param;
  //icp_param.lambda = 1.f;
  //icp_param.max_iter = 100;
  //icp_param.min_variation = 10e-5;
  //icp_param.initial_guess = Eigen::Matrix4f::Identity();
  //LOG(INFO) << "ICP Parameters:\n" << icp_param;

  
  //----------------Point to point------------------
  
  //icp::IcpPointToPointHubert icp_algorithm;
  //icp_algorithm.setParameters(icp_param);
  //icp_algorithm.setInputCurrent(modelCloud);
  //icp_algorithm.setInputReference(dataCloud);
  //icp_algorithm.run();
  //
  //icp::IcpResultsXYZ icp_results = icp_algorithm.getResults();
  //LOG(INFO) << "ICP Results:\n" << icp_results;
  //pcl::copyPointCloud(*(icp_results.registeredPointCloud), *resultCloud);

  
  // -------------------Point to point (sim3)-----------------------
  
 
//      //----------------Creating a second transformed pointcloud----------------
//      
//      transformation(0,0) *= 0.5;
//      transformation(1,1) *= 0.5;
//      transformation(2,2) *= 0.5;
//      std::cout << "Transformation:\n" << transformation;
   // Generates a data point cloud to be matched against the model
//   pcl::transformPointCloud(*modelCloud, *dataCloud, transformation);
*/
//   Eigen::Matrix4f transformation;
//   transformation<<-1,0,0,0,
//        0,1,0,0,
//        0,0,-1,0,
//        0,0,0,1;
  icp::IcpParameters icp_param_sim3;
  icp_param_sim3.lambda = 1.f;
  icp_param_sim3.max_iter = 200;
  icp_param_sim3.min_variation = 10e-8;
  icp_param_sim3.max_correspondance_distance = 10e-3;  //this para is impor
  icp_param_sim3.initial_guess = Eigen::Matrix4f::Identity();
//   icp_param_sim3.initial_guess = transformation;
  std::cout << "ICP Parameters Sim3:\n" << icp_param_sim3;
#ifdef P2P
  icp::IcpPointToPointHubertSim3 icp_algorithm;
  icp_algorithm.setParameters(icp_param_sim3);
  icp_algorithm.setInputCurrent(dataCloud);
  icp_algorithm.setInputReference(modelCloud);
  icp_algorithm.run();
  
  icp::IcpResults icp_results = icp_algorithm.getResults();
  std::cout << "ICP Results:\n" << icp_results;
  pcl::transformPointCloud(*dataCloud, *resultCloud,icp_results.transformation);
  pcl::concatenateFields(*resultCloud, *modelCloud, *fusedCloud);
  
  pcl::io::savePLYFile("/home/ubuntu/result.ply",*fusedCloud);
#endif
  /**
   * Point to Plane
   **/
#ifdef POINT2PLANE
  LOG(INFO) << "Computing cloud normals";
  // Create the normal estimation class, and pass the input dataset to it
  pcl::NormalEstimationOMP<pcl::PointXYZ, pcl::Normal> ne;
  // Use all neighbors in a sphere of radius 10m
  // WARNING: Wrong value of this parameter may result to having NaN normals in
  // case nearest neighbors aren't found!
  //ne.setRadiusSearch (10);
  ne.setKSearch(100);
  // Create an empty kdtree representation, and pass it to the normal estimation object.
  // Its content will be filled inside the object, based on the given input dataset (as no other search surface is given).
  pcl::search::KdTree<PointT>::Ptr tree (new
      pcl::search::KdTree<PointT>());
  ne.setSearchMethod (tree);

  ne.setInputCloud (modelCloud);
  // Output datasets
  pcl::PointCloud<pcl::Normal>::Ptr mesh_normal_pc (new
      pcl::PointCloud<pcl::Normal>);
  // Compute the features
  ne.compute (*mesh_normal_pc);
  pcl::PointCloud<pcl::PointNormal>::Ptr mesh_pointnormal_pc(
    new pcl::PointCloud<pcl::PointNormal>);
  pcl::concatenateFields(*modelCloud, *mesh_normal_pc, *mesh_pointnormal_pc);

  ne.setInputCloud (dataCloud);
  // Output datasets
  pcl::PointCloud<pcl::Normal>::Ptr scene_normal_pc (new
      pcl::PointCloud<pcl::Normal>);
  // Compute the features
  ne.compute (*scene_normal_pc);
  pcl::PointCloud<pcl::PointNormal>::Ptr scene_pointnormal_pc(
    new pcl::PointCloud<pcl::PointNormal>);
  pcl::concatenateFields(*dataCloud, *scene_normal_pc, *scene_pointnormal_pc);
  
 
  //// Point to plane ICP
//   icp::IcpPointToPlaneHubert icp_algorithm;
//   icp_algorithm.setParameters(icp_param);
//   icp_algorithm.setInputCurrent(scene_pointnormal_pc);
//   icp_algorithm.setInputReference(mesh_pointnormal_pc);
//   icp_algorithm.run();
// 
//   icp::IcpResults_<float, pcl::PointNormal> icp_results = icp_algorithm.getResults();
//   LOG(INFO) << "ICP Results:\n" << icp_results;
//   pcl::copyPointCloud(*(icp_results.registeredPointCloud), *resultCloud);

  //// Point to plane ICP SiM3
  icp::IcpPointToPlaneHubertSim3 icp_algorithm;
  icp_algorithm.setParameters(icp_param_sim3);
  icp_algorithm.setInputCurrent(mesh_pointnormal_pc);
  icp_algorithm.setInputReference(scene_pointnormal_pc);
  icp_algorithm.run();

  icp::IcpResults icp_results = icp_algorithm.getResults();
  LOG(INFO) << "ICP Results:\n" << icp_results;
  pcl::transformPointCloud(*modelCloud, *resultCloud, icp_results.transformation);
#endif
  /**
   * Visualize
   **/
  std::cout << "\nPoint cloud colors :  white  = original point cloud\n"
            "                       red  = transformed point cloud\n";
  pcl::visualization::PCLVisualizer viewer("Matrix transformation example");
  viewer.initCameraParameters();
  viewer.registerPointPickingCallback (pp_callback);
  viewer.registerKeyboardCallback(&keyboard_callback);
  
  
  int v1(0);
  viewer.createViewPort(0.0,0.0,0.5,1.0,v1);
  viewer.addCoordinateSystem(1.0,"left",v1);
  viewer.setBackgroundColor(0,0,0,v1);
  viewer.addText("left",10,10,"v1 text",v1);
  
  pcl::visualization::PointCloudColorHandlerCustom<PointT>
  reference_cloud_color_handler(modelCloud, 230, 20, 20); 
  viewer.addPointCloud(modelCloud, reference_cloud_color_handler,
                       "reference_cloud",v1);
  pcl::visualization::PointCloudColorHandlerCustom<PointT>
  registered_cloud_color_handler(resultCloud, 20, 230, 20);  // Green
  viewer.addPointCloud(resultCloud,registered_cloud_color_handler,"registered cloud",v1);
  
  int v2(0);
  viewer.createViewPort(0.5,0.0,1.0,0.5,v2);
  viewer.addCoordinateSystem(1.0,"cloud1",v2);
  viewer.setBackgroundColor(0.2,0.2,0.2,v2);
  viewer.addText("reference cloud",10,10,"v2 text",v2);

  
  pcl::visualization::PointCloudColorHandlerCustom<PointT>
  source_cloud_color_handler(modelCloud, 230, 20, 20);
  viewer.addPointCloud(modelCloud,
                       source_cloud_color_handler, "original_cloud",v2);  
  int v3(0);
  viewer.createViewPort(0.5,0.5,1.0,1.0,v3);
  viewer.addCoordinateSystem(1.0,"cloud2",v3);
  viewer.setBackgroundColor(0.2,0.2,0.2,v3);
  viewer.addText("current cloud",10,10,"v3 text",v3);

  pcl::visualization::PointCloudColorHandlerCustom<PointT>
  current_cloud_color_handler(dataCloud, 20, 230, 20);  // Green
  viewer.addPointCloud(dataCloud,current_cloud_color_handler,"current cloud",v3);
//--------------- Define R,G,B colors for the point cloud---------------
/*

//   pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ>
//   transformed_cloud_color_handler(dataCloud, 230, 20, 20);  // Red 230 20 20
//   viewer.addPointCloud(dataCloud, transformed_cloud_color_handler,
//                        "transformed_cloud");
//   pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ>
//   transformed_cloud_color_handler(dataCloud, 230, 20, 20); 
  
  
//   pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ>
//   registered_cloud_color_handler(resultCloud, 20, 230, 20);  // Green
//   viewer.addPointCloud(resultCloud,
//                        registered_cloud_color_handler,
//                        "registered cloud");
 
//   viewer.addCoordinateSystem(1.0, "cloud", 0);
//  // viewer.addCoordinateSystem(1.0,"cloud1",1);
//   // Setting background to a dark grey
//   viewer.setBackgroundColor(0.05, 0.05, 0.05, 0);
  */
  viewer.setPointCloudRenderingProperties(
    pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 2, "current_cloud",v3);  
  viewer.setPointCloudRenderingProperties(
    pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 2, "reference_cloud",v2);
  viewer.setPointCloudRenderingProperties(
    pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 2, "reference_cloud",v1);
  viewer.setPointCloudRenderingProperties(
    pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 2, "registered_cloud",v1);
  
  std::stringstream r;
  r << icp_results;
  viewer.addText(r.str(), 0, 0,"show_result",v1);
  viewer.setShowFPS(true);

  // Display the visualiser until 'q' key is pressed
  while (!viewer.wasStopped()) { 
//    if(toggle)
//   {
//   viewer.addPointCloud(dataCloud, transformed_cloud_color_handler,
//                        "transformed_cloud");
//   viewer.updatePointCloud(dataCloud,"transformed_cloud");
//   toggle = !toggle;
//   }
    viewer.spinOnce();
  }
  //}

  return 0;
}






void keyboard_callback(const pcl::visualization::KeyboardEvent& event)
{
  if(event.getKeySym()=="space"&&event.keyDown())
    toggle = !toggle;

}
void pp_callback (const pcl::visualization::PointPickingEvent &event)
{
  if (event.getPointIndex () == -1)
    return;
  float x, y, z;
  event.getPoint(x, y, z);
  std::cout << "Point Selected: \n"
            << "\tIndex: " << event.getPointIndex ()
            << "\tCoord: (" <<  x << ", " << y << ", " << z << ")";
}
