#include "cHardWallObject.h"
cHardWallObject::cHardWallObject()
{
	m_type = HARDWALL;
	m_Vector = cVector(0, 0, 0);
}
cHardWallObject::cHardWallObject(cVector vector)
{
	m_type = HARDWALL;
	m_Vector = vector;

}
cHardWallObject::~cHardWallObject()
{

}
void cHardWallObject::Render()
{
	RenderObject();
	if (m_LineLight)
	glDisable(GL_LIGHTING);
	glPushMatrix();
	glLineWidth(0.05);
	glColor3ub(80, 80, 80);
	glTranslatef(m_Vector.x, m_Vector.y, m_Vector.z);
	glutWireCube(1.99);
	glPopMatrix();
	if (m_LineLight)
	glEnable(GL_LIGHTING);
}
void cHardWallObject::RenderObject()
{
#pragma region _RENDEROBJECT_
	glPushMatrix();
	glColor3ub(47, 52, 59);

	glNormal3f(0, 0, -1);
	glBegin(GL_QUADS);
	glVertex3f(m_Vector.x - 0.99, m_Vector.y - 0.99, m_Vector.z - 0.99);
	glVertex3f(m_Vector.x + 0.99, m_Vector.y - 0.99, m_Vector.z - 0.99);
	glVertex3f(m_Vector.x + 0.99, m_Vector.y + 0.99, m_Vector.z - 0.99);
	glVertex3f(m_Vector.x - 0.99, m_Vector.y + 0.99, m_Vector.z - 0.99);


	glEnd();


	glNormal3f(0, 0, 1);

	glBegin(GL_QUADS);
	glVertex3f(m_Vector.x - 0.99, m_Vector.y - 0.99, m_Vector.z + 0.99);
	glVertex3f(m_Vector.x + 0.99, m_Vector.y - 0.99, m_Vector.z + 0.99);
	glVertex3f(m_Vector.x + 0.99, m_Vector.y + 0.99, m_Vector.z + 0.99);
	glVertex3f(m_Vector.x - 0.99, m_Vector.y + 0.99, m_Vector.z + 0.99);


	glEnd();
	glNormal3f(0, 1, 0);

	glBegin(GL_QUADS);
	glVertex3f(m_Vector.x - 0.99, m_Vector.y + 0.99, m_Vector.z - 0.99);
	glVertex3f(m_Vector.x + 0.99, m_Vector.y + 0.99, m_Vector.z - 0.99);
	glVertex3f(m_Vector.x + 0.99, m_Vector.y + 0.99, m_Vector.z + 0.99);
	glVertex3f(m_Vector.x - 0.99, m_Vector.y + 0.99, m_Vector.z + 0.99);


	glEnd();
	glNormal3f(0, -1, 0);

	glBegin(GL_QUADS);
	glVertex3f(m_Vector.x - 0.99, m_Vector.y - 0.99, m_Vector.z - 0.99);
	glVertex3f(m_Vector.x + 0.99, m_Vector.y - 0.99, m_Vector.z - 0.99);
	glVertex3f(m_Vector.x + 0.99, m_Vector.y - 0.99, m_Vector.z + 0.99);
	glVertex3f(m_Vector.x - 0.99, m_Vector.y - 0.99, m_Vector.z + 0.99);


	glEnd();
	glNormal3f(1, 0, 0);

	glBegin(GL_QUADS);
	glVertex3f(m_Vector.x + 0.99, m_Vector.y + 0.99, m_Vector.z - 0.99);
	glVertex3f(m_Vector.x + 0.99, m_Vector.y + 0.99, m_Vector.z + 0.99);
	glVertex3f(m_Vector.x + 0.99, m_Vector.y - 0.99, m_Vector.z + 0.99);
	glVertex3f(m_Vector.x + 0.99, m_Vector.y - 0.99, m_Vector.z - 0.99);


	glEnd();
	glNormal3f(-1, 0, 0);


	glBegin(GL_QUADS);
	glVertex3f(m_Vector.x - 0.99, m_Vector.y + 0.99, m_Vector.z - 0.99);
	glVertex3f(m_Vector.x - 0.99, m_Vector.y + 0.99, m_Vector.z + 0.99);
	glVertex3f(m_Vector.x - 0.99, m_Vector.y - 0.99, m_Vector.z + 0.99);
	glVertex3f(m_Vector.x - 0.99, m_Vector.y - 0.99, m_Vector.z - 0.99);


	glEnd();
	glPopMatrix();

#pragma endregion

}

void cHardWallObject::Update(float time)
{
	UpdateOpenning(time);

}