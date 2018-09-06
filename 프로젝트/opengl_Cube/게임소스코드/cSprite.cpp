#include "cSprite.h"

void cSprite::Entry(int number, const char* filename)
{
	SAFE_DELETE(pBytes);
	SAFE_DELETE(info);
	SAFE_DELETE(pBytesRGBA);

	glBindTexture(GL_TEXTURE_2D, Textures[number]);
	pBytes = LoadBitMap(filename, &info);
	pBytesRGBA = RGBA_From_RGB(pBytes, info->bmiHeader.biWidth, info->bmiHeader.biHeight);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, info->bmiHeader.biWidth, info->bmiHeader.biHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, pBytesRGBA);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);



}
void cSprite::OnRender(int number)
{
	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, Textures[number]);

}
void cSprite::OffRender(int number)
{
	glDisable(GL_TEXTURE_2D);
}
