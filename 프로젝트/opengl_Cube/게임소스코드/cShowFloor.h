#ifndef CSHOWFLOOR_H
#define CSHOWFLOOR_H
#include <gl/glut.h>

#define RGBFloat(a){(float)((float)a/255.0)}
class cShowFloor
{
private:
	int			m_NowSelete; //���� ����
	int			m_MaxSelete;  // �ִ�ġ

	
	float alpha;
	float alpha_flag;


	int   m_AddAngle;					//<<
public:
	cShowFloor();
	~cShowFloor();
public:
	void Render(); // �׸� Game���� ȣ����...

	void Update(); // ���İ�����,~~��� Game���� ȣ����...

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
