#ifndef DIBLIB_INCLUDE_H
#define DIBLIB_INCLUDE_H

#include <string>

namespace DIBLIB
{
	class WORD
	{
	public:
		WORD();

		unsigned short get() const;
		void set(unsigned short word);
		void swap();
	private:
		unsigned char byte1;
		unsigned char byte2;
	};

	class DWORD
	{
	public:
		DWORD();

		unsigned short get() const;
		void set(unsigned short dword);
		void swap();
	private:
		unsigned char byte1;
		unsigned char byte2;
		unsigned char byte3;
		unsigned char byte4;
	};

	class RGBQUAD
	{
	};

	class BITMAPINFOHEADER
	{
	public:

	private:
		DWORD biSize; // 32 bits unsigned integer typedef unsigned long
		DWORD biWidth; // 32 bits signed integer typedef long
		DWORD biHeight; // 32 bits signed integer typedef long
		WORD biPlanes; // 16 bits unsigned integer typedef unsigned short
		WORD biBitCount; // 16 bits unsigned integer typedef unsigned short
		DWORD biCompression; // 32 bits unsigned integer typedef unsigned long
		DWORD biSizeIamge; // 32 bits unsigned integer typedef unsigned long
		DWORD biXPelsPerMeter; // 32 bits signed integer typedef long
		DWORD biYPelsPerMeter; // 32 bits signed integer typedef long
		DWORD biClrUsed; // 32 bits unsigned integer typedef unsigned long
		DWORD biClrImportant; // 32 bits unsigned integer typedef unsigned long
	};

	class BITMAPINFO
	{
	private:
		BITMAPINFOHEADER bmiHeader;
		RGBQUAD * bmiColors;
	};
}

class DIB
{
public:
	void loadFile(std::string filename);

private:
	DIBLIB::BITMAPINFOHEADER bmiHeader;
};

#endif