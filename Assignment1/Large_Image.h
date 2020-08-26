#ifndef Large_Image_h
#define Large_Image_h

#include "Base_Image.h"
#include "Matrix.h"

using namespace std;

class Large_Image
{
public:
	Large_Image();
	~Large_Image();

	double* readText(const char *fileName, int sizeR, int sizeC);

	Matrix* matrixObj = new Matrix;
	vector<vector<double_t>> sceneMatrix;

	vector<vector<double_t>> getVector();

};
#endif

