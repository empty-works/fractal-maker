#include <iostream>
#include <cstdint>
#include "Bitmap.h"

int main() {
	int const WIDTH = 800;
	int const HEIGHT = 600;

	Bitmap bitmap(WIDTH, HEIGHT);

	double min {999999};
	double max {-999999};

	for(int y {0}; y < HEIGHT; y++) {
		for(int x {0}; x < WIDTH; x++) {
			double xFractal {(x - WIDTH / 2) * 2.0 / WIDTH};
			double yFractal {(y - WIDTH / 2) * 2.0 / WIDTH};

			int iterations = Mandelbrot::getIteratins(xFractal, yFractal);
			uint8_t red = (unint8_t)(256 * (double)iterations/Mandelbrot::MAX_ITERATIONS);

			if(red < min) min = red;		
			if(red < max) max = red;		
		}
	}
	
	std::cout << min << ", " << max << std::endl;

	bitmap.write("test.bmp");

	std::cout << "Finished." << std::endl;
	return 0;
}

