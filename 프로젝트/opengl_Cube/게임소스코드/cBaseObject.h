#ifndef _CBASEOBJECT_H
#define _CBASEOBJECT_H
#include "cVector.h"
#include "cMyInclude.h"
struct Openning
{
public:
	bool				startcheck;
	float				waittime;
	cVector				TempVector;
	float			    frametime;
};
class cBaseObject
{
public:
	bool				m_LineLight; // false ������ ����Ʈȿ���ް�
protected:
	Openning			m_Openning; //�����׿��ʿ��Ѱ�
	cVector				m_Vector; // Move��
	int					m_type; // Ÿ��
	float				m_angle;
public:
	cBaseObject();
	~cBaseObject();

public:
	virtual void Render() = 0;
	virtual void Update(float time) = 0;
public:
	void SettingOpenning() //�����׽������� ȣ��
	{
		m_Openning.startcheck = true;
		int time = rand() % 251;
		time += m_Vector.y * 131;
		m_Openning.waittime = time *0.001;
		m_Openning.TempVector = m_Vector;
		m_Openning.frametime = 0;
		m_Vector.y = 30;
	}
	void UpdateOpenning(float time) // ������Ʈ���� ���������� ȣ��
	{
		if (m_Openning.startcheck)
		{
			m_Openning.frametime += time;
			if (m_Openning.frametime >= m_Openning.waittime)
			{
				m_Vector.y -= 0.9;
				if (m_Vector.y < m_Openning.TempVector.y)
				{
					m_Vector.y = m_Openning.TempVector.y;
					m_Openning.startcheck = false;
					m_Openning.waittime = 0;
				}
			}
		}

	}
	void SetType(int type)
	{
		m_type = type;
	}
	void SetVector(cVector _vector)
	{
		m_Vector = _vector;
	}
	void SetVector(float x, float y, float z)
	{
		m_Vector = cVector(x, y, z);
	}
	cVector GetVector()
	{
		return m_Vector;
	}
	int GetType()
	{
		return m_type;
	}
	void SetAngle(float _angle)
	{
		m_angle = _angle;
	}
	void SetAddAngle(float _angle)
	{
		m_angle += _angle;

	}
	float GetAngle()
	{
		return m_angle;
	}
};
#endif // !_CBASEOBJECT_h
