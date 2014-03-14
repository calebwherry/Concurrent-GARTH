////////////////////////////////////////
////////////////////////////////////////
//
//	Copyright (C) 2014 Korovasoft, Inc.
//
//  File:
//      \file ConcurrentObjects.cpp
//
//  Description:
//      \brief ConcurrentObjects Library implementation.
//
//  Author:
//      \author J. Caleb Wherry
//
////////////////////////////////////////
////////////////////////////////////////


// Forward declarations:
////


// Local includes:
#include "ConcurrentObjects.h"


// Compiler includes:
#include <stdexcept>
#include <thread>


/// ConcurrentObjects namespace
namespace ConcurrentObjects
{

	ConcurrentCounter::ConcurrentCounter()
	{
		currentCount = 0;
	}

	ConcurrentCounter::ConcurrentCounter(uint32_t _maxCount):
		maxCount(_maxCount),
		currentCount(0)
	{
		// Do nothing.
	}

	void ConcurrentCounter::increment()
	{
		
		// Check to make sure count doesn't go above maxCount. If so, throw error:
		if ( (currentCount+1) <= maxCount)
		{
			currentCount++;
		}
		else
		{
			throw std::out_of_range("Can't count that high!");
		}

	}

	uint32_t ConcurrentCounter::getCount()
	{
		return currentCount;
	}

} // ConcurrentObjects namespace
