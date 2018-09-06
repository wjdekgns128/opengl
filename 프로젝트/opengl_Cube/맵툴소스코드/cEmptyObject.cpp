#include "cEmptyObject.h"
cEmptyObject::cEmptyObject(float n)
{
	m_type = EMPTY;
	m_Vector = cVector(0, 0, 0);
	m_apl = n;
	m_angle = 0;


}
cEmptyObject::cEmptyObject(cVector vector,float n)
{
	m_type = EMPTY;
	m_apl = n;
	m_Vector = vector;
	m_angle = 0;

}
cEmptyObject::~cEmptyObject()
{

}
void cEmptyObject::Render()
{
	if (m_apl <= 0.1)
		return;
	glPushMatrix();
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4f(1, 0, 1,m_apl);
	glTranslatef(5, 0, 5);
	glRotatef(m_angle, 0, 1, 0);
	glTranslatef(-5, 0, -5);
	glTranslatef(m_Vector.x + 1, m_Vector.y + 1, m_Vector.z + 1);
	glutWireCube(2);

	
	glPopMatrix();

}
void cEmptyObject::Update()
{

}