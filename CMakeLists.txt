cmake_minimum_required(VERSION 3.10.0)
project(LineDrawing VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cloudrender main.cpp tgaimage.cpp tgaimage.h geometry.h model.h model.cpp) 

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
