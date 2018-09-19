// 모든 오브젝트들이 기본적으로 가지고있어야하는 것들(2D,3D변환..)

#ifndef _CBASEOBJECT_H
#define _CBASEOBJECT_H
#include <gl/glut.h>
#include <stdio.h>
#include "cVector.h"
#include <Windows.h>

class cBaseObject
{
public:
	int m_DrawFont;
	int  m_anglecheck;
	int		m_Color[3];
	int m_CaveAngle;

protected:
	cVector			m_2DVector;
	cVector			m_3DVector;
	cVector			m_Scal;
	int			m_NowMode;
	int				m_type;


public:
	cBaseObject()
	{
		m_CaveAngle = 0;
		m_Color[0] = 0;
		m_Color[1] = 0;
		m_Color[2] = 0;

		m_anglecheck = 0;
		m_2DVector = cVector(0, 0, 0);
		m_3DVector = cVector(0, 0, 0);
		m_Scal = cVector(0, 0, 0);
		m_NowMode = 0;
		m_DrawFont = 0;
	}
	~cBaseObject()
	{

	}
public:
	void Setting(int a, int b, int c)
	{
		m_Color[0] = a;
		m_Color[1] = b;
		m_Color[2] = c;

	}
	void ChageMode(int num)
	{
		m_NowMode = num;
	}
	void Chage2Dto3D()
	{
		GLint viewport[4];
		GLdouble modelview[16];
		GLdouble projection[16];
		GLfloat winX, winY, winZ;
		GLdouble posX, posY, posZ;
		cVector Temp2 = m_2DVector;
		if (m_type == 2 )
		{
			Temp2.x += m_Scal.x / 2;
			Temp2.y += m_Scal.y / 2;

		}
		glGetDoublev(GL_MODELVIEW_MATRIX, modelview);
		glGetDoublev(GL_PROJECTION_MATRIX, projection);
		glGetIntegerv(GL_VIEWPORT, viewport);
		winX = ((float)Temp2.x);
		winY = (float)viewport[3] - ((float)Temp2.y);
		glReadPixels(0, int(winY), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);
		gluUnProject(winX, winY, winZ, modelview, projection, viewport, &posX, &posY, &posZ);

	

		m_3DVector.x = posX/2;
		m_3DVector.y = posY/2;
		m_3DVector.z = -posZ/2;
	}
public:
	virtual void Update() = 0;
	virtual void Render2D() = 0;
	virtual void Render3D() = 0;
	virtual void Mouse(int button, int state, int x, int y) = 0;
	virtual bool Coll2d(cVector start, cVector Scl) = 0;
public:
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
public:
	void Set2DVector(cVector t)
	{
		m_2DVector = t;
	}
	void Set3DVector(cVector t)
	{
		m_3DVector = t;
	}
	
	void SetSclVector(cVector t)
	{
		m_Scal = t;
	}
	int GetType()
	{
		return m_type;
	}
	cVector Get2DVector()
	{
		return m_2DVector;
	}
	cVector Get3DVector()
	{
		return m_3DVector;
	
	}
	cVector GetSclVector()
	{
		return m_Scal;
	}

	virtual void ZUp()
	{
		m_Scal.z += 10;
		if (m_Scal.z > 100)
			m_Scal.z = 100;
	}
	virtual void ZDown()
	{
		m_Scal.z -= 10;
		if (m_Scal.z < 20)
			m_Scal.z = 20;

	}
	void xUp()
	{
		m_Scal.x += 10;
		if (m_Scal.x > 100)
			m_Scal.x = 100;
	}
	void xDown()
	{
		m_Scal.x -= 10;
		if (m_Scal.x < 20)
			m_Scal.x = 20;
	}
	void yUp()
	{
		m_Scal.y += 10;
		if (m_Scal.y > 100)
			m_Scal.y = 100;
	}
	void yDown()
	{
		m_Scal.y -= 10;
		if (m_Scal.y < 20)
			m_Scal.y = 20;
	}
};
#endif // !_CBASEOBJECT_h
