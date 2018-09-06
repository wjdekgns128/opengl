#ifndef _CBASEDAY_
#define _CBASEDAY_
#include "cVector.h"
#include <vector>
using namespace std;
struct object
{
public:
	object()
	{

	}
	object(cVector vector)
	{
		this->m_pVector = vector;
	}
public:
	int		m_state; // 상태
	cVector m_pVector;
	cVector	m_Color; //색상
	float   m_Api; //알파값
	float	m_dietime;
	float  m_dietimecheck;
	cVector	m_Speed;
};
class cBaseDay
{
protected:

	vector<object*>		m_pObjects;
	float CreateTime;
	float MakeTime;

public:
public:
	void ClearRe()
	{
		for (int i = 0; i < m_pObjects.size(); i++)
		{
			if (m_pObjects[i] != NULL)
			{
				delete m_pObjects[i];
				m_pObjects[i] = NULL;
			}
		}

		m_pObjects.clear();
	}
	cBaseDay() { ; }
	virtual ~cBaseDay() {		
		for (int i = 0; i < m_pObjects.size(); i++)
		{
			if (m_pObjects[i] != NULL)
			{
				delete m_pObjects[i];
				m_pObjects[i] = NULL;
			}
		}
		m_pObjects.clear();

	}

	virtual void Render() = 0;
	virtual void Update(float _time) = 0;
};
#endif