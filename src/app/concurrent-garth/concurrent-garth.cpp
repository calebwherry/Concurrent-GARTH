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


// Local Includes:
////

// Compiler Includes:
#include <ConcurrentUtil.h>
#include <ConcurrentObjects.h>
#include <Garth.h>
#include <thread>
#include <vector>
#include <iostream>
#include <memory>
//#include <mpi.h>

// Namespaces:
using namespace std;
using namespace Garth;
namespace CU = ConcurrentUtil;
namespace CO = ConcurrentObjects;

// Function specs:
void helloWorld();

// Global vars/objs:
uint32_t MAX_COUNT = 100000000,
         NUM_THREADS;
CO::ConcurrentCounter counter(MAX_COUNT);


// Main:
int main(int argc, char* argv[])
{

  // Create unique Zoo & ZooKeeper for entire simulation:
  unique_ptr<Zoo> zoo(new Zoo("Galapagos Zoo"));
  unique_ptr<ZooKeeper> zooKeeper(new ZooKeeper("Darwin"));

  // Assign Zoo to ZooKeeper:
  zooKeeper->assignZoo(move(zoo));

  // Go through the motions of a typical Zoo day:
  zooKeeper->openZoo();
  zooKeeper->suspendZoo();
  zooKeeper->resumeZoo();
  zooKeeper->closeZoo();


  //
  // Lets try some MPI stuff:
  //
  /*
  int rank, size;
 
  MPI_Init (&argc, &argv);
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);
  MPI_Comm_size (MPI_COMM_WORLD, &size);
  printf( "Hello world from process %d of %d\n", rank, size );
  MPI_Finalize();
  */


  //
  // Lets try some Threading stuff:
  //

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
