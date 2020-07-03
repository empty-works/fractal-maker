#include <iostream>
#include <cstdint>
#include <math.h>
#include "Mandelbrot.h"
#include <memory>
#include "Bitmap.h"
#include "ZoomList.h"

int main() {
	int const WIDTH = 800;
	int const HEIGHT = 600;

	std::unique_ptr<int[]> histogram(new int[Mandelbrot::MAX_ITERATIONS]{0});
	std::unique_ptr<int[]> fractal(new int[WIDTH * HEIGHT]{0});

	Bitmap bitmap(WIDTH, HEIGHT);

	double min {999999};
	double max {-999999};

	ZoomList zoomList(WIDTH, HEIGHT);
	zoomList.add(Zoom(WIDTH / 2, HEIGHT / 2, 1));	

	for(int y {0}; y < HEIGHT; y++) {
		for(int x {0}; x < WIDTH; x++) {
			double xFractal {(x - WIDTH / 2 - 200) * 2.0 / HEIGHT};
			double yFractal {(y - HEIGHT / 2) * 2.0 / HEIGHT};

			int iterations = Mandelbrot::getIterations(xFractal, yFractal);

			fractal[y * WIDTH + x] = iterations;

			if(iterations != Mandelbrot::MAX_ITERATIONS) {
				histogram[iterations]++;
			}	
		}
	}

	int total {0};
	for(size_t i {0}; i < Mandelbrot::MAX_ITERATIONS; i++) {
		total += histogram[i];
	}

	for(size_t y {0}; y < HEIGHT; y++) {
		for(size_t x {0}; x < WIDTH; x++) {
			uint8_t red = 0;
			uint8_t green = 0; 
			uint8_t blue = 0;

			int iterations = fractal[y * WIDTH + x];

			if(iterations != Mandelbrot::MAX_ITERATIONS) {
			
				double hue {0.0};
				for(size_t i {0}; i <= iterations; i++) {
					hue += ((double)histogram[i]) / total;
				}

				green = std::pow(255, hue); 
			}

			bitmap.setPixel(x, y, red, green, blue);
		}
	}

	bitmap.write("test.bmp");

	std::cout << "Finished." << std::endl;
	return 0;
}
