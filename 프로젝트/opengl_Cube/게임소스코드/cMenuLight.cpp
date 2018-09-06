#include "cMenuLight.h"

cMenuLight::cMenuLight()
{
	m_Dir = true;
	m_YDir = true;

	m_Vector = cVector(-5, 4.5, -6);
	CreateType();
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);
	GLfloat ambientLight[4];
	glMateriali(GL_FRONT, GL_SHININESS, 128);
	ambientLight[0] = RGBFloat(0);
	ambientLight[1] = RGBFloat(0);
	ambientLight[2] = RGBFloat(0);
	ambientLight[3] = 1;
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);

	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}
cMenuLight::~cMenuLight()
{
	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_BLEND);
}
void cMenuLight::Render()
{
	glPushMatrix();
	glTranslatef(m_Vector.x, m_Vector.y, m_Vector.z);
	GLfloat qaLightPosition1[] = { 0,0,0, 1 };
	GLfloat dirVector1[] = { 1, 0, 0, 0.0 };
	GLfloat color1[] = { 1,1,1,1 };
	glLightfv(GL_LIGHT0, GL_SPECULAR, color1);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, color1);
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition1);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dirVector1);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 3.0);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 25);
	glPopMatrix();
}
void cMenuLight::Update(float time)
{
	if (!m_WaitIng)
	{
			
		if (m_Dir)
		{
			m_Vector.z += m_MoveSpeed.z;
			m_Vector.x += m_MoveSpeed.x;
			if (m_Vector.z > 6)
			{
				m_Vector.z = 6;
				m_Dir = false;
				CreateType();
			}
		}
		else
		{
			m_Vector.z -= m_MoveSpeed.z;
			m_Vector.x -= m_MoveSpeed.x;

			if (m_Vector.z < -6)
			{
				m_Vector.z = -6;
				m_Dir = true;
				CreateType();
			}
		}
	}
	if (m_MoveSpeed.y > 0.0)
	{
		if (m_YDir)
		{
			m_Vector.y -= m_MoveSpeed.y;
			if (m_Vector.y < 3)
			{
				m_Vector.y = 3;
				m_YDir = !m_YDir;
			}
		}
		else
		{
			m_Vector.y += m_MoveSpeed.y;
			if (m_Vector.y > 6.5)
			{
				m_Vector.y = 6.5;
				m_YDir = !m_YDir;
			}
		}
	}
	else if (m_WaitTime[0] > 0.0)
	{
		m_TempWaitTime += time;
		if (m_TempWaitTime > m_WaitTime[m_WaitIng])
		{
			m_TempWaitTime = 0;
			m_WaitIng = !m_WaitIng;
		}
	}
	
	
}