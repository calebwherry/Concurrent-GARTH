////////////////////////////////////////
////////////////////////////////////////
//
//  Copyright (C) 2014 Korovasoft, Inc.
//
//  File:
//      \file Zoo.cpp
//
//  Description:
//      \brief Garth Library: Zoo implementaion.
//
//  Author:
//      \author J. Caleb Wherry
//
////////////////////////////////////////
////////////////////////////////////////


// Forward declarations:
////


// Local includes:
#include "Zoo.h"


// Compiler includes:
#include <iostream>


// Namespaces:
using namespace std;


/// Garth namespace
namespace Garth
{

  //
  // Zoo implementations:
  //

  // Default constructor:
  Zoo::Zoo ():
    name(string("")),
    status(UNKNOWN)
  {
  };

  // Custom constructor:
  Zoo::Zoo (const string& name_, ZooStatus status_):
    name(name_),
    status(status_)
  {
    cout << "Zoo::Zoo(): Construction complete for " << name << "!" << endl;
  };

  // Methods:
  void Zoo::open()
  {
    status = OPEN;

    cout << "Zoo::open(): " << name << " is now open!" << endl;
  };

  void Zoo::suspend()
  {
    status = SUSPENDED;

    cout << "Zoo::suspend(): " << name << " has been suspended!" << endl;
  };

  void Zoo::resume()
  {
    status = RESUMED;

    cout << "Zoo::resume(): " << name << " has been resumed!" << endl;
  };

  void Zoo::close()
  {
    status = CLOSED;

    cout << "Zoo::close(): " << name << " has been closed!" << endl;
  };


} // Garth namespace
