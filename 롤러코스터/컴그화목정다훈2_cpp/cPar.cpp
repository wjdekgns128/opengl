#include "cPar.h"


void cPar::Render()
{
	
	for (int i = 0; i < m_pObjects.size(); i++)
	{
		if (m_pObjects[i]->m_state == 1)
		{
			glPushMatrix();
			glColor4f(m_pObjects[i]->m_Color.x, m_pObjects[i]->m_Color.y, m_pObjects[i]->m_Color.z, m_pObjects[i]->m_Api);
			glTranslatef(m_pObjects[i]->m_pVector.x, m_pObjects[i]->m_pVector.z, m_pObjects[i]->m_pVector.y);
			glutSolidCube(2);
			glPopMatrix();

		}
	}
}
void cPar::Update(float _time)
{
	for (int i = 0; i < m_pObjects.size(); i++)
	{
		if (m_pObjects[i]->m_state == 1)
		{
			m_pObjects[i]->m_pVector = m_pObjects[i]->m_pVector - m_pObjects[i]->m_Speed;
			m_pObjects[i]->m_Api -= m_downapl;
			if ( m_pObjects[i]->m_Api <= 0.0)
			{
				m_pObjects[i]->m_state = 0;
			}
		}
		else
			m_pObjects.erase(m_pObjects.begin() + i);
	}
}
void cPar::CreateObject()
{
	int x = randomRange((int)m_RandomMin.x, (int)m_RandomMax.x);
	int y = randomRange((int)m_RandomMin.y, (int)m_RandomMax.y);
	int z = randomRange((int)m_RandomMin.z, (int)m_RandomMax.z);

	object* Temp = new object;
	int typ = rand() % 2;
	Temp->m_Speed = cVector((rand() % 4 + 1), (rand() % 4 + 1), (rand() % 4 + 1));
	if (typ == 1)
		Temp->m_Speed = Temp->m_Speed  * -1;
	Temp->m_pVector = cVector(x, y, z);
	Temp->m_Api = 1.0f;
	Temp->m_Color = cVector((rand()%255)/255.0, (rand() % 255) / 255.0, (rand() % 255) / 255.0);
	Temp->m_state = 1;
	Temp->m_dietime = m_dirtime;
	Temp->m_dietimecheck = 0.0;
	m_downapl = (1.0 / m_dirtime) * 0.035;
	m_pObjects.insert(m_pObjects.begin(), Temp);

}