#include "cShow.h"


void cShow::Render()
{

	for (int i = 0; i < m_pObjects.size(); i++)
	{
		if (m_pObjects[i]->m_state == 1)
		{
			glPushMatrix();
			glColor4f(m_pObjects[i]->m_Color.x, m_pObjects[i]->m_Color.y, m_pObjects[i]->m_Color.z, m_pObjects[i]->m_Api);

			glTranslatef(m_pObjects[i]->m_pVector.x, m_pObjects[i]->m_pVector.y, m_pObjects[i]->m_pVector.z);
			glRotatef(-90, 1, 0, 0);

			glutSolidCone(4, 6,15, 15);
			glPopMatrix();

		}
	}
}
void cShow::Update(float _time)
{
	MakeTime += _time;

	if (MakeTime >= CreateTime)
	{
		MakeTime = 0;
		int randr = rand() % 8 + 1;
		for (int i = 0; i < randr;i++ )
		CreateObject();
	}

	for (int i = 0; i < m_pObjects.size(); i++)
	{
		if (m_pObjects[i]->m_state == 1)
		{
			m_pObjects[i]->m_pVector= m_pObjects[i]->m_pVector - m_pObjects[i]->m_Speed;
			m_pObjects[i]->m_dietimecheck += _time;
			if (m_pObjects[i]->m_dietimecheck >= m_pObjects[i]->m_dietime || m_pObjects[i]->m_pVector.y < -5 || m_pObjects[i]->m_Api <= 0.0)
			{
				m_pObjects[i]->m_dietimecheck = 0.0;
				m_pObjects[i]->m_state = 0;
			}
		}
		else
			m_pObjects.erase(m_pObjects.begin()+i);
	}
}
void cShow::CreateObject()
{
	int x = randomRange((int)m_RandomMin.x, (int)m_RandomMax.x);
	int y = randomRange((int)m_RandomMin.y, (int)m_RandomMax.y);
	int z = randomRange((int)m_RandomMin.z, (int)m_RandomMax.z);

	object* Temp = new object;
	Temp->m_Speed = cVector(0,rand() % 4 + 2, 0);
	Temp->m_pVector = cVector(x, y, z);
	Temp->m_Api = 1.0f;
	Temp->m_Color = cVector(1, 1, 1);
	Temp->m_state = 1;
	Temp->m_dietime = m_dirtime;
	Temp->m_dietimecheck = 0.0;
	m_downapl =  (1.0 / m_dirtime) * 0.05;
	m_pObjects.insert(m_pObjects.begin(),Temp);

}