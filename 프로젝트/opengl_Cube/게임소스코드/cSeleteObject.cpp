
#include "cSeleteObject.h"
#include "cMapClear.h"
#include "cMapLoad.h"
cSeleteObject::cSeleteObject(float angle, int seletenumber)
{
	m_MathAngle = 0;
	m_NowAngle = 0;
	m_Dir = true;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int z = 0; z < 5; z++)
				m_pppObject[j][i][z] = NULL;
		}
	}
	m_angle = angle;
	m_SeleteNumber = seletenumber;
	m_YCount = GETLOAD->GetYCount(seletenumber);
	m_NowClearCount = GETCLEAR->GetClearCount(seletenumber);
	for (int i = 0; i < m_YCount; i++)
	{
		for (int x = 0; x < 5; x++)
		{
			for (int z = 0; z < 5; z++)
			{
				int type = GETLOAD->GetData(seletenumber, x, i, z);
				switch (type)
				{
				case START:
					m_pppObject[x][i][z] = new cStartObject(cVector(x * 2, i * 2, z * 2));
					break;
				case END:
					m_pppObject[x][i][z] = new cEndObject(cVector(x * 2, i * 2, z * 2));

					break;
				case WALL:
					m_pppObject[x][i][z] = new cWallObject(cVector(x * 2, i * 2, z * 2));
					break;
				case EMPTY:
					m_pppObject[x][i][z] = new cEmptyObject(cVector(x * 2, i * 2, z * 2));
					break;
				case HARDWALL:
					m_pppObject[x][i][z] = new cHardWallObject(cVector(x * 2, i * 2, z * 2));
					break;
				case PORTAL:
					m_pppObject[x][i][z] = new cPortalObject(cVector(x * 2, i * 2, z * 2));

					break;
				}

				m_pppObject[x][i][z]->m_LineLight = false;
			}
		}

	}
}
void cSeleteObject::Render()
{
	for (int i = 0; i < m_YCount; i++)
	{
		glPushMatrix();
		glTranslatef(30, 0, 30);
		glRotatef(m_angle, 0, 1, 0);
		glTranslatef(-30, 0, -30);
		glPushMatrix();
		glTranslatef(5, 5, 5);
		glRotatef(m_NowAngle, 0, 1, 0);
		glTranslatef(-5, -5, -5);
		for (int x = 0; x < 5; x++)
		{
			for (int z = 0; z < 5; z++)
			{
				if (m_pppObject[x][i][z] != NULL)
				{

					m_pppObject[x][i][z]->Render();

				}
			}
		}
		glPopMatrix();
		glPopMatrix();

	}
}
void cSeleteObject::Update()
{
	if (m_MathAngle != 0)
	{
		if (m_Dir)
			m_angle += m_plueAngle;
		else
			m_angle -= m_plueAngle;
		m_MathAngle -= m_plueAngle;
		if (m_MathAngle < 0)
			m_MathAngle = 0;
			 
	}
}