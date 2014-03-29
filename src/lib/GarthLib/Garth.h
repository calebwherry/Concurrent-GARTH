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

    private:

      std::string name;
      std::vector<double> genome;
      double fitness;

    public:

      /// Default constructor
      Organism();

      /// Custom constructor
      Organism (
        const std::string& name_,
        double fitness_ = 0.0
      );

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

    private:

      std::string name;       ///< Zoo name
      ZooStatus status;       ///< Status of Zoo
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

      void openZoo();
      void suspendZoo();
      void resumeZoo();
      void closeZoo();

  }; 


} // Garth namespace


#endif // GARTH_H
