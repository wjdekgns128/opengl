#ifndef CSHOWFLOOR_H
#define CSHOWFLOOR_H
#include <gl/glut.h>

#define RGBFloat(a){(float)((float)a/255.0)}
class cShowFloor
{
private:
	int			m_NowSelete; //현재 선택
	int			m_MaxSelete;  // 최대치

	
	float alpha;
	float alpha_flag;


	int   m_AddAngle;					//<<
public:
	cShowFloor();
	~cShowFloor();
public:
	void Render(); // 그림 Game에서 호출중...

	void Update(); // 알파값조절,~~등등 Game에서 호출중...

public:
	void SetMaxSelete(int _Sel) { m_MaxSelete = _Sel; }
	int GetMaxSelete() { return m_MaxSelete; }
	int GetSelete() { return m_NowSelete; }
	void SetSelete(int _sel) { m_NowSelete = _sel; }
	void UpSelete() { 

		m_NowSelete++; 
		m_NowSelete %= (m_MaxSelete+1);
	}
	void DownSelete() {
		m_NowSelete--;
		if (m_NowSelete > m_MaxSelete)
			m_NowSelete = m_MaxSelete;
		if (m_NowSelete < 0)
			m_NowSelete = m_MaxSelete;
	}

	void ReSetting()
	{
		m_NowSelete = 0;

		alpha = 255;
		alpha_flag = 0;
		m_AddAngle = 0;
	}
	void SetAddAngle(float _angle)				 //<<
	{
		m_AddAngle += _angle;
	}

	void InGameBG();
	
};
#endif // _CHSOWFLOOR_H
