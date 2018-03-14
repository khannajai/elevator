cmake_minimum_required(VERSION 3.5.1)
project(elevator)

#set variables for directory names and files
set(SOURCES_INCLUDE "include")
file(GLOB SOURCES "src/*.cpp" ${SOURCES_INCLUDE}/*.h)
file(GLOB SOURCES_TEST "test/*.cpp")

#for linking the files
include_directories(${SOURCES_INCLUDE})
add_executable(elevator ${SOURCES})

#compiler flags
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")