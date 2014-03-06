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

	# Check version. If too old, error out:
	if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 4.8)
		message(FATAL_ERROR "GCC compiler version must be at least 4.8!")
	endif()

	# Set compiler specific variables:
	set(CMAKE_CXX_FLAGS "-Wall -Wextra -ggdb -O2 -std=c++11 -Wl,--no-as-needed")

elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")

	# Check version. If too old, error out:
	if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 3.2)
		message(FATAL_ERROR "Clang compiler version must be at least 3.2!")
	endif()

	# Set compiler specific variables:
	set(CMAKE_CXX_FLAGS "-Wall -Wextra -ggdb -O2 -std=c++11")

elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")

	# Check version. If too old, error out:
	if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 18.0)
		message(FATAL_ERROR "MSVC compiler version must be at least 18.0!")
	endif()

	# Set compiler specific variables:
	set(CMAKE_CXX_FLAGS "")

elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")

	# Check version. If too old, error out:
	if (CMAKE_CXX_COMPILER_VERSION VERSION_LESS 14.0)
		message(FATAL_ERROR "MSVC compiler version must be at least 14.0!")
	endif()

	# Set compiler specific variables:
	set(CMAKE_CXX_FLAGS "")

else()

	message(WARNING "The '${CMAKE_CXX_COMPILER_ID}' compiler is untested and unsupported, continue at your own risk!")

endif()



#
# Set global project path variables:
#
set(PROJECT_ROOT_DIR "${PROJECT_SOURCE_DIR}")
set(PROJECT_SRC_DIR "${PROJECT_ROOT_DIR}/src")
set(PROJECT_LIB_DIR "${PROJECT_SRC_DIR}/lib")
set(PROJECT_APP_DIR "${PROJECT_SRC_DIR}/app")
set(PROJECT_TEST_DIR "${PROJECT_SRC_DIR}/test")
set(PROJECT_DOC_DIR "${PROJECT_ROOT_DIR}/doc")


#
# Testing:
#
include( CTest )


#
# Add subdirectories:
#
add_subdirectory(src)
add_subdirectory(doc)
add_subdirectory(papers)
