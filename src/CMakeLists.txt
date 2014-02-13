########################################
########################################
##
##	Copyright (C) 2014 Korovasoft, Inc.
##
##  File:
##      \file CMakeLists.txt
##
##  Description:
##      \brief Source-level CMakeLists.txt
##
##  Author:
##      \author J. Caleb Wherry
##
########################################
########################################

cmake_minimum_required(VERSION 2.8)
project(Concurrent-GARTH)

# Compiler flags:
set(CMAKE_CXX_FLAGS "-Wall -Wextra -ggdb -O2 -std=c++11 -Wl,--no-as-needed")

# Add subdirectories:
add_subdirectory(concurrent-garth)
