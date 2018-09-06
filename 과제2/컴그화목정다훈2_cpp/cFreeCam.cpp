#include "cFreeCam.h"

cFreeCam::cFreeCam()
{
}
cFreeCam::~cFreeCam()
{
}
void cFreeCam::Update()
{
	glutWarpPointer(m_windowsX / 2, m_windowsY / 2);
	cVector MoveVectorTemp(cos(m_xAngle)*cos(m_yAngle), sin(m_yAngle), sin(m_xAngle)*cos(m_yAngle));
	m_CamLook = MoveVectorTemp;
	MoveZ(MoveVectorTemp);
	MoveX();
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(m_CamEye.x, m_CamEye.y, m_CamEye.z, m_CamEye.x + m_CamLook.x, m_CamEye.y + m_CamLook.y, m_CamEye.z + m_CamLook.z, m_CamUp.x, m_CamUp.y, m_CamUp.z);
	/*glTranslatef(5, 0, 5);
	glRotatef(g_Angle, 0, 1, 0);
	glTranslatef(-5, 0, -5);*/
	//MathAngleEye();
	//printf("%f %f %f %f %f %f %f %f\n", m_CamEye.x, m_CamEye.y, m_CamEye.z, m_CamLook.x, m_CamLook.y, m_CamLook.z, m_xAngle, m_yAngle);
}
void cFreeCam::MoveZ(cVector temp)
{
	float y = m_CamEye.y; // y축은 고정
	m_CamEye = m_CamEye + temp * m_zSpeed;
	if (m_CamEye.y < 10)
		m_CamEye.y = 10;
}
void cFreeCam::MoveX()
{
	m_CamEye.x = m_CamEye.x + m_xSpeed*cos(m_xAngle - M_PI / 2);
	m_CamEye.z = m_CamEye.z + m_xSpeed*sin(m_xAngle - M_PI / 2);
}
void cFreeCam::KeyBoard(int Type, unsigned char key)
{
	if (Type == KEYBOARDDOWN)
	{

		if (key == 'w')
		{
			SetzSpeed(5);
		}
		if (key == 's')
		{
			SetzSpeed(-5);
		}
		if (key == 'a')
		{
			SetxSpeed(5);
		}
		if (key == 'd')
		{
			SetxSpeed(-5);
		}
		if (key == 'y')
			SetY(GetEye().y + 5);
		if (key == 'Y')
			SetY(GetEye().y - 5);
	}
	else
	{
		if (key == 'w' || key == 's')
		SetzSpeed(0);
		if (key == 'a' || key == 'd')
			SetxSpeed(0);
	}
}
