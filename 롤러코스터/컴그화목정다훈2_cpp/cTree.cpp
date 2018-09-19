#include "cTree.h"
#include <random>
cTree::cTree()
{
	m_type = 0;
	m_NowMode = 0;
	m_Scal = cVector(20, 20, 40/*+ rand() % 200*/);

}
cTree::~cTree()
{

}
void cTree::Render2D()
{
	glColor3ub(20, 160, 5);
	glBegin(GL_TRIANGLES);
	glVertex3f(m_2DVector.x, m_2DVector.y, 0);
	glVertex3f(m_2DVector.x - m_Scal.x, m_2DVector.y + m_Scal.y, 0);
	glVertex3f(m_2DVector.x + m_Scal.x, m_2DVector.y + m_Scal.y, 0);
	glEnd();

	if (m_NowMode == 2)
	{
		glColor3f(0, 0, 0);
		char st[1000];
		sprintf(st, "%d", (int)m_Scal.z);
		glRasterPos2d(m_2DVector.x - 10, m_2DVector.y + 22);
		for (unsigned int i = 0; i < strlen(st); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
	}

}
void cTree::Render3D()
{
	float y = m_Scal.z *0.5;
	glColor3ub(140, 70, 70);
	glPushMatrix();

	glTranslatef(m_3DVector.x, y / 2 + 0.5, m_3DVector.y);
	glScalef(m_Scal.x, y*0.8, m_Scal.y);
	glutSolidCube(1);
	glPushMatrix();
	glColor3ub(70, 140, 90);
	glTranslatef(0,0.5,0);
	glRotatef(-90, 1, 0, 0);
	glScalef(1, 1, 0.7);
	glutSolidCone(1,1, 25, 25);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(20, 160, 5);
	glTranslatef(0, 1, 0);
	glRotatef(-90, 1, 0, 0);
	glScalef(1, 1, 0.7);
	glutSolidCone(1, 1, 25, 25);
	glPopMatrix();
	glPopMatrix();

	


}
void cTree::Update()
{

}
void cTree::Mouse(int button, int state, int x, int y)
{
}
