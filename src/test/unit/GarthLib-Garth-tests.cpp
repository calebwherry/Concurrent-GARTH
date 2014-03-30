////////////////////////////////////////
////////////////////////////////////////
//
//  Copyright (C) 2014 Korovasoft, Inc.
//
//  File:
//      \file GarthLib-Garth-tests.cpp
//
//  Description:
//      \brief Concurrent-GARTH: GarthLib::Garth tests
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

TEST (Garth, Construtors)
{

  EXPECT_NO_THROW({
    Zoo zoo;
  });

}
