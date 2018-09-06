#ifndef _CSELETEOBJECT_H
#define _CSLETETOBJECT_H

#include "cMyInclude.h"
#include "cBaseObject.h"
#include "cStartObject.h"
#include "cEndObject.h"
#include "cWallObject.h"
#include "cEmptyObject.h"
#include "cHardWallObject.h"
#include "cPortalObject.h"
class cSeleteObject
{
private:
	cBaseObject*   m_pppObject[5][8][5];
	int				m_YCount;
	int				m_NowClearCount;
	float			m_angle; // 시작 앵글값;
	float			m_MathAngle;
	float			m_plueAngle;
	float			m_NowAngle; // 현재 자체의앵글값
	int				m_SeleteNumber; // 현재 스테이지번호
	bool			m_Dir;
public:
	cSeleteObject(float angle, int seletenumber);
	~cSeleteObject()
	{
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				for (int z = 0; z < 5; z++)
					SAFE_DELETE(m_pppObject[j][i][z]);
			}
		}
	}
public:
	int   GetCount() {
		return m_NowClearCount;
	}
	float  GetMathAngle() { return m_MathAngle; }
	float GetNowAngle() { return m_NowAngle; }
	float  GetAngle() { return m_angle; }
	void   SetNowAngle(float _angle) { m_NowAngle = _angle; }
	void   SetNowAddAngle(float _angle) { m_NowAngle += _angle; }
	void   SetAngle(float _angle) { m_angle = _angle; }
	void   SetAddAngle(float _angle) { m_angle += _angle; }
	void   SetMathAngle(float _angle) { 
		if (m_MathAngle > 0)
			return;
		m_MathAngle = _angle;
		m_plueAngle = m_MathAngle / 30;
	}
	void SetDir(bool _dir)
	{
		m_Dir = _dir;
	}

public:
	void Render();
	void Update();
};
#endif