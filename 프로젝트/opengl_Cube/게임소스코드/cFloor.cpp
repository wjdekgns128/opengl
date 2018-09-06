#include "cFloor.h"

cFloor::cFloor(int num)
{
	m_mynumber = num;
	ReSetting();
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			m_pObject[i][j] = NULL;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			m_pParticleBase[i][j] = new cParticleBase();

		}
	}
}
cFloor::~cFloor()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
			SAFE_DELETE(m_pObject[i][j]);
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			SAFE_DELETE(m_pParticleBase[i][j]);


		}
	}

}
void cFloor::SettingObject(int x, int z, int type)
{
	SAFE_DELETE(m_pObject[x][z]);

	switch (type)
	{
	case START:
		m_pObject[x][z] = new cStartObject(cVector(x * 2 + 1, m_mynumber * 2 + 1, z * 2 + 1));
		break;
	case END:
		m_pObject[x][z] = new cEndObject(cVector(x * 2 + 1, m_mynumber * 2 + 1, z * 2 + 1));
		
		break;
	case WALL:
		m_pObject[x][z] = new cWallObject(cVector(x * 2 + 1, m_mynumber * 2 + 1, z * 2 + 1));
		break;
	case EMPTY:
		m_pObject[x][z] = new cEmptyObject(cVector(x * 2 + 1, m_mynumber * 2 + 1, z * 2 + 1));
		break;
	case HARDWALL:
		m_AngleCheck = false;
		m_pObject[x][z] = new cHardWallObject(cVector(x * 2 + 1, m_mynumber * 2 + 1, z * 2 + 1));
		break;
	case PORTAL:
		m_pObject[x][z] = new cPortalObject(cVector(x * 2 + 1, m_mynumber * 2 + 1, z * 2 + 1));
		cPortalObject* temp = (cPortalObject*)m_pObject[x][z];
		temp->m_Moveing = m_Moveing;
		break;
	}


}
void cFloor::Render()
{
	 if(m_BoomType != 2 && m_BoomType != 3)
	{
		glPushMatrix();
		glTranslatef(5, 0, 5);
		glRotatef(m_RealAngle, 0, 1, 0);
		glTranslatef(-5, 0, -5);
		
		//GLfloat matrixMV[16];
		//glGetFloatv(GL_MODELVIEW_MATRIX, matrixMV);
		//printf("%f %f %f\n", matrixMV[12], matrixMV[13], matrixMV[14]);

		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (m_pObject[i][j] != NULL)
				{

					m_pObject[i][j]->Render();
				}

			}
		}
		glPopMatrix();
	}
	else if(m_BoomType == 2)
	{
		glShadeModel(GL_SMOOTH);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				m_pParticleBase[i][j]->Render();
			}
		}
		glDisable(GL_BLEND);

	}

}
void cFloor::Update(float time)
{
	if (m_BoomType == 1)
	{
			m_BoomType = 2;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					m_pParticleBase[i][j]->Setting(rand()%4+2,i,m_mynumber,j);
					m_pParticleBase[i][j]->Start();
				}
			}
		
	}
	else if (m_BoomType == 0)
	{
		if (m_Angle != 0)
		{
			m_RealAngle += 10;
			m_Angle -= 10;
			if (m_Angle == 0)
			{
				RotatedSetting();
				m_RealAngle = 0;
		
			}
		}
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (m_pObject[i][j] != NULL)
				{
					m_pObject[i][j]->Update(time);
				}

			}
		}
	}
	else if(m_BoomType == 2)
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				m_pParticleBase[i][j]->Update(time);
			}
		}
		if (!m_pParticleBase[0][0]->m_check)
		{
			m_BoomType = 3;
		}
	}
	
}
bool cFloor::RotatedFloor()
{
	if (!m_AngleCheck)
		return false;
	if (m_Angle != 0)
		return false;
	m_Angle = 90; //

	return true;

}
void cFloor::RotatedSetting()
{
	int type[5][5] = { 0, };
	for (int i = 4; i >= 0; i--)
	{
		for (int j = 0; j < 5; j++)
		{
			int x = 4 - i;
			int z = j;
			x ^= z ^= x ^= z;
			type[x][z] = m_pObject[i][j]->GetType();
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			SettingObject(i, j, type[i][j]);
		}
	}

}
