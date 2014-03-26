////////////////////////////////////////
////////////////////////////////////////
//
//  Copyright (C) 2014 Korovasoft, Inc.
//
//  File:
//      \file Organism.h
//
//  Description:
//      \brief Garth Library: Organism header.
//
//  Author:
//      \author J. Caleb Wherry
//
////////////////////////////////////////
////////////////////////////////////////


// Include guards:
#ifndef GARTH_ORGANISM_H
#define GARTH_ORGANISM_H


// Forward declarations:
//


// Local includes:
//


// Compiler includes:
#include <string>


// Namespaces:
//


/// Garth namespace
namespace Garth
{

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


#endif // GARTH_ORGANISM_H
