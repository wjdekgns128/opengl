#include "cCam.h"

cCam::cCam()
{
	SetEye(0, 0, 0);
	SetUp(0, 1, 0);
	m_xAngle = ToRadian(90);
	m_yAngle = 0;
	m_xSpeed = 0;
	m_zSpeed = 0;
	m_windowsX = 0;
	m_windowsY = 0;
}
cCam::~cCam()
{

}
void cCam::Update()
{
}
