/*
 * main.cpp
 *
 *  Created on: May 27, 2018
 *      Author: babis
 */

#include <iostream>

#include "../hpp/prjSDD.hpp"
#include "../hpp/load_input.hpp"

using namespace std;

#define dbg 0

int main( int argc, char *argv[] )
{
	int n = atoi( argv[2] );

	double * A = new double[n*n];

	/* load input matrix */
	load_input( argv[1], A, n ); // A

	double *X = prjSDD( A, n, 1e-6 );
	
	for( int i=0; i<n; ++i )
	{
		for( int j=0; j<n; ++j )
			cout << X[i*n+j] << " ";

		cout << endl;
	}
}
