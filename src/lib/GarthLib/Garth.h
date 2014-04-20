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

      std::string name;       ///< Zoo name
      ZooStatus status;       ///< Status of Zoo

    protected:

      Population population;  ///< Zoo Organism population

    public:

      /// Default constructor
      Zoo();

      /// Custom constructor
      Zoo (
        const std::string& name_,
        ZooStatus status_ = OPEN
      );

      void open();
      void suspend();
      void resume();
      void close();

  };


  /// ZooKeeper class
  class ZooKeeper
  {

    private:

      std::string name;
      std::unique_ptr<Zoo> zoo;

    public:

      /// Default constructor
      ZooKeeper();

      /// Custom constructor
      ZooKeeper (
        const std::string& name_
      );  

      void assignZoo (
        std::unique_ptr<Zoo> zoo_
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
