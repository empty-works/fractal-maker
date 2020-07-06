#ifndef RGB_H_
#define RGB_H_

struct RGB {
private:
	double r;
	double g;
	double b;
public:
	RGB(double r, double g, double b);
	virtual ~RGB();
};

#endif
