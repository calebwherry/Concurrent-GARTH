########################################
########################################
##
##	Copyright (C) 2014 Korovasoft, Inc.
##
##  File:
##      \file CMakeLists.txt
##
##  Description:
##      \brief Application-level CMakeLists.txt
##
##  Author:
##      \author J. Caleb Wherry
##
########################################
########################################


#
#  Set compiler flags for source files:
#
set(CMAKE_CXX_FLAGS "-Wall -Wextra -ggdb -O2 -std=c++11 -Wl,--no-as-needed")


#
# Add subdirectories:
#
add_subdirectory(concurrent-garth)
