#include "MergedImage.h"
#include "STBShell.h"

MergedImage::~MergedImage()
{
	STBShell::deleteImageData(imageData);
}

void MergedImage::endMessage()
{
	cout << "All done! Thank you for using my software, i hope you had fun! I sure did while coding it!";
}
