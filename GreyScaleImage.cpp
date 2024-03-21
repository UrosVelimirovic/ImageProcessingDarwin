#include "GreyscaleImage.h"
#include <math.h>
#include "STBShell.h"

GreyScaleImage::~GreyScaleImage()
{
    STBShell::deleteImageData(imageData);
}

void GreyScaleImage::makeSobel()
{
    unsigned char* newSobelImageData = new unsigned char[width * height];
   
    int rows = height;
    int columns = width;

    // Cache line size on most x86_64 cpus is 64 bytes.
    // Therefore for optimization of sobel algorithm we will use this
    // parameter. Of course, code can be adjusted so that it fits
    // some other machines. We will use x86_64 architecture info since this 
    // architecture is the most common
    int cacheLineSize = 64;

    // Using "Reduce Miss rate by blocking" technique for optimization:
    // The algorithm is a simple sobel convolution algorihtm just adjusted to
    // run faster. The main problem with the basic algorithm is that if the matrix is big enough
    // it will store certain rows in cache and later remove them from cache to insert some others.
    // As processing is going, old removed rows will have to be inserted into cache again because
    // they will be processed again for new pixels beneath them. So the solution is instead of going
    // to the end of the matrix row, we will divide the matrix into blocks so that each block contains
    // three rows of certain size + one row from output image matrix. The size of these rows will be calculated
    // as to fit cache the best so that we minimize the miss penalties in cache. This ultimately makes the program
    // run faster. For more details consult the apropriate literature.

    // Most iner for loop has no two for loops which is expected. We simply unrolled them since they 
    // always have the constant number of iterations. Just a small optimization.

    for ( int block = 0; block < columns / cacheLineSize; block++) {
        for ( int row = 1; row < rows - 1; row++) {
            for ( int column = block * cacheLineSize; column < columns - 1 && column < (block + 1) * cacheLineSize; column++) {
                const double gx = -1 * imageData[(row - 1) * columns + (column - 1)] +
                    1 * imageData[(row - 1) * columns + (column + 1)] +
                    -2 * imageData[(row - 0) * columns + (column - 1)] +
                    2 * imageData[(row - 0) * columns + (column + 1)] +
                    -1 * imageData[(row + 1) * columns + (column - 1)] +
                    1 * imageData[(row + 1) * columns + (column + 1)];
                const double gy = -1 * imageData[(row - 1) * columns + (column - 1)] +
                    -2 * imageData[(row - 1) * columns + (column - 0)] +
                    -1 * imageData[(row - 1) * columns + (column + 1)] +
                    1 * imageData[(row + 1) * columns + (column - 1)] +
                    2 * imageData[(row + 1) * columns + (column - 0)] +
                    1 * imageData[(row + 1) * columns + (column + 1)];
                newSobelImageData[row * columns + column] = sqrt(gx * gx + gy * gy);
            }
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
    sobelImage.setfirstOriginalImage(this->firstOriginalImage);

    sobelImage.startProcessing();
}

