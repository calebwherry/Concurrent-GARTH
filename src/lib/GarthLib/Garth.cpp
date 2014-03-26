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
