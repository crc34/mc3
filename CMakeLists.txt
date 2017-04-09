


cmake_minimum_required(VERSION 2.8)

project(mcmc)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
include_directories(include thirdParty/Catch/include)

add_library(mcmc SHARED src/mcmc.cpp)

add_executable(tests tests/tests.cpp)
target_link_libraries(tests mcmc)


