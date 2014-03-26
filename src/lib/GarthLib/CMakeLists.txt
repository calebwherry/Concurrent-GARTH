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
add_library(GarthLib STATIC Zoo.cpp ZooKeeper.cpp Organism.cpp)


#
# Add library headers and archive files to install:
#
install(TARGETS GarthLib DESTINATION lib)
install(FILES Zoo.h ZooKeeper.h Organism.h DESTINATION include)
