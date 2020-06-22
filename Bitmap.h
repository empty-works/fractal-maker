#ifndef BITMAP_H_
#define BITMAP_H_

class Bitmap {
	int m_width{0};
	int m_height{0};

	public:
	Bitmap(int width, int height);
	virtual ~Bitmap();
};

#endif
