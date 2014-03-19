////////////////////////////////////////
////////////////////////////////////////
//
//  Copyright (C) 2014 Korovasoft, Inc.
//
//  File:
//      \file ConcurrentUtil.h
//
//  Description:
//      \brief ConcurrentUtil Library header.
//
//  Author:
//      \author J. Caleb Wherry
//
////////////////////////////////////////
////////////////////////////////////////


// Include guards:
#ifndef CONCURRENT_UTIL_H
#define CONCURRENT_UTIL_H


// Forward declarations:
////


// Local includes:
////


// Compiler includes:
#include<cstdint>


/// ConcurrentUtil namespace
namespace ConcurrentUtil
{

  uint32_t getNumberCores();

} // ConcurrentUtil namespace


#endif // CONCURRENT_UTIL_H
