#ifndef MANDELBROT_H_
#define MANDELBROT_H_

class Mandelbrot {
public:
	Mandelbrot();
	virtual ~Mandelbrot();

	static int getIterations(double x, double y);
};

#endif
