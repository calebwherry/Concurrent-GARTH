///////////////////////////////////////
///////////////////////////////////////
//
//	File:
//		concurrent-garth-orig.cpp
//
//	Description:
//		GA to find platonic solids using Thomson problem
//
//	Author:
//		J. Caleb Wherry
//
//	Created:
//		12/14/2013
//
////////////////////////////////////////
////////////////////////////////////////


// Compiler Includes:
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>
#include <chrono>
#include <thread>


// Namespaces:
using namespace std;


// Plot Functions:
void createFig1Script(string, string);
void createFig2Script(string, string);


// Logic Functions:
double randu();
void initiate();
void select();
void cross();
void mutate();
bool converged();
void print();
void rank_pop();
double cost(const vector<double>&);
void sort(vector<double>&, vector<int>&);
void shuffle(vector<int>&);

void helloWorld()
{
}

// Global vars:
int32_t seed; // RNG seed
int32_t nc; // number of charges
int32_t nv; // number of variables
int32_t ng = 128; // size of gene pool
int32_t ni = 256; // initial size of gene pool
int32_t nr = ng/2; // number of parents or kids
int32_t ne = 1; // number of elite states
int32_t gmax = 1000; // max number of generations
double pm = 1.0/100; // mutation percentage
vector<vector<double>> c; // chromosomes
vector<double> f(ng); // cost function
vector<vector<double>> configMatrix; // configuration matrix for better plotting
vector<vector<double>> bestOrganismFitnesses; //best fitness at each population.
double tol = 1e-8; // Tolerance for convergence of solutions;
int32_t popCount = 0;
#define M_PI 3.14159265358979323846
uint32_t NUM_THREADS = 2;

// Main:
int main(int argc, char* argv[])
{

	//
	// Command Line Args:
	//
	
	int numArgs = argc;
	string problemPrefix = argv[0];


	//
	// Constants:
	//
	//////


	//
	// Problem Setup:
	//

	// Set initial seed from /dev/urandom:
  FILE* urandom = fopen("/dev/urandom", "r");
  size_t tmp = fread(&seed, sizeof(int32_t), 1, urandom);
  fclose(urandom);

  // Hard-coded seed to get consistent results and for reproducibility of results:
  seed = -484303784;


	// Fill best organism vector with iteration count:
	for (int32_t i = 0; i < gmax; ++i)
	{
		bestOrganismFitnesses.push_back({i});
	}


	// Number of vertices to optimize for each platonic solid:
	vector<uint32_t> vertices = {4, 6, 8, 12, 20};

	// Main loop over number of vertices:
	for (uint32_t i = 0; i<vertices.size(); ++i)
	{
		// Start time:
		auto start_time = chrono::high_resolution_clock::now();

		// Create Threads:
		vector<thread> threads;
		for (uint32_t i = 0; i < NUM_THREADS; i++)
	  {
			threads.push_back( thread(helloWorld) );
		}


		// Set which problem we are working on:
    nc = vertices[i];
		nv = 2*nc;
		c = {ng, vector<double>(nv)};

		// Initiate population:
		initiate();

		// GA loop:
    popCount = 0;
    bool contd = false;
    while (!contd && popCount<gmax)
		{
      ++popCount;
      select();
      cross();
      rank_pop();
      mutate();
			contd = converged();

			// Save best organisms fitness and pop count:
			bestOrganismFitnesses[popCount-1].push_back(f[0]);
    }

		// Join threads:
		for (auto& thread : threads)
		{
			thread.join();
		}

		// End time:
		auto end_time = chrono::high_resolution_clock::now();

		// Print config to screen:
    print();

		// Output timing:
		cout << "Running time - ";
		cout << chrono::duration_cast<chrono::seconds>(end_time - start_time).count() << ".";
		cout << chrono::duration_cast<chrono::microseconds>(end_time - start_time).count() << endl;

		//
		// Output
		//

		// Figure file object:
		/*
		string figDataFileName = problemPrefix + "_fig1_" + to_string(i+1) + ".dat";
		ofstream figDataFile;
		figDataFile.open(figDataFileName.c_str());
		cout << "\tCreated data file for figure 1_" << i+1 << ": " << figDataFileName << endl;

		// Print matrix to file:
		for (const auto& row : configMatrix)
		{
			for (const auto& col : row)
			{
				auto a_ij = col;
				figDataFile << a_ij << " ";
			}
			figDataFile << endl;
		}

		// Close open file handlers:
		figDataFile.close();
		*/

	}

	// Figure file object:
	/*
	string fig2DataFileName = problemPrefix + "_fig2.dat";
	ofstream fig2DataFile;
	fig2DataFile.open(fig2DataFileName.c_str());
	cout << "\tCreated data file for figure 2: " << fig2DataFileName << endl;

	// Print data to file:
	//int skip = 10;
	//int count = 0;
	for (const auto& row : bestOrganismFitnesses)
	{
		//count++;
		//if ((count-1+skip)%skip != 0) continue;

		for (const auto& col : row)
		{
			auto a_ij = col;
			fig2DataFile << a_ij << " ";
		}
		fig2DataFile << endl;
	}

	// Create figure scripts:
	createFig2Script(problemPrefix, fig2DataFileName);

	// Close open file handlers:
	fig2DataFile.close();
	*/

	return 0;
}

// Create xmgrace figure 2 batch script:
void createFig2Script(
	string problemPrefix,
	string dataFileName
	)
{

	// Figure 2 script and file object:
	string fig2ScriptName = problemPrefix + "_fig2.bfile";
	ofstream fig2Script;
	fig2Script.open(fig2ScriptName.c_str());
	cout << "\tCreated batch script for figure 2: " << fig2ScriptName << endl;

	// Add all needed options for creating figure 2 to script:
	fig2Script << "read nxy \"" << dataFileName << "\"" << endl
						 //<< "world 0, 0, 1100, 110" << endl
						 << "xaxis label \"Generation\"" << endl
						 << "xaxis tick major 100" << endl
						 << "xaxes scale logarithmic" << endl
						 << "yaxis label \"Fitness Score\"" << endl
						 << "yaxis tick major 10" << endl
						 << "yaxes scale logarithmic" << endl
             << "s0 legend \"N=4\"" << endl
             << "s0 color 1" << endl
             << "s0 symbol 1" << endl
						 << "s1 legend \"N=6\"" << endl
						 << "s1 color 2" << endl
						 << "s1 symbol 2" << endl
 					 	 << "s2 legend \"N=8\"" << endl
             << "s2 color 3" << endl
             << "s2 symbol 3" << endl
             << "s3 legend \"N=12\"" << endl
             << "s3 color 4" << endl
             << "s3 symbol 4" << endl
             << "s4 legend \"N=20\"" << endl
             << "s4 color 5" << endl
             << "s4 symbol 5" << endl
						 << "title \"Convergence of Best Organism\"" << endl
						 << "print to \"" << problemPrefix << "_fig2.eps\"" << endl
						 << "device \"EPS\" OP \"level2\"" << endl
						 << "autoscale" << endl
						 << "print" << endl;

	// Close file handler:
	fig2Script.close();

}


// Generate a uniform pseudorandom number in [0,1]
//  following x(i+1) = (a*x(i)+b) mod c with a=pow(7,5)
//  and c=pow(2,31)-1.
// Note: Modified from Tao Pang code.
double randu()
{
  // Some constants:
  const int32_t a = 16807,      // a = pow(7,5)
                b = 0,          // b = 0
                c = 2147483647, // c = pow(2,31)-1
                q = 127773,     // q = c/a
                r = 2836;       // r = c mod a

  const double cd = c;
  int32_t h = seed/q;
  int32_t l = seed%q;
  int32_t t = a*l-r*h;

  if (t > 0) seed = t;
  else seed = c+t;

  // Return random number:
  return seed/cd;
}


// Method to initialize the simulation by creating an
// zeroth generation of the gene population.
//	Note: Modified from Tao Pang.
void initiate()
{
	vector<vector<double>> d(ni, vector<double>(nv));
	vector<double> e(ni);
	vector<int> index(ni);

	for (int i=0; i<ni; ++i) 
	{
		for (int j=0; j<nv; ++j) d[i][j] = randu();
		e[i] = cost(d[i]);
		index[i] = i;
	}
	sort(e,index);

	for (int i=0; i<ng; ++i)
	{
		f[i] = e[i];
		for (int j=0; j<nv; ++j) c[i][j] = d[index[i]][j];
	}
}


// Method to run tournaments in selecting the parents.
//	Note: Modified from Tao Pang.
void select() 
{
	vector<int> index(ng);
	vector<vector<double>> d(ng, vector<double>(nv));
	vector<double> e(ng);

	for (int i=0; i<ng; ++i)
	{
		for (int l=0; l<nv; ++l) d[i][l] = c[i][l];
		e[i] = f[i];
		index[i] = i;
	}

	shuffle(index);
	int k = 0;
	for (int i=0; i<nr; ++i) 
	{
		if (e[index[k]] < e[index[k+1]])
		{
			for (int l=0; l<nv; ++l) c[i][l]=d[index[k]][l];
			f[i] = e[index[k]];
		}
		else 
		{
			for (int l=0; l<nv; ++l) c[i][l]=d[index[k+1]][l];
			f[i] = e[index[k+1]];
		}
		k += 2;
	}
}


// Method to perform single-point crossover operations.
//	Note: Modified from Tao Pang
void cross() 
{
	int k = 0;
	for (int i=nr; i<nr+nr/2; ++i) 
	{
		int nx = 1 + (int)(nv*randu());
		for (int l=0; l<nx; ++l)
		{
			c[i][l] = c[k][l];
			c[i+nr/2][l] = c[k+1][l];
		}
		for (int l=nx; l<nv; ++l)
		{
			c[i][l] = c[k+1][l];
			c[i+nr/2][l] = c[k][l];
		}
		k += 2;
	}
}


// Method to mutate a percentage of bits in the selected
// chromosomes except the best one.
//	Note: Modified from Tao Pang.
void mutate() 
{
	vector<double> r(nv);

	// Mutation in the elite configurations
	for (int i=0; i<ne; ++i) 
	{
		for (int l=0; l<nv; ++l) r[l] = c[i][l];

		int mb = (int)(nv*pm+1);
		for (int j=0; j<mb; ++j)
		{
			int ib = (int)(nv*randu());
			r[ib] = randu();
		}

		double e = cost(r);
		if (e<f[i])
		{
			for (int l=0; l<nv; ++l) c[i][l] = r[l];
			f[i] = e;
		}
	}

	// Mutation in other configurations 
	int mmax = (int)((ng-ne)*nv*pm+1);
	for (int i=0; i<mmax; ++i) 
	{
		int ig = (int)((ng-ne)*randu()+ne);
		int ib = (int)(nv*randu());
		c[ig][ib] = randu();
	}

	// rank_pop the chromosomes in the population
	rank_pop();
}


// Method to save the coordinates and to output the cost function
// of the best chromosome in the final generation.
//	Note: Modified from Tao Pang.
void print()
{

	vector<double> r(nv);
	vector<double> theta(nc);
	vector<double> phi(nc);
	vector<double> x(nc);
	vector<double> y(nc);
	vector<double> z(nc);

	//  double rescale = sqrt(nc*Math.E/8);
	double rescale = sqrt(nc/4);

	// Write out the coordinates of the best chromosome
	for (int i=0; i<nv; ++i) r[i] = c[0][i];

	// Matrix to hold config in different format:
	configMatrix = {3, vector<double>(nc)};

	// Print best config coords:
	cout << "\tN = " << nc << endl;
	cout << "\tConverged in " << popCount << " generations." << endl;
	cout << "\t\tOptimal Organism Configuration:" << endl;
	cout << "\t\tx, y, z" << endl;
	int k = 0;
	for (int i=0; i<nc; ++i)
	{
		theta[i] = M_PI*r[k];
		phi[i] = 2*M_PI*r[k+1];

		double ri = rescale*sin(theta[i]);

		x[i] = ri*cos(phi[i]);
		y[i] = ri*sin(phi[i]);
		z[i] = rescale*cos(theta[i]);

		cout << "\t\t\t" << x[i] << "  " << y[i] << "  " << z[i] << endl;
		configMatrix[0][i] = x[i];
		configMatrix[1][i] = y[i];
		configMatrix[2][i] = z[i];
		k += 2;
	}

	// Print out the energy of the best chromosome:
	cout << "\t\tOptimal Organism Fitness:" << endl;
	cout << "\t\t\t" << f[0] << endl;

	/*
	// Prints all fitness values for entire last population, not what we want...
	for (int i=0; i<ng; ++i)
	{
		cout << "\t\tOrganism " << i << ": " << f[i] << endl;
	}
	*/

}


// Method to rank_pop chromosomes in the population.
//	Note: Modified from Tao Pang.
void rank_pop() 
{
	vector<vector<double>> d(ng, vector<double>(nv));
	vector<double> e(ng);
	vector<int> index(ng);

	for (int i=0; i<ng; ++i) 
	{
		for (int j=0; j<nv; ++j) d[i][j] = c[i][j];
		e[i] = cost(d[i]);
		index[i] = i;
	}

	sort(e,index);
	for (int i=0; i<ng; ++i)
	{
		f[i] = e[i];
		for (int j=0; j<nv; ++j) c[i][j] = d[index[i]][j];
	}
}


// Method to evaluate the cost for a given variable array.
//	Note: Modified from Tao Pang.
double cost(const vector<double>& r) 
{
	double g = 0;
	vector<double> theta(nc);
	vector<double> phi(nc);

	int k = 0;
	for (int i=0; i<nc; ++i)
	{
		theta[i] = M_PI*r[k];
		phi[i] = 2*M_PI*r[k+1];
		k += 2;
	}

	for (int i=0; i<nc-1; ++i)
	{
		double ri = sin(theta[i]);
		double xi = ri*cos(phi[i]);
		double yi = ri*sin(phi[i]);
		double zi = cos(theta[i]);
		for (int j=i+1; j<nc; ++j)
		{
			double rj = sin(theta[j]);
			double dx = xi - rj*cos(phi[j]);
			double dy = yi - rj*sin(phi[j]);
			double dz = zi - cos(theta[j]);
			g += 1/sqrt(dx*dx+dy*dy+dz*dz);
		}
	}
	return g;
}


// Method to sort an array x[i] from the lowest to the
// highest with the original order stored in index[i].
//	Note: Modified from Tao Pang.
void sort(vector<double>& x, vector<int>& index)
{
	int m = x.size();
	for (int i = 0; i<m; ++i) 
	{
		for (int j = i+1; j<m; ++j) 
		{
			if (x[i] > x[j]) 
			{
				double xtmp = x[i];
				x[i] = x[j];
				x[j] = xtmp;
				int itmp = index[i];
				index[i] = index[j];
				index[j] = itmp;
			}
		}
	}
}


// Method to shuffle the index array.
//	Note: Modified from Tao Pang.
void shuffle(vector<int>& index)
{
	int k = index.size();
	for (int i = 0; i<k; ++i) 
	{
		int j = (int)(k*randu());
		if (j!=i) 
		{
			int itmp = index[i];
			index[i] = index[j];
			index[j] = itmp;
		}
	}
}

// Method to check the convergence.
//	Note: Modified from Tao Pang.
bool converged()
{

	// Check 2 most fit organism and see if their fitness is close:
	//if ( fabs(f[1] - f[0]) < tol )
	//{
	//	return true;
	//}

	return false;
}
