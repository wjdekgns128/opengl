#ifndef _CPLAYER_H
#define _CPLAYER_H
#include <gl/glut.h>
#include "cVector.h"
#include "cMyDefine.h"
class cPlayer
{
public:
	cVector		m_SettingVetor;

private:
	cVector m_pVector;
	int		m_state;
	float  m_angle;
public:
	cPlayer(cVector _temp);
	cPlayer();
	~cPlayer();
public:
	void Render();
public:
	void SetY(float _do)
	{
		m_pVector.y = _do;
	}
	void SetYDown(float _down)
	{
		m_pVector.y -= _down;
	}
	void SetTempVector(cVector temp)
	{
		m_SettingVetor = temp;
	}
	void SetVector(cVector temp)
	{
		m_pVector = temp;
	}
	float GetY()
	{
		return m_pVector.y;
	}
	cVector GetVector()
	{
		return m_pVector;
	}
	void SetState(int state)
	{
		m_state = state;
	}
	int GetState()
	{
		return m_state;
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
#endif