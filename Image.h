#ifndef IMAGE_H
#define IMAGE_H



class Image {

public:
	int width;
	int height;
	int channels;
	unsigned char* image_data;
	string imagePath;

	virtual void startProcessing() = 0;
};

#endif IMAGE_H


