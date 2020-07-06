#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <iostream>
#include <cstdint>
#include <math.h>
#include <memory>
#include <string>
#include "Zoom.h"
#include "Mandelbrot.h"
#include "Bitmap.h"
#include "ZoomList.h"
#include "RGB.h"

class FractalCreator {
private:
	int m_width;
	int m_height;
	std::unique_ptr<int[]> m_histogram;
	std::unique_ptr<int[]> m_fractal;
	Bitmap m_bitmap;
	ZoomList m_zoomList;
        int m_total {0};
	void calculateIteration();
	void calculateTotalIterations();
	void drawFractal();
	void writeBitmap(std::string name);
public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();
	void run(std::string name);
	void addZoom(const Zoom & zoom);
};

#endif
