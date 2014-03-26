////////////////////////////////////////
////////////////////////////////////////
//
//  Copyright (C) 2014 Korovasoft, Inc.
//
//  File:
//      \file Organism.cpp
//
//  Description:
//      \brief Garth Library: Organism implementaion.
//
//  Author:
//      \author J. Caleb Wherry
//
////////////////////////////////////////
////////////////////////////////////////


// Forward declarations:
////


// Local includes:
#include "Organism.h"


// Compiler includes:
#include <iostream>


// Namespaces:
using namespace std;


/// Garth namespace
namespace Garth
{

  //
  // Organism implementation:
  //

  // Default constructor:
  Organism::Organism():
    name(string("")),
    fitness(0.0)
  {
  };

  // Custom constructor:
  Organism::Organism(const string& name_, double fitness_):
    name(name_),
    fitness(fitness_)
  {
  };


} // Garth namespace
