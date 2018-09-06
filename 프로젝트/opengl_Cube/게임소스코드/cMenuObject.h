#ifndef _CMENUOBJECT_H
#define _CMENUOBJECT_H
#define SIZECUBE 0.6
#include "cVector.h"
#include "cMyInclude.h"
class cMenuObject
{
private:
	cVector		m_pColor;
	float		m_Api;
	int			m_type;
	cVector		m_Vector;
public:
	cMenuObject();
	~cMenuObject();
public:
	void Update();
	void Render();


public:
	void Setting(cVector Temp, int type)
	{
		m_Vector = Temp;
		m_type = type;
		m_pColor = CreateColor();
	}
private:
	cVector		CreateColor()
	{
		if (m_type == 0)
			return cVector(160, 50, 50);
		else if (m_type == 1)
			return cVector(0, 255, 0);
		else if (m_type == 2)
			return cVector(0, 0, 255);

		return cVector(0, 0, 0);

	}
};
#endif