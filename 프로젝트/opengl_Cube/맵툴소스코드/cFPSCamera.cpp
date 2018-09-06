#include "cFPSCamera.h"

cFPSCamera::cFPSCamera()
{
	SetEye(0, 0, 0);
	SetUp(0, 1, 0);
	m_xAngle = 0;
	m_yAngle = 0;
	m_xSpeed = 0;
	m_zSpeed = 0;
	m_DisAngle = 0;
}
cFPSCamera::~cFPSCamera()
{

}
void cFPSCamera::Update()
{
	//static int number = 0;
		cVector MoveVectorTemp(cos(m_xAngle)*cos(m_yAngle), sin(m_yAngle), sin(m_xAngle)*cos(m_yAngle));
		m_CamLook = MoveVectorTemp;
		MoveZ(MoveVectorTemp);
		MoveX();
		glLoadIdentity();
		glMatrixMode(GL_MODELVIEW);
		gluLookAt(m_CamEye.x, m_CamEye.y, m_CamEye.z, m_CamEye.x + m_CamLook.x, m_CamEye.y + m_CamLook.y, m_CamEye.z + m_CamLook.z, m_CamUp.x, m_CamUp.y, m_CamUp.z);
		glTranslatef(5, 0, 5);
		glRotatef(m_DisAngle, 0, 1, 0);
		glTranslatef(-5, 0, -5);

		//number++;
}
void cFPSCamera::MoveZ(cVector temp)
{
	m_CamEye = m_CamEye + temp * m_zSpeed ;
}
void cFPSCamera::MoveX()
{
	m_CamEye.x = m_CamEye.x + m_xSpeed*cos(m_xAngle - M_PI/2);
	m_CamEye.z = m_CamEye.z + m_xSpeed*sin(m_xAngle - M_PI / 2);
}
