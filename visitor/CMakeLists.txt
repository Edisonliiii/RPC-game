# meta information
cmake_minimum_required(VERSION 3.10)
project(visitor)

# cxx standard version
set(CMAKE_CXX_STANDARD 11)

# set sources
set(SOURCES
  src/area_visitor.cc
  src/circle.cc
  src/rectangle.cc
  src/triangle.cc
  src/main.cc
)

# generate the static library
add_library(sourcepack
  src/area_visitor.cc
  src/circle.cc
  src/rectangle.cc
  src/triangle.cc
)

target_include_directories(sourcepack
  PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

# exec
add_executable(visitor ${SOURCES})

# include
target_include_directories(visitor
  PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)


add_subdirectory(test)