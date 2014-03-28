////////////////////////////////////////
////////////////////////////////////////
//
//  Copyright (C) 2014 Korovasoft, Inc.
//
//  File:
//      \file GarthLib-tests.cpp
//
//  Description:
//      \brief Concurrent-GARTH: GarthLib tests
//
//  Author:
//      \author J. Caleb Wherry
//
////////////////////////////////////////
////////////////////////////////////////


// Local Includes:
////

// Compiler Includes:
#include <Garth.h>
#include <gtest/gtest.h>

// Namespaces:
using namespace std;
using namespace Garth;

TEST (Objects, Construtors)
{

  EXPECT_NO_THROW({
    Zoo zoo;
  });

}
