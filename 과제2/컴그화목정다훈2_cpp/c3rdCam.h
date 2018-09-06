#ifndef _C3RDCAM_H
#define _C3RDCAM_H
#include "cMyInclude.h"
#include "cCam.h"
class c3rdCam :public cCam
{
public:

public:
	c3rdCam()
	{
		
	}
	~c3rdCam();


public:
	void Update();
	void MoveZ(cVector temp);//zรเ
	void MoveX();
	void KeyBoard(int Type, unsigned char key);

public:
	void MouseMove(int x, int y)
	{
		int dx = x - m_windowsX / 2;
		int dy = m_windowsY / 2 - y;

		if (dx)
			SetAddXAngle(ToRadian(0.2*dx));
		if (dy)
			SetAddYAngle(ToRadian(0.2*dy));
	}
};
#endif // !cFPSCamera_h
