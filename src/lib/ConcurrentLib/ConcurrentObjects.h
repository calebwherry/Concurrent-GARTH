////////////////////////////////////////
////////////////////////////////////////
//
//	Copyright (C) 2014 Korovasoft, Inc.
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

} // ConcurrentObjects namespace


#endif // CONCURRENT_OBJECTS_H
