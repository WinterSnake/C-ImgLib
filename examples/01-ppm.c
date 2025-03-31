/*
	Image Loader Library: PPM

	Written By: Ryan Smith
*/
#include "imglib.h"

#define BG_COLOR ((0x11 << (8 * 2)) | (0xD5 << (8 * 1)) | (0x1F << (8 * 0)))
#define FG_COLOR ((0x66 << (8 * 2)) | (0x2F << (8 * 1)) | (0x2C << (8 * 0)))

int main(int argc, char** argv)
{
	(void)argc; (void)argv;

	Image img = ImgLib_New(800, 600, FORMAT_RGB_8);
	// Draw
	size_t stride = ImgLib_GetPixelStride(img.format);
	// iter: (i)
	for (size_t i = 0; i < img.width * img.height; ++i)
	{
		uint8_t* offset = (uint8_t*)img.pixels + stride * i;
		*(offset + 0) = (BG_COLOR >> (8 * 2)) & 0xFF;  // R
		*(offset + 1) = (BG_COLOR >> (8 * 1)) & 0xFF;  // G
		*(offset + 2) = (BG_COLOR >> (8 * 0)) & 0xFF;  // B
	}
	// iter: (x, y)
	for (size_t y = 260; y < 433; ++y)
	{
		for (size_t x = 122; x < 224; ++x)
		{
			uint8_t* offset = (uint8_t*)img.pixels + (x * stride + y * img.width * stride);
			*(offset + 0) = (FG_COLOR >> (8 * 2)) & 0xFF;  // R
			*(offset + 1) = (FG_COLOR >> (8 * 1)) & 0xFF;  // G
			*(offset + 2) = (FG_COLOR >> (8 * 0)) & 0xFF;  // B
		}
	}
	ImgLib_Save("square.ppm", &img);
	ImgLib_Free(&img);

	return 0;
}
