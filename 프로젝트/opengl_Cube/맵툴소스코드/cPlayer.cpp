#include "cPlayer.h"
#include <stdio.h>
cPlayer::cPlayer()
{
	m_pVector = cVector(0, 0, 0);
	m_SettingVetor = cVector(0, 0, 0);
	m_state = 0;
	m_angle = 0;
}
cPlayer::cPlayer(cVector temp)
{
	m_pVector = temp;
	m_SettingVetor = temp;
	m_state = 0;
}
cPlayer::~cPlayer()
{

}
void cPlayer::Render()
{
	if (m_state == 0)
		return;
	glPushMatrix();
	glColor3f(0, 0, 1);
	glTranslatef(m_SettingVetor.x, m_SettingVetor.y, m_SettingVetor.z);
	glutSolidSphere(0.7, 15, 15);
	glLoadIdentity();
	glTranslatef(5, 0, 5);
	glRotatef(m_angle, 0, 1, 0);
	glTranslatef(-5, 0, -5);
	glTranslatef(m_pVector.x + 1, m_pVector.y + 2.1, m_pVector.z + 1);
	GLfloat matrixMV[16];
	glGetFloatv(GL_MODELVIEW_MATRIX, matrixMV);
	m_SettingVetor.x = matrixMV[12];
	m_SettingVetor.y =matrixMV[13];
	m_SettingVetor.z = matrixMV[14];

	glPopMatrix();
}