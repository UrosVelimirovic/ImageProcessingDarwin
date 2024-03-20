#include "OriginalImage.h"


#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"
#define _CRT_SECURE_NO_WARNINGS

const double OriginalImage::redFactor = 0.3;
const double OriginalImage::greenFactor = 0.59;
const double OriginalImage::blueFactor = 0.11;

void OriginalImage::loadImage()
{
	do {
		cout << "Please enter a PATH to the image you want to process..." << endl
			<< "Make sure there is a file extension at the end of the file name!" << endl;
		cin >> imagePath;

		imageData = stbi_load(imagePath.c_str(), &this->width, &this->height, &this->channels, 0);

		// check if the image wasn't loaded correctly
		if (!imageData) {
			cout << "Error: Wrong file PATH!" << endl;
		}
	} while (!imageData);
}

void OriginalImage::makeGrayscale()
{
    unsigned char* newGrayScaleImageData = new unsigned char[width * height];
    int size = width * height;

    // Traversing through pixels
    for (int i = 0; i < size; i++) {
        int index = i * channels;
        unsigned char red = imageData[index];
        unsigned char green = imageData[index + 1];
        unsigned char blue = imageData[index + 2];

        // formula for grayscale
        newGrayScaleImageData[i] = static_cast<unsigned char>(redFactor * red + greenFactor * green + blueFactor * blue);
    }

    // making a new image
    stbi_write_png("out_grayscale.png", width, height, 1, newGrayScaleImageData, width);
    
    

    // making the new path for greyScale image
    string newPath;
    int slashOrBeginning = imagePath.size() - 1;
    for (; slashOrBeginning >= 0; slashOrBeginning--) {
        if (imagePath[slashOrBeginning] == '\\') {
            break;
        }
    }
    if (slashOrBeginning < 0) {
        newPath = "out_grayscale.png";
    }
    else newPath = imagePath.substr(0, slashOrBeginning + 1) + "out_grayscale.png";

    // setting greyscale image
    greyScaleImage.setChannels(channels);
    greyScaleImage.setHeight(height);
    greyScaleImage.setWidth(width);
    greyScaleImage.setImageData(newGrayScaleImageData);
    greyScaleImage.setImagePath(newPath);

}

OriginalImage::~OriginalImage()
{
    // freeing the image after using it.
    stbi_image_free(imageData);
}

//C:\Users\uros1\source\repos\ImageProcessing\ImageProcessing\Lenna_(test_image).png
//C:\Users\uros1\source\repos\ImageProcessing\ImageProcessing\kompjuter.png
//C:\Users\uros1\source\repos\ImageProcessing\ImageProcessing\Tara.png