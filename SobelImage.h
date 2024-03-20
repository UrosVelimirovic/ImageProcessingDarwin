#ifndef SOBELIMAGE_H
#define SOBELIMAGE_H

#include "Image.h"

class SobelImage : public Image {
public:
	void startProcessing() override {
		
	}

	void setWidth(int width) {
		this->width = width;
	}
	void setHeight(int height) {
		this->height = width;
	}
	void setChannels(int channels) {
		this->channels = channels;
	}
	void setImageData(unsigned char* imageData) {
		this->imageData = imageData;
	}
	void setImagePath(string path) {
		this->imagePath = path;
	}
private:

};
#endif SOBELIMAGE_H
