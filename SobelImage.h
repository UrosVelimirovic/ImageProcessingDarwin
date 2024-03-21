#ifndef SOBELIMAGE_H
#define SOBELIMAGE_H

#include "Image.h"
#include "MergedImage.h"

class SobelImage : public Image {
	MergedImage mergedImage;
public:
	void startProcessing() override {
		makeMergedImage();
	}


private:
	void makeMergedImage();
};
#endif SOBELIMAGE_H
