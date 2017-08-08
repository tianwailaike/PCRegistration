cmake_minimum_required(VERSION 2.6)
project(pcregistration)

#compiler config
set(CMAKE_CXX_COMPILER "g++")
#set(CMAKE_CXX_COMPILER "clang++")

#debug config
set(CMAKE_BUILD_TYPE Debug)

#debug config
#set(CMAKE_BUILD_TYPE Release)
#set(CMAKE_CXX_FLAGS "-std=c++11 -march=native -O3 ")

#DIR config
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR})
set(SRC_DIR ${PROJECT_SOURCE_DIR}/src)
set(INC_DIR ${PROJECT_SOURCE_DIR}/include)
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
include_directories(${PROJECT_SOURCE_DIR}/include
                    ${PROJECT_SOURCE_DIR}/include/super4pcs
                    ${PROJECT_SOURCE_DIR}/include/icprefine)
# add the binary tree to the search path for include files
include_directories("${PROJECT_BINARY_DIR}")
set(OpenCV_INSTALL_PATH "/opt/opencv-2.4.13")
set(OpenCV_DIR "/opt/opencv-2.4.13/share/OpenCV")

#pctest
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "/home/ubuntu/Downloads/opencv-2.4.13/build")
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "/opt/Qt5.8.0/5.8/gcc_64/lib/cmake")
set(CMAKE_PREFIX_PATH ${CMAKE_PREFIX_PATH} "/usr/lib/cmake/vtk-6.2")
################################################################################
## Configuration file
################################################################################
set(CUDA_USE_STATIC_CUDA_RUNTIME OFF) #防止出现can't find lopencv_dep_cudart
# configure a header file to pass some of the CMake settings
set(CMAKE_CXX_FLAGS ${ADDITIONAL_CMAKE_CXX_FLAGS} "-O3 -msse2 -msse3 -Wall")
# Set option to enable timing recording
OPTION (SUPER4PCS_COMPILE_TESTS "Enable testing" TRUE)
OPTION (IO_USE_OPENCV "Use OpenCV for texture loading" TRUE)
OPTION (ENABLE_TIMING "Enable computation time recording" FALSE)
OPTION (SUPER4PCS_USE_CHEALPIX "Use Chealpix for orientation filtering (deprecated)" FALSE)
OPTION (DL_DATASETS "Download demo datasets and associated run scripts" FALSE)




################################################################################
## GUARDS
################################################################################

# guard against in-source builds (source: Eigen)
if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
  message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there. You may need to remove CMakeCache.txt. ")
endif()

# guard against bad build-type strings (source: Eigen)
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release")
endif()
string(TOLOWER "${CMAKE_BUILD_TYPE}" cmake_build_type_tolower)
if(    NOT cmake_build_type_tolower STREQUAL "debug"
   AND NOT cmake_build_type_tolower STREQUAL "release"
   AND NOT cmake_build_type_tolower STREQUAL "relwithdebinfo")
  message(FATAL_ERROR "Unknown build type \"${CMAKE_BUILD_TYPE}\". Allowed values are Debug, Release, RelWithDebInfo (case-insensitive).")
endif()

################################################################################
## Compiler configuration
################################################################################
if( NOT cmake_build_type_tolower STREQUAL "release" )
  add_definitions(-DDEBUG)
endif()

if (MSVC)
  if (MSVC_VERSION LESS 1900)
        message(FATAL_ERROR "Requires Microsoft Visual Studio Compiler version 14.0 or above.")
  endif()
endif()

# Add the c++11 flag, whatever it is
# This test is by-passed for MSVC compiler, which support C++11 features natively
# without requiring a flag (after version 1800)
include(CheckCXXCompilerFlag)
if (NOT MSVC)
  CHECK_CXX_COMPILER_FLAG(-std=c++11 COMPILER_SUPPORTS_CXX11)
  CHECK_CXX_COMPILER_FLAG(-std=c++0x COMPILER_SUPPORTS_CXX0X)
  if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
  elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
  else()
        message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
  endif()
endif()

################################################################################
## Apply user-defined configuration
################################################################################
if (ENABLE_TIMING)
    ADD_DEFINITIONS( -DTEST_GLOBAL_TIMINGS )
    message ("OPT: Enable timing recording")
endif (ENABLE_TIMING)

if (DL_DATASETS)
    include(ExternalProject)

    ExternalProject_Add(dl-dataset-demo1
        SOURCE_DIR ${CMAKE_CURRENT_BINARY_DIR}/datasets/demo1
        URL https://www.irit.fr/~Nicolas.Mellado/dl/datasets/point-clouds/Super4PCS-dataset-demo1.zip
        URL_MD5 68796d9b4efa7edee3ed6f55b92cf7ad
        CONFIGURE_COMMAND ""
        BUILD_COMMAND ""
        INSTALL_COMMAND ""
    )

add_custom_target(dl-datasets DEPENDS dl-dataset-demo1)

endif (DL_DATASETS)

################################################################################
## Dependencies
################################################################################

#Super4pcs
add_subdirectory(${PROJECT_SOURCE_DIR}/thirdparty)
if(SUPER4PCS_USE_CHEALPIX)
    add_definitions(-DSUPER4PCS_USE_CHEALPIX)
    include_directories(${Chealpix_INCLUDE_DIR})
endif(SUPER4PCS_USE_CHEALPIX)

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

#icprefine
#find_package(Eigen3 REQUIRED)

#find_package(PCL 1.7.2)# REQUIRED COMPONENTS common io features visualization)
#add_definitions(${PCL_DEFINITIONS})
find_package(ICP REQUIRED)
message(status "ICP PACKAGE is ${ICP_INCLUDE_DIRS} ${ICP_LIBRARIES}")

add_definitions(-g -Wall -Wno-comment)
set(SOPHUS_INCLUDE_DIRS /opt/Sophus/include)
message(status ${SOPHUS_INCLUDE_DIRS})
#file(GLOB SOPHUS_HEADERS ${SOPHUS_INCLUDE_DIRS}/*.hpp)


#-----------pctest------------
find_package(OpenCV REQUIRED)
find_package(PCL 1.7.2 REQUIRED COMPONENTS common io visualization registration)
find_package(Qt5 REQUIRED COMPONENTS Gui Core Widgets)
find_package(VTK REQUIRED)
add_definitions(${PCL_DEFINITIONS})
# find_package(Qt5Gui REQUIRED)
# find_package(Qt5Core REQUIRED)
# find_package(Qt5Widgets REQUIRED)

set(CMAKE_AUTOMOC ON)  #通过这个打开moc编译
#set(VTK_LIBRARIES vtkRendering vtkGraphics vtkHybrid QVTK)
################################
# Normal Libraries & Executables
################################
# Add all cpp files but main.cpp to the library

#--------------Super4pcs----------------
include_directories(${SRC_DIR}
                    ${INC_DIR})
set(Super4PCS_SRC
    ${SRC_DIR}/super4pcs/algorithms/match4pcsBase.cc
    ${SRC_DIR}/super4pcs/algorithms/4pcs.cc
    ${SRC_DIR}/super4pcs/algorithms/super4pcs.cc
    ${SRC_DIR}/super.cpp
)
set(Super4PCS_INCLUDE
    ${INC_DIR}/super4pcs/sampling.h
    ${INC_DIR}/super4pcs/shared4pcs.h
    ${INC_DIR}/super4pcs/pairExtraction.h
    ${INC_DIR}/super4pcs/algorithms/match4pcsBase.h
    ${INC_DIR}/super4pcs/algorithms/4pcs.h
    ${INC_DIR}/super4pcs/algorithms/super4pcs.h
    ${INC_DIR}/super4pcs/pairCreationFunctor.h
)

add_subdirectory(${SRC_DIR}/super4pcs/io)
add_subdirectory(${SRC_DIR}/super4pcs/utils)
add_subdirectory(${SRC_DIR}/super4pcs/accelerators)

#generate super4pcs algo library 
add_library(super4pcs_algo ${Super4PCS_SRC} ${Super4PCS_INCLUDE})
# add the executable
add_executable(super4pcs ${SRC_DIR}/super4pcs/super4pcs_test.cc)
#add_executable(super ${SRC_DIR}/super.cpp)
TARGET_LINK_LIBRARIES(super4pcs_algo super4pcs_io super4pcs_accel)
TARGET_LINK_LIBRARIES(super4pcs super4pcs_algo super4pcs_utils)
#TARGET_LINK_LIBRARIES(super super4pcs_algo super4pcs_utils)
#--------------icprefine------------------
file(GLOB ICP_SRC ${SRC_DIR}/icprefine/*.cpp)
set(ICP_INCLUDE
    ${INC_DIR}/icprefine/icprefine.h
)
include_directories (
  ${EIGEN3_INCLUDE_DIR}
  ${PCL_INCLUDE_DIRS}
  ${SOPHUS_INCLUDE_DIRS}
  ${ICP_INCLUDE_DIRS}
  )

link_directories (
  ${PCL_LIBRARY_DIRS}
  )
set(ICPREFINE_LIBRARIES
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

# Add all cpp files but main.cpp to the library
  add_library(icp_algo SHARED ${ICP_SRC} ${ICP_INCLUDE} ${CMAKE_SOURCE_DIR}/src/icprefine.cpp)
  target_link_libraries(icp_algo ${ICP_LIBRARIES} ${ICPREFINE_LIBRARIES})
  add_executable(icprefine ${SRC_DIR}/icprefine.cpp)
  target_link_libraries(icprefine ${ICP_LIBRARIES} ${ICPREFINE_LIBRARIES})


################################################################################
## Tests
################################################################################

if(SUPER4PCS_COMPILE_TESTS)
        include(cmake/ConfigureTesting.cmake)
        add_subdirectory(tests EXCLUDE_FROM_ALL)
endif(SUPER4PCS_COMPILE_TESTS)

if(ICPREFINE_COMPILE_TESTS)
        include(cmake/ConfigureTesting.cmake)
        add_subdirectory(tests EXCLUDE_FROM_ALL)
endif(ICPREFINE_COMPILE_TESTS)

################################################################################
## Project files
################################################################################

include_directories(${OpenCV_INCLUDE_DIRS}
                    ${PCL_INCLUDE_DIRS}
                    ${VTK_INCLUDE_DIRS}
                    ${INC_DIR})
link_directories(${PCL_LIBRARY_DIRS}
                 "${CMAKE_SOURCE_DIR}/lib")
file(GLOB srcs ${SRC_DIR}/*.cpp)
file(GLOB hdrs ${SRC_DIR}/*.h)
qt5_wrap_ui(hdr_ui ${SRC_DIR}/pclviewer.ui) #used to moc compile ui.h

add_executable(pctest ${SRC_DIR}/pclviewer.cpp ${SRC_DIR}/pclviewer.h ${hdr_ui} ${SRC_DIR}/main.cpp
                ${SRC_DIR}/ICPViewer.cpp ${INC_DIR}/ICPViewer.h )
qt5_use_modules(pctest Widgets Core Gui)#this is a modern way to use the qt moudles
message(status ${Qt5Gui_LIBRARIES}) 
message(status ${VTK_LIBRARIES})
target_link_libraries(pctest ${PCL_COMMON_LIBRARIES} ${PCL_IO_LIBRARIES} ${PCL_VISUALIZATION_LIBRARIES}
                      ${OpenCV_LIBS} ${VTK_LIBRARIES} icp_algo super4pcs_algo)     
                      #icp_algo super4pcs_algo         

#install(TARGETS pcregistration RUNTIME DESTINATION bin)
