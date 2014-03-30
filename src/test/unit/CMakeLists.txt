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
add_executable(GarthLib-Garth-tests GarthLib-Garth-tests.cpp)
add_executable(ConcurrentLib-ConcurrentObjects-tests ConcurrentLib-ConcurrentObjects-tests.cpp)
add_executable(ConcurrentLib-ConcurrentUtil-tests ConcurrentLib-ConcurrentUtil-tests.cpp)


#
# Link libraries:
#
target_link_libraries(GarthLib-Garth-tests GarthLib ${GTEST_BOTH_LIBRARIES} pthread)
target_link_libraries(ConcurrentLib-ConcurrentObjects-tests ConcurrentLib ${GTEST_BOTH_LIBRARIES} pthread)
target_link_libraries(ConcurrentLib-ConcurrentUtil-tests ConcurrentLib ${GTEST_BOTH_LIBRARIES} pthread)


#
# Add as test:
#
add_test(GarthLib-Garth-tests GarthLib-Garth-tests)
add_test(ConcurrentLib-ConcurrentObjects-tests ConcurrentLib-ConcurrentObjects-tests)
add_test(ConcurrentLib-ConcurrentUtil-tests ConcurrentLib-ConcurrentUtil-tests)


#
# Specify install directory:
#
install(
  TARGETS 
    GarthLib-Garth-tests
    ConcurrentLib-ConcurrentObjects-tests
    ConcurrentLib-ConcurrentUtil-tests
  DESTINATION 
    test
)
