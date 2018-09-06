#ifndef _CMENULIGHT_H
#define _CMENULIGHT_H
#include "cMyDefine.h"
#include "cMyInclude.h"

class cMenuLight
{
private:
	bool			m_Dir; // 방향 true -> false <-
	int				m_Type; // 현재타입
	cVector			m_Vector;

	cVector			m_MoveSpeed; //속도
	bool			m_WaitIng;
	float			m_TempWaitTime;
	float			m_WaitTime[2];
	bool			m_YDir;
public:
	cMenuLight();
	~cMenuLight();
public:
	void Render();
	void Update(float time);

	void CreateType()
	{
		m_Type = rand()%3;

		if (m_Type == 0)
		{
			m_MoveSpeed = cVector(0, 0, 0.05);
			m_TempWaitTime = 0.0;
			m_WaitTime[0] = 0.0;
			m_WaitTime[1] = 0.0;
			m_WaitIng = false;
			m_Vector.y = 4.5;
		}
		else if (m_Type == 1)
		{
			m_MoveSpeed = cVector(0, 0, 0.05);
			m_TempWaitTime = 0.0;
			m_WaitTime[0] = 1.3;
			m_WaitTime[1] = 0.7;
			m_WaitIng = false;
			m_Vector.y = 4.5;

		}
		else if (m_Type == 2)
		{
			m_MoveSpeed = cVector(0, 0.045, 0.05);
			m_TempWaitTime = 0.0;
			m_WaitTime[0] = 0.0;
			m_WaitTime[1] = 0.0;
			m_WaitIng = false;
			
		}
	}
};

#endif