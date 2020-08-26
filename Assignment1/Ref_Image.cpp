#include "Ref_Image.h"

Ref_Image::Ref_Image()
{
}


Ref_Image::~Ref_Image()
{
}

// Reads .txt file representing an image of R rows and C Columns stored in filename 
// and converts it to a 1D array of doubles of size R*C
// Memory allocation is performed inside readTXT
// Read .txt file with image of size (R rows x C columns), and convert to an array of doubles



double* Ref_Image::readText(const char *fileName, int sizeR, int sizeC)
{
	double* data = new double[sizeR*sizeC];
	int i = 0;
	ifstream myFile(fileName);
	if (myFile.is_open())
	{

		while (myFile.good())
		{
			if (i > sizeR*sizeC - 1) break;
			myFile >> *(data + i);
			//cout << *(data + i) << ' ';
			i++;
		}
		myFile.close();
	}

	else cout << "Unable to open file";
	//cout << i;

	cout << "Wally loaded" << endl;
	// Stores the vector in an object (sceneMatrix)
	wallyMatrix = matrixObj->convert(data, sizeR, sizeC);
	// Deletes matrixObj
	delete matrixObj;
	return data;
}

vector<vector<double_t>> Ref_Image::getVector()
{
	// Sends the vector to Base_Image
	return wallyMatrix;
}