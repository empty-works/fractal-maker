#ifndef ZOOMSTORE_H_
#define ZOOMSTORE_H_

#include "Zoom.h"
#include <vector>

struct ZoomStore {
	std::vector<Zoom> zoomList {};
	ZoomStore();
	bool setToList(Zoom obj) {
		zoomList.push_back(obj);
		return true;
	}
	std::Pair getPair(int x, int y) {
		return std::Pair(x, y);
	}
};

#endif
