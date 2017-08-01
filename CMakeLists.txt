cmake_minimum_required(VERSION 2.8)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake"
    ${CMAKE_SOURCE_DIR})
message(status ${CMAKE_MODULE_PATH})

set(PROJECT_NAME icp)
project(${PROJECT_NAME})
set(CMAKE_BUILD_TYPE Release)
find_package(Eigen3 REQUIRED)

find_package(PCL 1.7.2)# REQUIRED COMPONENTS common io features visualization)
add_definitions(${PCL_DEFINITIONS})
find_package(ICP REQUIRED)
message(status "ICP PACKAGE is ${ICP_INCLUDE_DIRS} ${ICP_LIBRARIES}")

# Look for c++11 support
if(CMAKE_COMPILER_IS_GNUCXX)
   execute_process(COMMAND ${CMAKE_C_COMPILER} -dumpversion OUTPUT_VARIABLE GCC_VERSION)
   if (GCC_VERSION VERSION_GREATER 4.7 OR GCC_VERSION VERSION_EQUAL 4.7)
        message(STATUS "C++11 activated.")
        add_definitions("-std=c++11")
   elseif(GCC_VERSION VERSION_GREATER 4.3 OR GCC_VERSION VERSION_EQUAL 4.3)
        message(WARNING "C++0x activated. If you get any errors update to a compiler which fully supports C++11")
        add_definitions("-std=gnu++0x")
   else ()
        message(FATAL_ERROR "C++11 needed. Therefore a gcc compiler with a version higher than 4.3 is needed.")   
   endif()
else(CMAKE_COMPILER_IS_GNUCXX)
   add_definitions("-std=c++0x") 
endif(CMAKE_COMPILER_IS_GNUCXX)

add_definitions(-g -Wall -Wno-comment)
set(SOPHUS_INCLUDE_DIRS /opt/Sophus/include)
message(status ${SOPHUS_INCLUDE_DIRS})
#file(GLOB SOPHUS_HEADERS ${SOPHUS_INCLUDE_DIRS}/*.hpp)
include_directories (
  ${EIGEN3_INCLUDE_DIR}
  ${PCL_INCLUDE_DIRS}
  ${SOPHUS_INCLUDE_DIRS}
  ${ICP_INCLUDE_DIRS}
  )

link_directories (
  ${PCL_LIBRARY_DIRS}
  )
set(LIBRARIES
  ${EIGEN3_LIBRARY}
  ${PCL_LIBRARIES}
  ${PCL_COMMON_LIBRARIES}
  ${PCL_IO_LIBRARIES}
  ${PCL_FEATURES_LIBRARIES}
  ${PCL_VISUALIZATION_LIBRARIES}
  )
message(STATUS ${ICP_INCLUDE_DIRS})
file(GLOB ICP_HEADERS "${ICP_INCLUDE_DIRS}/*.hpp")
message(STATUS "icp headers : ${ICP_HEADERS}")
################################
# Normal Libraries & Executables
################################
# Add all cpp files but main.cpp to the library
  
  add_executable(icptest main.cpp )
  target_link_libraries(icptest ${ICP_LIBRARIES} ${LIBRARIES})

