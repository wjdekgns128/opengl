#include "cLogo.h"
#include "cMain.h"

cLogo::cLogo()
{
	m_pFPSCamera = NULL;
	m_NextEventTime = 0.0;
	m_NextSceen = 0.0;
	m_number = 0;
}
cLogo::~cLogo()
{
	SAFE_DELETE(m_pFPSCamera);
	

}
void cLogo::InitWindown(int w, int h)
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
void cLogo::Init()
{
	m_NextEventTime = 0.0;

	if (m_pFPSCamera == NULL)
	{
		m_pFPSCamera = new cFPSCamera;
		m_pFPSCamera->SetEye(-11, 0, 0);

	
	}

	for (int y = 0; y < 10; y++)
	{
		for (int i = 0; i < 10; i++)
		{
			m_ppObject[y][i].SetVector(cVector(-2, y - 4.5, i - 4.5));
			if ((y > 3 && y < 9 && i == 0 )||(y == 6 &&  (i== 1))||
				(y == 5 || y ==7)&& (i==2) || (y == 4 || y == 8) && (i == 3))
				m_ppObject[y][i].Setting(1);
			else if(((y <=6 && y >= 2) && i == 4) || (y == 6 && (i>4 && i < 7))
				|| (y == 5 && (i==6)) || (y == 4 && (i == 6)) 
				|| (y == 4 && (i == 5)))
				m_ppObject[y][i].Setting(2);
			else if(i ==7 && (y <=4 && y >1)
				|| y == 1 && (i>=7 && i<=9)
				|| (i == 9 && (y <= 4 && y >1)))
				m_ppObject[y][i].Setting(3);

			if(i==0 || y ==9 ||y ==0 || i == 9)
				m_ppObject[y][i].SetEffectTime(0.34);
			else if (i == 1 || y == 8 || y == 1 || i == 8)
				m_ppObject[y][i].SetEffectTime(0.26);
			else if (i == 2 || y == 7 || y == 2 || i == 7)
				m_ppObject[y][i].SetEffectTime(0.18);
			else if (i == 3 || y == 6 || y == 3 || i == 6)
				m_ppObject[y][i].SetEffectTime(0.1);
			else
				m_ppObject[y][i].SetEffectTime(0);

		}

	}
	/*m_ppObject[5][4].SetEffectTime(1);

	m_ppObject[6][3].SetEffectTime(1.5);
	m_ppObject[6][4].SetEffectTime(1.5);
	m_ppObject[5][3].SetEffectTime(1.5);

	m_ppObject[5][2].SetEffectTime(2);
	m_ppObject[6][2].SetEffectTime(2);
	m_ppObject[7][2].SetEffectTime(2);
	m_ppObject[7][3].SetEffectTime(2);
	m_ppObject[7][4].SetEffectTime(2);



	m_ppObject[5][1].SetEffectTime(2.5);
	m_ppObject[6][1].SetEffectTime(2.5);
	m_ppObject[7][1].SetEffectTime(2.5);
	m_ppObject[8][1].SetEffectTime(2.5);
	m_ppObject[8][2].SetEffectTime(2.5);
	m_ppObject[8][3].SetEffectTime(2.5);
	m_ppObject[8][4].SetEffectTime(2.5);


	m_ppObject[5][0].SetEffectTime(3);
	m_ppObject[6][0].SetEffectTime(3);
	m_ppObject[7][0].SetEffectTime(3);
	m_ppObject[8][0].SetEffectTime(3);
	m_ppObject[9][0].SetEffectTime(3);
	m_ppObject[9][1].SetEffectTime(3);
	m_ppObject[9][2].SetEffectTime(3);
	m_ppObject[9][3].SetEffectTime(3);
	m_ppObject[9][4].SetEffectTime(3);
*/

}
void cLogo::Destroy()
{
	
	SAFE_DELETE(m_pFPSCamera);
	
}
void cLogo::Update(float time)
{
	m_NextSceen += time;
	if (m_number < 100)
	{
		m_NextEventTime += time;
		if (m_NextEventTime > 3.3) // 모두 내려오면
		{
			m_NextEventTime = 0;
			EffectChage(5, 5);

		}
	}
	if (m_NextSceen > 4.25)
	{
		m_NextSceen = 0.0;
		cMain::GetInstance()->Trans(1);
	}
	for (int y = 0; y < 10; y++)
	{
		for (int i = 0; i < 10; i++)
		{
			m_ppObject[y][i].Update(time);
		}
	}
}
void cLogo::EffectChage(int y, int z)
{
	if (y < 0 || y > 9 || z < 0 || z > 9)
		return;
	if (m_ppObject[y][z].GetEventType() == 1)
	{
		m_ppObject[y][z].Effect();
		EffectChage(y + 1,z);
		EffectChage(y - 1, z);
		EffectChage(y , z+1);
		EffectChage(y , z-1);

		m_number++;
	}
}
void cLogo::Render() //드로우
{
	Render3D();
	Render2D();
	glutSwapBuffers();

}
void cLogo::MouseClick(int button, int state, int x, int y) // 마우스클릭상태
{
}

void cLogo::Render2D()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, m_WindowsW, m_WindowsH, 0, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

}
void cLogo::Render3D()
{
	glEnable(GL_DEPTH_TEST);
	GLfloat fAspect = (GLfloat)m_WindowsW / (GLfloat)m_WindowsH;
	glViewport(0, 0, m_WindowsW, m_WindowsH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, fAspect, 1.0, 200.0);
	glMatrixMode(GL_MODELVIEW);
	


	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	m_pFPSCamera->Update();
	for (int y = 0; y < 10; y++)
	{
		for (int i = 0; i < 10; i++)
		{
			m_ppObject[y][i].Render();
		}
	}
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

}
void cLogo::MouseMove(int x, int y) //마우스무드상태
{
	//int dx = x - m_WindowsW / 2;
	//int dy = m_WindowsH / 2 - y;
	//if (dx)
	//	m_pFPSCamera->SetAddXAngle(ToRadian(0.2*dx));
	//if (dy)
	//	m_pFPSCamera->SetAddYAngle(ToRadian(0.2*dy));

}
void cLogo::SKeyBoard(int Type, int key, int x, int y) //스페셜
{

	

}
void cLogo::KeyBoard(int Type, unsigned  char  key, int x, int y) //일반키
{

	
	/*if (Type == KEYBOARDDOWN)
	{
	if (key == 'w')
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
	m_pFPSCamera->SetxSpeed(0);

	}*/
}