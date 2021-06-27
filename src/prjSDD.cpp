/*
 * prjSDD.cpp
 *
 *  Created on: May 27, 2018
 *      Author: babis
 */

#include <cmath>

#include "../hpp/prjSDD.hpp"
#include "../hpp/prjS.hpp"
#include "../hpp/prjDD.hpp"

double fro( double*, double*, int);

/* Dykstra's algorithm */

double *prjSDD( double *A, int n, double itol )
{

	double *I, *X, *z, *Xprv;

	X = new double[n*n];

	Xprv = new double[n*n];

	z = new double[n*n];

	/* initialize I with zeros */
	I = new double[n*n]();

	/* initialize X & Xprv with A */
	for ( int xi=0; xi<n*n; xi++ )
		X[xi] = Xprv[xi] = A[xi];

	while( true )
	{
		/* Step 1: Project onto the space of symmetric matrices */
		prjS( X, n );

		/* Step 2: Project onto the space of diagonally dominant matrices */
		for ( int zi=0; zi<n*n; zi++ )
			z[zi] = X[zi] = X[zi] - I[zi];

		prjDD( X, n );

		/* Convergence Test */
		if ( fro(X,Xprv,n) <= itol )
			break;

		/* Xprv = X */
		for ( int xi=0; xi<n*n; xi++ )
			Xprv[xi] = X[xi];

		/* Step 3: Set Dykstra's increment */
		for ( int i=0; i<n*n; i++ )
			I[i] = X[i] - z[i];
	}

	/* deallocate memory that is unnecessary */
	delete[] Xprv;
	delete[] z;
	delete[] I;

	return X;
}



double fro( double *X, double *Xprv, int n )
{
	double sum = 0;

	for( int xi=0; xi<n*n; ++xi )
	{
		double diff = X[xi] - Xprv[xi];
		sum += diff * diff;
	}

	return (sqrt(sum));
}
