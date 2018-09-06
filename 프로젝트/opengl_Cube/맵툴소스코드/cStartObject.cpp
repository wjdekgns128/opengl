#include "cStartObject.h"

cStartObject::cStartObject()
{
	m_type = START;
	m_Vector = cVector(0, 0, 0);
	m_angle = 0;

}
cStartObject::cStartObject(cVector vector)
{
	m_type = START;
	m_Vector = vector;
	m_angle = 0;

}
cStartObject::~cStartObject()
{

}
void cStartObject::Render()
{
	glPushMatrix();
	glColor3f(0, 1, 0);
	glTranslatef(5, 0, 5);
	glRotatef(m_angle, 0, 1, 0);
	glTranslatef(-5, 0, -5);
	glTranslatef(m_Vector.x+1, m_Vector.y+1, m_Vector.z+1);
	glutWireCube(2);
	glPopMatrix();

}
void cStartObject::Update()
{

}