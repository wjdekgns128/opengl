#ifndef _CLOGOOBJECT_H
#define _CLOGOOBJECT_H
#include"cMyInclude.h"

class cLogoObject
{
private:
	cVector				m_postion;
	float				m_x;

	int				t;
	int					m_Type;
	float					m_Color[4][3];
	float speed;

	float			FrameTime;
	float			 CreateTime;


	float				m_ScaleNumber;
	bool				m_EventChage;
	int					m_EventType;
	float				m_EffectTime;
public:
	cLogoObject();
	~cLogoObject();
public:
	int		GetEventType()
	{
		return m_EventType;
	}
	void SetEventType(int _sel)
	{
		m_EventType = _sel;
	}
	void SetEffectTime(float _time)
	{
		m_EffectTime = _time;
	}
	void Effect()
	{
		m_EventType = 2;
	}
	void SetVector(cVector _temp)
	{
		m_x = _temp.x;
		m_postion = _temp;
		m_postion.x = rand()%20 + 20;
		m_postion.x *= -1;
	}
	void Setting(int type)
	{
		m_Type = type;
	}
	void Render();
	void Update(float time);
};
#endif