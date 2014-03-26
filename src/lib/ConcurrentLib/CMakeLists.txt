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
# Create a static library:
#
add_library(ConcurrentLib STATIC ConcurrentUtil.cpp ConcurrentObjects.cpp)


#
# Add library headers and archive files to install:
#
install(TARGETS ConcurrentLib DESTINATION lib)
install(FILES ConcurrentUtil.h ConcurrentObjects.h DESTINATION include/garth)
