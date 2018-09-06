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
	glTranslatef(m_Vector.x, m_Vector.y, m_Vector.z);

	/*GLfloat matrixMV[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, matrixMV);
	printf("%f %f %f\n", matrixMV[12], matrixMV[13], matrixMV[14]);*/

	glutWireCube(2);
	glPopMatrix();

}
void cStartObject::Update(float time)
{
	UpdateOpenning(time);

}