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


#
# Add include directories for local libraries:
#
include_directories(${PROJECT_LIB_DIR}/GarthLib)


#
# Add executables:
#
add_executable(concurrent-garth concurrent-garth.cpp)


#
# Link libraries:
#
target_link_libraries(concurrent-garth Garth)


#
# Specify install directory:
#
install(TARGETS concurrent-garth DESTINATION bin)