#ifndef Ref_Image_h
#define Ref_Image_h

#include "Base_Image.h"
#include "Matrix.h"

using namespace std;

class Ref_Image
{
public:
	Ref_Image();
	~Ref_Image();

	double* readText(const char *fileName, int sizeR, int sizeC);

	Matrix* matrixObj = new Matrix;
	vector<vector<double_t>> wallyMatrix;

	vector<vector<double_t>> getVector();
};

#endif
