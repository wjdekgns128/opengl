#ifndef _CSPRITE_H
#define _CSPRITE_H
#include <Windows.h>
#include "cMyInclude.h"
#include <vector>

class cSprite
{
private:
	GLubyte *pBytes; // 데이터를 가리킬 포인터
	GLubyte *pBytesRGBA; // 데이터를 가리킬 포인터

	BITMAPINFO *info;
	GLuint  Textures[50]; //50개
public:
	cSprite() 
	{ 
		pBytes = NULL;
		info = NULL;
		pBytesRGBA = NULL;
		glGenTextures(50, Textures);

	}
	~cSprite() { 
		SAFE_DELETE(pBytesRGBA);
		SAFE_DELETE(pBytes);
		SAFE_DELETE(info);
	}
public:
	void Entry(int number, const char* filename);
	void OnRender(int number);
	void OffRender(int number);

private:
	GLubyte* RGBA_From_RGB(GLubyte* pixels, int w, int h)
	{
		int texture_size = w*h;
		GLubyte* RGBA_pixels = new GLubyte[texture_size * 4];
		for (int i = 0; i < texture_size;i++)
		{
			RGBA_pixels[i * 4] = pixels[i * 3];
			RGBA_pixels[i * 4 + 1] = pixels[i * 3 + 1];
			RGBA_pixels[i * 4 + 2] = pixels[i * 3 + 2];

			if (pixels[i * 3 + 0] == 255 && pixels[i * 3 + 1] == 255 && pixels[i * 3 + 2] == 255)
				RGBA_pixels[i * 4 + 3] = 0;
			else
				RGBA_pixels[i * 4 + 3] = 255;
		}
		return RGBA_pixels;

	}
	GLubyte* LoadBitMap(const char* name, BITMAPINFO** info)
	{
		FILE *fp;
		GLubyte *bits;
		int bitsize, infosize;
		BITMAPFILEHEADER header;
		if ((fp = fopen(name, "rb")) == NULL)
			return NULL;
		if (fread(&header, sizeof(BITMAPFILEHEADER), 1, fp) < 1) {
			fclose(fp);
			return NULL;
		}
		if (header.bfType != 'MB') {
			fclose(fp);
			return NULL;
		}
		infosize = header.bfOffBits - sizeof(BITMAPFILEHEADER);
		if ((*info = (BITMAPINFO *)malloc(infosize)) == NULL) {
			fclose(fp);
			exit(0);
			return NULL;
		}
		if (fread(*info, 1, infosize, fp) < (unsigned int)infosize) {
			free(*info);
			fclose(fp);
			return NULL;
		}
		if ((bitsize = (*info)->bmiHeader.biSizeImage) == 0)
			bitsize = ((*info)->bmiHeader.biWidth *
				(*info)->bmiHeader.biBitCount + 7) / 8.0 *
			abs((*info)->bmiHeader.biHeight);
		if ((bits = (unsigned char *)malloc(bitsize)) == NULL) {
			free(*info);
			fclose(fp);
			return NULL;
		}
		if (fread(bits, 1, bitsize, fp) < (unsigned int)bitsize) {
			free(*info); free(bits);
			fclose(fp);
			return NULL;
		}
		fclose(fp);
		return bits;
	}

};
#endif