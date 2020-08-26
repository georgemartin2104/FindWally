#include "Matrix.h"


Matrix::Matrix()
{

}


Matrix::~Matrix()
{

}
// Converts a 1D array into a 2D vector - takes the data, number of rows, number of columns
vector<vector<double_t>> Matrix::convert(double * data, int rows, int columns)
{
	vector< vector<double_t> > matrix2D;
	vector<double_t> calcRows;
	int k = 0;

	for (size_t i = 0; i < rows; i++)
	{
		calcRows.clear();
		for (size_t j = 0; j < columns; j++)
		{
			// Creates a 1D array of data for each column
			calcRows.push_back(data[k]);
			k++;
		}
		// Sets the 1D array to a new row in the 2D vector
		matrix2D.push_back(calcRows);
	}

	return matrix2D;
}


