#include "cParticleBase.h"

cParticleBase::cParticleBase()
{
	m_vObject.clear();
	m_deletecheck = false;
	m_check = true;
}
cParticleBase::~cParticleBase()
{

}

void	cParticleBase::Setting(int max,int x ,int y ,int z)
{

	for (int i = 0; i < max;i++)
	{
			cParticleObject Temp;
			Temp.Setting(0, cVector(x * 2 + 1, y * 2 + 1, z * 2 + 1),cVector(0.1 , 0.05, 0.1), cVector(0.2, 0.15, 0.2), 3);
			m_vObject.push_back(Temp);
	}
}
void		cParticleBase::Start()
{
	for (int i = 0; i < m_vObject.size(); i++)
	{
		m_vObject[i].Start();
		m_deletecheck = true;
		m_check = true;
	}
}
void cParticleBase::Update(float time)
{
	if (m_check == false)
		return;
	for (int i = 0; i < m_vObject.size(); i++)
	{

		m_vObject[i].Update(time);
		if (m_deletecheck)
		{
			m_check = m_vObject[i].GetState();
		}
	}
	if (m_check == false) {
		m_vObject.clear();
	}
}
void cParticleBase::Render()
{

	for (int i = 0; i < m_vObject.size(); i++)
	{
		
		m_vObject[i].Render();
		
	}
}