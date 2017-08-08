#include "super.h"
using namespace pcregistration;
super::super()
{
  input1 = "/home/ubuntu/lyc2017/Super4PCS/models/bunny.obj";
  input2 = "/home/ubuntu/lyc2017/Super4PCS/models/bunny_data.obj";
  init_super(input1,input2);
  
}
super::~super()
{
  
}
//convert from P3D to PCL pointcloud
void super::P3D2PCL(vector<Point3D>& set, PointCloud& pc)
{
  if(set[0].hasColor())
   for(size_t i = 0;i<set.size();i++)
    {
      pc->points[i].x = set[i].x();
      pc->points[i].y = set[i].y();
      pc->points[i].z = set[i].z();
      pc->points[i].r = set[i].rgb().coeffRef(0);
      pc->points[i].g = set[i].rgb().coeffRef(1);
      pc->points[i].b = set[i].rgb().coeffRef(2);
    }
  else 
    for(size_t i=0;i<set.size();i++)
    {
      pc->points[i].x = set[i].x();
      pc->points[i].y = set[i].y();
      pc->points[i].z = set[i].z();
      pc->points[i].r = 255;
      pc->points[i].g = 255;
      pc->points[i].b = 255;
    }
    
}

void super::init_super(string refpath, string curpath)
{
//First input
  if(refpath.empty())
     input1 = "/home/ubuntu/lyc2017/Super4PCS/models/bunny.obj";
  else
     input1 = refpath;
// Second input.
  if(curpath.empty()) 
     input2 = "/home/ubuntu/lyc2017/Super4PCS/models/bunny_data.obj";
  else
     input2 = curpath;
// Output. The transformed second input.
   output = "/home/ubuntu/lyc2017/Super4PCS/T2.obj";
// Default name for the '.obj' output file
   defaultObjOutput = "/home/ubuntu/lyc2017/Super4PCS/super.obj";
// Default name for the '.ply' output file
   defaultPlyOutput = "/home/ubuntu/lyc2017/Super4PCS/super.ply";

// Transformation matrice.
   outputMat = "/home/ubuntu/lyc2017/Super4PCS/mat_super.txt";

// Sampled cloud 1
   outputSampled1 = "";

// Sampled cloud 2
   outputSampled2 = "";
   PCSOptions options_;
// Delta (see the paper).
   options_.delta = 0.05;

// Estimated overlap (see the paper).
   options_.overlap_estimation = 0.3;

// Threshold of the computed overlap for termination. 1.0 means don't terminate
// before the end.
   options_.terminate_threshold = 1.0;

// Maximum norm of RGB values between corresponded points. 1e9 means don't use.
   options_.max_color_distance = -1;

// Number of sampled points in both files. The 4PCS allows a very aggressive
// sampling.
   options_.sample_size = 200;
   
// Maximum angle (degrees) between corresponded normals.
   options_.max_normal_difference = -1;

// Maximum allowed computation time.
   options_.max_time_seconds = 1000;
   setParams(options_);
   use_super4pcs = true;
}
void super::getArgs(int argc, char **argv) {
  int i = 1;
  while (i < argc) {
    if (!strcmp(argv[i], "-i")) {
      input1 = std::string(argv[++i]);
      input2 = std::string(argv[++i]);
    } else if (!strcmp(argv[i], "-o")) {
      options.overlap_estimation = atof(argv[++i]);
    } else if (!strcmp(argv[i], "-d")) {
      options.delta = atof(argv[++i]);
    } else if (!strcmp(argv[i], "-c")) {
      options.max_color_distance = atof(argv[++i]);
    } else if (!strcmp(argv[i], "-t")) {
      options.max_time_seconds = atoi(argv[++i]);
    } else if (!strcmp(argv[i], "-a")) {
      options.max_normal_difference = atof(argv[++i]);
    } else if (!strcmp(argv[i], "-n")) {
      options.sample_size = atoi(argv[++i]);
    } else if (!strcmp(argv[i], "-r")) {
      output = argv[++i];
    } else if (!strcmp(argv[i], "-m")) {
      outputMat = argv[++i];
    } else if (!strcmp(argv[i], "-x")) {
      use_super4pcs = false;
    } else if (!strcmp(argv[i], "--sampled1")) {
      outputSampled1 = argv[++i];
    } else if (!strcmp(argv[i], "--sampled2")) {
      outputSampled2 = argv[++i];
    } else if (!strcmp(argv[i], "-h")) {
      fprintf(stderr, "\nUsage: %s -i input1 input2\n\n", argv[0]);
      fprintf(stderr, "\t[ -o overlap (%2.2f) ]\n", options.overlap_estimation);
      fprintf(stderr, "\t[ -d delta (%2.2f) ]\n", options.delta);
      fprintf(stderr, "\t[ -n n_points (%d) ]\n", options.sample_size);
      fprintf(stderr, "\t[ -a norm_diff (%f) ]\n", options.max_normal_difference);
      fprintf(stderr, "\t[ -c max_color_diff (%f) ]\n", options.max_color_distance);
      fprintf(stderr, "\t[ -t max_time_seconds (%d) ]\n", options.max_time_seconds);
      fprintf(stderr, "\t[ -r result_file_name (%s) ]\n", output.c_str());
      fprintf(stderr, "\t[ -m output matrix file (%s) ]\n", outputMat.c_str());
      fprintf(stderr, "\t[ -x (use 4pcs: false by default) ]\n");
      fprintf(stderr, "\t[ --sampled1 (output sampled cloud 1 -- debug+super only) ]\n");
      fprintf(stderr, "\t[ --sampled2 (output sampled cloud 2 -- debug+super only) ]\n");
      exit(0);
    } else if (argv[i][0] == '-') {
      cerr << "Unknown flag\n";
      exit(-1);
    };
    i++;
  }
  std::cout<<"overlap is :"<<options.overlap_estimation<<std::endl;
  std::cout<<"delta is :"<<options.delta<<std::endl;
  std::cout<<"n_points is :"<<options.sample_size<<std::endl;
  // if no output file (geometry/matrix) is set, force 3d mesh
  if (output.empty() && outputMat.empty()) output = defaultObjOutput;

}
void super::setDelta(double delta_)
{
  options.delta = delta_;
}

super::PCSMatrixT super::getResults()
{
  return result;
  
}

void super::setParams(PCSOptions options_)
{
  options = options_;
}
int super::run_super() 
{
  IOManager iomananger;

  // Read the inputs.
  
  if (!iomananger.ReadObject((char *)input1.c_str(), set1, tex_coords1, normals1, tris1,
                  mtls1)) {
    perror("Can't read input set1");
    exit(-1);
  }

  if (!iomananger.ReadObject((char *)input2.c_str(), set2, tex_coords2, normals2, tris2,
                  mtls2)) {
    perror("Can't read input set2");
    exit(-1);
  }
  
  // clean only when we have pset to avoid wrong face to point indexation
  // when reading ply, which without tris ,then the following step 
  // * will normalize the cordinates ,but it may reflect to Transformation estimation
  // so you can enable this to get accurate estimation and then use the estimation to transformate
  //cordinates
  
  if(input1.substr(input1.size()-3)!="ply")
  {
//     vector<Point3D> set2_;
//     set2_ = Point3D(set2);
  if (tris1.size() == 0)
  {
    Utils::CleanInvalidNormals(set1, normals1);
    std::cout<<"point set1 with no tris"<<std::endl;
  }
  if (tris2.size() == 0)
  {
    Utils::CleanInvalidNormals(set2, normals2);
    std::cout<<"point set2 with no tris"<<std::endl;
  }
  }
  
  // Match and return the score (estimated overlap or the LCP).
  typename Point3D::Scalar score = 0;

  try {

      if (use_super4pcs) {
          MatchSuper4PCS matcher(options);
          cout << "Use Super4PCS" << endl;
	    score = matcher.ComputeTransformation(set1, &set2, result);

          if(! outputSampled1.empty() ){
              std::cout << "Exporting Sampled cloud 1 to "
                        << outputSampled1.c_str()
                        << "..." << std::flush;
              iomananger.WriteObject((char *)outputSampled1.c_str(),
                                     matcher.getFirstSampled(),
                                     vector<Eigen::Matrix2f>(),
                                     vector<typename Point3D::VectorType>(),
                                     vector<tripple>(),
                                     vector<string>());
              std::cout << "DONE" << std::endl;
          }
          if(! outputSampled2.empty() ){
              std::cout << "Exporting Sampled cloud 2 to "
                        << outputSampled2.c_str()
                        << "..." << std::flush;
              iomananger.WriteObject((char *)outputSampled2.c_str(),
                                     matcher.getSecondSampled(),
                                     vector<Eigen::Matrix2f>(),
                                     vector<typename Point3D::VectorType>(),
                                     vector<tripple>(),
                                     vector<string>());
              std::cout << "DONE" << std::endl;
          }
      }
      else {
          Match4PCS matcher(options);
          cout << "Use old 4PCS" << endl;
          score = matcher.ComputeTransformation(set1, &set2,result);
      }

  }
  catch (const std::exception& e) {
      std::cout << "[Error]: " << e.what() << '\n';
      std::cout << "Aborting with code -2 ..." << std::endl;
      return -2;
  }
  catch (...) {
      std::cout << "[Unknown Error]: Aborting with code -3 ..." << std::endl;
      return -3;
  }

  cout << "Score: " << score << endl;
  cout <<"(Homogeneous) Transformation from " << input2.c_str()
       << " to "<< input1.c_str() << ":\n";

  cout << result << std::endl;


  if(! outputMat.empty() ){
      std::cout << "Exporting Matrix to "
                << outputMat.c_str()
                << "..." << std::flush;
      iomananger.WriteMatrix(outputMat, result.cast<double>(), IOManager::POLYWORKS);
      std::cout << "DONE" << std::endl;
  }

  if (! output.empty() ){

      std::cout << "Exporting Registered geometry to "
                << output.c_str()
                << "..." << std::flush;
      std::cout<< "size of sets2 is :"<<set2.size()<<std::endl;
//       for(int i=0;i<10;i++)
// 	std::cout<<set2[i].x()<<" "<<set2[i].y()<<" "<<set2[i].z()<<std::endl;
      
      //uncomment the following two lines to enable the fusion result
//       for(int i=0;i<set1.size();i++)
// 	set2.push_back(set1[i]);
      iomananger.WriteObject((char *)output.c_str(),
                             set2,
                             tex_coords2,
                             normals2,
                             tris2,
                             mtls2);
      std::cout << "DONE" << std::endl;
  }

  return 1;
}

int super::run_super(int argc, char** argv) 
{
  getArgs(argc, argv);

  IOManager iomananger;

  // Read the inputs.
  
  if (!iomananger.ReadObject((char *)input1.c_str(), set1, tex_coords1, normals1, tris1,
                  mtls1)) {
    perror("Can't read input set1");
    exit(-1);
  }

  if (!iomananger.ReadObject((char *)input2.c_str(), set2, tex_coords2, normals2, tris2,
                  mtls2)) {
    perror("Can't read input set2");
    exit(-1);
  }
  
  // clean only when we have pset to avoid wrong face to point indexation
  // when reading ply, which without tris ,then the following step 
  // * will normalize the cordinates ,but it may reflect to Transformation estimation
  // so you can enable this to get accurate estimation and then use the estimation to transformate
  //cordinates
  
  if(input1.substr(input1.size()-3)!="ply")
  {
//     vector<Point3D> set2_;
//     set2_ = Point3D(set2);
  if (tris1.size() == 0)
  {
    Utils::CleanInvalidNormals(set1, normals1);
    std::cout<<"point set1 with no tris"<<std::endl;
  }
  if (tris2.size() == 0)
  {
    Utils::CleanInvalidNormals(set2, normals2);
    std::cout<<"point set2 with no tris"<<std::endl;
  }
  }
  
  // Match and return the score (estimated overlap or the LCP).
  typename Point3D::Scalar score = 0;

  try {

      if (use_super4pcs) {
          MatchSuper4PCS matcher(options);
          cout << "Use Super4PCS" << endl;
           score = matcher.ComputeTransformation(set1, &set2, result);

          if(! outputSampled1.empty() ){
              std::cout << "Exporting Sampled cloud 1 to "
                        << outputSampled1.c_str()
                        << "..." << std::flush;
              iomananger.WriteObject((char *)outputSampled1.c_str(),
                                     matcher.getFirstSampled(),
                                     vector<Eigen::Matrix2f>(),
                                     vector<typename Point3D::VectorType>(),
                                     vector<tripple>(),
                                     vector<string>());
              std::cout << "DONE" << std::endl;
          }
          if(! outputSampled2.empty() ){
              std::cout << "Exporting Sampled cloud 2 to "
                        << outputSampled2.c_str()
                        << "..." << std::flush;
              iomananger.WriteObject((char *)outputSampled2.c_str(),
                                     matcher.getSecondSampled(),
                                     vector<Eigen::Matrix2f>(),
                                     vector<typename Point3D::VectorType>(),
                                     vector<tripple>(),
                                     vector<string>());
              std::cout << "DONE" << std::endl;
          }
      }
      else {
          Match4PCS matcher(options);
          cout << "Use old 4PCS" << endl;
          score = matcher.ComputeTransformation(set1, &set2,result);
      }

  }
  catch (const std::exception& e) {
      std::cout << "[Error]: " << e.what() << '\n';
      std::cout << "Aborting with code -2 ..." << std::endl;
      return -2;
  }
  catch (...) {
      std::cout << "[Unknown Error]: Aborting with code -3 ..." << std::endl;
      return -3;
  }

  cout << "Score: " << score << endl;
  cout <<"(Homogeneous) Transformation from " << input2.c_str()
       << " to "<< input1.c_str() << ":\n";

  cout << result << std::endl;


  if(! outputMat.empty() ){
      std::cout << "Exporting Matrix to "
                << outputMat.c_str()
                << "..." << std::flush;
      iomananger.WriteMatrix(outputMat, result.cast<double>(), IOManager::POLYWORKS);
      std::cout << "DONE" << std::endl;
  }

  if (! output.empty() ){

      std::cout << "Exporting Registered geometry to "
                << output.c_str()
                << "..." << std::flush;
      std::cout<< "size of sets2 is :"<<set2.size()<<std::endl;
//       for(int i=0;i<10;i++)
// 	std::cout<<set2[i].x()<<" "<<set2[i].y()<<" "<<set2[i].z()<<std::endl;
      
      //uncomment the following two lines to enable the fusion result
//       for(int i=0;i<set1.size();i++)
// 	set2.push_back(set1[i]);
      iomananger.WriteObject((char *)output.c_str(),
                             set2,
                             tex_coords2,
                             normals2,
                             tris2,
                             mtls2);
      std::cout << "DONE" << std::endl;
  }

  return 1;
}

// int main(int argc, char** argv)
// {
//   super superpc;
//   if(argc>1)
//     superpc.run_super(argc,argv);
//   else
//     superpc.run_super();
//   return 1;
// }