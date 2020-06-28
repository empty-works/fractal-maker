#ifndef MANDELBROT_H_
#define MANDELBROT_H_

class Mandelbrot {
public:
	static const int MAX_ITERATIONS = 1000; // The more iterations the better the quality of the image. Will take longer though.

public:
	Mandelbrot();
	virtual ~Mandelbrot();

	static int getIterations(double x, double y);
};

#endif
