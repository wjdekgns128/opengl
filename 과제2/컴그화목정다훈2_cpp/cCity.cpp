#include "cCity.h"
#include <random>
cCity::cCity()
{
	m_type = 1;

	m_NowMode = 0;
	m_Scal = cVector(30, 30, 40/*+ rand() % 200*/);
	m_Color[0] = rand() % 200 + 50;
	m_Color[1] = rand() % 200 + 50;
	m_Color[2] = rand() % 200+ 50;

}
cCity::~cCity()
{

}
void cCity::Render2D()
{
	glColor3ub(m_Color[0], m_Color[1], m_Color[2]);
	glRectf(m_2DVector.x, m_2DVector.y, m_2DVector.x + m_Scal.x, m_2DVector.y + m_Scal.y);
	if (m_NowMode == 2)
	{
		glColor3f(0, 0, 0);
		char st[1000];
		sprintf(st, "%d", (int)m_Scal.z);
		glRasterPos2d(m_2DVector.x - 1, m_2DVector.y + 18);
		for (unsigned int i = 0; i < strlen(st); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
	}

}
void cCity::Render3D()
{
	
	glPushMatrix();

	glColor3ub(m_Color[0], m_Color[1], m_Color[2]);

	glTranslatef(m_3DVector.x, m_Scal.z / 2 + 0.5, m_3DVector.y);
	glScalef(m_Scal.x, m_Scal.z, m_Scal.y);
	glutSolidCube(1);
	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0, 0, 0.32);
	glScalef(0.4, 0.2, 0.4);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0, 0, -0.32);
	glScalef(0.4, 0.2, 0.4);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(0.32, 0, 0);
	glScalef(0.4, 0.2, 0.4);
	glutWireCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0, 0, 0);
	glTranslatef(-0.32, 0, 0);
	glScalef(0.4, 0.2, 0.4);
	glutWireCube(1);
	glPopMatrix();


	glPopMatrix();

}
void cCity::Update()
{

}
void cCity::Mouse(int button, int state, int x, int y)
{
}
