########################################
########################################
##
##  Copyright (C) 2014 Korovasoft, Inc.
##
##  File:
##      \file CMakeLists.txt
##
##  Description:
##      \brief Test-level CMakeLists.txt
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
# GTest
#
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
enable_testing()


#
# Add executables:
#
add_executable(GarthLib-tests GarthLib-tests.cpp)


#
# Link libraries:
#
target_link_libraries(GarthLib-tests GarthLib ${GTEST_BOTH_LIBRARIES} pthread)


#
# Add as test:
#
add_test(GarthLib-tests GarthLib-tests)


#
# Specify install directory:
#
install(TARGETS GarthLib-tests DESTINATION test)
