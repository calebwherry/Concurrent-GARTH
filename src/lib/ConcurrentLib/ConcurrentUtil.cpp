////////////////////////////////////////
////////////////////////////////////////
//
//  Copyright (C) 2014 Korovasoft, Inc.
//
//  File:
//      \file ConcurrentUtil.cpp
//
//  Description:
//      \brief ConcurrentUtil Library implementation.
//
//  Author:
//      \author J. Caleb Wherry
//
////////////////////////////////////////
////////////////////////////////////////


// Forward declarations:
////


// Local includes:
#include "ConcurrentUtil.h"


// Compiler includes:
#include <thread>


/// ConcurrentUtil namespace
namespace ConcurrentUtil
{

  uint32_t getNumberCores()
  {

    // Initial core number from thread library:
    uint32_t numThreads = std::thread::hardware_concurrency();

    // Above function could return 0, so we hardcore a value of 4 if that happens:
    return (numThreads != 0) ? numThreads : 4;
  
  }

} // ConcurrentUtil namespace
