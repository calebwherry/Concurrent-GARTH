########################################
########################################
##
##  Copyright (C) 2014 Korovasoft, Inc.
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


#
# Include directories:
#
include_directories(
  ${PROJECT_LIB_DIR}/ConcurrentLib
)


#
# Create a static library:
#
add_library(GarthLib Garth.cpp)


#
# Add library headers and archive files to install:
#
install(TARGETS GarthLib DESTINATION lib)
install(FILES Garth.h DESTINATION include/garth)
