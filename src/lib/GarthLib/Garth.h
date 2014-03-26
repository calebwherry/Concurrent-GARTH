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


// Namespaces:
//


/// Garth namespace
namespace Garth
{


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

      std::string name;   ///< Zoo name
      ZooStatus status;   ///< Status of Zoo

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



  /// Organism class
  class Organism
  {
    private:

      std::string name;
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


} // Garth namespace


#endif // GARTH_H
