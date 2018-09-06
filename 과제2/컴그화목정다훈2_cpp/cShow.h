#ifndef _CSHOW_H
#define _CSHOW_H

#include "cBaseDay.h"
#include <gl/glut.h>
class cShow : public cBaseDay
{
private:
	cVector m_RandomMin;
	cVector	m_RandomMax;
	float   m_dirtime;
	float  m_downapl;
public:
	cShow(cVector min, cVector Max, float cratetime,float dietime = 5)
	{
		CreateTime = cratetime;
		MakeTime = 0.0;
		m_RandomMin = min;
		m_RandomMax = Max;
		m_pObjects.clear();
		m_dirtime = dietime;
	}
	~cShow()
	{

	}
public:
	void Render();
	void Update(float _time);
	void CreateObject();


private:
	int randomRange(int n1, int n2) { //지정된범위
		return (int)(rand() % (n2 - n1 + 1)) + n1;
	}
};

#endif