#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"
#include <fstream>

Bitmap::Bitmap(int width, int height): m_width(width), m_height(height), m_pPixels(new uint8_t[width*height*3]{}){

}	

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
	uint8_t *pPixel = m_pPixels.get(); // Memory block that represents the whole screen.
	pPixel += (y * 3) * m_width + (x * 3); // y * m_width is if every pixel is 1 byte times 3  in all rows (y) before the one we're interested in.	
				   // Then move it forward by x number of columns until pixel (pPixel) we want.
	// In reverse order because it is in little endian format.
	pPixel[0] = blue;
	pPixel[1] = green;
	pPixel[2] = red;
}

bool Bitmap::write(std::string filename) {
	BitmapFileHeader fileHeader;
	BitmapInfoHeader infoHeader;
	fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader) + m_width * m_height * 3;
	fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

	infoHeader.width = m_width;
	infoHeader.height = m_height;	

	std::ofstream file;
	file.open(filename, std::ios::out | std::ios::binary);
	if(!file) {
		std::cout << "Error opening file." << std::endl;
		return false;
	}
	file.write((char *)&fileHeader, sizeof(fileHeader));
	file.write((char *)&infoHeader, sizeof(infoHeader));
	file.write((char *)m_pPixels.get(), m_width * m_height * 3);

	file.close();
	
	return false;	
}

Bitmap::~Bitmap() {

}
