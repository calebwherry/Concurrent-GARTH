////////////////////////////////////////
////////////////////////////////////////
//
//  Copyright (C) 2014 Korovasoft, Inc.
//
//  File:
//      \file Garth.h
//
//  Description:
//      \brief Garth Library header.
//
//  Author:
//      \author J. Caleb Wherry
//
////////////////////////////////////////
////////////////////////////////////////


// Include guards:
#ifndef GARTH_H
#define GARTH_H


// Forward declarations:
//


// Local includes:
//


// Compiler includes:
#include <memory>
#include <string>
#include <ConcurrentObjects.h>


// Namespaces:
namespace CO = ConcurrentObjects;


/// Garth namespace
namespace Garth
{

  /// Organism class
  class Organism
  {

    protected:

      std::string name;
      std::vector<double> genome;
      uint32_t numGenes;
      double fitness;

    public:

      /// Default constructor
      Organism();

      /// Custom constructor
      Organism (
        const std::string& name_,
        double fitness_ = 0.0
      );

      /// Destructor
      virtual ~Organism();

      /// Mutate method
      virtual void mutate();

  };

  /// Population typedef (new syntax)
  using Population = CO::ConcurrentVector<Organism>;


  /// Habitat class
  class Habitat
  {

    private:

      std::string name;
      uint32_t numberTrainers;

    public:

      /// Default constructor
      Habitat();

      /// Custom constructor
      Habitat (
        uint32_t numberTrainers
      );

      /// Get number of trainers:
      uint32_t getNumberTrainers();

      /// Set number of trainers:
      void setNumberTrainers(uint32_t numberTrainers);

  };

  /// Habitat typedef
  using Habitats = std::vector<Habitat>;


  /// Zoo Statuses
  enum ZooStatus
  {
    UNKNOWN,    ///< Unknown status
    OPEN,       ///< Open status
    SUSPENDED,  ///< Suspended status
    RESUMED,    ///< Resumed status
    CLOSED      ///< Closed status
  };


  /// Zoo class
  class Zoo
  {

    friend class ZooKeeper;

    private:

      std::string name;         ///< Zoo name
      ZooStatus status;         ///< Status of Zoo
      Population population;    ///< Zoo Organism population
      Habitats habitats;        ///< Zoo habitats
      uint32_t numberHabitats;  ///< Number of habitats
      uint32_t maxGenerations;  ///< Max number of generations
      uint32_t numberTrainers;  ///< Number of trainers

    public:

      /// Default constructor
      Zoo();

      /// Custom constructor
      Zoo (
        const std::string& name_,
        ZooStatus status_ = OPEN
      );

      // Zoo operations:
      void open();
      void suspend();
      void resume();
      void close();

      // Get methods:
      uint32_t getMaxGenerations();
      uint32_t getNumberHabitats();
      uint32_t getNumberTrainers();

      // Set Max Generations
      void setMaxGenerations (
        uint32_t maxGenerations_
      );

      // Set Number of Habitats
      void setNumberHabitats (
        uint32_t numberHabitats_
      );

      // Set Number Trainers
      void setNumberTrainers (
        uint32_t numberHabitats
      );

  };


  /// ZooKeeper class
  class ZooKeeper
  {

    private:

      std::string name;
      std::shared_ptr<Zoo> zoo;

    public:

      /// Default constructor
      ZooKeeper();

      /// Custom constructor
      ZooKeeper (
        const std::string& name_,
        std::shared_ptr<Zoo> zoo_
      );  

      // Zoo operations:
      void openZoo();
      void suspendZoo();
      void resumeZoo();
      void closeZoo();

      // Population operations:
      void initializePopulation();
      void shufflePopulation();
      void rankPopulation();
      void mutatePopulation();
      bool populationConverged();

      // Organism operations:
      std::shared_ptr<Organism> getOptimalOrganism();

  };


  /// Trainer class
  class Trainer
  {
    
    private:

      std::string name;

    public:

      /// Default constructor
      Trainer();

      /// Custom constructor
      Trainer (
        const std::string& name_
      );

      /// Set name
      void setName (
        const std::string& name_
      );

      /// Get name
      std::string getName();

  };


} // Garth namespace


#endif // GARTH_H
