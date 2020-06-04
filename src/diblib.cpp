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
}

void DIBLIB::WORD::swap()
{
	unsigned char temp = byte2;
	byte2 = byte1;
	byte1 = temp;
}

char DIBLIB::WORD::getByte1()
{
	return byte1;
}

char DIBLIB::WORD::getByte2()
{
	return byte2;
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

char DIBLIB::DWORD::getByte1()
{
	return byte1;
}

char DIBLIB::DWORD::getByte2()
{
	return byte2;
}

char DIBLIB::DWORD::getByte3()
{
	return byte3;
}

char DIBLIB::DWORD::getByte4()
{
	return byte4;
}

// ----------------------------------------------------------------------------
//  BITMAPFILEHEADER CLASS METHODS
// ----------------------------------------------------------------------------
void DIBLIB::BITMAPFILEHEADER::print()
{
	bfSize.swap();

	std::cout
		<< "================================================================================"
		<< "\n B I T M A P   F I L E   H E A D E R"
		<< "\n================================================================================"
		<< "\nbfType: "      << bfType.getByte1() << " " << bfType.getByte2()
		<< "\nbfSize: "      << bfSize.get()
		<< "\nbfReserved1: " << bfReserved1.get()
		<< "\nbfReserved2: " << bfReserved2.get()
		<< "\nbfOffBits: "   << bfOffBits.get()
		<< "\n================================================================================" << std::endl;
}

void DIBLIB::BITMAPFILEHEADER::swap()
{
	bfSize.swap();
	bfOffBits.swap();
}

// ----------------------------------------------------------------------------
//  BITMAPINFOHEADER CLASS METHODS
// ----------------------------------------------------------------------------
void DIBLIB::BITMAPINFOHEADER::print()
{
	std::cout
		<< "================================================================================"
		<< "\n B I T M A P   I N F O   H E A D E R\n"
		<< "\n================================================================================"
		<< "\nbiSize: "          << biSize.get()
		<< "\nbiWidth: "         << biWidth.get()
		<< "\nbiHeight: "        << biHeight.get()
		<< "\nbiPlanes: "        << biPlanes.get()
		<< "\nbiBitCount: "      << biBitCount.get()
		<< "\nbiCompression: "   << biCompression.get()
		<< "\nbiSizeImage: "     << biSizeImage.get()
		<< "\nbiXPelsPerMeter: " << biXPelsPerMeter.get()
		<< "\nbiYPelsPerMeter: " << biYPelsPerMeter.get()
		<< "\nbiClrUsed: "       << biClrUsed.get()
		<< "\nbiClrImportant: "  << biClrImportant.get()
		<< "\n================================================================================" << std::endl;
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

	std::cout << "@debug | sizeof(BITMAPFILEHEADER): " << sizeof(DIBLIB::BITMAPFILEHEADER) << std::endl;

	// reading BITMAPFILEHEADER
	bitmapFile.read(reinterpret_cast<char *>(&bmfHeader), sizeof(DIBLIB::BITMAPFILEHEADER));
	bmfHeader.print();
}

