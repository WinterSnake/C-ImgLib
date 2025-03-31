/*
	Image Loader Library
	- Interface

	Written By: Ryan Smith
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "imglib.h"

static void ImgLib_Save__PPM(FILE* file, Image* image);

size_t ImgLib_GetPixelStride(enum FORMAT_T format)
{
	switch(format)
	{
		case FORMAT_RGB_8: return sizeof(uint8_t) * 3;
		case FORMAT_RGBA_8: return sizeof(uint8_t) * 4;
		default: return 0;
	}
}

Image ImgLib_New(uint32_t width, uint32_t height, enum FORMAT_T format)
{
	return (Image){
		.width = width,
		.height = height,
		.format = format,
		.pixels = IMGLIB_MALLOC(width * height * ImgLib_GetPixelStride(format)),
	};
}

Image ImgLib_Load(const char* file_path)
{
	(void)file_path;
	Image image = { 0 };
	return image;
}
void ImgLib_Save(const char* file_path, Image* image)
{
	const char* ext = strrchr(file_path, '.');
	// TODO: [ERROR]no file format
	if (ext == NULL) return;
	FILE* f = fopen(file_path, "wb");
	// TODO: ext lookup table
	// PPM
	if (strcmp(ext, "ppm")) ImgLib_Save__PPM(f, image);
	// TODO: [ERROR]unknown file format
	else { }
	fclose(f);
	return;
}

void ImgLib_Free(Image* image)
{
	IMGLIB_FREE(image->pixels);
	image->width = 0;
	image->height = 0;
}

/* PPM */
// TODO: Move to separate files (ppm.c, jpg.c, png.c, ...)
static void ImgLib_Save__PPM(FILE* file, Image* image)
{
	fprintf(file, "P6\n%u %u 255\n", image->width, image->height);
	fwrite(image->pixels, sizeof(uint8_t) * 3, image->width * image->height, file);
}
