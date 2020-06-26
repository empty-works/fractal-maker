#include <iostream>
#include "Bitmap.h"

int main() {
	int const WIDTH = 800;
	int const HEIGHT = 600;

	Bitmap bitmap(WIDTH, HEIGHT);


	bitmap.write("test.bmp");

	std::cout << "Finished." << std::endl;
	return 0;
}

