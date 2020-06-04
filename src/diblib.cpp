#include <diblib.h>

#include <iostream>
#include <iomanip>
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

unsigned long DIBLIB::DWORD::get() const
{
	return (((0 | byte1) << 8 | byte2) << 8 | byte3) << 8 | byte4;
}

void DIBLIB::DWORD::set(unsigned long dword)
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
	std::cout
		<< "================================================================================"
		<< "\n B I T M A P   F I L E   H E A D E R   -   " << sizeof(DIBLIB::BITMAPFILEHEADER) << " bytes"
		<< "\n================================================================================"
		<< "\n     bfType: "
			<< std::setw(4) << bfType.getByte1()
			<< std::setw(4) << bfType.getByte2()
			<< std::setw(4) << "-"
			<< std::setw(4) << "-" << " | "
			<< bfType.get()
		<< "\n     bfSize: "
			<< std::setw(4) << static_cast<int>(bfSize.getByte1())
			<< std::setw(4) << static_cast<int>(bfSize.getByte2())
			<< std::setw(4) << static_cast<int>(bfSize.getByte3())
			<< std::setw(4) << static_cast<int>(bfSize.getByte4()) << " | "
			<< bfSize.get()
		<< "\nbfReserved1: "
			<< std::setw(4) << static_cast<int>(bfReserved1.getByte1())
			<< std::setw(4) << static_cast<int>(bfReserved1.getByte2())
			<< std::setw(4) << "-"
			<< std::setw(4) << "-" << " | "
			<< bfReserved1.get()
		<< "\nbfReserved2: "
			<< std::setw(4) << static_cast<int>(bfReserved2.getByte1())
			<< std::setw(4) << static_cast<int>(bfReserved2.getByte2())
			<< std::setw(4) << "-"
			<< std::setw(4) << "-" << " | "
			<< bfReserved2.get()
		<< "\n  bfOffBits: "
			<< std::setw(4) << static_cast<int>(bfOffBits.getByte1())
			<< std::setw(4) << static_cast<int>(bfOffBits.getByte2())
			<< std::setw(4) << static_cast<int>(bfOffBits.getByte3())
			<< std::setw(4) << static_cast<int>(bfOffBits.getByte4()) << " | "
			<< bfOffBits.get()
		<< "\n================================================================================" << std::endl;
}

void DIBLIB::BITMAPFILEHEADER::swap()
{
	bfSize.swap();
	bfReserved1.swap();
	bfReserved2.swap();
	bfOffBits.swap();
}

// ----------------------------------------------------------------------------
//  BITMAPINFOHEADER CLASS METHODS
// ----------------------------------------------------------------------------
void DIBLIB::BITMAPINFOHEADER::print()
{
	std::cout
		<< "================================================================================"
		<< "\n B I T M A P   I N F O   H E A D E R   -   " << sizeof(DIBLIB::BITMAPINFOHEADER) << " bytes"
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

	// reading BITMAPFILEHEADER
	bitmapFile.read(reinterpret_cast<char *>(&bmfHeader), sizeof(DIBLIB::BITMAPFILEHEADER));
	bmfHeader.swap();
	bmfHeader.print();
}

