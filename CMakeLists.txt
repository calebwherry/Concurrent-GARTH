########################################
########################################
##
##	Copyright (C) 2014 Korovasoft, Inc.
##
##  File:
##      \file CMakeLists.txt
##
##  Description:
##      \brief Top-level CMakeLists.txt
##
##  Author:
##      \author J. Caleb Wherry
##
########################################
########################################

#
# CMake version and project name:
#
cmake_minimum_required(VERSION 2.8)
project(Concurrent-GARTH)


#
# Check compiler versions:
#
if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	# require at least gcc 4.8.0
	if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.7)
		message(FATAL_ERROR "GCC version must be at least 4.8.0!")
	endif()
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
	# require at least clang 3.2.0
	if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 3.2.0)
		message(FATAL_ERROR "Clang version must be at least 3.2.0!")
	endif()
else()
	message(WARNING "You are using an unsupported compiler! Compilation has only been tested with GCC and Clang.")
endif()


#
# Add subdirectories:
#
add_subdirectory(lib)
add_subdirectory(src)
