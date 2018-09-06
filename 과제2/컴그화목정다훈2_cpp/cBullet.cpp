#include "cBullet.h"

cBullet::cBullet(cVector Temp, cVector Next, cVector Rotion,cVector angle)
{
	m_Vector = Temp;
	m_Rotion = Rotion;
	m_State = 0;
	m_Angle = angle;
	m_Time = 0;

	cVector Tes =  Next- Temp;
	Tes.normalize();

	m_Speed.x = Tes.x;
	m_Speed.y = Tes.y;
	m_Speed.z = Tes.z;
	m_pPar = NULL;
}
cBullet::~cBullet()
{
	SAFE_DELETE(m_pPar);
}
void cBullet::Render()
{
	if (m_State == 0)
	{

		glPushMatrix();
		glColor3f(0.5, 0.5, 0.8);

		glTranslatef(m_Vector.x, m_Vector.z + 5.5, m_Vector.y);
		glRotatef(m_Angle.x, m_Rotion.x, m_Rotion.z, m_Rotion.y);
		glutSolidSphere(5, 15, 15);
		glPopMatrix();
	}
	else
		m_pPar->Render();
}
void cBullet::Update(float time)
{
	if (m_State == 0)
	{
		m_Vector = m_Speed * 7 + m_Vector;
		m_Time += time;
		if (m_Time > 2 || m_Vector.x > 900 || m_Vector.x < -900 || m_Vector.y < -600 || m_Vector.y > 600)
		{
			m_State = 1;
			m_Time = 0;
			m_pPar = new cPar(m_Vector-1, m_Vector +1, 0, 3);
			for (int i = 0; i < 100; i++)
				m_pPar->CreateObject();
		}
	}
	else
	{
		m_pPar->Update(time);
		if (m_pPar->GetSize() == 0)
		{
			m_State = 2;
			m_pPar->ClearRe();
		}
	}
}