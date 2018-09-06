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
	glPushMatrix();
	glColor3f(25.0/255.0, 40.0/255.0, 105.0/255.0);
	glTranslatef(m_Vector.x + 1, m_Vector.y + 1, m_Vector.z + 1);
	glutSolidCube(2);
	glPopMatrix();

}
void cHardWallObject::Update()
{

}