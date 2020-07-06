#include <iostream>
#include "FractalCreator.h"
#include "RGB.h"

int main() {

	RGB rgb1(4, 5, 6);
	RGB rgb2(1, 2, 3);
	RGB rgb3 = rgb1 - rgb2;
	std::cout << rgb3.r << ", " << rgb3.g << ", " << rgb3.b << std::endl;

	int height = 600;

	FractalCreator fractalCreator(800, 600);

	fractalCreator.addZoom(Zoom(295, height - 202, 0.1));
	fractalCreator.addZoom(Zoom(312, height - 304, 0.1));
	fractalCreator.calculateIteration();
	fractalCreator.calculateTotalIterations();
	fractalCreator.drawFractal();
	fractalCreator.writeBitmap("test.bmp");

	std::cout << "Finished." << std::endl;
	return 0;
}
