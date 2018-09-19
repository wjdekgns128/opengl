#include "cFpsCam.h"


cFpsCam::~cFpsCam()
{
}
void cFpsCam::Update()
{
	//m_CamEye = m_CamLook + cVector(m_Dir.x * cos(m_xAngle), m_Dir.y, m_Dir.z * sin(m_xAngle));
	glLoadIdentity();
	glMatrixMode(GL_MODELVIEW);
	gluLookAt(m_CamEye.x , m_CamEye.y , m_CamEye.z , m_CamLook.x, m_CamLook.y, m_CamLook.z, m_CamUp.x, m_CamUp.y, m_CamUp.z);
}
void cFpsCam::MoveZ(cVector temp)
{


}
void cFpsCam::MoveX()
{


}
void cFpsCam::KeyBoard(int Type, unsigned char key)
{

}
