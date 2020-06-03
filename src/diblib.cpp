#include <diblib.h>

#include <iostream>
#include <fstream>

// ----------------------------------------------------------------------------
//  WORD CLASS METHODS
// ----------------------------------------------------------------------------
DIBLIB::WORD::WORD() : byte1(0), byte2(0) {}

unsigned short DIBLIB::WORD::get() const
{
	return (0 | byte1) << 8 | byte2;
}

void DIBLIB::WORD::set(unsigned short word)
{
	byte1 = (word >> 8);
	byte2 = (word & 0xF0);
}

void DIBLIB::WORD::swap()
{
	unsigned char temp = byte2;
	byte2 = byte1;
	byte1 = temp;
}

// ----------------------------------------------------------------------------
//  DWORD CLASS METHODS
// ----------------------------------------------------------------------------
DIBLIB::DWORD::DWORD() : byte1(0), byte2(0), byte3(0), byte4(0) {}

unsigned short DIBLIB::DWORD::get() const
{
	return (((0 | byte1) << 8 | byte2) << 8 | byte3) << 8 | byte4;
}

void DIBLIB::DWORD::set(unsigned short dword)
{
}

void DIBLIB::DWORD::swap()
{
	unsigned char temp = byte1;
	byte1 = byte4;
	byte4 = temp;
	temp = byte2;
	byte2 = byte3;
	byte3 = temp;
}

// ----------------------------------------------------------------------------
//  DIB CLASS METHODS
// ----------------------------------------------------------------------------

void DIB::loadFile(std::string filename)
{
	std::ifstream bitmapFile(filename, std::ios::in | std::ios::binary);

	if(!bitmapFile)
	{
		// remove the output below and throw exception!
		std::cout << "(!) This file (" << filename << ") cannot be opened.\n" << std::endl;
		return;
	}

	std::cout << "@debug | sizeof(BITMAPINFOHEADER): " << sizeof(DIBLIB::BITMAPINFOHEADER) << std::endl;

	// reading BITMAPINFOHEADER
	bitmapFile.read(reinterpret_cast<char *>(&bmiHeader), sizeof(DIBLIB::BITMAPINFOHEADER));
}