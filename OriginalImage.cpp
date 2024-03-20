#include "OriginalImage.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

void OriginalImage::loadImage()
{
	do {
		cout << "Please enter a PATH to the image you want to process..." << endl
			<< "Make sure there is a file extension at the end of the file name!" << endl;
		cin >> imagePath;

		image_data = stbi_load(imagePath.c_str(), &this->width, &this->height, &this->channels, STBI_rgb_alpha);

		// check if the image wasn't loaded correctly
		if (!image_data) {
			cout << "Error: Wrong file PATH!" << endl;
		}
	} while (!image_data);
}
