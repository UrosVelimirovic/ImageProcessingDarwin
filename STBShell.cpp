#include "STBShell.h"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

unsigned char* STBShell::loadImage(const char* filename, int* x, int* y, int* comp, int req_comp)
{
    return stbi_load(filename, x, y, comp, req_comp);
}

void STBShell::makeImage(const char* filename, int x, int y, int comp, const void* data, int stride_bytes)
{
   int a = stbi_write_png(filename, x, y, comp, data, stride_bytes);
   a;
}

void STBShell::deleteImageData(void* retval_from_stbi_load)
{
    stbi_image_free(retval_from_stbi_load);

}
