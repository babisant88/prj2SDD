/*
 * prjDDrow.cpp
 *
 *  Created on: May 28, 2018
 *      Author: babis
 */

#include <cmath>

#include "../hpp/prjDDrow.hpp"

template <typename T> int sgn(T val)
{
    return (T(0) < val) - (val < T(0));
}

void prjDDrow( double *x, int row_i, int n )
{
	int nnz;
	double db, aux;
	bool s;

	double d = 0.0;
	for( int j=0; j<n; ++j )
		if( j != row_i )
			d += fabs( x[j] );

	d -= x[row_i];

	/* count the number of non-zero entries in
	 * x except for x[row_i] and add one */
	nnz = 1;

	for( int j=0; j<n; ++j )
		if ( j != row_i && x[j] != 0 )
			nnz++;

	db = d/nnz;
	s = true;

	while( s )
	{
		s = false;

		for( int j=0; j<n; ++j )
		{
			if ( x[j] != 0 && j != row_i )
			{
				aux = x[j] - sgn( x[j] ) * db;
				if( sgn( aux ) * sgn( x[j] ) < 0 )
				{
					d = d - fabs( x[j] );
					nnz -= 1;
					x[j] = 0;
					s = true;
				}
			}
		}

		db = d/nnz;
	}

	for( int j=0; j<n; ++j )
	{
		if( j != row_i )
		{
			if( x[j] > 0 )
				x[j] -= db;
			else if ( x[j] < 0 )
				x[j] += db;
		}
		else
			x[j] += db;
	}
}
