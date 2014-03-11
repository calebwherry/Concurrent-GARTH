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


/// Local Includes:
////

/// Compiler Includes:
#include <ConcurrentUtil.h>
#include <Garth.h>
#include <thread>
#include <vector>
#include <iostream>

/// Namespaces:
using namespace std;
using namespace Garth;
namespace CU = ConcurrentUtil;

/// Function specs:
void helloWorld();


/// Main:
int main()
{

	//  Test GarthLib:
	GarthEngine* engine = new GarthEngine();


	// Get number of cores available:
	// TOD0: This should probably have a -1 since main runs in its own thread...
	const uint32_t NUM_THREADS = CU::getNumberCores();

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


// Hello World function:
void helloWorld()
{
	cout << "Thread " << this_thread::get_id() << " calling in!" << endl;
}
