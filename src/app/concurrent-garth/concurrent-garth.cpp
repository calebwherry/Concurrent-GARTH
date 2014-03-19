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
#include <ConcurrentObjects.h>
#include <Garth.h>
#include <thread>
#include <vector>
#include <iostream>

/// Namespaces:
using namespace std;
using namespace Garth;
namespace CU = ConcurrentUtil;
namespace CO = ConcurrentObjects;

/// Function specs:
void helloWorld();

/// Global vars/objs:
uint32_t MAX_COUNT = 100000000,
         NUM_THREADS;
CO::ConcurrentCounter counter(MAX_COUNT);


/// Main:
int main()
{

  // Test GarthLib:
  GarthEngine engine;
  engine.start();
  engine.stop();


  // Get number of cores available:
  // TOD0: This should probably have a -1 since main runs in its own thread...
  NUM_THREADS = CU::getNumberCores();

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

  // Output final counter value:
  cout << "Final counter value (should be " << MAX_COUNT << "): " << counter.getCount() << endl;

  // Exit status:
  return 0;

}


// Hello World function:
void helloWorld()
{

  cout << "Thread " << this_thread::get_id() << " calling in!" << endl;

  for (uint32_t i = 0; i < (MAX_COUNT/NUM_THREADS); ++i)
  {
    counter.increment();
  }

}
