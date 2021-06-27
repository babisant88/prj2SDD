/*
 * load_input.cpp
 *
 *  Created on: Jun 12, 2018
 *      Author: babis
 */

#include <iostream>
#include <fstream>
#include <cstring>

#define dbg 0

using namespace std;

int load_input( char * filename, double * X, int n )
{
	string line;
	ifstream myfile ( filename );

	int row_i, col_i;

	row_i = 0;

	if ( myfile.is_open() )
	{
		while( getline( myfile, line ) )
		{
			char * pch;
			pch = strtok( (char *)line.c_str(), " " );

			col_i = 0;

			while ( pch != NULL )
			{
				X[row_i*n+col_i] = atof( pch );
				col_i++;
				pch = strtok ( NULL, " " );
			}

			row_i++;
		}

		myfile.close();
	}
	else
		cout << "Unable to open file" << filename << endl;

#if dbg

	for( int t_row_i=0; t_row_i <n; t_row_i ++ )
	{
		for( int t_col_i=0; t_col_i <n; t_col_i ++ )
			cout << X[t_row_i*n+t_col_i] << " ";

		cout << endl;
	}

#endif

	return 0;
}
