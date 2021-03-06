#include "c3rdCam.h"


c3rdCam::~c3rdCam()
{
}
void c3rdCam::Update()
{
	glutWarpPointer(m_windowsX / 2, m_windowsY / 2);

	cVector MoveVectorTemp(cos(m_xAngle)*cos(m_yAngle), sin(m_yAngle), sin(m_xAngle)*cos(m_yAngle));
	m_CamLook = MoveVectorTemp;
	MoveZ(MoveVectorTemp);
	MoveX();
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(m_CamEye.x, m_CamEye.y, m_CamEye.z, m_CamEye.x + m_CamLook.x, m_CamEye.y + m_CamLook.y, m_CamEye.z + m_CamLook.z, m_CamUp.x, m_CamUp.y, m_CamUp.z);
	//printf("%f %f %f %f %f %f %f %f\n", m_CamEye.x, m_CamEye.y, m_CamEye.z, m_CamLook.x, m_CamLook.y, m_CamLook.z, m_xAngle, m_yAngle);

}
void c3rdCam::MoveZ(cVector temp)
{
	float y = m_CamEye.y; // y���� ����
	m_CamEye = m_CamEye + temp * m_zSpeed;
	if (m_CamEye.y < 1)
		m_CamEye.y = 1;
}

void c3rdCam::MoveX()
{
	m_CamEye.x = m_CamEye.x + m_xSpeed*cos(m_xAngle - M_PI / 2);
	m_CamEye.z = m_CamEye.z + m_xSpeed*sin(m_xAngle - M_PI / 2);

}
void c3rdCam::KeyBoard(int Type, unsigned char key)
{
	
}
