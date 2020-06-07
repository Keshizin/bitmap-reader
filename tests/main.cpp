#include <diblib.h>
#include <iostream>

int main()
{
	DIB test;
	test.loadFile("tests/1bpp.bmp");
	test.printDump();
	test.release();

	test.loadFile("tests/4bpp.bmp");
	test.printDump();
	test.release();

	test.loadFile("tests/8bpp.bmp");
	test.printDump();
	test.release();

	test.loadFile("tests/24bpp.bmp");
	test.printDump();
	test.release();
	return 0;
}