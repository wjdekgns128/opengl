#include "cBackGround.h"

cBackGround::cBackGround()
{
	m_Scal.x = 2000;
	m_Scal.y = 1400;
	m_Scal.z = 2;
	m_2DVector.x = 0;
	m_2DVector.y = 0;
	glGenTextures(5, textures);
	glBindTexture(GL_TEXTURE_2D, textures[0]);				//테스트

	pBytes = LoadBitMap("res/test1.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, info->bmiHeader.biWidth, info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
	glBindTexture(GL_TEXTURE_2D, textures[1]);				//테스트
	SAFE_DELETE(pBytes);
	SAFE_DELETE(info);

	pBytes = LoadBitMap("res/test2.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, info->bmiHeader.biWidth, info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
	SAFE_DELETE(pBytes);
	SAFE_DELETE(info);
	glBindTexture(GL_TEXTURE_2D, textures[2]);				//테스트
	pBytes = LoadBitMap("res/test3.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, info->bmiHeader.biWidth, info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
	SAFE_DELETE(pBytes);
	SAFE_DELETE(info);

	glBindTexture(GL_TEXTURE_2D, textures[3]);				//테스트
	pBytes = LoadBitMap("res/test5.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, info->bmiHeader.biWidth, info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
	SAFE_DELETE(pBytes);
	SAFE_DELETE(info);
	glBindTexture(GL_TEXTURE_2D, textures[4]);				//테스트
	pBytes = LoadBitMap("res/test4.bmp", &info);
	glTexImage2D(GL_TEXTURE_2D, 0, 3, info->bmiHeader.biWidth, info->bmiHeader.biHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, pBytes);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_COLOR, GL_MODULATE);
	SAFE_DELETE(pBytes);
	SAFE_DELETE(info);
}
cBackGround::~cBackGround()
{

}
void cBackGround::Render2D()
{
	glColor3ub(50, 255, 80);
	glRectf(m_2DVector.x, m_2DVector.y, m_2DVector.x + m_Scal.x, m_2DVector.y + m_Scal.y);

}
void cBackGround::Render3D()
{
	glPushMatrix();
	glColor3ub(50, 255, 80);
	glNormal3f(0, 0, 0);

	glBegin(GL_QUADS);
	glVertex3f(m_3DVector.x-1000 , m_3DVector.z, m_3DVector.y-700 );
	glVertex3f(m_3DVector.x-1000 + m_Scal.x , m_3DVector.z , m_3DVector.y-700 );
	glVertex3f(m_3DVector.x-1000 + m_Scal.x, m_3DVector.z, m_3DVector.y + m_Scal.y-700 );
	glVertex3f(m_3DVector.x-1000 , m_3DVector.z, m_3DVector.y + m_Scal.y -700);
	glEnd();
	glPopMatrix();




	glPushMatrix();

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, textures[0]);
	glColor3f(1, 1, 1);
	
	 glNormal3f(0, 0, 0);

	glBegin(GL_QUADS);
	glTexCoord2f(1, 0);
	glVertex3f(m_3DVector.x-1000, m_3DVector.z-0 , m_3DVector.y-700 );
	glTexCoord2f(1, 1);
	glVertex3f(m_3DVector.x-1000, m_3DVector.z+1400 , m_3DVector.y-700 );
	glTexCoord2f(0, 1);
	glVertex3f(m_3DVector.x+1000, m_3DVector.z+1400, m_3DVector.y-700);
	glTexCoord2f(0, 0);
	glVertex3f(m_3DVector.x+1000, m_3DVector.z-0 , m_3DVector.y-700 );
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, textures[1]);
	glColor3f(1, 1, 1);
	
	glNormal3f(0, 0, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(1, 0);
	glVertex3f(m_3DVector.x - 1000, m_3DVector.z - 0, m_3DVector.y + 700);
	glTexCoord2f(1, 1);
	glVertex3f(m_3DVector.x - 1000, m_3DVector.z + 1400, m_3DVector.y + 700);
	glTexCoord2f(0, 1);
	glVertex3f(m_3DVector.x + 1000, m_3DVector.z + 1400, m_3DVector.y + 700);
	glTexCoord2f(0, 0);
	glVertex3f(m_3DVector.x + 1000, m_3DVector.z - 0, m_3DVector.y + 700);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();


	glPushMatrix();

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, textures[2]);
	glColor3f(1, 1, 1);

	glNormal3f(0, 0, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(1, 0);
	glVertex3f(m_3DVector.x-1000 , m_3DVector.z - 0, m_3DVector.y -700);
	glTexCoord2f(1, 1);
	glVertex3f(m_3DVector.x-1000 , m_3DVector.z + 1400, m_3DVector.y -700);
	glTexCoord2f(0, 1);
	glVertex3f(m_3DVector.x-1000 , m_3DVector.z + 1400, m_3DVector.y +700);
	glTexCoord2f(0, 0);
	glVertex3f(m_3DVector.x-1000 , m_3DVector.z - 0, m_3DVector.y +700);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
	

	glPushMatrix();

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, textures[3]);
	glColor3f(1, 1, 1);
	glNormal3f(0,0, 0);
	glBegin(GL_QUADS);
	glTexCoord2f(1, 0);
	glVertex3f(m_3DVector.x+1000 , m_3DVector.z - 0, m_3DVector.y - 700);
	glTexCoord2f(1, 1);
	glVertex3f(m_3DVector.x+1000 , m_3DVector.z + 1400, m_3DVector.y - 700);
	glTexCoord2f(0, 1);
	glVertex3f(m_3DVector.x+1000 , m_3DVector.z + 1400, m_3DVector.y + 700);
	glTexCoord2f(0, 0);
	glVertex3f(m_3DVector.x+1000 , m_3DVector.z - 0, m_3DVector.y + 700);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();

	glPushMatrix();

	glEnable(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, textures[4]);
	glColor3f(1, 1, 1);
	
	glNormal3f(0,0,0);
	glBegin(GL_QUADS);
	glTexCoord2f(1, 0);
	glVertex3f(m_3DVector.x-1000 , m_3DVector.z+1400, m_3DVector.y-700 );
	glTexCoord2f(1, 1);
	glVertex3f(m_3DVector.x-1000 , m_3DVector.z+1400 , m_3DVector.y+700 );
	glTexCoord2f(0, 1);
	glVertex3f(m_3DVector.x+1000 , m_3DVector.z+1400 , m_3DVector.y+700 );
	glTexCoord2f(0, 0);
	glVertex3f(m_3DVector.x+1000 , m_3DVector.z+1400 , m_3DVector.y -700);
	glEnd();
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}
void cBackGround::Update()
{

}
void cBackGround::Mouse(int button, int state, int x, int y)
{

}
