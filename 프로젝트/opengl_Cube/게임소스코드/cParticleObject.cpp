#include "cParticleObject.h"

cParticleObject::cParticleObject()
{

}
cParticleObject::~cParticleObject()
{

}
void cParticleObject::Update(float time)
{
	if (m_state == false)
		return;
	m_Postion = m_Postion+  m_Speed;
	m_Apl -= m_DownApl;
	if (m_Apl <= 50)
	{
		m_Apl = 0;
		m_state = false;
	}
}
void cParticleObject::Render()
{
	if (m_state == false)
		return;

	glPushMatrix();
	

	glTranslatef(m_Postion.x, m_Postion.y, m_Postion.z);
	glColor4ub(m_Color.x, m_Color.y, m_Color.z, m_Apl);
	if (m_type == 0)
		glutSolidCube(m_scale);
	else
		glutSolidSphere(m_scale, 15, 15);

	glPopMatrix();

}