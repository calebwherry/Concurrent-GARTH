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
include_directories(
  ${PROJECT_LIB_DIR}/GarthLib 
  ${PROJECT_LIB_DIR}/ConcurrentLib
)


#
# MPI Library:
#
find_package(MPI REQUIRED) 
include_directories(${MPI_INCLUDE_PATH})
set(CMAKE_CXX_COMPILE_FLAGS "${CMAKE_CXX_COMPILE_FLAGS} ${MPI_COMPILE_FLAGS}")
set(CMAKE_CXX_LINK_FLAGS "${CMAKE_CXX_LINK_FLAGS} ${MPI_LINK_FLAGS}")

#
# Add executables:
#
add_executable(mpi-test mpi-test.cpp)


#
# Link libraries:
#
target_link_libraries(mpi-test ConcurrentLib GarthLib ${MPI_LIBRARIES})


#
# Specify install directory:
#
install(TARGETS mpi-test DESTINATION bin)
