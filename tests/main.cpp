#include <windows.h>

#include <diblib.h>
#include <iostream>

int main()
{
	DIB test;
	test.loadFile("tests/1bpp.bmp", true);
	test.printDump();
	test.release();

	test.loadFile("tests/4bpp.bmp", true);
	test.printDump();
	test.release();

	test.loadFile("tests/8bpp.bmp", true);
	test.printDump();
	test.release();

	test.loadFile("tests/24bpp.bmp", true);
	test.printDump();
	test.release();
	return 0;
}