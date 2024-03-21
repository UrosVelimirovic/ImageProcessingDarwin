#ifndef STBShell_H
#define STBShell_H



// STBShell is a class that is used to create an object oriented shell over STB functions used.
class STBShell {

public:
	STBShell() = delete;
	static unsigned char* loadImage(const char* filename, int* x, int* y, int* comp, int req_comp);
	static void makeImage(const char* filename, int x, int y, int comp, const void* data, int stride_bytes);
	static void deleteImageData(void* retval_from_stbi_load);
};
#endif STBShell_H
