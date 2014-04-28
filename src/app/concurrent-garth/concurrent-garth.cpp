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

// Derived class:
class MyOrganism : public Organism
{

  public:

    // Constructor
    MyOrganism() {}

    // Destructor
    ~MyOrganism() {}

    // Mutate function:
    void mutate()
    {
      cout << "Mutating..." << endl;
    }

};


// Main:
int main(int argc, char* argv[])
{

  // Genetic Algorithm Constraints:
  uint32_t generationCount = 0;


  // Create shared Zoo & ZooKeeper for simulation:
  shared_ptr<Zoo> zoo( make_shared<Zoo>("Galapagos Zoo") );

  // Set initial conditions for Zoo:
  zoo->setMaxGenerations(10000);
  zoo->setNumberHabitats(1);  // Eventually will be MPI influenced...
  zoo->setNumberTrainers( CU::getNumberCores() );


  // Create new ZooKepper:
  shared_ptr<ZooKeeper> zooKeeper( make_shared<ZooKeeper>("Darwin", zoo) );

  // Set intial conditions for zooKeeper:
  zooKeeper->initializePopulation();

  // Open the zoo (start the simulation):
  zooKeeper->openZoo();


  // Create simulation loop:
  while ( (generationCount <= zoo->getMaxGenerations()) && 
          !zooKeeper->populationConverged()
        )
  {

    cout << "Generation: " << generationCount << endl;

    // Increase generation number:
    generationCount++;

  }


  // Close the zoo (finish the simulation):
  zooKeeper->closeZoo();

  
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
