#ifndef _CBULLET_H
#define _CBULLET_H
#include "cMyDefine.h"
#include "cVector.h"
#include <gl/glut.h>
#include "cPar.h"
class cBullet
{
	cPar*				m_pPar;
	cVector				m_Vector;
	cVector				m_Rotion;
	cVector				m_Angle;
	cVector				m_Speed;
	int					m_State;
	float				m_Time;
public:
	cBullet(cVector Temp,cVector Next, cVector Rotion, cVector angle);
	~cBullet();
public:
	void Update(float time);
	void Render();
	int GetState()
	{
		return m_State;
	}
};
#endif