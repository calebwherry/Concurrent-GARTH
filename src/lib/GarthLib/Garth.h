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
////


// Local includes:
////


// Compiler includes:
#include <string>


// Namespaces:
////


/// Garth namespace
namespace Garth
{

  // Zoo Statuses:
  enum ZooStatus
  {
    UNKNOWN,
    OPEN,
    SUSPENDED,
    RESUMED,
    CLOSED
  };


  /// Zoo class
  class Zoo
  {
    private:
      ZooStatus status;

    public:

      /// Default constructor
      Zoo ();

      /// Custom constructor
      Zoo (
        ZooStatus _status
      );

      void open();
      void suspend();
      void resume();
      void close();
  };


  /// Zoo Keeper class
  class ZooKeeper
  {
    private:
      std::string name;

    public:

      /// Default constructor
      ZooKeeper();

      /// Custom constructor
      ZooKeeper (
        const std::string& name
      );

      void openZoo();
      void suspendZoo();
      void resumeZoo();
      void closeZoo();
  };

} // Garth namespace


#endif // GARTH_H
