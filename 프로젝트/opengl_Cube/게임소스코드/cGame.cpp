#include "cGame.h"
#include "cMain.h"
#include "cMapLoad.h"
#include "cMapClear.h"
void ButtonClickEvent(int num, void* s) // 함수포인터를 위한 전역함수
{
	((cGame*)s)->ButtonEvent(num);
}


cGame::cGame()
{
	m_pButton = NULL;
	m_pPlayer = NULL;
	m_pBackGround = NULL;
	m_pFPSCamera = NULL;
	for (int i = 0; i < 8;i++)
		m_pFloor[i] = NULL;

}
cGame::~cGame()
{
	 SAFE_DELETE(m_pBackGround);
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pFPSCamera);
	for (int i = 0; i < 8; i++)
		SAFE_DELETE(m_pFloor[i]);
	SAFE_DELETE(m_pButton);
}
void cGame::MapSetting()
{
	m_Rotioning = false;
	m_PortalBoom = false;
	m_PortalNeed = false;
	m_Portaling = false;
	m_FadeInOut = true;
	m_UpdateStar = 0;
	m_FadeInOutFloat = 1.0;
	m_pFPSCamera->SetEye(-10, 18, -10);
	m_pFPSCamera->SetXAngle(ToRadian(45));
	m_pFPSCamera->SetYAngle(ToRadian(-25));
	m_pFPSCamera->g_Angle = 0;

	m_RotateState = 0;
	m_NowStage = GETLOAD->GetNowNumber();
	m_YCount = 0;
	m_CamAngleY = 0;
	m_OpenningEndTime = 0.0;
	check = false;
	tim = 0;

	m_YCount = GETLOAD->GetYCount(m_NowStage);
	m_NowStageClearCount = GETLOAD->GetClearCount(m_NowStage);
	SAFE_DELETE(m_pPlayer);
	if (m_pPlayer == NULL)
	{
		m_pPlayer = new cPlayer();
		

	}
	for (int _y = 0; _y < m_YCount; _y++)
	{
		m_pFloor[_y]->ReSetting();

		for (int _x = 0; _x < 5; _x++)
		{
			for (int _z = 0; _z < 5; _z++)
			{
				m_pFloor[_y]->SettingObject(_x, _z, GETLOAD->GetData(m_NowStage, _x, _y, _z));
			}
		}
		m_pFloor[_y]->Openning();

	}
	m_ShowFloor.ReSetting();
	m_ShowFloor.SetSelete(m_YCount - 1);
	m_ShowFloor.SetMaxSelete(m_YCount - 1);
	cVector Temp = GETLOAD->GetStartPoint(m_NowStage) * 2 + 1;
	Temp.y += 2;
	m_pPlayer->SetPostion(Temp); // 3만큼올리고
	m_pBackGround->m_EndPointVector = GETLOAD->GetEndPoint(m_NowStage);
	m_pBackGround->Setting();
	printf("%d\n", GETLOAD->GetNowNumber());

}
void cGame::InitWindown(int w, int h)
{
	if (h == 0)
		h = 1;
	glEnable(GL_DEPTH_TEST);

	GLfloat fAspect = (GLfloat)w / (GLfloat)h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, fAspect, 1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	m_WindowsW = w;
	m_WindowsH = h;
}
void cGame::Init()
{

	m_closeWindowns = false;
	m_clearStarEventCheck = false;
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_BLEND);
	glEnable(GL_LIGHTING);
	GETLOAD->Load();
	GETCLEAR->Load();
	mciOpen.lpstrDeviceType = L"WaveAudio";
	mciOpen.lpstrElementName = L"res/Sound/UIClick.wav";
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&mciOpen);
	mciOpen.lpstrDeviceType = L"WaveAudio";
	mciOpen.lpstrElementName = L"res/Sound/SeleteToInGame.wav";
	mciSendCommand(1, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&mciOpen);
	if (m_pFPSCamera == NULL)
	{
		m_pFPSCamera = new cFPSCamera;
		m_pFPSCamera->SetEye(-10, 18, -10);

		m_pFPSCamera->SetXAngle(ToRadian(45));
		m_pFPSCamera->SetYAngle(ToRadian(-25));
	}
	
	for (int i = 0; i < 8; i++)
	{
		if (m_pFloor[i] == NULL)
		{
				m_pFloor[i] = new cFloor(i);
		}
	}
	if (m_pBackGround == NULL)
	{
		m_pBackGround = new cBackGround;
		m_pBackGround->Setting();
	}
	if (m_pButton == NULL)
	{
		m_pButton = new cUIButton();
		m_pButton->Entry(0, "res/InGame/Retry.bmp",500,10,50,50);
		m_pButton->Entry(1, "res/InGame/Home.bmp", 550, 10, 50, 50);

		m_pButton->Entry(2, "res/InGame/ClearWindow.bmp", 110, 110, 400, 400, false); // 클리어창

		m_pButton->Entry(3, "res/InGame/Next.bmp", 185, 390, 60, 60); // 다음
		m_pButton->Entry(4, "res/InGame/Retry.bmp", 285, 390, 60, 60); // 재시작
		m_pButton->Entry(5, "res/InGame/Home.bmp", 385, 390, 60, 60); // 홈
		
		m_pButton->Entry(6, "res/InGame/UnClear.bmp", 175, 270, 85, 85,false); //
		m_pButton->Entry(7, "res/InGame/UnClear.bmp", 275, 220, 85, 85,false); //
		m_pButton->Entry(8, "res/InGame/UnClear.bmp", 375, 270, 85, 85,false); //
																		 //
		m_pButton->Entry(9, "res/InGame/Clear.bmp", 175, 270, 85, 85,false); ////
		m_pButton->Entry(10, "res/InGame/Clear.bmp", 275, 220, 85, 85,false); ///
		m_pButton->Entry(11, "res/InGame/Clear.bmp", 375, 270, 85, 85,false); ///
													
		m_pButton->Entry(12, "res/InGame/stagefail.bmp", 150, 150, 340, 70, false); ///
		m_pButton->Entry(13, "res/InGame/stageclear.bmp", 180, 150, 260, 70, false); ///
		for (int i = 2; i <= 13; i++)
		{
			m_pButton->SetActive(i, false);
			m_pButton->SetApl(i,0);
		}
		m_pButton->SetFunction(ButtonClickEvent,this);
	}
	MapSetting();



}
void cGame::Destroy()
{
	glDisable(GL_COLOR_MATERIAL);
	glDisable(GL_BLEND);
	glDisable(GL_LIGHTING);
	glDisable(GL_CULL_FACE);

	SAFE_DELETE(m_pBackGround);
	SAFE_DELETE(m_pButton);

	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pFPSCamera);
	for (int i = 0; i < 8; i++)
		SAFE_DELETE(m_pFloor[i]);
}
void cGame::MoveIngPortal()
{
	cVector Temp = m_pPlayer->GetMathPostion();
	int x1 = (Temp.x) / 2;
	int y1 = (Temp.y - 0.75) / 2;
	int z1 = (Temp.z) / 2;
	 //m_pFloor[y]->GetType(x, z);
	for (int i = 0; i < m_YCount; i++)
	{
		for (int x = 0; x < 5; x++)
		{
			for (int z = 0; z < 5; z++)
			{
				if (x1 == x && y1 == i && z1 == z)
					continue;
				else if (m_pFloor[i]->GetType(x, z) == PORTAL)
				{
					m_pPlayer->m_angle = 0;
					m_pPlayer->m_MathAngle = 0;
					m_pPlayer->m_realangle = 0;

					m_pPlayer->m_Postion = cVector(x*2+1, i*2+1,z*2+1);
					m_ShowFloor.SetSelete(i);
					m_pFloor[i]->SettingTo(x, z);
					m_pFloor[y1]->SettingTo(x1, z1);
					m_PortalNeed = true;
					m_Portaling = false;
					m_PortalBoom = true;
					m_Boom = i;
					m_Y = m_YCount;
				
					return;
				}
			}
		}
	}

}
void cGame::Update(float time)
{
	if (m_FadeInOut == true)
	{
		m_FadeInOutFloat -= 0.015;
		if (m_FadeInOutFloat < 0)
		{
			m_FadeInOut = false;
			m_FadeInOutFloat = 0;

		}

	}
	else
	{
		if (m_PortalBoom)
		{
			static int number = 0;
			if (number > 11)
			{
				number = 0;
				if (m_pFloor[m_Y-1]->GetBoomType() == 0)
				{
					m_pFloor[m_Y - 1]->SetBoomType(1);
					m_ShowFloor.SetMaxSelete(m_ShowFloor.GetMaxSelete() - 1);
				}
				m_Y--;
				if (m_Boom >= m_Y-1)
				{
					m_PortalBoom = false;
					number = 0;
				}
			}
			number++;
		}
	
		if (m_Portaling)
		{
			MoveIngPortal();
		}
		if (m_RotateState == 0)
		{
			m_OpenningEndTime += time;
			if (m_OpenningEndTime > m_YCount * 0.35)
			{
				m_OpenningEndTime = 0;
				m_RotateState = 1;
				m_pPlayer->SetState(1); // 시작으로변경

			}
		}
		else if (m_RotateState == 1)
		{
			m_OpenningEndTime += time;
			if (m_OpenningEndTime > 0.6)
			{
				m_OpenningEndTime = 0;
				m_RotateState = 2;
			}
		}
		else if (m_RotateState == 2) // 0-내려오는거 1이면 플레이어 생성 2이면 게임중 3이면 게임종료이벤트
		{
			if (!m_Portaling)
			{
				int type = CollType();
				if (type == PORTAL && m_PortalNeed == false)
				{
					m_Portaling = true;
				}
				else
				{
					m_pPlayer->CollManager(type, time);
				}

				if (type == END)
					check = true;
			}
			int NowNumber = ((m_pPlayer->GetMathPostion().y + 0.7) / 2);
			if (NowNumber < m_YCount - 1)
			{
				int tempnumber = NowNumber + 1;
				if (tempnumber >= 0)
				{
					if (m_pFloor[tempnumber]->GetBoomType() == 0)
					{
						m_pFloor[tempnumber]->SetBoomType(1);
						m_ShowFloor.SetMaxSelete(m_ShowFloor.GetMaxSelete() - 1);
					}

				}
			}

		}
		if (m_pPlayer->GetState() == 5 && m_RotateState == 2)
		{
			if (check == true)
			{
				tim += time;
				if (tim > 0.3)
				{
					m_pFloor[0]->SetBoomType(1);
					tim = 0;
					check = false;
					m_RotateState = 3;

				}
			}
		}
		else if (m_pPlayer->GetState() == 6 && m_RotateState == 2)
		{
			m_RotateState = 4;
		}
		if (m_RotateState == 4)
			ClearOpenWindown(false);
		else if (m_RotateState == 3)
			ClearOpenWindown(true);
		if (m_CamAngleY > 0)
		{
			m_pFPSCamera->g_Angle -= 5;
			m_CamAngleY -= 5;
			m_pBackGround->SetAddAngle(5);
			m_ShowFloor.SetAddAngle(5);
		}
		else if (m_CamAngleY < 0)
		{
			m_pFPSCamera->g_Angle += 5;
			m_CamAngleY += 5;
			m_pBackGround->SetAddAngle(-5);
			m_ShowFloor.SetAddAngle(-5);
		}
		for (int i = 0; i < m_YCount; i++)
		{
			m_pFloor[i]->Update(time);
		}
		m_pPlayer->Update(time);
	
	}
	if (m_closeWindowns)
	{
		ClearCloseWindown();
	}
	if (m_clearStarEventCheck)
	{
		ClearStarUpdate();
	}
	m_ShowFloor.Update();
	//glutWarpPointer(m_WindowsW / 2, m_WindowsH / 2);
}

void cGame::Render() //드로우
{
	Render3D();
	Render2D();

	glutSwapBuffers();

}
void cGame::MouseClick(int button, int state, int x, int y) // 마우스클릭상태
{
	if (m_FadeInOut == true)
		return;
	if (button == GLUT_LEFT_BUTTON) // 왼쪽 버튼일때
	{
		if (state == GLUT_DOWN) // 다운 이벤트일때
		{
			m_pButton->CollButton(x, y);
		}
	}
}
void cGame::ClearStarUpdate()
{
	static int NowLev = 9;
	

	float a = m_pButton->GetApl(NowLev);
	if (m_UpdateStar == 0)
	{
		m_clearStarEventCheck = false;
		if (GETCLEAR->GetClearCount(m_NowStage) < (m_RealStar))
		{
			GETCLEAR->SetClearCount(m_NowStage, m_RealStar);
			GETCLEAR->Save();
		}
		NowLev = 9;
		return;
	}
	
	if (a < 1)
	{
		m_pButton->SetApl(NowLev, a + 0.025);
	}
	else
	{
		m_pButton->SetApl(NowLev, 1);
		NowLev++;
		m_UpdateStar--;
		
	}
	
}
void cGame::ButtonEvent(int num)
{
	if (m_clearStarEventCheck)
		return;
	mciSendCommand(1, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
	mciSendCommand(1, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&mciPlay);

	if (m_RotateState == 2)
	{
		switch (num)
		{
		case 0:
			m_closeWindowns = true;
			MapSetting();
			break;
		case 1:
			cMain::GetInstance()->Trans(2);
			break;
		}
	}
	else if (m_RotateState == 5 || m_RotateState == 6) // 클리어
	{
		switch (num)
		{
		case 3:
			if (m_RotateState == 6)
				return;
			m_closeWindowns = true;
			if (m_NowStage+1 == GETLOAD->GetFileNamesCount())
			{
				cMain::GetInstance()->Trans(2);

			}
			else
			{
				GETLOAD->SetNowNumber(m_NowStage + 1);

				MapSetting();
			}
		

			break;
		case 4:
			m_closeWindowns = true;
			MapSetting();
			break;
		case 5:
			m_closeWindowns = true;
			cMain::GetInstance()->Trans(2);
			break;
		}
	}
}
void cGame::ClearCloseWindown()
{
	float a = m_pButton->GetApl(2);
	float b = m_pButton->GetApl(3);
	if (a > 0)
	{
		m_pButton->SetApl(2, a - 0.1);
		if (b > 0)
			m_pButton->SetApl(3, b - 0.1);
		m_pButton->SetApl(4, a - 0.1);
		m_pButton->SetApl(5, a - 0.1);
		m_pButton->SetApl(6, a - 0.1);
		m_pButton->SetApl(7, a - 0.1);
		m_pButton->SetApl(8, a - 0.1);
		if (m_pButton->GetActive(12))
			m_pButton->SetApl(12, a - 0.1);
		if (m_pButton->GetActive(13))
			m_pButton->SetApl(13, a - 0.1);
		if(m_pButton->GetActive(9))
		m_pButton->SetApl(9, a - 0.1);
		if (m_pButton->GetActive(10))
		m_pButton->SetApl(10, a - 0.1);
		if (m_pButton->GetActive(11))
		m_pButton->SetApl(11, a - 0.1);
	
	}
	else
	{
		for (int i = 2; i <= 13; i++)
		{
			m_pButton->SetApl(i, 0);
			m_pButton->SetActive(i, false);

		}

		m_closeWindowns = false;
		m_clearStarEventCheck = false;
	}
}
void cGame::ClearOpenWindown(bool c)
{

	if (m_RotateState == 5 || m_RotateState == 6) // 클리어창 이벤트끝.
		return;
	if (m_pButton->GetActive(2) == false)
	{
		m_pButton->SetActive(2, true);
		m_pButton->SetActive(4, true);
		m_pButton->SetActive(5, true);
		m_pButton->SetActive(3,true);
		m_pButton->SetActive(6, true);
		m_pButton->SetActive(7, true);
		m_pButton->SetActive(8, true);
		if(c)
		m_pButton->SetActive(13, true);
		else
			m_pButton->SetActive(12, true);

	}
	else
	{
		float a = m_pButton->GetApl(2);
		if (a < 1)
		{
			m_pButton->SetApl(2, a + 0.02);
			if (c)
			{
				m_pButton->SetApl(3, a + 0.02);
				m_pButton->SetApl(13, a + 0.02);

			}
			else
			{
				if (a < 0.3)
					m_pButton->SetApl(3, a + 0.02);

				m_pButton->SetApl(12, a + 0.02);


			}

			m_pButton->SetApl(4, a + 0.02);
			m_pButton->SetApl(5, a + 0.02);
			m_pButton->SetApl(6, a + 0.02);
			m_pButton->SetApl(7, a + 0.02);
			m_pButton->SetApl(8, a + 0.02);

		}
		else
		{
			m_pButton->SetApl(2, 1);
			m_pButton->SetApl(4, 1);
			m_pButton->SetApl(5, 1);
			m_pButton->SetApl(6, 1);
			m_pButton->SetApl(7, 1);
			m_pButton->SetApl(8, 1);

			if (c)
			{
				m_RotateState = 5;
				m_pButton->SetApl(3, 1);
				m_clearStarEventCheck = true;
				m_pButton->SetActive(9, true);
				m_pButton->SetActive(10, true);
				m_pButton->SetActive(11, true);
				m_pButton->SetApl(13, 1);
				m_UpdateStar++;
				if (m_NowStageClearCount >= -1)
					m_UpdateStar++;
				if (m_NowStageClearCount >= 0)
					m_UpdateStar++;

				m_RealStar = m_UpdateStar;
			}
			else
			{
				m_pButton->SetApl(3, 0.3);
				m_pButton->SetApl(12, 1);

				m_RotateState = 6;

			}
		}
	}
}
void cGame::Render2D()
{
	glDisable(GL_LIGHTING);
	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, m_WindowsW, m_WindowsH, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	m_pButton->Render2D();
	if (m_FadeInOut == true)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(0, 0, 0, m_FadeInOutFloat);
		glRectf(0, 0, 600, 600);
		glDisable(GL_BLEND);
	}

	ShowCount();
}
void cGame::Render3D()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	GLfloat fAspect = (GLfloat)m_WindowsW / (GLfloat)m_WindowsH;
	glViewport(0, 0, m_WindowsW, m_WindowsH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, fAspect, 1.0, 200.0);
	glMatrixMode(GL_MODELVIEW);

	m_pFPSCamera->Update(); //오차방지 업데이트(좌표셋팅)후 드로우
	/*cVector Temp = cMain::GetInstance()->ScreenToWorld(m_MouseX, m_MouseY);
	printf("%f %f %f\n", Temp.x, Temp.y, Temp.z);
	m_pBackGround->m_MousePoint = Temp;*/
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	m_pBackGround->Render();


	m_ShowFloor.Render();
	
	m_pPlayer->Render();

	for (int i = 0; i < m_YCount; i++)
	{
		m_pFloor[i]->Render();
	}


}
void cGame::ShowCount()
{
	glRasterPos2d(300, 30);

	glColor3f(1, 1, 1);
	char str1[100] = { 0, };
	_itoa_s(m_NowStageClearCount, str1, 10);
	for (unsigned int i = 0; i< strlen(str1); i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str1[i]);
}
int cGame::CollType() //충돌후 현재 충돌하고있는 타입 리턴
{
	cVector Temp = m_pPlayer->GetMathPostion();

	int x = (Temp.x) / 2 ;
	int y = (Temp.y-0.75 ) / 2 ;
	int z = (Temp.z) /2;
	if (y < 0)
		return -2; // 아래로
	if (x >= 5 || x < 0 || y >= m_YCount || z < 0 || z >= 5)
		return -1;//위로
	
	return m_pFloor[y]->GetType(x, z);
}
void cGame::MouseMove(int x, int y) //마우스무드상태
{
	//m_MouseX = x;
	//m_MouseY = y;

	//int dx = x - m_WindowsW / 2;
	//int dy = m_WindowsH / 2 - y;
	//if (dx)
	//	m_pFPSCamera->SetAddXAngle(ToRadian(0.2*dx));
	//if (dy)
	//	m_pFPSCamera->SetAddYAngle(ToRadian(0.2*dy));

}
void cGame::SKeyBoard(int Type, int key, int x, int y) //스페셜
{
	if (m_RotateState != 2)
		return;
	if (m_FadeInOut == true)
		return;
	if (Type == KEYBOARDDOWN)
	{
		if (m_CamAngleY == 0)
		{
			if (key == GLUT_KEY_RIGHT)
			{
				m_CamAngleY = -90;
			}
			else if (key == GLUT_KEY_LEFT)
			{
				m_CamAngleY = 90;
			}
		}

		if (key == GLUT_KEY_UP)
		{
			m_ShowFloor.UpSelete();
		}
		else if (key == GLUT_KEY_DOWN)
		{
			m_ShowFloor.DownSelete();
		}
	}
		
			
}
void cGame::KeyBoard(int Type, unsigned  char  key, int x, int y) //일반키
{
	if (m_RotateState != 2)
		return;
	if (m_FadeInOut == true)
		return;
	if (Type == KEYBOARDDOWN)
	{
		if (key == ' ')
		{
			if (m_pPlayer->GetMvoeing() || m_Rotioning)
				return;
			m_Rotioning = true;
			if (m_pFloor[m_ShowFloor.GetSelete()]->RotatedFloor()	&& m_pFloor[m_ShowFloor.GetSelete()]->GetBoomType() == 0)
			{
				mciSendCommand(2, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
				mciSendCommand(2, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&mciPlay);
				if (m_ShowFloor.GetSelete() == 0)
				{
					m_pBackGround->m_EndAngle += 90;
				}
				m_NowStageClearCount--;
				if ((int)(m_pPlayer->GetMathPostion().y + 0.5) <= (float)((int)m_ShowFloor.GetSelete() * 2 + 1) +1 &&
					(int)(m_pPlayer->GetMathPostion().y + 0.5) >= (float)((int)m_ShowFloor.GetSelete() * 2 + 1) - 1)
				{
					m_pPlayer->RotatedPlayer();

				}
			}
		}
		else if (key == 27)
		{
			cMain::GetInstance()->Trans(2);

		}
	
	}
	else
	{
		if (key == ' ')
		{
			m_Rotioning = false;

		}

	}

}