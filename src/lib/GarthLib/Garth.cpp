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
  // Organism implementation:
  //

  // Default constructor:
  Organism::Organism():
    name(string("")),
    genome(),
    numGenes(0),
    fitness(0.0)
  {
    // Nothing to do.
  };

  // Custom constructor:
  Organism::Organism(const string& name_, double fitness_):
    name(name_),
    genome(),
    numGenes(0),
    fitness(fitness_)
  {
    // Nothing to do.
  };

  // Destructor
  Organism::~Organism()
  {
    // Nothing to do.
  }

  // Mutate
  void Organism::mutate()
  {
    // Nothing to do.
  }


  //  
  // Zoo implementation:
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

  uint32_t Zoo::getMaxGenerations()
  {
    return maxGenerations;
  };

  uint32_t Zoo::getNumberHabitats()
  {
    return numberHabitats;
  };

  uint32_t Zoo::getNumberTrainers()
  {
    return numberTrainers;
  };

  void Zoo::setMaxGenerations(uint32_t maxGenerations_)
  {
    maxGenerations = maxGenerations_;
  };

  void Zoo::setNumberHabitats(uint32_t numberHabitats_)
  {
    numberHabitats = numberHabitats_;
  };

  void Zoo::setNumberTrainers(uint32_t numberTrainers_)
  {
    numberTrainers = numberTrainers_;
  };


  //  
  // ZooKeeper implementation:
  //  

  // Default constructor:
  ZooKeeper::ZooKeeper():
    name(string("")),
    zoo(shared_ptr<Zoo>())
  {
  };  

  // Custom constructor:
  ZooKeeper::ZooKeeper(const string& name_, shared_ptr<Zoo> zoo_):
    name(name_),
    zoo(zoo_)
  {
    cout << "ZooKeeper::ZooKeeper(): ZooKeeper " << name << " created!" << endl;  
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

  // initializePopulation method:
  void ZooKeeper::initializePopulation()
  {
  };

  // shufflePopulation method:
  void ZooKeeper::shufflePopulation()
  {
  };

  // rankPopulation method:
  void ZooKeeper::rankPopulation()
  {
  };

  // mutatePopulation method:
  void ZooKeeper::mutatePopulation()
  {
  };

  // populationConverged method:
  bool ZooKeeper::populationConverged()
  {
    return false;
  };

  // getOptimalOrgnism method:
  shared_ptr<Organism> ZooKeeper::getOptimalOrganism()
  {
    return make_shared<Organism>();
  };



  //
  // Habitat implementation:
  //

  // Default constructor:
  Habitat::Habitat():
    name(string("")),
    numberTrainers(0)
  {
  };

  // Custom constructor:
  Habitat::Habitat(uint32_t numberTrainers_):
    numberTrainers(numberTrainers_)
  {
  };

  // Get num trainers method:
  uint32_t Habitat::getNumberTrainers()
  {
    return numberTrainers;
  };

  // Set num trainers:
  void Habitat::setNumberTrainers(uint32_t numberTrainers_)
  {
    numberTrainers = numberTrainers_;
  };


  //
  // Trainer implementation:
  //

  // Default constructor:
  Trainer::Trainer():
    name(string(""))
  {
  };  

  // Custom constructor:
  Trainer::Trainer(const string& name_):
    name(name_)
  {
  };

  // Set name:
  void Trainer::setName(const string& name_)
  {
    name = name_;
  };

  // Get name:
  string Trainer::getName()
  {
    return name;
  };


} // Garth namespace
