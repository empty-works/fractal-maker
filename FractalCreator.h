#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>
#include "Zoom.h"

class FractalCreator {
private:

	std::unique_ptr<int[]> m_histogram;
	std::unique_ptr<int[]> m_fractal(new int[m_width * m_height]{0});
public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();

	void calculateIteration();
	void drawFractal();
	void addZoom(const Zoom & zoom);
	void writeBitmap(std::string name);
};

#endif
