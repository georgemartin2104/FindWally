#ifndef Base_Image_h
#define Base_Image_h

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>


#include "Ref_Image.h"
#include "Large_Image.h"

using namespace std;

class Base_Image
{
public:
	Base_Image();
	~Base_Image();

	int main();
	void writePgm(const char *filename, double *data, int sizeR, int sizeC, int Q);
	void findWally(vector<vector<double_t>> sceneVector, vector<vector<double_t>> wallyVector);

};

#endif