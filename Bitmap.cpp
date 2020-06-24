#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

Bitmap::Bitmap(int width, int height): m_width(width), m_height(height), m_pPixels(new uint8_t[width*height*3]{}){

}	

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
	
}

bool Bitmap::write(std::string filename) {
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;
	fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3;
	fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);


	return false;	
}

Bitmap::~Bitmap() {

}
