#include "cPortalObject.h"
cPortalObject::cPortalObject()
{
	m_type = PORTAL;
	m_Vector = cVector(0, 0, 0);
	m_angle = 0;
	m_r = 0.0;
	m_Moveing = true;
}
cPortalObject::cPortalObject(cVector vector)
{
	m_type = PORTAL;
	m_Vector = vector;
	m_angle = 0;
	m_Moveing = true;
	m_r = 0.0;
}
cPortalObject::~cPortalObject()
{

}
void cPortalObject::Render()
{
	if (m_Moveing)
	{
		glPushMatrix();
		glColor3f(0.5, 1, 1);
		glTranslatef(5, 0, 5);
		glRotatef(m_angle, 0, 1, 0);
		glTranslatef(-5, 0, -5);
		m_r += 1;
		glTranslatef(m_Vector.x , m_Vector.y , m_Vector.z );
		glRotatef(m_r, 0, 1, 0);

		//glutSolidSphere(1,15,15);
		glutSolidTorus(0.1, 0.7, 15, 15);
		glutSolidTorus(0.05, 0.4, 15, 15);
		glutSolidTorus(0.03, 0.1, 15, 15);

		glPopMatrix();

	}
	else
	{

	}

}
void cPortalObject::Update(float time)
{
	UpdateOpenning(time);

}