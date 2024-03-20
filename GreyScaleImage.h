#ifndef GREYSCALEIMAGE_H
#define GREYSCALEIMAGE_H

#include "Image.h"

class GreyScaleImage: public Image {
public:
	void startProcessing() override {
		makeSobel();
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
	void makeSobel();
};
#endif GREYSCALEIMAGE_H
