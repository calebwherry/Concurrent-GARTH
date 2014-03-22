////////////////////////////////////////
////////////////////////////////////////
//
//  Copyright (C) 2014 Korovasoft, Inc.
//
//  File:
//      \file Garth.cpp
//
//  Description:
//      \brief Garth Library implementaion.
//
//  Author:
//      \author J. Caleb Wherry
//
////////////////////////////////////////
////////////////////////////////////////


// Forward declarations:
////


// Local includes:
#include "Garth.h"


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
    status(UNKNOWN)
  {
    cout << "Zoo::Zoo(): Construction complete!" << endl;
  };

  // Custom constructor:
  Zoo::Zoo (ZooStatus _status):
    status(_status)
  {
    cout << "Zoo::Zoo(): Construction complete!" << endl;
  };

  // Methods:
  void Zoo::open()
  {
    status = OPEN;

    cout << "Zoo::open(): The Zoo is now open!" << endl;
  };

  void Zoo::suspend()
  {
    status = SUSPENDED;

    cout << "Zoo::suspend(): The Zoo has been suspended!" << endl;
  };

  void Zoo::resume()
  {
    status = RESUMED;

    cout << "Zoo::resume(): The Zoo has been resumed!" << endl;
  };

  void Zoo::close()
  {
    status = CLOSED;

    cout << "Zoo::close(): The Zoo has been closed!" << endl;
  };


  //
  // ZooKeeper implementations:
  //

  // Default constructor:
  ZooKeeper::ZooKeeper():
    name(string(""))
  {
    cout << "ZooKeeper::ZooKeeper(): A new ZooKeeper has been hired!" << endl;
  };

  // Custom constructor:
  ZooKeeper::ZooKeeper(const string& _name):
    name(_name)
  {
    cout << "ZooKeeper::ZooKeeper(): ZooKeeper " << name << " has been hired!" << endl;
  };

  // Methods:
  void ZooKeeper::openZoo() {};
  void ZooKeeper::suspendZoo() {};
  void ZooKeeper::resumeZoo() {};
  void ZooKeeper::closeZoo() {};

} // Garth namespace
