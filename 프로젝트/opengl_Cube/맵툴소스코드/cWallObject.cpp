#include "cWallObject.h"
cWallObject::cWallObject()
{
	m_type = WALL;
	m_Vector = cVector(0, 0, 0);
	m_angle = 0;

}
cWallObject::cWallObject(cVector vector)
{
	m_type = WALL;
	m_Vector = vector;
	m_angle = 0;
}
cWallObject::~cWallObject()
{

}
void cWallObject::Render()
{
	glPushMatrix();
	glColor3f(1, 1, 1);
	glTranslatef(5, 0, 5);
	glRotatef(m_angle, 0, 1, 0);
	glTranslatef(-5, 0, -5);
	glTranslatef(m_Vector.x + 1, m_Vector.y + 1, m_Vector.z + 1);
	glutSolidCube(2);

	
	glPopMatrix();
}
void cWallObject::Update()
{

}