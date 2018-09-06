#ifndef CGAME_H
#define CGAME_H
#include "cScene.h"
#include "cVector.h"
#include "cCam.h"
#include "cFreeCam.h"
#include "cFpsCam.h"
#include "c3rdCam.h"
#include "cBaseObject.h"
#include "cBackGround.h"
#include "cPointObject.h"
#include "cEdge.h"
#include <vector>
#include "cTree.h"
#include "cCity.h"
#include "cCave.h"
#include "cLight.h"
#include "cLightObject.h"
#include "cShow.h"
#include "cHot.h"
#include "cRain.h"
#include "cBaseDay.h"
#define FPSCAM 0
#define VIEWCAM 1
#define FREECAM 2
#define MAXDAY 3

using namespace std;
class cGame : public cScene
{
private:
	int				m_nowDay;
	cBaseDay*		m_pDay[MAXDAY];
	cLight*			m_pLight;
	cCave*			m_pCave;
	bool			m_pCaveBool;
	int				m_CreateObjectNumber;
	int				m_NowCam;
	cCam*			m_pCam[3];
	cEdge*			m_pEdge;
	float			m_WindowsW;
	float			m_WindowsH;
	int				m_NowChage;
	int				m_draw;
	int				m_Mode; // 0 이면 그리기 ,1이면 이동 ,
	vector<cBaseObject*>		m_pvObject;
	vector<cPointObject*>				m_pvPointObject; //각 포인트점들가지고있는 변수

	int			m_Chage;
	int			m_NowObjectChage;
	
	bool		m_load;
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
	void ChageView();
	void CreateMoveModeMouse(int x, int y);
	void SizeDown(int x, int y);
	void SizeUp(int x, int y);
	void CreaetTree(int c)
	{
		int count = 0;
		while (1)
		{
			int randr = rand() % 2;
			if (count == c)
				break;
			bool check = false;
			int x = rand() % 800 + 100;
			int y = rand() % 500 + 100;

			for (int i = 0; i < m_pvObject.size(); i++)
			{
				check = m_pvObject[i]->Coll2d(cVector(x - 10, y - 10, 0), cVector(50, 50, 20));
			}
			if (check == true)
			{
				if (randr == 0)
				{
					cTree* Temp = new cTree;
					Temp->Set2DVector(cVector(x, y, 0));
					m_pvObject.push_back(Temp);
				}
				else
				{
					cCity* Temp = new cCity;
					Temp->Set2DVector(cVector(x, y, 0));
					m_pvObject.push_back(Temp);
				}
				count++;
			}
			if (m_pvObject.size() == 1)
			{
				cTree* Temp = new cTree;
				Temp->Set2DVector(cVector(x, y, 0));
				m_pvObject.push_back(Temp);
				count++;
			}

		}


		count = 0;
		while (1)
		{
			if (count == 5)
				break;
			bool check = false;
			int x = rand() % 800 + 100;
			int y = rand() % 500 + 100;
			for (int i = 0; i < m_pvObject.size(); i++)
			{
				check = m_pvObject[i]->Coll2d(cVector(x - 10, y - 10, 0), cVector(50, 50, 20));
			}
			if (check == true)
			{
				cLightObject* Temp = new cLightObject;
				Temp->Set2DVector(cVector(x, y, 0));
				Temp->Setting(count);
				m_pvObject.push_back(Temp);
			}
			count++;
		}
	}
};
#endif // !CMENU_H
