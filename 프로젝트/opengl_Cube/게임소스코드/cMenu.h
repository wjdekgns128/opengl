#ifndef CMENU_H
#define CMENU_H
#include"cMyInclude.h"
#include "cScene.h"
#include "cFPSCamera.h"
#include "cMenuObject.h"
#include "cMenuLight.h"
#include "cUIButton.h"
#define MENUSTARTZ -6.5
#define MENUSTARTY 6

class cMenu : public cScene
{
private:
	cUIButton*		m_pButton;
	cMenuLight*		m_pLight;
	cMenuObject		m_ppObject[4][5][5];
	cFPSCamera*		m_FPSCamera;
	int				m_winW;
	int				m_winH;
	bool			m_NextSceneCheck;
	float alpha;
	float alpha_flag;


	float alpha1;
	float alpha_flag1;
	bool				m_FadeInOut;
	float				m_FadeInOutFloat;


	MCI_OPEN_PARMS			mciOpen;
	MCI_PLAY_PARMS			mciPlay;
	MCI_STATUS_PARMS		mciStatus;
public:
	cMenu();
	~cMenu();
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
	void Button(int num);
	void NextScene();
};
void ButtonClickEvent2(int num, void* s);

#endif // !CMENU_H
