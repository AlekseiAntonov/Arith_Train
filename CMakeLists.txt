
cmake_minimum_required(VERSION 3.15)
project(Arith_Train)
set(CMAKE_CXX_STANDARD 17)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include_directories($ENV{UniversalCRTSdkDir}/Include/ucrt)
include_directories($ENV{UniversalCRTSdkDir}/Include/10.0.10056.0/ucrt)

add_executable(Arith_Train WIN32 main.cpp WndProc.cpp Math.cpp main.h)