########################################
########################################
##
##	Copyright (C) 2014 Korovasoft, Inc.
##
##  File:
##      \file CMakeLists.txt
##
##  Description:
##      \brief App-level CMakeLists.txt
##
##  Author:
##      \author J. Caleb Wherry
##
########################################
########################################

cmake_minimum_required(VERSION 2.8)
project(Concurrent-GARTH)

# Compiler flags:
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

# Add executables:
add_executable(concurrent-garth concurrent-garth.cpp)

# Link libraries:
target_link_libraries(concurrent-garth garth)

# Specify install directory:
install(TARGETS concurrent-garth DESTINATION bin)
