#include "cMenu.h"
#include "cMain.h"
#include "Digitalv.h"
void ButtonClickEvent2(int num, void* s)
{
	((cMenu*)s)->Button(num);
}
void cMenu::Button(int num)
{
	if (m_FadeInOut == true || m_NextSceneCheck == true)
		return;
	mciSendCommand(mciOpen.wDeviceID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);

	mciSendCommand(mciOpen.wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&mciPlay);

	//PlaySound(L"res/Sound/UIClick.wav", NULL, SND_ASYNC   | SND_NOSTOP);
	if (num == 0)
		exit(1);
}
cMenu::cMenu()
{
	m_FPSCamera = NULL;
	m_pLight = NULL;
	m_pButton = NULL;
}
cMenu::~cMenu()
{
	mciSendCommand(1, MCI_CLOSE, 0, (DWORD)(LPVOID)NULL);
	SAFE_DELETE(m_pButton);
	SAFE_DELETE(m_FPSCamera);
	SAFE_DELETE(m_pLight);
}
void cMenu::InitWindown(int w, int h)
{

	glEnable(GL_DEPTH_TEST);
	if (h == 0)
		h = 1;
	GLfloat fAspect = (GLfloat)w / (GLfloat)h;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, fAspect, 1.0, 1000.0);
	glMatrixMode(GL_MODELVIEW);
	m_winW = w;
	m_winH = h;
}
void cMenu::Init()
{
	PlaySound(L"res/Sound/BGM.wav", NULL, SND_ASYNC | SND_LOOP | SND_NOSTOP);

	mciOpen.lpstrDeviceType = L"WaveAudio";
	mciOpen.lpstrElementName = L"res/Sound/UIClick.wav";
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&mciOpen);

	m_FadeInOut = true;
	m_FadeInOutFloat = 1.0;
	alpha = 60;
	alpha1 = 0;
	alpha_flag1 = 0;
	alpha_flag = 0;
	m_NextSceneCheck = false;
	if (m_FPSCamera == NULL)
	{
		m_FPSCamera = new cFPSCamera();
		m_FPSCamera->SetEye(-20, 0, 0);

	}
	if (m_pLight == NULL)
	{
		m_pLight = new cMenuLight;
		
	}
	if (m_pButton == NULL)
	{
		m_pButton = new cUIButton();
		m_pButton->Entry(0, "res/InGame/Home.bmp", 550, 10, 50, 50);
		m_pButton->Entry(1, "res/TitleStart.bmp", 182.5, 350, 240, 120);

		m_pButton->SetFunction(ButtonClickEvent2,this);
		m_pButton->SetApl(1, 1);
	}
	
	

	for (int x = 0; x < 5; x++) // C
	{
		for (int y = 0; y < 5; y++)
		{
			cVector Temp = cVector(0, MENUSTARTY - (y  * SIZECUBE), MENUSTARTZ + (x * SIZECUBE));
			if((y != 0 && y != 4) && x >= 1)
				m_ppObject[0][x][y].Setting(Temp, -1);
			else
			m_ppObject[0][x][y].Setting(Temp, 0);
		}
	}


	for (int x = 0; x < 5; x++) // u
	{
		for (int y = 0; y < 5; y++)
		{
			cVector Temp = cVector(0, MENUSTARTY - ((y)  * SIZECUBE), MENUSTARTZ + ((x+6) * SIZECUBE));
			if ((x != 0 && x != 4) && y != 4)
				m_ppObject[1][x][y].Setting(Temp, -1);
			else
				m_ppObject[1][x][y].Setting(Temp, 0);
		}
	}
	for (int x = 0; x < 5; x++) // B
	{
		for (int y = 0; y < 5; y++)
		{
			cVector Temp = cVector(0, MENUSTARTY - ((y)* SIZECUBE), MENUSTARTZ + ((x + 12) * SIZECUBE));
			if ((x != 0) && (y == 1 || y == 3) && x != 0 && x != 4 || (x == 4 && y == 0) || (x == 4 && y == 4) || (x == 4 && y == 2))
				m_ppObject[2][x][y].Setting(Temp, -1);
			else
				m_ppObject[2][x][y].Setting(Temp, 0);
		}
	}

	for (int x = 0; x < 5; x++) // B
	{
		for (int y = 0; y < 5; y++)
		{
			cVector Temp = cVector(0, MENUSTARTY - ((y)* SIZECUBE), MENUSTARTZ + ((x + 18) * SIZECUBE));
			if ((x != 0) && (y == 1 || y == 3) && x != 0)
				m_ppObject[3][x][y].Setting(Temp, -1);
			else
				m_ppObject[3][x][y].Setting(Temp, 0);
		}
	}
}
void cMenu::Destroy()
{
	SAFE_DELETE(m_FPSCamera);
	SAFE_DELETE(m_pLight);
	SAFE_DELETE(m_pButton);
	mciSendCommand(1, MCI_CLOSE, 0, (DWORD)(LPVOID)NULL);

}
void cMenu::Update(float time)
{
	if (m_FadeInOut == true)
	{
		m_FadeInOutFloat -= 0.025;
		if (m_FadeInOutFloat < 0)
		{
			m_FadeInOut = false;
			m_FadeInOutFloat = 0;

		}
	}
	else
	{
		if (m_NextSceneCheck == true)
		{
			NextScene();
		}
		if (m_NextSceneCheck == false)
		{
			m_pLight->Update(time);
			if (alpha_flag1)
			{
				alpha1 += 0.01;
				if (alpha1 > 0.8)
					alpha_flag1 = false;
			}
			else
			{
				alpha1 -= 0.01;
				if (alpha1 <0.3)
					alpha_flag1 = true;
			}
			m_pButton->SetApl(1, alpha1);
		}

	}

}
void cMenu::NextScene()
{
	m_FadeInOutFloat += 0.025;
	m_pButton->SetApl(0, 1 - m_FadeInOutFloat);
	m_pButton->SetApl(1, 1 - m_FadeInOutFloat);

	if (m_FadeInOutFloat >= 1)
	{
		cMain::GetInstance()->Trans(2);

	}
}
void cMenu::Render() //드로우
{
	Render3D();
	Render2D();
	glutSwapBuffers();
}
void cMenu::Render3D()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	GLfloat fAspect = (GLfloat)m_winW / (GLfloat)m_winH;
	glViewport(0, 0, m_winW, m_winH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, fAspect, 1.0, 200.0);
	glMatrixMode(GL_MODELVIEW);

	glClearColor(0, 0, 0, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	m_FPSCamera->Update();
	m_pLight->Render();

	for (int i = 0; i < 4; i++)
	{
		for (int x = 0; x < 5; x++)
		{
			for (int y = 0; y < 5; y++)
			{
				m_ppObject[i][x][y].Render();
			}
		}
	}
	glShadeModel(GL_SMOOTH);
	glEnable(GL_BLEND);
	glDisable(GL_LIGHTING);
	if (alpha >= 80)			alpha_flag = 0;
	else if (alpha <= 30)		alpha_flag = 1;
	if (alpha_flag)				alpha += 0.5;
	else if (!alpha_flag)		alpha -= 0.5;
	glPushMatrix();
	glTranslatef(15, 0, 0);
	glRotatef(90, 0, 1, 0);
	glNormal3f(1, 0, 0);
	glBegin(GL_POLYGON);
	glColor4f(RGBFloat(100), RGBFloat(90), RGBFloat(150), RGBFloat(alpha));//우측 상단
	glVertex3f(-18, 18, -5);
	glColor4f(RGBFloat(200), RGBFloat(130), RGBFloat(30), RGBFloat(alpha));//중앙
	glVertex3f(-18, -18, -5);
	glColor4f(RGBFloat(200), RGBFloat(130), RGBFloat(30), RGBFloat(alpha));//좌측 하단
	glVertex3f(18, -18, -5);
	glColor4f(RGBFloat(100), RGBFloat(90), RGBFloat(150), RGBFloat(alpha));//좌측 상단
	glVertex3f(18, 18, -5);
	glEnd();
	glPopMatrix();
	glEnable(GL_LIGHTING);
	glDisable(GL_BLEND);
	//glPushMatrix();
	//glColor3f(1, 0.5, 0);
	//char* STRS = "Rwerwerwerwe";
	//glRasterPos2f(2, 2 );
	////glRasterPos3i(x, y ,z);
	//for (unsigned int i = 0; i< strlen(STRS); i++)
	//	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, STRS[i]);
	//glPopMatrix();
}
void cMenu::Render2D()
{
	glDisable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, m_winW, m_winH, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	m_pButton->Render2D();
	if (m_FadeInOut == true || m_NextSceneCheck == true)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(0, 0, 0, m_FadeInOutFloat);
		glRectf(0, 0, 600, 600);
		glDisable(GL_BLEND);
	}

}
void cMenu::MouseClick(int button, int state, int x, int y) // 마우스클릭상태
{
	if (m_FadeInOut == true || m_NextSceneCheck == true)
		return;
	if (button == GLUT_LEFT_BUTTON) // 왼쪽 버튼일때
	{
		if (state == GLUT_DOWN) // 다운 이벤트일때
		{
			if (m_pButton->CollButton(x, y))
			{
			}
			else
			{
				mciSendCommand(mciOpen.wDeviceID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);

				mciSendCommand(mciOpen.wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&mciPlay);

				m_NextSceneCheck = true;
			}
		}
	}
}
void cMenu::MouseMove(int x, int y) //마우스무드상태
{



}
void cMenu::SKeyBoard(int Type, int key, int x, int y) //스페셜
{
}
void cMenu::KeyBoard(int Type, unsigned  char  key, int x, int y) //일반키
{
	if (Type == KEYBOARDDOWN)
	{
		if (key == 27)
			exit(1);
		else
		{
			mciSendCommand(mciOpen.wDeviceID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);

			mciSendCommand(mciOpen.wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&mciPlay);


			m_NextSceneCheck = true;
		}
	}

}