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
//#include <GarthEngine.h>
#include <thread>
#include <vector>
#include <iostream>

/// Namespaces:
using namespace std;

/// Function specs:
void helloWorld();

/// Global variables:
constexpr uint32_t NUM_THREADS = 10;


/// Main:
int main()
{
	
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

	return 0;
}


// Hello World function:
void helloWorld()
{
	cout << "Thread " << this_thread::get_id() << " calling in!" << endl;
}
