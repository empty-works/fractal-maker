#include <iostream>
#include "FractalCreator.h"
#include "RGB.h"

int main() {

	int height = 600;

	FractalCreator fractalCreator(800, 600);
	fractalCreator.run("test.bmp");

	std::cout << "Finished." << std::endl;
	return 0;
}
