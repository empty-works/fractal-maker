#ifndef BITMAP_H_
#define BITMAP_H_

#include <string>

class Bitmap {
	int m_width{0};
	int m_height{0};

	public:
	Bitmap(int width, int height);
	void setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);
	bool write(std::string filename);
	virtual ~Bitmap();
};

#endif
