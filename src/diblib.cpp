#include <diblib.h>

#include <iostream>
#include <fstream>

// ----------------------------------------------------------------------------
//  DIB CLASS METHODS
// ----------------------------------------------------------------------------

void DIB::loadFile(std::string filename)
{
	std::ifstream bitmapFile(filename, std::ios::in);

	if(!bitmapFile)
	{
		// remove the output below and throw exception!
		std::cout << "(!) This file cannot be opened.\n" << std::endl;
		return;
	}
}