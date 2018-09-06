#ifndef _CSELETE_H
#define _CSELETE_H
#include "cScene.h"
#include "cFPSCamera.h"
#include <vector>
#include "cSeleteObject.h"
#include "cUIButton.h"
using namespace std;
class cSelete : public cScene
{
private:
	cUIButton*					m_pButton;
	vector< cSeleteObject*>		m_vpSeleteObject;
	cFPSCamera*		m_pFPSCamera;
	float			m_WindowsW;
	float			m_WindowsH;
	float					m_OneByAngle; //한바퀴에 몇도?
	float					m_NowAngle;
	int				m_nowSelete;
	GLfloat ambientLight[4];
	bool			m_NextSceneCheck;
	bool				m_FadeInOut;
	float				m_FadeInOutFloat;
	bool			m_UIUpApi;
	bool			m_UIDownApi;
	bool			m_UpdateState;
	bool			m_UpdateDownState;

	int				m_TempSelete;


	bool				m_NowDirR;//어느방향?
	bool				m_NowDirL;//어느방향?

	float			m_NowAplR;//알파값
	float			m_NowAplL;//알파값

	float alpha;
	float alpha_flag;
	int			  m_MouseRL; // 0 x 1,L 2 R

	bool			m_Back;
	MCI_OPEN_PARMS			mciOpen1;

	MCI_OPEN_PARMS			mciOpen;

	MCI_PLAY_PARMS			mciPlay;
	MCI_STATUS_PARMS		mciStatus;
public:
	cSelete();
	~cSelete();
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
	void NextScene();
	void OpenUI(int num);
	void CloseUI(int num);
	void ButtonEvent(int num);

};
void ButtonClickEvent1(int num, void* s);

#endif // !CMENU_H
