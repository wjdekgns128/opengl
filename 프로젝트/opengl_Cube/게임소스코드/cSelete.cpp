#include "cSelete.h"
#include "cMain.h"
#include "cMapLoad.h"
#include "cMapClear.h"

GLfloat qaLightPosition[] = { 0,0,1, 1 };
GLfloat dirVector0[] = { 0, 0, 1, 0.0 };
GLfloat color[] = { 1,1,1,1 };

void ButtonClickEvent1(int num, void* s) // 함수포인터를 위한 전역함수
{
	((cSelete*)s)->ButtonEvent(num);
}
void cSelete::ButtonEvent(int num)
{
	if (m_FadeInOut == true || m_NextSceneCheck == true)
		return;
	if (m_Back)
		return;
mciSendCommand(mciOpen.wDeviceID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
	mciSendCommand(mciOpen.wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&mciPlay);


	if (num == 2)
	{
		m_Back = true;
		m_UIDownApi = true;
	}
}
cSelete::cSelete()
{
	m_pFPSCamera = NULL;
	m_pButton = NULL;
	m_vpSeleteObject.clear();
}
cSelete::~cSelete()
{

	mciSendCommand(1, MCI_CLOSE, 0, (DWORD)(LPVOID)NULL);
	mciSendCommand(2, MCI_CLOSE, 0, (DWORD)(LPVOID)NULL);
	SAFE_DELETE(m_pButton);
	SAFE_DELETE(m_pFPSCamera);
	for (int i = 0; i < m_vpSeleteObject.size(); i++)
		SAFE_DELETE(m_vpSeleteObject[i]);

	m_vpSeleteObject.clear();
}
void cSelete::InitWindown(int w, int h)
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
void cSelete::Init()
{
	m_MouseRL = 0;
	alpha_flag = 0.0;
	m_UIUpApi = true;
	m_FadeInOut = true;
	m_UIDownApi = false;
	m_FadeInOutFloat = 1.0;
	ambientLight[0] = RGBFloat(80);
	ambientLight[1] = RGBFloat(80);
	ambientLight[2] = RGBFloat(80);
	ambientLight[3] = 1;
	color[0] = 1;
	color[1] = 1;
	color[2] = 1;
	color[3] = 1;

	m_vpSeleteObject.clear();
	mciOpen.lpstrDeviceType = L"WaveAudio";
	mciOpen.lpstrElementName = L"res/Sound/UIClick.wav";
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&mciOpen);
	mciOpen1.lpstrDeviceType = L"WaveAudio";
	mciOpen1.lpstrElementName = L"res/Sound/Floor.wav";
	mciSendCommand(0, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&mciOpen1);

	GETLOAD->Load();
	GETCLEAR->Load();
	glEnable(GL_COLOR_MATERIAL);

	// 조명값들 
	glMateriali(GL_FRONT, GL_SHININESS, 128);
	////배경
	m_nowSelete = 0;
	m_OneByAngle = 0;
	m_NowAngle = 0;
	m_NextSceneCheck = false;
	m_UpdateDownState = false;
	m_UpdateState = true; // 별
	m_NowDirR = false;
	m_NowDirL = false;
	m_Back = false;
	m_NowAplR = 0.0;
	m_NowAplL = 0.0;

	if (m_pFPSCamera == NULL)
	{
		m_pFPSCamera = new cFPSCamera;
		/*	m_pFPSCamera->SetEye(-13, 6, 5);*/
			//m_pFPSCamera->SetXAngle(ToRadian(-30));
		/*	m_pFPSCamera->SetXAngle(ToRadian(45));
		m_pFPSCamera->SetYAngle(ToRadian(-25));*/
		m_pFPSCamera->SetEye(-13, 6, -13);
		m_pFPSCamera->SetXAngle(ToRadian(45));

	}
	if (m_vpSeleteObject.size() == 0)
	{
		int tempangle = 0;
		m_OneByAngle = 360.0 / (float)GETLOAD->GetFileNamesCount();
		for (int i = 0; i < GETLOAD->GetFileNamesCount(); i++)
		{
			m_vpSeleteObject.push_back(new cSeleteObject(tempangle, i));
			tempangle += m_OneByAngle;
		}
	}
	if (m_pButton == NULL)
	{
		m_pButton = new cUIButton();
		m_pButton->Entry(10, "res/Selete/SelectRIGHT.bmp", 390, 490, 65, 65, false);
		m_pButton->Entry(11, "res/Selete/SelectRIGHT2.bmp", 160, 490, 65, 65, false);
		m_pButton->Entry(2, "res/InGame/Home.bmp", 545, 10, 50, 50);

		m_pButton->Entry(3, "res/InGame/Clear.bmp", 230, 490, 50, 50, false);
		m_pButton->Entry(4, "res/InGame/Clear.bmp", 285, 490, 50, 50, false);
		m_pButton->Entry(5, "res/InGame/Clear.bmp", 340, 490, 50, 50, false);
		m_pButton->Entry(6, "res/InGame/UnClear.bmp", 230, 490, 50, 50, false);
		m_pButton->Entry(7, "res/InGame/UnClear.bmp", 285, 490, 50, 50, false);
		m_pButton->Entry(8, "res/InGame/UnClear.bmp", 340, 490, 50, 50, false);
		m_pButton->Entry(9, "res/Selete/Selete.bmp", 185, -40, 240, 140, false);
		m_pButton->Entry(0, "res/Selete/SelectRIGHT(FULL).bmp", 390, 490, 65, 65, false);
		m_pButton->Entry(1, "res/Selete/SelectRIGHT(FULL)2.bmp", 160, 490, 65, 65, false);


	}
	for (int i = 0; i < 12; i++)
	{
		m_pButton->SetApl(i, 0);


	}
	m_pButton->SetActive(3, false);
	m_pButton->SetActive(4, false);
	m_pButton->SetActive(5, false);
	m_pButton->SetActive(0, false);
	m_pButton->SetActive(1, false);

	m_pButton->SetFunction(ButtonClickEvent1, this);

	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);

	glEnable(GL_LIGHTING);
	alpha = 230;
	alpha_flag = 0;
}
void cSelete::CloseUI(int num)
{
	if (m_UIDownApi)
	{
		static float apl = 1;
		for (int i = num; i < 12; i++)
		{
			m_pButton->SetApl(i, apl);
		}


		if (apl < 0)
		{
			for (int i = num; i < 12; i++)
			{
				m_pButton->SetActive(i, false);
			}
			apl = 1;
			m_UIDownApi = false;
		}
		apl -= 0.05;
	}
}
void cSelete::OpenUI(int num)
{
	if (m_UIUpApi)
	{
		static float apl = 0.0;
		for (int i = num; i < 3; i++)
		{
			m_pButton->SetApl(i, apl);
		}
		m_pButton->SetApl(6, apl);
		m_pButton->SetApl(7, apl);
		m_pButton->SetApl(8, apl);
		m_pButton->SetApl(9, apl);
		m_pButton->SetApl(10, apl);
		m_pButton->SetApl(11, apl);

		if (apl >= 1)
		{
			apl = 0;
			m_UIUpApi = false;
		}
		apl += 0.018;
	}

}
void cSelete::Destroy()
{
	for (int i = 0; i < m_vpSeleteObject.size(); i++)
		SAFE_DELETE(m_vpSeleteObject[i]);
	SAFE_DELETE(m_pButton);
	m_vpSeleteObject.clear();
	SAFE_DELETE(m_pFPSCamera);
	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHTING);
	mciSendCommand(1, MCI_CLOSE, 0, (DWORD)(LPVOID)NULL);
	mciSendCommand(2, MCI_CLOSE, 0, (DWORD)(LPVOID)NULL);


}
void cSelete::Update(float time)
{
	if (m_FadeInOut == true)
	{
		m_FadeInOutFloat -= 0.018;
		if (m_FadeInOutFloat < 0)
		{
			m_FadeInOut = false;
			m_FadeInOutFloat = 0;

		}
		OpenUI(2);

	}
	else
	{
		if (m_Back)
		{
			color[0] -= 0.03;
			color[1] -= 0.03;
			color[2] -= 0.03;
			m_FadeInOutFloat += 0.03;
			CloseUI(2);


			if (color[0] < 0)
			{
				ambientLight[0] = 0;
				ambientLight[1] = 0;
				ambientLight[2] = 0;
				cMain::GetInstance()->Trans(1);

			}
		}
		if (m_Back == false)
		{
			if (m_NowDirR)
			{
				m_pButton->SetActive(0, true);
				m_pButton->SetApl(0, m_NowAplR);
				m_NowAplR += 0.02;
				if (m_NowAplR >= 1)
				{
					m_NowAplR = 1;
				}

			}
			else if (m_NowDirL)
			{
				m_pButton->SetActive(1, true);
				m_pButton->SetApl(1, m_NowAplL);
				m_NowAplL += 0.02;
				if (m_NowAplL >= 1)
				{
					m_NowAplL = 1;
				}
			}if (m_NowDirR == false)
			{
				if (m_pButton->GetActive(0) == true)
				{
					m_pButton->SetApl(0, m_NowAplR);
					m_NowAplR -= 0.02;
					if (m_NowAplR < 0.1)
					{
						m_NowAplR = 0.1;
						m_pButton->SetActive(0, false);
					}
				}
			}
			if (m_NowDirL == false)
			{
				if (m_pButton->GetActive(1) == true)
				{
					m_pButton->SetApl(1, m_NowAplL);
					m_NowAplL -= 0.02;
					if (m_NowAplL < 0.1)
					{
						m_pButton->SetActive(1, false);
						m_NowAplL = 0.1;
					}
				}
			}


			if (m_NextSceneCheck == true)
			{
				NextScene();
				CloseUI(2);
			}
			else
			{
				m_vpSeleteObject[m_nowSelete]->SetNowAddAngle(0.4);

			}
			for (int i = 0; i < m_vpSeleteObject.size(); i++)
				m_vpSeleteObject[i]->Update();

		}
		if (m_UpdateState)
		{
			static float apl = 0.0;
			int GetStar = m_vpSeleteObject[m_nowSelete]->GetCount();
			for (int i = 0; i < GetStar; i++)
			{
				m_pButton->SetActive(3 + i, true);
				m_pButton->SetApl(3 + i, apl);


			}
			apl += 0.03;
			if (apl >= 1)
			{
				apl = 0;
				m_UpdateState = false;
			}
		}
		if (m_MouseRL == 1)
		{
			if (m_vpSeleteObject[0]->GetMathAngle() <= 0.0)
			{
				for (int i = 0; i < 3; i++)
				{
					m_pButton->SetActive(3 + i, false);

				}
				m_UpdateState = true;

				for (int i = 0; i < m_vpSeleteObject.size(); i++)
				{
					m_vpSeleteObject[i]->SetMathAngle(m_OneByAngle);

					m_vpSeleteObject[i]->SetDir(true);
				}
				m_nowSelete--;
				m_NowDirL = true;
				m_NowDirR = false;

				if (m_nowSelete < 0)
					m_nowSelete = m_vpSeleteObject.size() - 1;
				else if (m_nowSelete >= m_vpSeleteObject.size())
					m_nowSelete = 0;

			}
		}

		else if (m_MouseRL == 2)
		{
			if (m_vpSeleteObject[0]->GetMathAngle() <= 0.0)
			{
				for (int i = 0; i < 3; i++)
				{
					m_pButton->SetActive(3 + i, false);

				}
				m_UpdateState = true;

				for (int i = 0; i < m_vpSeleteObject.size(); i++)
				{
					m_vpSeleteObject[i]->SetMathAngle(m_OneByAngle);

					m_vpSeleteObject[i]->SetDir(false);
				}
				m_nowSelete++;
				m_NowDirR = true;
				m_NowDirL = false;

				if (m_nowSelete < 0)
					m_nowSelete = m_vpSeleteObject.size() - 1;
				else if (m_nowSelete >= m_vpSeleteObject.size())
					m_nowSelete = 0;

			}
		}

	}


	//glutWarpPointer(m_WindowsW / 2, m_WindowsH / 2);
}

void cSelete::Render() //드로우
{
	Render3D();
	Render2D();
	glutSwapBuffers();

}
void cSelete::MouseClick(int button, int state, int x, int y) // 마우스클릭상태
{
	if (m_Back)
		return;
	if (button == GLUT_LEFT_BUTTON)
	{
		if (state == GLUT_UP)
		{
			m_MouseRL = 0;
			if (m_NowDirL)
				m_NowDirL = false;
			if (m_NowDirR)
				m_NowDirR = false;
		}
	}

	if (m_NextSceneCheck || m_FadeInOut || m_UpdateState)
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


				if (x < 300)
				{
					m_MouseRL = 1;

				}
				else if (x >= 300)
				{
					m_MouseRL = 2;


				}
			}
		}
	}
}

void cSelete::Render2D()
{
	glDisable(GL_LIGHTING);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, m_WindowsW, m_WindowsH, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	m_pButton->Render2D();

	if (m_FadeInOut == true || m_Back)
	{
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glColor4f(0, 0, 0, m_FadeInOutFloat);
		glRectf(0, 0, 600, 600);
		glDisable(GL_BLEND);
	}



}
void cSelete::Render3D()
{
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	GLfloat fAspect = (GLfloat)m_WindowsW / (GLfloat)m_WindowsH;
	glViewport(0, 0, m_WindowsW, m_WindowsH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, fAspect, 1.0, 200.0);
	glMatrixMode(GL_MODELVIEW);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	m_pFPSCamera->Update();
	glEnable(GL_LIGHTING);

	for (int i = 0; i < m_vpSeleteObject.size(); i++)
		m_vpSeleteObject[i]->Render();



	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);


	glPushMatrix();
	glTranslatef(3, 18, -13);

	glRotatef(40, 1, 0, 0);

	glColor3f(1, 1, 1);

	glLightfv(GL_LIGHT0, GL_DIFFUSE, color);
	glLightfv(GL_LIGHT0, GL_POSITION, qaLightPosition);
	glLightfv(GL_LIGHT0, GL_SPOT_DIRECTION, dirVector0);
	glLightf(GL_LIGHT0, GL_SPOT_EXPONENT, 2.0);
	glLightf(GL_LIGHT0, GL_SPOT_CUTOFF, 25);

	glPopMatrix();


	glPushMatrix();

	glTranslatef(-13, 18, 3);
	glRotatef(90, 0, 1, 0);
	glRotatef(40, 1, 0, 0);

	glColor3f(1, 0, 0);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, color);
	glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, dirVector0);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 2.0);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 25);

	glPopMatrix();
	//glEnable(GL_LIGHTING);
	//glEnable(GL_LIGHT0);
	//	GLfloat lightpos[4];
//	
//	lightpos[0] = m_pFPSCamera->GetAngleEye().x;
//	lightpos[1] = m_pFPSCamera->GetAngleEye().y;
//	lightpos[2] = m_pFPSCamera->GetAngleEye().z;
//	lightpos[3] = 1;
//	printf("%f %f %f\n", lightpos[0], lightpos[1], lightpos[2]);
//glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
//GLfloat ambient[4] = { 1,1,1,1 };
//glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);




	glDisable(GL_LIGHT0);
	glDisable(GL_LIGHT1);
	glPushMatrix();
	glColor3f(0, 0, 0);
	glRotatef(45, 0, 1, 0);
	glTranslatef(0, 0, 50);
	glScalef(200, 200, 1);
	glutSolidCube(1);
	glPopMatrix();

	glEnable(GL_BLEND);

	if (alpha >= 255)		alpha_flag = 0;
	else if (alpha <= 130)		alpha_flag = 1;
	if (alpha_flag)		alpha += 1;
	else if (!alpha_flag)	alpha -= 1;
	glPushMatrix();
	glTranslatef(32, 7, 0);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 1, 0);
	glBegin(GL_POLYGON);
	glColor4f(RGBFloat(100), RGBFloat(90), RGBFloat(150), RGBFloat(alpha));//우측 상단
	glVertex3f(-32, 36, -15);
	glColor4f(RGBFloat(230), RGBFloat(200), RGBFloat(100), RGBFloat(alpha));//중앙
	glVertex3f(-32, -12.25, -15);
	glColor4f(RGBFloat(230), RGBFloat(130), RGBFloat(30), RGBFloat(alpha));//좌측 하단
	glVertex3f(15, -12.25, -15);
	glColor4f(RGBFloat(100), RGBFloat(90), RGBFloat(150), RGBFloat(alpha));//좌측 상단
	glVertex3f(15, 36, -15);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 7, 32);
	glScalef(1, 1, 0);
	glBegin(GL_POLYGON);
	glColor4f(RGBFloat(100), RGBFloat(90), RGBFloat(150), RGBFloat(alpha));
	glVertex3f(32, 36, -15);
	glColor4f(RGBFloat(230), RGBFloat(200), RGBFloat(100), RGBFloat(alpha));//중앙
	glVertex3f(32, -12.25, -15);
	glColor4f(RGBFloat(230), RGBFloat(130), RGBFloat(30), RGBFloat(alpha));
	glVertex3f(-15, -12.25, -15);
	glColor4f(RGBFloat(100), RGBFloat(90), RGBFloat(150), RGBFloat(alpha));
	glVertex3f(-15, 36, -15);
	glEnd();
	glPopMatrix();


	glPushMatrix();
	glTranslatef(0, -5.5, 0);
	glRotatef(90, 1, 0, 0);
	glScalef(1, 1, 0);
	glBegin(GL_POLYGON);
	glColor4f(RGBFloat(230), RGBFloat(130), RGBFloat(90), RGBFloat(alpha));
	glVertex3f(-35, 35, -15);
	glColor4f(RGBFloat(230), RGBFloat(200), RGBFloat(255), RGBFloat(alpha));
	glVertex3f(-15, -15, -15);
	glColor4f(RGBFloat(230), RGBFloat(130), RGBFloat(90), RGBFloat(alpha));
	glVertex3f(35, -35, -15);
	glColor4f(RGBFloat(200), RGBFloat(180), RGBFloat(90), RGBFloat(alpha));//중앙
	glVertex3f(35, 35, -15);
	glEnd();
	glPopMatrix();
	glDisable(GL_BLEND);



}
void cSelete::MouseMove(int x, int y) //마우스무드상태
{
	/*int dx = x - m_WindowsW / 2;
	int dy = m_WindowsH / 2 - y;
	if (dx)
		m_pFPSCamera->SetAddXAngle(ToRadian(0.2*dx));
	if (dy)
		m_pFPSCamera->SetAddYAngle(ToRadian(0.2*dy));
*/
}
void cSelete::SKeyBoard(int Type, int key, int x, int y) //스페셜
{
	if (m_Back)
		return;
	if (Type == KEYBOARDUP)
	{
		if (key == GLUT_KEY_RIGHT)
		{

			m_NowDirR = false;
		}
		if (key == GLUT_KEY_LEFT)
		{
			m_NowDirL = false;

		}
	}
	if (m_NextSceneCheck || m_FadeInOut || m_UpdateState)
		return;
	if (Type == KEYBOARDDOWN)
	{

		if (key == GLUT_KEY_RIGHT || key == GLUT_KEY_LEFT)
		{
			mciSendCommand(mciOpen.wDeviceID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);

			mciSendCommand(mciOpen.wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&mciPlay);


			if (m_vpSeleteObject[0]->GetMathAngle() <= 0.0)
			{
				for (int i = 0; i < 3; i++)
				{
					m_pButton->SetActive(3 + i, false);

				}
				m_UpdateState = true;

				for (int i = 0; i < m_vpSeleteObject.size(); i++)
				{
					m_vpSeleteObject[i]->SetMathAngle(m_OneByAngle);
					if (key == GLUT_KEY_RIGHT)
					{
						m_vpSeleteObject[i]->SetDir(false);
					}
					else
					{
						m_vpSeleteObject[i]->SetDir(true);
					}
				}
				if (key == GLUT_KEY_RIGHT)
				{
					m_NowDirR = true;
					m_nowSelete++;

				}
				else
				{
					m_nowSelete--;
					m_NowDirL = true;

				}
				if (m_nowSelete < 0)
					m_nowSelete = m_vpSeleteObject.size() - 1;
				else if (m_nowSelete >= m_vpSeleteObject.size())
					m_nowSelete = 0;

			}
		}
	}


}
void cSelete::NextScene()
{
	static float rspeed = 1;
	static float xspeed = 0.05;
	static bool c = false;
	m_vpSeleteObject[m_nowSelete]->SetNowAddAngle(rspeed);
	rspeed += 0.2;
	color[0] -= 0.012;
	color[1] -= 0.012;
	color[2] -= 0.012;
	if (color[0] <= 0)
	{
		color[0] = 0;
		color[1] = 0;
		color[2] = 0;
		ambientLight[0] = 0;
		ambientLight[1] = 0;
		ambientLight[2] = 0;
		xspeed = 0.03;
		rspeed = 1;
		c = false;
		GETLOAD->SetNowNumber(m_nowSelete);
		cMain::GetInstance()->Trans(3);
	}

	else if (color[0] < 0.3)
	{
		cVector Temp = m_pFPSCamera->GetEye();
		Temp.x += xspeed;
		Temp.z += xspeed;
		xspeed += 0.1;
		m_pFPSCamera->SetEye(Temp);
	}
	else if (color[0] < 0.53)
	{
		if (c == false)
		{
			mciSendCommand(mciOpen1.wDeviceID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
			mciSendCommand(mciOpen1.wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&mciPlay);
		}
		c = true;



	}
}
void cSelete::KeyBoard(int Type, unsigned  char  key, int x, int y) //일반키
{

	if (m_NextSceneCheck || m_FadeInOut || m_Back)
		return;
	if (Type == KEYBOARDDOWN)
	{

		if (key == ' ')
		{
		
			m_UIDownApi = true;
			m_NextSceneCheck = true;
			//cMain::GetInstance()->Trans(3);
		}
		if (key == 27)
		{
			m_Back = true;
			m_UIDownApi = true;
		}
	}
	/*if (key == 'w')
	{
	m_pFPSCamera->SetzSpeed(0.2);
	}
	if (key == 's')
	{
	m_pFPSCamera->SetzSpeed(-0.2);
	}
	if (key == 'a')
	{
	m_pFPSCamera->SetxSpeed(0.2);
	}
	if (key == 'd')
	{
	m_pFPSCamera->SetxSpeed(-0.2);
	}
	}
	else
	{
	if (key == 'w' || key == 's')
	m_pFPSCamera->SetzSpeed(0);
	if (key == 'a' || key == 'd')
	m_pFPSCamera->SetxSpeed(0);*/

	//}
}