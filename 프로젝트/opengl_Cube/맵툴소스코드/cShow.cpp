#include "cShow.h"

cShow::cShow(int _nowy)
{
	m_NowY = _nowy;
}
cShow::~cShow()
{

}
void cShow::Redner()
{
	glLineWidth(5);
	glPushMatrix();
	glColor3f(0, 1, 1);
	glScalef(10, 2, 10);
	glTranslatef(0.5,  m_NowY  + 0.5, 0.5);

	glutWireCube(1);
	glPopMatrix();
	glLineWidth(1);

}