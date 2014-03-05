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
## TODO: No worky with Travis-CI environment... why? I believe it is because cmake version on Travis-CI is 2.8.7 and I am running 2.8.11 locally. Must be a fix in there somewhere.
#if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
#  set(CMAKE_CXX_FLAGS "-Wall -Wextra -ggdb -O2 -std=c++11 -Wl,--no-as-needed")
#elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
#  set(CMAKE_CXX_FLAGS "-Wall -Wextra -ggdb -O2 -std=c++11")
#elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
#  set(CMAKE_CXX_FLAGS "")
#else()
#	message(WARNING "You are using an unsupported compiler so no compiler flags have been set! Compilation has only been tested with GCC, Clang, and MSVC.")
#endif()
set(CMAKE_CXX_FLAGS "-Wall -Wextra -ggdb -O2 -std=c++11 -Wl,--no-as-needed")


#
# Add subdirectories:
#
add_subdirectory(concurrent-garth)
