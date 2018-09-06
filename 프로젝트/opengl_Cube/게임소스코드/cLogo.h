#ifndef CLOGO_H
#define CLOGO_H
#include "cScene.h"
#include "cFPSCamera.h"
#include "cLogoObject.h"
class cLogo : public cScene
{
private:
	cLogoObject		m_ppObject[10][10];
	cFPSCamera*		m_pFPSCamera;
	float			m_WindowsW;
	float			m_WindowsH;
	float			m_NextEventTime;
	float			m_NextSceen;
	int				m_number;
public:
	cLogo();
	~cLogo();
public:
	void Render3D();
	void Render2D();
	void Init();
	void Destroy();
	void Update(float time);
	void Render();
	void MouseClick(int button, int state, int x, int y);
	void MouseMove(int x, int y);
	void SKeyBoard(int Type, int key, int x, int y);
	void KeyBoard(int Type, unsigned  char  key, int x, int y);
	void InitWindown(int w, int h);
public:
	void EffectChage(int y, int z);


};
#endif // !CMENU_H
