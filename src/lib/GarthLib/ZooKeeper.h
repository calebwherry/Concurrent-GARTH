////////////////////////////////////////
////////////////////////////////////////
//
//  Copyright (C) 2014 Korovasoft, Inc.
//
//  File:
//      \file ZooKeeper.h
//
//  Description:
//      \brief Garth Library: ZooKeeper header.
//
//  Author:
//      \author J. Caleb Wherry
//
////////////////////////////////////////
////////////////////////////////////////


// Include guards:
#ifndef GARTH_ZOOKEEPER_H
#define GARTH_ZOOKEEPER_H


// Forward declarations:
//


// Local includes:
#include "Zoo.h"


// Compiler includes:
#include <string>
#include <memory>


// Namespaces:
//


/// Garth namespace
namespace Garth
{

  /// Zoo Keeper class
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


#endif // GARTH_ZOOKEEPER_H
