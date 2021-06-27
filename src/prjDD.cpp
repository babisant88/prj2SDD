/*
 * prjDD.cpp
 *
 *  Created on: May 28, 2018
 *      Author: babis
 */

#include "../hpp/prjDD.hpp"
#include "../hpp/prjDDrow.hpp"

#include <cmath>
#include <iostream>
#include <omp.h>

using namespace std;

void prjDD( double *X, int n )
{
	#pragma omp parallel for schedule(dynamic)
	for ( int row_i=0; row_i<n; row_i++ )
	{
		double *x, s;

		/* x points to the row_i-<th> row of matrix X */
		x = X + row_i*n;

		s = 0;
		for( int j=0; j<n; ++j )
			if( j != row_i )
				s += fabs(x[j]);

		if( x[row_i] >= 0 && x[row_i] < s )
			prjDDrow( x, row_i, n );
		else if ( x[row_i] < 0 )
		{
			cout << "X is a non-SPD matrix" << endl;
			exit(-1);
		}
	}
}
