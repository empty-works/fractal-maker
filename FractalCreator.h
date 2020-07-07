#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <iostream>
#include <cstdint>
#include <math.h>
#include <vector>
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

	std::vector<int> m_ranges;	
	std::vector<RGB> m_colors;
	std::vector<int> m_range_totals;

	bool m_bGotFirstRange {false};
	
	void calculateIteration();
	void calculateTotalIterations();
	void drawFractal();
	void writeBitmap(std::string name);
public:
	FractalCreator(int width, int height);
	void addRange(double rangeEnd, const RGB &rgb);
	virtual ~FractalCreator();
	void run(std::string name);
	void addZoom(const Zoom & zoom);
};

#endif
