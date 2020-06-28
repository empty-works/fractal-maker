#include <iostream>
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

			if(xFractal < min) min = xFractal;		
			if(xFractal < max) max = xFractal;		
		}
	}
	
	std::cout << min << ", " << max << std::endl;

	bitmap.write("test.bmp");

	std::cout << "Finished." << std::endl;
	return 0;
}

