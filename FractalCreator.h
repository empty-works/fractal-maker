#ifndef FRACTALCREATOR_H_
#define FRACTALCREATOR_H_

#include <string>

class FractalCreator {
public:
	FractalCreator(int width, int height);
	virtual ~FractalCreator();

	void calculateIteration();
	void drawFractal();
	void addZoom(const Zoom & zoom);
	void writeBitmap(std::string name);
};

#endif
