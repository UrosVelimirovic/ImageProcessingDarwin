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
	unsigned char* imageData;
	
public:

	// Making the class abstract
	virtual void startProcessing() = 0;
};

#endif IMAGE_H


