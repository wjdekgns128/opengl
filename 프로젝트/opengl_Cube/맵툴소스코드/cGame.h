#ifndef CGAME_H
#define CGAME_H
#include"cMyInclude.h"
#include "cScene.h"
#include "cEmptyObject.h"
#include "cFPSCamera.h"
#include "cBaseObject.h"
#include "cEndObject.h"
#include "cStartObject.h"
#include "cWallObject.h"
#include "cHardWallObject.h"
#include "cPlayer.h"
#include "cShow.h"
class cGame : public cScene
{
private:
	cPlayer*		m_pPlayer;
	cFPSCamera*		m_pFPSCamera;
	cBaseObject*	m_pppObject[5][5][8];
	cBaseObject*	m_pppCreateObject[5][5][8];
	cShow*			m_pShow;
	float			m_WindowsW;
	float			m_WindowsH;
	bool			m_viewcheck;
	bool			m_createstate;
	int			m_anglecheck;
	float			m_angle;
	int				m_Count;
public:
	cGame();
	~cGame();
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
	void CreateChage();
	void ObjectSetting(cVector Temp);
	int CollPlayer();
public:
	void DrawGrid();
	void CamReSetting()
	{
		m_angle = 0;
		m_anglecheck = 0;
		m_Count = 0;
		if (m_pFPSCamera == NULL)
			return;
		m_pFPSCamera->SetEye(-10, 15, -7.7);
		m_pFPSCamera->SetXAngle(ToRadian(41));
		m_pFPSCamera->SetYAngle(ToRadian(-19.7));
		m_pFPSCamera->m_DisAngle = 0;
	}
	void RotateSetting(int y);
};
#endif // !CMENU_H
