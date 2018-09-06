#ifndef _CFPSCAM_H
#define _CFPSCAM_H
#include "cMyInclude.h"
#include "cCam.h"
class cFpsCam :public cCam
{
public:
	cVector			m_Dir; //∞≈∏Æ

public:
	cFpsCam(cVector dir)
	{
		m_Dir = dir;
	}
	~cFpsCam();


public:
	void Update();
	void MoveZ(cVector temp);//z√‡
	void MoveX();
	void KeyBoard(int Type, unsigned char key);

public:
	void MouseMove(int x, int y)
	{
	
	}
};
#endif // !cFPSCamera_h
