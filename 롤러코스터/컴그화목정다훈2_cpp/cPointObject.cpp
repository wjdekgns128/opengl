#include "cPointObject.h"
#include <random>
cPointObject::cPointObject()
{
	m_start = false;
	m_NowMode = 0;
	m_Scal = cVector(20, 20, 80/*+ rand() % 200*/);

}
cPointObject::~cPointObject()
{

}
void cPointObject::Render2D()
{
	glColor3ub(192, 192, 192);

	if (m_start)
	{
		glColor3ub(70, 200, 255);
	}
	glRectf(m_2DVector.x, m_2DVector.y, m_2DVector.x + m_Scal.x, m_2DVector.y + m_Scal.y);
	if (m_NowMode == 2)
	{
		glColor3f(0, 0, 0);
		char st[1000];
		sprintf(st, "%d", (int)m_Scal.z);
		glRasterPos2d(m_2DVector.x + 3, m_2DVector.y + 15);
		for (unsigned int i = 0; i < strlen(st); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);

	}
	else
	{
		if (m_start)
		{
			glColor3f(0, 0, 0);
			char st[1000] = ("SP");
			glRasterPos2d(m_2DVector.x + 7, m_2DVector.y + 25);
			for (unsigned int i = 0; i < strlen(st); i++)
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);

		}
	}
	


}
void cPointObject::Render3D()
{
	glPushMatrix();

	glColor3ub(192, 192, 192);
	if (m_start)
	{
		glColor3ub(70, 200, 255);
	}
	glTranslatef(m_3DVector.x, m_Scal.z/2 + 0.5, m_3DVector.y);
	glScalef(m_Scal.x, m_Scal.z, m_Scal.y);
	glutSolidCube (1);
	glPopMatrix();

}
void cPointObject::Update()
{

}
void cPointObject::Mouse(int button, int state, int x, int y)
{
	m_2DVector.x = x;
	m_2DVector.z = 600-y;

}
