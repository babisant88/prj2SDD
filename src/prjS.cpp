/*
 * prjS.cpp
 *
 *  Created on: May 27, 2018
 *      Author: babis
 */

#include "../hpp/prjS.hpp"

void prjS( double *X, int n )
{
	for ( int row_i=0; row_i<n; row_i++ )
		for( int col_i=row_i+1; col_i<n; col_i++ )
			X[row_i*n+col_i] = X[col_i*n+row_i] = (X[row_i*n+col_i] + X[col_i*n+row_i])/2;
}

