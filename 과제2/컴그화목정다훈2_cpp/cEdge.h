// 모든 오브젝트들이 기본적으로 가지고있어야하는 것들(2D,3D변환..)

#ifndef _CEDGE_H
#define _CEDGE_H
#include <vector>
#include "cPointObject.h"
#include "cMyDefine.h"
#include <functional> // less
#include <algorithm>
#include "cCam.h"
#include "cBullet.h"
using namespace std;
class cEdge 
{
public:
	cVector							TEMPS;
private:
	vector<cPointObject*>			m_pPointVector; // 각지점 (점들의 정보)
	vector<cVector>					m_pEdgePoint;
	vector<cVector>					m_pEdgePoint2D;
	vector<cBullet*>				m_vpBullet;


	float							m_time;
	vector <cVector >				m_pEdgeAngle;
	vector <cVector >				m_pEdgeAngleXYZ;

	int								m_nowNumber;
	int								m_nowNumber1;
	int								m_nowNumber2;
	int								m_nowNumber3;

	vector<int>						m_number;

	cCam*							m_pCam;
	int								m_tempnumber;
	int								m_tempnumber1;
	int								m_tempnumber2;
	int								m_tempnumber3;

	int								m_mode;
public:
	cEdge();
	~cEdge();

public:
	void Setting(int Temp)
	{
		m_mode = Temp;
	}
	void SettingCam(cCam* FpsCam)
	{
		m_pCam = FpsCam;
	}
	void		SettingPoint(vector<cPointObject*> _POINT)
	{
		m_pPointVector = _POINT;
	}
public:
	void Update(float time);
	void Render2D();
	void Render3D();
	void Mouse(int button, int state, int x, int y);
	void Key(unsigned char key);
	void RenderPlayer(); //롤러코스터
	bool Coll2d(cVector start, cVector Scl)
	{
		return false;
	}
	// 투디 충돌체크
	void GetSPline(); // 곡선구하는
	void GetSP2DLine(bool check = true);
private:
	cVector GetSPLineGet(cVector a, cVector b)
	{
		return cVector((a.x - b.x) / 2, (a.y - b.y) / 2, (a.z - b.z) / 2);

	}
public:
	cVector GetNowVector()
	{
		m_nowNumber %= m_pEdgePoint.size();
		return m_pEdgePoint[m_nowNumber];
	}
	cVector GetNowRVector()
	{
		m_nowNumber %= m_pEdgePoint.size();
		return m_pEdgeAngle[m_nowNumber];
	}
	cVector GetNowRYXVector()
	{
		m_nowNumber %= m_pEdgePoint.size();
		return m_pEdgeAngleXYZ[m_nowNumber];
	}
};
#endif // !_CBASEOBJECT_h
