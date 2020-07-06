#include "FractalCreator.h"

void FractalCreator::run(std::string name) {
	
	addZoom(Zoom(295, m_height - 202, 0.1));
	addZoom(Zoom(312, m_height - 304, 0.1));
	calculateIteration();
	calculateTotalIterations();
	drawFractal();
	writeBitmap(name);
}

FractalCreator::FractalCreator(int width, int height): m_width(width), m_height(height),
 m_histogram(new int[Mandelbrot::MAX_ITERATIONS] {0}), 
 m_fractal(new int[m_width * m_height]{0}), 
 m_bitmap(m_width, m_height),
 m_zoomList(m_width, m_height) {
		
	m_zoomList.add(Zoom(m_width / 2, m_height / 2, 4.0 / m_width));
}

FractalCreator::~FractalCreator() {

}

void FractalCreator::calculateIteration() {

	for(int y {0}; y < m_height; y++) {
		for(int x {0}; x < m_width; x++) {
			std::pair<double, double> coords = m_zoomList.doZoom(x, y);
			int iterations = Mandelbrot::getIterations(coords.first, coords.second);

			m_fractal[y * m_width + x] = iterations;

			if(iterations != Mandelbrot::MAX_ITERATIONS) {
				m_histogram[iterations]++;
			}	
		}
	}
}

void FractalCreator::calculateTotalIterations() {

	for(size_t i {0}; i < Mandelbrot::MAX_ITERATIONS; i++) {
		m_total += m_histogram[i];
	}
}

void FractalCreator::drawFractal() {

	for(size_t y {0}; y < m_height; y++) {
		for(size_t x {0}; x < m_width; x++) {
			uint8_t red = 0;
			uint8_t green = 0; 
			uint8_t blue = 0;

			int iterations = m_fractal[y * m_width + x];

			if(iterations != Mandelbrot::MAX_ITERATIONS) {
			
				double hue {0.0};
				for(size_t i {0}; i <= iterations; i++) {
					hue += ((double)m_histogram[i]) / m_total;
				}

				green = std::pow(255, hue); 
			}

			m_bitmap.setPixel(x, y, red, green, blue);
		}
	}
}

void FractalCreator::addZoom(const Zoom & zoom) {
	m_zoomList.add(zoom);
}

void FractalCreator::writeBitmap(std::string name) {
	m_bitmap.write(name);
}

