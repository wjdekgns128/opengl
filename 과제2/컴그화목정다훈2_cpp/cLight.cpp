#include "cLight.h"
#include <stdio.h>

cLight::cLight()
{

	
	ReSetting();

}
cLight::~cLight()
{

}
void cLight::Update()
{
	if (m_state == 0)
	{
		for (int i = 0; i < 3; i++)
		{
			AmbientLight[i] -= 0.0004;

		}

		if (AmbientLight[0] < 0)
		{
			m_state = 1;
			AmbientLight[0] = 0;
			AmbientLight[1] = 0.;
			AmbientLight[2] = 0;

		}
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			AmbientLight[i] += 0.0004;
		}
		if (AmbientLight[0] > MaxF)
		{
			m_state = 0;
			AmbientLight[0] = MaxF;
			AmbientLight[1] = MaxF;
			AmbientLight[2] = MaxF;
		}
	}
}
void cLight::Render()
{
	glPushMatrix();
	glColor3f(1, 0.2, 0.2);
	glRotatef(m_nube, 0, 0, 1);
	glTranslatef(0, 1300, 0);
	glutSolidSphere(70,15,15);
	glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight);
	glPopMatrix();

	glPushMatrix();
	glColor3ub(128, 128, 192);
	glRotatef(  m_nube1, 0, 0, 1);
	glTranslatef(0, 1400, 0);
	glutSolidSphere(65, 15, 15);

	glPopMatrix();

	m_nube += Speed;
	m_nube1 += Speed1;
	if (m_nube > 105)
		m_nube = -105;
	if (m_nube1 > 105)
		m_nube1 = -105;

}