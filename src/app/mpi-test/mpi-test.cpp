////////////////////////////////////////
////////////////////////////////////////
//
//  Copyright (C) 2014 Korovasoft, Inc.
//
//  File:
//      \file mpi-test.cpp
//
//  Description:
//      \brief MPI test application
//
//  Author:
//      \author J. Caleb Wherry
//
////////////////////////////////////////
////////////////////////////////////////


// Local Includes:
////

// Compiler Includes:
#include <iostream>
#include <mpi.h>

// Namespaces:
using namespace std;

// Function specs:
void helloWorld (int, int);

// Main:
int main(int argc, char* argv[])
{

  //
  // Lets try some MPI stuff:
  //
  int rank, size;
 
  MPI_Init (&argc, &argv);
  MPI_Comm_rank (MPI_COMM_WORLD, &rank);
  MPI_Comm_size (MPI_COMM_WORLD, &size);

  // Function to call on each CPU:
  helloWorld(rank, size);

  MPI_Finalize();

  // Exit status:
  return 0;

}


// Hello World function:
void helloWorld(int rank, int size)
{

  cout << "CPU " << rank << "/" << size << " calling in!" << endl;

}
