#include "Bitmap.h"

Bitmap::Bitmap(int width, int height): m_width(width), m_height(height), m_pPixels(new uint8_t[width*height*3]) {

}	

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {

}

bool Bitmap::write(std::string filename) {
	return false;	
}

Bitmap::~Bitmap() {

}
