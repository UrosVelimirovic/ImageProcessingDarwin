#ifndef ORIGINALIMAGE_H
#define ORIGINALIMAGE_H

#include "Image.h"
#include "GreyScaleImage.h"

class OriginalImage: public Image {
	static const double redFactor;
	static const double blueFactor;
	static const double greenFactor;
	GreyScaleImage greyScaleImage;
public:

	void startProcessing() override {
		loadImage();
		makeGrayscale();
	}

	~OriginalImage();

private:
	void loadImage();
	void makeGrayscale();
	
};

#endif ORIGINALIMAGE_H

