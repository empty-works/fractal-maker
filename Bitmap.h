#ifndef BITMAP_H_
#define BITMAP_H_

#include <string>

class Bitmap {
	int m_width{0};
	int m_height{0};

	public:
	Bitmap(int width, int height);
	bool write(std::string filename);
	virtual ~Bitmap();
};

#endif
