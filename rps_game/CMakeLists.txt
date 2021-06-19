# meta information
cmake_minimum_required(VERSION 3.10)
project(RpcGame)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
  # game components
  src/computer.cc
  src/human.cc
  # strategies
  src/strategy_pure_random.cc
  # entry
  src/game.cc
  src/main.cc
)

add_library(sourcepack
  src/computer.cc
  src/human.cc
)

target_include_directories(sourcepack
  PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

add_executable(RpcGame ${SOURCES})

target_include_directories(RpcGame
  PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)
