#ifndef STBShell_H
#define STBShell_H


class STBShell {

public:
	static unsigned char* loadImage(const char* filename, int* x, int* y, int* comp, int req_comp);
	static void makeImage(const char* filename, int x, int y, int comp, const void* data, int stride_bytes);
	static void deleteImageData(void* retval_from_stbi_load);
};
#endif STBShell_H
