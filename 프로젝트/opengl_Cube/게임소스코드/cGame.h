#ifndef CGAME_H
#define CGAME_H
#include"cMyInclude.h"
#include "cUIButton.h"

#include "cScene.h"
#include "cFPSCamera.h"
#include "cFloor.h"

#include "cShowFloor.h"
#include "cPlayer.h"
#include "cBackGround.h"
#include "cPortalObject.h"
class cGame : public cScene
{
private:
	bool				m_FadeInOut;
	float				m_FadeInOutFloat;
	cBackGround*		m_pBackGround; // Light 배경
	cPlayer*		m_pPlayer;
	cShowFloor		m_ShowFloor;
	cFloor*			m_pFloor[8]; //한층
	cFPSCamera*		m_pFPSCamera;
	cUIButton*		m_pButton;//Test;
	float			m_WindowsW;
	float			m_WindowsH;
	int				m_YCount; // 스테이지의 y갯수
	int				m_NowStage; //현재 스테이지
	int				m_NowStageClearCount;
	int				m_CamAngleY;
	float			m_OpenningEndTime; // 이벤트끝나는시간 ~ 3초이내
	int				m_RotateState; // 회전할수있는지 0이면 회전 불가능(도형내려오는중) 1이면 주인공생성중 2이면 가능
	 bool			check;
	 float			tim;

	 bool			m_closeWindowns;
	 bool			m_clearStarEventCheck;
	 int			m_UpdateStar;
	 int			m_RealStar;

	 MCI_OPEN_PARMS			mciOpen;

	 MCI_PLAY_PARMS			mciPlay;
	 MCI_STATUS_PARMS		mciStatus;

	 bool			m_Portaling;
	 bool			m_PortalNeed;
	 bool			m_PortalBoom;
	 int			m_Boom;
	 int			m_Y;


	 bool			m_Rotioning;
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
	void MoveIngPortal();
	void ShowCount();// 기회
	void CamReSetting()
	{
		if (m_pFPSCamera == NULL)
			return;
		m_pFPSCamera->SetEye(-10, 18, -10);
		m_pFPSCamera->SetXAngle(ToRadian(45));
		m_pFPSCamera->SetYAngle(ToRadian(-25));
		m_pFPSCamera->g_Angle = 0;
	}
	void MapSetting();

	void ButtonEvent(int num);
	int CollType(); //충돌후 현재 충돌하고있는 타입 리턴
	void ClearOpenWindown(bool c); // c가 true 클리어,c false면 낫클리어
	void ClearCloseWindown(); // 닫기
	void ClearStarUpdate();	
};
void ButtonClickEvent(int num,void* s);
#endif // !CMENU_H
