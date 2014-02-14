########################################
########################################
##
##	Copyright (C) 2014 Korovasoft, Inc.
##
##  File:
##      \file CMakeLists.txt
##
##  Description:
##      \brief Library-level CMakeLists.txt
##
##  Author:
##      \author J. Caleb Wherry
##
########################################
########################################

cmake_minimum_required(VERSION 2.8)
project(Concurrent-GARTH)

add_library(garth STATIC Garth.cpp)

install(TARGETS garth DESTINATION lib)
install(FILES Garth.h DESTINATION include)
