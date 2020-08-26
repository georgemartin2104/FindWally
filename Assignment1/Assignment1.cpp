#include "Assignment1.h"

// Runs BaseImage as a seperate main function
int main()
{
	Base_Image* BaseImage = new Base_Image;
	BaseImage->main();
	delete BaseImage;
}

