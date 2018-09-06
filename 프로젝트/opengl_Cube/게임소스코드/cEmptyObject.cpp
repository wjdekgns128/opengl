#include "cEmptyObject.h"
cEmptyObject::cEmptyObject()
{
	m_type = EMPTY;
	m_Vector = cVector(0, 0, 0);
	m_angle = 0;


}
cEmptyObject::cEmptyObject(cVector vector)
{
	m_type = EMPTY;
	m_Vector = vector;
	m_angle = 0;

}
cEmptyObject::~cEmptyObject()
{

}
void cEmptyObject::Render()
{
	
	glPushMatrix();
	//glEnable(GL_BLEND);
	//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//glColor4f(1, 0, 1,1);
	
	glTranslatef(m_Vector.x, m_Vector.y , m_Vector.z);
	//glutWireCube(2);

	
	glPopMatrix();

}
void cEmptyObject::Update(float time)
{

}