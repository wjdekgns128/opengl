#include "cLogoObject.h"

cLogoObject::cLogoObject()
{
	m_ScaleNumber = 0.99;
	t = 0;
	m_Type = 0;
	speed = 0;
	FrameTime = 0;
	CreateTime = rand()% 1501;
	CreateTime *= 0.001;
	m_Color[0][0] = 1;
	m_Color[0][1] = 1;
	m_Color[0][2] = 1;

	m_Color[1][0] = 1;
	m_Color[1][1] = 0;
	m_Color[1][2] = 0;

	m_Color[2][0] = 40.04/255.0;
	m_Color[2][1] = 30.0 / 255.0;
	m_Color[2][2] = 1;

	m_Color[3][0] = 0;
	m_Color[3][1] = 255.0 / 255.0;
	m_Color[3][2] = 128.0/255.0;
	m_EventType = 0;
	m_EventChage = false;
}
cLogoObject::~cLogoObject()
{

}
void cLogoObject::Render()
{
	
	glPushMatrix();
	glColor3f(m_Color[m_Type][0], m_Color[m_Type][1], m_Color[m_Type][2]);
	/*glTranslatef(0, -5, 0);
	glRotatef(m_angle, 0, 0, 1);
	glTranslatef(0, 5, 0);*/



	

	glTranslatef(m_postion.x, m_postion.y, m_postion.z);

	glScalef(0.5, m_ScaleNumber, m_ScaleNumber);

	if (m_EventChage == false)
		glutWireCube(1);
	else
		glutSolidCube(1);
	/*glTranslatef(m_postion.x, m_postion.y, m_postion.z);
	glScalef(1, m_ScaleNumber, m_ScaleNumber);
	glTranslatef(-m_postion.x, -m_postion.y, -m_postion.z);*/
	//glutSolidCube (1);

	glPopMatrix();
}
void cLogoObject::Update(float time)
{

	if (m_EventType == 0)
	{
		FrameTime += time;
		if (FrameTime > CreateTime)
		{
			speed += time * 0.5;
			m_postion.x += speed;

			if (m_postion.x >= m_x)
			{
				m_postion.x = m_x;
				m_EventType = 1;
				FrameTime = 0;
			}
		}
	}
	else if (m_EventType == 2)
	{
		FrameTime += time;
		if (FrameTime > m_EffectTime)
		{
			m_EventType = 3;
			FrameTime = 0;
			m_EventChage = true;	
		}
	}
	else if (m_EventType == 3)
	{
		if (t == 0)
		{
			m_ScaleNumber += 0.05;
			if (m_ScaleNumber > 1.25)
			{
				m_ScaleNumber =1.25;
				t++;
				
			}
		}
		else if(t== 1)
		{
			m_ScaleNumber -= 0.05;
			if (m_ScaleNumber < 0.99)
			{
				m_ScaleNumber = 0.99;
				t++;
				if (t == 2)
					m_EventType = 4;
			}
		}
	}
	
}