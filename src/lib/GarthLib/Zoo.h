////////////////////////////////////////
////////////////////////////////////////
//
//  Copyright (C) 2014 Korovasoft, Inc.
//
//  File:
//      \file Zoo.h
//
//  Description:
//      \brief Garth Library: Zoo header.
//
//  Author:
//      \author J. Caleb Wherry
//
////////////////////////////////////////
////////////////////////////////////////


// Include guards:
#ifndef GARTH_ZOO_H
#define GARTH_ZOO_H


// Forward declarations:
//


// Local includes:
//


// Compiler includes:
#include <string>
#include <memory>


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


} // Garth namespace


#endif // GARTH_ZOO_H
