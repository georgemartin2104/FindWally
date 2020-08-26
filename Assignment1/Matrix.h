#ifndef Matrix_h
#define Matrix_h


#include <vector>

using namespace std;

class Matrix
{
public:
	Matrix();
	~Matrix();

	
	vector<vector<double_t>> convert(double* data, int rows, int columns);

private:


};

#endif