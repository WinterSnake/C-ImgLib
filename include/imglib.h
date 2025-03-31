/*
	Image Loader Library

	Supported Formats:
		- PPM

	Written By: Ryan Smith
*/
#ifndef _IMGLIB_H
#define _IMGLIB_H

#include <stddef.h>
#include <stdint.h>

#ifndef IMGLIB_MALLOC
	#define IMGLIB_MALLOC malloc
#endif
#ifndef IMGLIB_FREE
	#define IMGLIB_FREE free
#endif

typedef struct ImgLib_Image
{
	uint32_t width, height;
	void* pixels;
	enum FORMAT_T {
		FORMAT_RGB_8,
		FORMAT_RGBA_8,
	} format;
} Image;

size_t ImgLib_GetPixelStride(enum FORMAT_T format);
Image ImgLib_New(uint32_t width, uint32_t height, enum FORMAT_T format);
Image ImgLib_Load(const char* file_path);
void ImgLib_Save(const char* file_path, Image* image);
void ImgLib_Free(Image* image);

#endif
