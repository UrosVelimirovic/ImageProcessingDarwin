#ifndef ORIGINALIMAGE_H
#define ORIGINALIMAGE_H

#include <iostream>
using namespace std;

#include "Image.h"

class OriginalImage: public Image {

public:
	void startProcessing() override {
		loadImage();
	}
private:
	void loadImage();
};

#endif ORIGINALIMAGE_H

