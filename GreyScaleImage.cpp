#include "GreyscaleImage.h"
#include <math.h>
#include "STBShell.h"


void GreyScaleImage::makeSobel()
{
    int GX[] = { -1, 0, 1, -2, 0, 2, -1, 0, 1 };
    int GY[] = { -1, -2, -1, 0, 0, 0, 1, 2, 1 };
    unsigned char* newSobelImageData = new unsigned char[width * height];
   
    int rows = height;
    int columns = width;
    for (int row = 1; row < (rows - 1); row++) {
        for (int column = 1; column < (columns - 1); column++) {
            double gx = 0;
            double gy = 0;

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int image_row = row + i - 1;
                    int image_column = column + j - 1;

                    double image_value = imageData[image_row * columns + image_column];

                    int kernel_index = i * 3 + j;

                    gx += image_value * GX[kernel_index];
                    gy += image_value * GY[kernel_index];
                }
            }

            int magnitudeValue = sqrt(gx * gx + gy * gy);
            magnitudeValue = min(255, max(0, magnitudeValue));
            newSobelImageData[row * columns + column] = static_cast<unsigned char>(magnitudeValue);
        }
    }

    // making a new image
    STBShell::makeImage("out_sobel.png", width, height, 1, newSobelImageData, width);

    cout << "Sobel done! Image name: out_sobel.png " << endl;

    // making the new path for sobel image
    string newPath;
    int slashOrBeginning = imagePath.size() - 1;
    for (; slashOrBeginning >= 0; slashOrBeginning--) {
        if (imagePath[slashOrBeginning] == '\\') {
            break;
        }
    }
    if (slashOrBeginning < 0) {
        newPath = "out_sobel.png";
    }
    else newPath = imagePath.substr(0, slashOrBeginning + 1) + "out_sobel.png";

    // setting sobel image
    sobelImage.setChannels(channels);
    sobelImage.setHeight(height);
    sobelImage.setWidth(width);
    sobelImage.setImageData(newSobelImageData);
    sobelImage.setImagePath(newPath);
}
