#ifndef GREYSCALEIMAGE_H
#define GREYSCALEIMAGE_H

#include "Image.h"
#include "SobelImage.h"

class GreyScaleImage: public Image {
private:
	SobelImage sobelImage;
public:
	void startProcessing() override {
		makeSobel();
	}

	void setWidth(int width) {
		this->width = width;
	}
	void setHeight(int height) {
		this->height = height;
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
	~GreyScaleImage();
private:
	void makeSobel();
};
#endif GREYSCALEIMAGE_H
