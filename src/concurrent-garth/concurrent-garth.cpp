////////////////////////////////////////
////////////////////////////////////////
//
//  Copyright (C) 2014 Korovasoft, Inc.
//
//  File:
//      \file concurrent-garth.cpp
//
//  Description:
//      \brief Concurrent-GARTH application
//
//  Author:
//      \author J. Caleb Wherry
//
////////////////////////////////////////
////////////////////////////////////////


/// Local includes:
////

/// Compiler Includes:
#include <Garth.h>
#include <thread>
#include <vector>
#include <iostream>

/// Namespaces:
using namespace std;
using namespace Garth;

/// Function specs:
uint32_t getNumCores();
void helloWorld();


/// Main:
int main()
{

	//  Test GarthLib:
	GarthEngine* engine = new GarthEngine();


	// Get number of cores available:
	// TOD0: This should probably have a -1 since main runs in its own thread...
	const uint32_t NUM_THREADS = getNumCores();

	// How many threads can this system handle?
	cout << endl << "Cores available: " << NUM_THREADS << endl << endl;
	
	// Vector of threads:
	vector<thread> threads;

	// Create threads:
	for (uint32_t i = 0; i < NUM_THREADS; i++)
	{
		threads.push_back( thread(helloWorld) );
	}

	// Say something from main thread:
	cout << "Main thread " << this_thread::get_id() << " calling in!" << endl;

	// Join threads with main thread:
	for(auto& thread : threads)
	{
		thread.join();
	}

	// Exit status:
	return 0;

}



// Get number of cores function:
uint32_t getNumCores()
{

	// Initial value from thread library:
	uint32_t numThreads = thread::hardware_concurrency();

	// Above function could return 0, so we hardcore a value of 4 if that happens:
	return (numThreads != 0) ? numThreads : 4;
}


// Hello World function:
void helloWorld()
{
	cout << "Thread " << this_thread::get_id() << " calling in!" << endl;
}
