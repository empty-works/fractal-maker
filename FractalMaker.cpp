#include <iostream>
#include <cstdint>
#include "Mandelbrot.h"
#include <memory>
#include "Bitmap.h"

int main() {
	int const WIDTH = 800;
	int const HEIGHT = 600;

	std::unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{0});
	std::unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT]{0});

	Bitmap bitmap(WIDTH, HEIGHT);

	double min {999999};
	double max {-999999};

	for(int y {0}; y < HEIGHT; y++) {
		for(int x {0}; x < WIDTH; x++) {
			double xFractal {(x - WIDTH / 2 - 200) * 2.0 / HEIGHT};
			double yFractal {(y - HEIGHT / 2) * 2.0 / HEIGHT};

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);

			fractal[y * WIDTH + x] = iterations;

			if(iterations != Mandelbrot::MAX_ITERATIONS) {
				histogram[iterations]++;
			}	

			uint8_t color = (uint8_t)(256 * (double)iterations/Mandelbrot::MAX_ITERATIONS);

			color = color * color * color;
			bitmap.setPixel(x, y, 0, color, 0);

			if(color < min) min = color;		
			if(color > max) max = color;		
		}
	}

	int total {0};
	for(size_t i {0}; i < Mandelbrot::MAX_ITERATIONS; i++) {
		total += histogram[i];
	}

	bitmap.write("test.bmp");

	std::cout << "Finished." << std::endl;
	return 0;
}

