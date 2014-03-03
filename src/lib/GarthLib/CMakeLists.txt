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


#
# Create a static library:
#
add_library(Garth STATIC Garth.cpp)


#
# Add library headers and archive files to install:
#
install(TARGETS Garth DESTINATION lib)
install(FILES Garth.h DESTINATION include)
