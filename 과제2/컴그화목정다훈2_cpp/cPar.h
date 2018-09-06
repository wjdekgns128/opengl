#ifndef _CPAR_H
#define _CPAR_H

#include "cBaseDay.h"
#include <gl/glut.h>
class cPar : public cBaseDay
{
private:
	cVector m_RandomMin;
	cVector	m_RandomMax;
	float   m_dirtime;
	float  m_downapl;
public:
	cPar(cVector min, cVector Max, float cratetime, float dietime = 5)
	{
		CreateTime = cratetime;
		MakeTime = 0.0;
		m_RandomMin = min;
		m_RandomMax = Max;
		m_pObjects.clear();
		m_dirtime = dietime;
	}
	~cPar()
	{

	}
public:
	void Render();
	void Update(float _time);
	void CreateObject();
	int GetSize()
	{
		return m_pObjects.size();
	}

private:
	int randomRange(int n1, int n2) { //지정된범위
		return (int)(rand() % (n2 - n1 + 1)) + n1;
	}
};

#endif