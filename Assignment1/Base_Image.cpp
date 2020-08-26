#include "Base_Image.h"

Base_Image::Base_Image()
{
}


Base_Image::~Base_Image()
{
}


int Base_Image::main()
{
	// Creates an obj for my Large_Image
	Large_Image* ClutteredScene = new Large_Image();
	// Creates an obj for my Ref_Image
	Ref_Image* Wally = new Ref_Image();
	// Reads the cluttered scene image and stores it in a 1D array
	ClutteredScene->readText("Cluttered_scene.txt", 768, 1024);
	// Reads the wally image and stores it in a 1D array
	Wally->readText("Wally_grey.txt", 49, 36);
	// Returns the cluttered scene vector
	ClutteredScene->getVector();
	// Returns the wally vector
	Wally->getVector();
	// Runs the findWally function with the scene vector and the wally vector
	findWally(ClutteredScene->sceneMatrix, Wally->wallyMatrix);
	// Deletes Clutteredscene and wally objects
	delete ClutteredScene;
	delete Wally;
	return 0;
}

void Base_Image::findWally(vector<vector<double_t>> sceneVector, vector<vector<double_t>> wallyVector)
{
	// Declare variables, a for wally's y axis, b for wally's x axis, counter is used for storing potential new matches
	// bestMatch is used for storing the most likely match found so far
	// location I and location J are used to store the location of the match
	int a = 0, b = 0;
	int counter = 0;
	int bestMatch = 0;
	int locationI = 0;
	int locationJ = 0;
	
	// 1D array for storing the location and image for writepgm to read
	double* wallyLocation = new double[768 * 1024];

	for (int i = 0; i < (768 - 49); i++)
	{
		for (int j = 0; j < (1024 - 36); j++) 
		{
			for (int a = 0; a < 49; a++)
			{
				for (int b = 0; b < 36; b++)
				{
					// If the pixel is white, ignore it
					if (wallyVector[a][b] == 255)
					{
						break;
					}
					// If the pixel is within 25 of the right colour, run
					if (sceneVector[i + a][j + b] >= wallyVector[a][b] - 25 && sceneVector[i + a][j + b] <= wallyVector[a][b] + 25)
					{
						// Counter goes up to check how likely the match is
						counter++;
						// If the current match is the new most likely match, replace the most likely match and store location, tell the user that a new best match is found
						if (counter > bestMatch)
						{
							bestMatch = counter;
							locationI = i;
							locationJ = j;
							std::cout << "New best match = " << bestMatch << " Is at location " << locationI << " " << locationJ << endl;

						}
						// If the current match is equal in likelihood, let the user know
						if (counter == bestMatch)
						{
							std::cout << "Equal best match found at : I = " << i << " J = " << j << endl;
						}
					}
				}
			}
			// After the wally image is finished, reset the counter
			counter = 0;
		}
	}

	// Edits the pixels around wally to a black colour to put a box around him
	for (int a = 0; a < 49; a++)
	{
		for (int b = 0; b < 36; b++)
		{
			if (a <= 3 || a >= 45)
			{
				sceneVector[locationI + a][locationJ + b] = 0;
			}
			if (b <= 3 || b >= 32)
			{
				sceneVector[locationI + a][locationJ + b] = 0;
			}
		}
	}
	// Store the new scene array (with wally boxed in)
	for (int i = 0; i < 768; i++)
	{
		for (int j = 0; j < 1024; j++)
		{
			wallyLocation[i * 1024 + j] = sceneVector[i][j];
		}
	}
	// Write the image with wally found
	writePgm("foundWally.pgm", wallyLocation, 768, 1024, 255);
}




// Converts a 1D array of doubles of size R*C to .pgm image of R rows and C Columns 
// and stores .pgm in filename
// Use Q = 255 for greyscale images and 1 for binary images.
void Base_Image::writePgm(const char *filename, double *data, int sizeR, int sizeC, int Q)
{

	int i;
	unsigned char *image;
	ofstream myFile;

	image = (unsigned char *) new unsigned char[sizeR*sizeC];

	// convert the integer values to unsigned char

	for (i = 0; i < sizeR*sizeC; i++)
		image[i] = (unsigned char)data[i];

	myFile.open(filename, ios::out | ios::binary | ios::trunc);

	if (!myFile) {
		std::cout << "Can't open file: " << filename << endl;
		exit(1);
	}

	myFile << "P5" << endl;
	myFile << sizeC << " " << sizeR << endl;
	myFile << Q << endl;

	myFile.write(reinterpret_cast<char *>(image), (sizeR*sizeC) * sizeof(unsigned char));

	if (myFile.fail()) {
		std::cout << "Can't write image " << filename << endl;
		exit(0);
	}

	myFile.close();

	delete[] image;

}