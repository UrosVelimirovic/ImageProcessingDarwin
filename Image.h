#ifndef IMAGE_H
#define IMAGE_H

#include <iostream>
using namespace std;


class Image {
protected:
	string imagePath;
	int width;
	int height;
	int channels;
	Image* firstOriginalImage;
	unsigned char* imageData;
	
public:

	// Making the class abstract
	virtual void startProcessing() = 0;

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
	unsigned char* getImageData() {
		return this->imageData;
	}

	void setfirstOriginalImage(Image* image) {
		this->firstOriginalImage = image;
	}
};

#endif IMAGE_H


