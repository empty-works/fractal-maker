#include <iostream>
#include "FractalCreator.h"
#include "RGB.h"
#include "Zoom.h"

int main() {

	int height = 600;

	FractalCreator fractalCreator(800, 600);

	fractalCreator.addRange(0.3, RGB(255, 0, 0));
	fractalCreator.addRange(0.5, RGB(255, 225, 0));
	fractalCreator.addRange(10, RGB(255, 255, 255));

	fractalCreator.addZoom(Zoom(295, 202, 0.1));
	fractalCreator.addZoom(Zoom(312, 304, 0.1));
	fractalCreator.run("test.bmp");

	std::cout << "Finished." << std::endl;
	return 0;
}
