#include "SobelImage.h"
#include "STBShell.h"

void SobelImage::makeMergedImage()
{
    unsigned char* originalImage = firstOriginalImage->getImageData();
    // imageData field is a foreground image
    unsigned char* newMergedImage = new unsigned char[width * height * channels];
    int size = width * height;
    double alphaFactor = 0.5; // [0-1] depending on the transparency required

    // Traversing through pixels
    for (int i = 0; i < size; i++) {
        int index = i * channels;
        unsigned char red = originalImage[index];
        unsigned char green = originalImage[index + 1];
        unsigned char blue = originalImage[index + 2];

        newMergedImage[index] = static_cast<unsigned char>((imageData[i] * alphaFactor) + (red * (1 - alphaFactor))); // red
        newMergedImage[index + 1] = static_cast<unsigned char>((imageData[i] * alphaFactor) + (green * (1 - alphaFactor))); // green
        newMergedImage[index + 2] = static_cast<unsigned char>((imageData[i] * alphaFactor) + (blue * (1 - alphaFactor))); // blue

        if (channels > 3) {
            newMergedImage[index + 3] = originalImage[index + 3]; // alpha
        }
    }

    // making a new image
    STBShell::makeImage("out_merged.png", width, height, channels, newMergedImage, width * channels);

    // std had to be provided since intrin.h also has an object cout
    std::cout << "Merged image done! Image name: out_merged.png " << endl << endl;

    // making the new path for sobel image
    string newPath;
    int slashOrBeginning = imagePath.size() - 1;
    for (; slashOrBeginning >= 0; slashOrBeginning--) {
        if (imagePath[slashOrBeginning] == '\\') {
            break;
        }
    }
    if (slashOrBeginning < 0) {
        newPath = "out_merged.png";
    }
    else newPath = imagePath.substr(0, slashOrBeginning + 1) + "out_merged.png";

    // setting sobel image
    mergedImage.setChannels(channels);
    mergedImage.setHeight(height);
    mergedImage.setWidth(width);
    mergedImage.setImageData(newMergedImage);
    mergedImage.setImagePath(newPath);
    mergedImage.setfirstOriginalImage(this->firstOriginalImage);

    mergedImage.startProcessing();
}
