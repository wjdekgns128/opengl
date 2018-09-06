#include "cEndObject.h"

cEndObject::cEndObject()
{
	m_type = END;
	m_Vector = cVector(0, 0, 0);
	m_angle = 0;
	/*GLfloat dirVector0[] = { 0.0, 1, 0, 0.0 };
	GLfloat qaDiffuseLight[] = { RGBFloat(255), RGBFloat(255), RGBFloat(255), 1.0 };
	GLfloat dirVecto1r0[] = { RGBFloat(255), RGBFloat(255), RGBFloat(255), 1.0 };
	glLightfv(GL_LIGHT0, GL_AMBIENT, dirVecto1r0);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 1);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 30.0);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dirVector0);*/
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
	glTranslatef(m_Vector.x, m_Vector.y, m_Vector.z );
	glutWireCube(2);
	glPopMatrix();

	


}
void cEndObject::Update(float time)
{
	UpdateOpenning(time);

}