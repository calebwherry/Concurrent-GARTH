////////////////////////////////////////
////////////////////////////////////////
//
//  Copyright (C) 2014 Korovasoft, Inc.
//
//  File:
//      \file ConcurrentLib-ConcurrentObjects-tests.cpp
//
//  Description:
//      \brief Concurrent-GARTH: ConcurrentLib::ConcurrentObjects tests
//
//  Author:
//      \author J. Caleb Wherry
//
////////////////////////////////////////
////////////////////////////////////////


// Local Includes:
////

// Compiler Includes:
#include <ConcurrentObjects.h>
#include <gtest/gtest.h>

// Namespaces:
using namespace std;
using namespace ConcurrentObjects;

TEST (ConcurrentObjects, Construtors)
{

  EXPECT_NO_THROW({
    ConcurrentVector<double> doubles;
  });

}
