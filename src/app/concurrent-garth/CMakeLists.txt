########################################
########################################
##
##  Copyright (C) 2014 Korovasoft, Inc.
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
include_directories(${PROJECT_LIB_DIR}/ConcurrentLib)


#
# MPI Library:
#
find_package(MPI REQUIRED) 
include_directories(${MPI_INCLUDE_PATH})


#
# Add executables:
#
add_executable(concurrent-garth concurrent-garth.cpp ${MPI_LIBRARIES})


#
# Link libraries:
#
target_link_libraries(concurrent-garth ConcurrentLib GarthLib mpi)


#
# Specify install directory:
#
install(TARGETS concurrent-garth DESTINATION bin)
