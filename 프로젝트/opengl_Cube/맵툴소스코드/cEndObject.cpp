#include "cEndObject.h"

cEndObject::cEndObject()
{
	m_type = END;
	m_Vector = cVector(0, 0, 0);
	m_angle = 0;

}
cEndObject::cEndObject(cVector vector)
{
	m_type = END;
	m_Vector = vector;
	m_angle = 0;

}
cEndObject::~cEndObject()
{

}
void cEndObject::Render()
{
	glPushMatrix();
	glColor3f(1, 0, 0);
	glTranslatef(5, 0, 5);
	glRotatef(m_angle, 0, 1, 0);
	glTranslatef(-5, 0, -5);
	glTranslatef(m_Vector.x + 1, m_Vector.y + 1, m_Vector.z + 1);
	glutWireCube(2);
	glPopMatrix();

}
void cEndObject::Update()
{

}