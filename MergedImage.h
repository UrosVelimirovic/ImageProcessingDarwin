#ifndef MERGEDIMAGE_H
#define MERGEDIMAGE_H

#include "Image.h"

class MergedImage : public Image {

public:
	void startProcessing() override {
		endMessage();
	}
	~MergedImage();
private:
	void endMessage();
};

#endif MERGEDIMAGE_H