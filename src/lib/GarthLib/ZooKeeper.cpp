////////////////////////////////////////
////////////////////////////////////////
//
//  Copyright (C) 2014 Korovasoft, Inc.
//
//  File:
//      \file ZooKeeper.cpp
//
//  Description:
//      \brief Garth Library: ZooKeeper implementaion.
//
//  Author:
//      \author J. Caleb Wherry
//
////////////////////////////////////////
////////////////////////////////////////


// Forward declarations:
////


// Local includes:
#include "ZooKeeper.h"


// Compiler includes:
#include <iostream>


// Namespaces:
using namespace std;


/// Garth namespace
namespace Garth
{

  //
  // ZooKeeper implementations:
  //

  // Default constructor:
  ZooKeeper::ZooKeeper():
    name(string(""))
  {
  };

  // Custom constructor:
  ZooKeeper::ZooKeeper(const string& name_):
    name(name_)
  {
    cout << "ZooKeeper::ZooKeeper(): ZooKeeper " << name << " created!" << endl;
  };

  // assignZoo method:
  void ZooKeeper::assignZoo(unique_ptr<Zoo> zoo_)
  {
    zoo = std::move(zoo_);

    cout << "ZooKeeper::assignZoo(): ZooKeeper " << name << " has been hired!" << endl;
  };

  // openZoo method:
  void ZooKeeper::openZoo()
  {
    zoo->open();
  };

  // suspendZoo method:
  void ZooKeeper::suspendZoo()
  {
    zoo->suspend();
  };

  // resumeZoo method:
  void ZooKeeper::resumeZoo()
  {
    zoo->resume();
  };

  // closeZoo method:
  void ZooKeeper::closeZoo()
  {
    zoo->close();
  };


} // Garth namespace
