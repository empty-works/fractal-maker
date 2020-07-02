#ifndef ZOOMLIST_H_
#define ZOOMLIST_H_

#include <vector>
#include "Zoom.h"

class ZoomList {
private:
	int m_width {0};
	int m_height {0};
	std::vector<Zoom> zooms;
public:
	ZoomList(int width, int height);
	void add(const Zoom &zoom);
};

#endif
