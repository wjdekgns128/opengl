// 모든 오브젝트들이 기본적으로 가지고있어야하는 것들(2D,3D변환..)

#ifndef _CPOINTOBJECT_H
#define _CPOINTOBJECT_H
#include "cBaseObject.h"
class cPointObject : public cBaseObject
{
private:
	bool		m_start;
public:
	cPointObject();
	~cPointObject();

public:
public:
	bool GetSP()
	{
		return m_start;
	}
	void Update();
	void Render2D();
	void Render3D();
	void ChageMode(int mo)
	{
		m_NowMode = mo;
	}
	void Mouse(int button, int state, int x, int y);
	void StartObject()
	{
		m_start = true;
		m_Scal = cVector(30, 30, 80 /*+ rand() % 200*/);

	}
	bool Coll2d(cVector start, cVector Scl)
	{
		int x1 = m_2DVector.x;
		int y1 = m_2DVector.y;
		int x2 = m_2DVector.x + m_Scal.x;
		int y2 = m_2DVector.y + m_Scal.y;

		int _x1 = start.x;
		int _y1 = start.y;
		int _x2 = start.x + (Scl.x);
		int _y2 = start.y + (Scl.y);

		if (y2 < _y1) return true;   
		if (y1 > _y2) return true;   
		if (x2 < _x1) return true;   
		if (x1 > _x2) return true;   
		return false;

	}
	void ZUp()
	{
		m_Scal.z += 10;
		if (m_Scal.z > 300)
			m_Scal.z = 300;
	}
	void ZDown()
	{
		m_Scal.z -= 10;
		if (m_Scal.z < 60)
			m_Scal.z = 60;
	}
		// 투디 충돌체크
};
#endif // !_CBASEOBJECT_h
