cmake_minimum_required(VERSION 3.17.2)
project(apps
VERSION 0.1
  DESCRIPTION "An example project with CMake"
  LANGUAGES CXX)


add_subdirectory(cmake/cmake_functions)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    find_package(ph REQUIRED)
endif()




add_subdirectory(xcards)
