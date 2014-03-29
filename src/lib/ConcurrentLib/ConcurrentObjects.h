////////////////////////////////////////
////////////////////////////////////////
//
//  Copyright (C) 2014 Korovasoft, Inc.
//
//  File:
//      \file ConcurrentObjects.h
//
//  Description:
//      \brief ConcurrentObjects Library header.
//
//  Author:
//      \author J. Caleb Wherry
//
////////////////////////////////////////
////////////////////////////////////////


// Include guards:
#ifndef CONCURRENT_OBJECTS_H
#define CONCURRENT_OBJECTS_H


// Forward declarations:
////


// Local includes:
////


// Compiler includes:
#include <atomic>
#include <cstdint>
#include <vector>
#include <thread>
#include <mutex>


/// ConcurrentObjects namespace
namespace ConcurrentObjects
{

  /// ConcurrentCounter data structure
  class ConcurrentCounter
  {

    private:

      uint32_t maxCount;
      std::atomic<uint32_t> currentCount;

    public:

      // Default constructor
      ConcurrentCounter();

      /// Custom constructor
      ConcurrentCounter(uint32_t _maxCount);

      /// Increment count
      void increment();

      /// Get count
      uint32_t getCount();

  };

  /// ConcurrentVector data structure
  template <typename T>
  class ConcurrentVector
  {

    private:

      std::vector<T> data;
      std::mutex dataMutex;

    public:

      // Default constructor
      ConcurrentVector();

      // Custom constructor
      ConcurrentVector(
        uint32_t size_
      );

      // Return size
      uint32_t size();

      // Access element
      T operator[](
        uint32_t index
      );

      // Push back element
      void push_back(
        T element
      );

      // Pop back element
      T pop_back();
  };


  //
  // Template implementations for ConcurrentVector
  //

  // Default constructor
  template <typename T>
  ConcurrentVector<T>::ConcurrentVector():
    data(std::vector<T>())
  {
  }

  // Custom Constructor:
  template <typename T>
  ConcurrentVector<T>::ConcurrentVector (
    uint32_t size_
  ): data(std::vector<T>(size_))
  {
  }

} // ConcurrentObjects namespace


#endif // CONCURRENT_OBJECTS_H
