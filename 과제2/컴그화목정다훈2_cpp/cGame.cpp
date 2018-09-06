#include "cGame.h"
#include "cMain.h"
#include <time.h>
#include <string.h>
cGame::cGame()
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	m_pCaveBool = false;
	srand((time(NULL)));
	m_NowChage = -1;
	m_NowObjectChage = -1;
	m_Chage = STATE2D;
	for (int i = 0; i < 3; i++)
		m_pCam[i] = NULL;
	m_pvObject.clear();
	m_pEdge = NULL;
	m_Mode = 0;
	m_pCave = NULL;
	m_CreateObjectNumber = 0;
	m_pLight = NULL;
	for (int i = 0; i < MAXDAY;i++)
	m_pDay[i] = NULL;
	m_nowDay = 0;
	m_load = false;
}
cGame::~cGame()
{
	glDisable(GL_BLEND);
	SAFE_DELETE(m_pLight);
	for (int i = 0; i < 3; i++)
		SAFE_DELETE(m_pCam[i]);
	for (int i = 0; i < m_pvObject.size(); i++)
		SAFE_DELETE(m_pvObject[i]);

	for (int i = 0; i < m_pvPointObject.size(); i++)
		SAFE_DELETE(m_pvPointObject[i]);
	SAFE_DELETE(m_pEdge);
	for (int i = 0; i < MAXDAY; i++)
		SAFE_DELETE(m_pDay[i]);
}
void cGame::ChageView()
{
	if (m_Chage == STATE3D)
	{
		m_nowDay = 0;
		glEnable(GL_COLOR_MATERIAL);
		glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
		glEnable(GL_LIGHTING);
		glEnable(GL_NORMALIZE);
		m_pLight->ReSetting();
		m_pLight->On();
		m_CreateObjectNumber = 0;
		m_Mode = 0;
		for (int i = 0; i < m_pvPointObject.size(); i++)
		{
			m_pvPointObject[i]->ChageMode(m_Mode);
		}
		for (int i = 0; i < m_pvObject.size(); i++)
			m_pvObject[i]->ChageMode(m_Mode);

		for (int i = 0; i < m_pvObject.size(); i++)
			m_pvObject[i]->m_DrawFont = 0;
		glutWarpPointer(m_WindowsW / 2, m_WindowsH / 2);

		m_NowCam = VIEWCAM;
		m_pCam[m_NowCam]->SetEye(910, 580, -567);
		m_pCam[m_NowCam]->SetLook(-0.86, -0.43, 0.26);
		m_pCam[m_NowCam]->SetXAngle(2.84);
		m_pCam[m_NowCam]->SetYAngle(-0.44);
		GLfloat fAspect = (GLfloat)m_WindowsW / (GLfloat)m_WindowsH;
		glViewport(0, 0, m_WindowsW, m_WindowsH);
		glLoadIdentity();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(45, fAspect, 1, 3000.0);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
	else
	{

		glDisable(GL_COLOR_MATERIAL);
		glDisable(GL_SMOOTH);
		glDisable(GL_LIGHTING);
		m_pLight->Off();

		glViewport(0, 0, m_WindowsW, m_WindowsH);
		glLoadIdentity();
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glOrtho(0, m_WindowsW, m_WindowsH, 0, -1, 1);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
	}
}
void cGame::InitWindown(int w, int h)
{
	m_WindowsW = w;
	m_WindowsH = h;
	for (int i = 0; i < 3; i++)
	{
		if (m_pCam[i] != NULL)
		{
			m_pCam[i]->SetWindowns(m_WindowsW, m_WindowsH);
		}

	}
	if (m_pLight == NULL)
		m_pLight = new cLight;
	ChageView();
}
void cGame::Init()
{
	m_Chage = STATE2D;
	if (m_pCam[0] == NULL)
	{
		m_pCam[0] = new cFpsCam(cVector(100, 2, 100));
	}
	if (m_pCam[2] == NULL)
	{
		m_pCam[2] = new cFreeCam();
	
	}
	if (m_pCam[1] == NULL)
	{
		m_pCam[1] = new c3rdCam();
	

	}
	if (m_pEdge == NULL)
	{
		m_pEdge = new cEdge();
	}

	

	m_pDay[0] = new cHot();
		m_pDay[1] = new cShow(cVector(-900, 1200, -650), cVector(900, 1500, 650), 0.5, 45);
		m_pDay[2] = new cRain(cVector(-900, 1200, -650), cVector(900, 1500, 650), 0.5, 45);
	m_pvObject.push_back(new cBackGround());
		CreaetTree(12);
}
void cGame::Destroy()
{

	for (int i = 0; i < 3; i++)
		SAFE_DELETE(m_pCam[i]);
	SAFE_DELETE(m_pEdge);

	for (int i = 0; i < m_pvObject.size(); i++)
		SAFE_DELETE(m_pvObject[i]);
	for (int i = 0; i < m_pvPointObject.size(); i++)
		SAFE_DELETE(m_pvPointObject[i]);
}
void cGame::Update(float time)
{
	static float time1 = 0;

	m_pEdge->Update(time);
	if (m_Chage == STATE3D)
	{
		time1 += time;
		if (time1 >= 80)
		{
			m_nowDay++;
			m_nowDay %= MAXDAY;
			time1 = 0;
		}
			
		if (m_nowDay == 0) // 맑은날씨
		{

			m_pLight->MaxF = 0.8f;
			m_pLight->Speed = 0.045;
			m_pLight->Speed1 = 0.045;
		}
		if (m_nowDay == 1) // 눈
		{
			m_pLight->MaxF = 0.6f;
			m_pLight->Speed = 0.05;
			m_pLight->Speed1 = 0.045;
		}
		if (m_nowDay == 2) // 비
		{
			m_pLight->MaxF = 0.7;
			m_pLight->Speed = 0.05;
			m_pLight->Speed1 = 0.05;
		}
		m_pDay[m_nowDay]->Update(time);
		m_pLight->Update();
		if (m_pLight->AmbientLight[0] > 0.45)
		{
			for (int i = 0; i < m_pvObject.size(); i++)
			{
				glDisable(GL_LIGHT2);
				glDisable(GL_LIGHT1);
				glDisable(GL_LIGHT3);
				glDisable(GL_LIGHT4);
				glDisable(GL_LIGHT5);
				m_pvObject[i]->m_anglecheck = 0;

			}
		}
		else
		{
			glEnable(GL_LIGHT2);
			glEnable(GL_LIGHT1);
			glEnable(GL_LIGHT3);
			glEnable(GL_LIGHT4);
			glEnable(GL_LIGHT5);
			for (int i = 0; i < m_pvObject.size(); i++)
				m_pvObject[i]->m_anglecheck = 1;
		}
	}
	else
		time1 = 0;
	
}

void cGame::Render() //드로우
{
	if (m_Chage == STATE3D)
		Render3D();
	else
		Render2D();
	glutSwapBuffers();

}


void cGame::Render2D()
{
	glDisable(GL_DEPTH_TEST);
	//glDisable(GL_CULL_FACE);

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	m_pvObject[0]->Render2D();
	m_pEdge->Render2D();

	for (int i = 1; i < m_pvObject.size(); i++)
		m_pvObject[i]->Render2D();

	for (int i = 0; i < m_pvPointObject.size(); i++)
		m_pvPointObject[i]->Render2D();

}
void cGame::Render3D()
{
	glEnable(GL_DEPTH_TEST);
	//glEnable(GL_CULL_FACE);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if(m_NowCam != 0)
	m_pCam[m_NowCam]->Update();
	m_pDay[m_nowDay]->Render();
	for (int i = 0; i < m_pvPointObject.size(); i++)
		m_pvPointObject[i]->Render3D();
	for (int i = 0; i < m_pvObject.size(); i++)
		m_pvObject[i]->Render3D();
	m_pEdge->Render3D();

	m_pLight->Render();
	//glPushMatrix();
	//GLfloat mat_emission[] = { 0, 80.0, 0.0, 1.0 };

	//GLfloat mat_specular[] = { 0, 0, 0, 1.0 };
	////GLfloat light_position[] = { 0.0, 0.2, 0.2, 1.0 };
	//glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	//glMateriali(GL_FRONT, GL_SHININESS, 128);
	//glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
	//glColor4f(1, 1, 0, 1);
	//glutSolidSphere(1.0, 20, 16); /* draw sun */
	//glPopMatrix();
	/*if (m_NowCam ==FPSCAM)
	{
		cVector t = m_pEdge->GetNowVector();
	

		float t12 = t.y;
		float t22 = t.z + 30;
		t.z = t12;
		t.y = t22;

	
		m_pCam[m_NowCam]->SetLook(t);
		m_pCam[m_NowCam]->SetEye(m_pEdge->TEMPS);
	}*/


	/*

	glPushMatrix();
	glColor3ub(50, 255, 80);

	glTranslatef(D.x, D.y, -D.z);
	glScalef(1000, 700, 1);
	glutSolidCube(1);
	glPopMatrix();

	
	glPushMatrix();
	glTranslatef(0, test, 0);
	glColor3f(1, 1, 1);

	glutWireCube(10);
	glPopMatrix();*/

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
void cGame::MouseMove(int x, int y) //마우스무드상태
{
	if (m_Chage == STATE3D)
	{
		m_pCam[m_NowCam]->MouseMove(x, y);
	}
	else
	{
		if (m_NowChage != -1)
		{
			if(m_pvPointObject[m_NowChage]->GetSP())
			m_pvPointObject[m_NowChage]->Set2DVector(cVector(x - 15, y - 15, 0));
			else
				m_pvPointObject[m_NowChage]->Set2DVector(cVector(x - 10, y - 10, 0));
			m_pEdge->GetSP2DLine(false);
		}
		if (m_NowObjectChage != -1)
		{
			cVector Temp = m_pvObject[m_NowObjectChage]->GetSclVector();
		if(m_pvObject[m_NowObjectChage]->GetType() == 0)
			m_pvObject[m_NowObjectChage]->Set2DVector(cVector(x , y - Temp.y / 2, 0));
		else
			m_pvObject[m_NowObjectChage]->Set2DVector(cVector(x - Temp.x / 2, y - Temp.y / 2, 0));

		}
	}
}
void cGame::MouseClick(int button, int state, int x, int y) // 마우스클릭상태
{

	if (m_Chage == STATE2D)
	{
		if (state == GLUT_DOWN)
		{
			if ((button == GLUT_LEFT_BUTTON))
			{
				if (m_Mode != 2)
					CreateMoveModeMouse(x, y);
				else if(m_Mode == 2)
					SizeUp(x, y);
			}
			else if((button == GLUT_RIGHT_BUTTON) && m_Mode == 2)
				SizeDown(x, y);

		}

	}

}
void cGame::SizeDown(int x, int y)
{
	int number = -1;
	int objectnumber = -1;
	if (m_draw == 0)
	{
		for (int i = 0; i < m_pvPointObject.size(); i++)
		{
			if (m_pvPointObject[i]->Coll2d(cVector(x , y , 0), cVector(10, 10, 0)))
			{
				number = -1;
			}
			else
			{
				number = i;
				break;
			}
		}
	}
	for (int i = 1; i < m_pvObject.size(); i++)
	{
		if (m_pvObject[i]->Coll2d(cVector(x , y , 0), cVector(10, 10, 0)))
		{
			objectnumber = -1;
		}
		else
		{
			objectnumber = i;
			break;
		}
	}
	if (number != -1)
	{
		m_pvPointObject[number]->ZDown();
		printf("사이즈조절 현재 사이즈 : %f(최저 60)\n", m_pvPointObject[number]->GetSclVector().z);
	}
	if (objectnumber != -1)
	{
			m_pvObject[objectnumber]->ZDown();
			printf("OBJECT 사이즈조절Z 현재 사이즈 : %f(최저 20)\n", m_pvObject[objectnumber]->GetSclVector().z);
	
	}
}
void cGame::SizeUp(int x, int y)
{
	int number = -1;
	int objectnumber = -1;
	if (m_draw == 0)
	{
		for (int i = 0; i < m_pvPointObject.size(); i++)
		{
			if (m_pvPointObject[i]->Coll2d(cVector(x , y , 0), cVector(10, 10, 0)))
			{
				number = -1;
			}
			else
			{
				number = i;
				break;
			}
		}
	}

	for (int i = 1; i < m_pvObject.size(); i++)
	{
		if (m_pvObject[i]->Coll2d(cVector(x , y , 0), cVector(10, 10, 0)))
		{
			objectnumber = -1;
		}
		else
		{
			objectnumber = i;
			break;
		}
	}
	if (number != -1)
	{
		m_pvPointObject[number]->ZUp();
		printf("사이즈조절 현재 사이즈 : %f(최대 300)\n", m_pvPointObject[number]->GetSclVector().z);
	}
	if (objectnumber != -1)
	{
		
			m_pvObject[objectnumber]->ZUp();
			printf("OBJECT 사이즈조절Z 현재 사이즈 : %f(최대 100)\n", m_pvObject[objectnumber]->GetSclVector().z);
	
	}
}
void cGame::CreateMoveModeMouse(int x, int y)
{
	if (m_Mode == 0)
	{
		if (m_NowChage == -1)
		{
			bool n = false;

			if (x < 20 || y <20 || y > 680 || x > 980)
				n = true;
			cPointObject* Temp = new cPointObject;
			Temp->Set2DVector(cVector(x - 10, y - 10, 1));

			for (int j = 1; j < m_pvObject.size(); j++)
			{
				if (!Temp->Coll2d(m_pvObject[j]->Get2DVector(), m_pvObject[j]->GetSclVector()))
				{
					n = true;
					break;
				}
			}
			if (!n)
			{
				if (m_pvPointObject.size() == 0)
				{
					Temp->Set2DVector(cVector(x - Temp->GetSclVector().x/2, y - Temp->GetSclVector().y / 2, 1));
					Temp->StartObject();
					m_pvPointObject.push_back(Temp);
					return;
				}
				else
				{
					int number = 0;
					for (int i = 0; i < m_pvPointObject.size(); i++)
					{
						if (m_pvPointObject[i]->Coll2d(Temp->Get2DVector(), Temp->GetSclVector()))
						{
							number = -1;
						}
						else
						{
							number = i;
							break;
						}
					}

					if (number != -1)
					{
						printf("충돌 움직임 상태\n");
						m_NowChage = number;

					}
					else
					{
						m_pvPointObject.push_back(Temp);
						m_pEdge->SettingPoint(m_pvPointObject);
						m_pEdge->GetSP2DLine();
					}
				}
			}

		}
		else
		{

			int number = 0;
			bool n = false;
			if (x < 20 || y <20 || y > 680 || x > 980)
				n = true;
			for (int i = 0; i < m_pvPointObject.size(); i++)
			{
				for (int j = 1; j < m_pvObject.size(); j++)
				{
					if (!m_pvPointObject[i]->Coll2d(m_pvObject[j]->Get2DVector(), m_pvObject[j]->GetSclVector()))
					{
						n = true;
						break;
					}
				}
			}
			if (!n)
			{
				for (int i = 0; i < m_pvPointObject.size(); i++)
				{
					if (i == m_NowChage)
						continue;

					if (m_pvPointObject[i]->Coll2d(m_pvPointObject[m_NowChage]->Get2DVector(), m_pvPointObject[m_NowChage]->GetSclVector()))
					{
						number = -1;
					}
					else
					{
						number = i;
						break;
					}
				}
				if (number == -1  || m_pvPointObject.size() == 1)
					m_NowChage = -1;
			}

		}
	}
	else if (m_Mode == 1)
	{
		if (m_NowObjectChage == -1)
		{
			int number = 0;
			bool n = false;
			cBaseObject* Temp = NULL;
			cCave* Temp1 = NULL;

			if (m_CreateObjectNumber == 0)
				Temp = new cTree;
			else if (m_CreateObjectNumber == 1)
				Temp = new cCity;
			else if (m_CreateObjectNumber == 3)
			{
				Temp = 	Temp1 = new cCave;
			}
			
				Temp->Set2DVector(cVector(x - Temp->GetSclVector().x / 2, y - Temp->GetSclVector().y / 2, 0));
				for (int j = 0; j < m_pvPointObject.size(); j++)
				{
					if (!m_pvPointObject[j]->Coll2d(Temp->Get2DVector(), Temp->GetSclVector()))
					{
						n = true;
						break;
					}
				}
			if (n == false)
			{

				for (int i = 1; i < m_pvObject.size(); i++)
				{
					if (m_pvObject[i]->Coll2d(cVector(x - 5, y - 5, 0), cVector(10, 10, 0)))
					{
						number = -1;
					}
					else
					{
						number = i;
						break;
					}
				}
				if (number != -1)
				{
					printf("objects 충돌 움직임 상태\n");
					m_NowObjectChage = number;
				}
				else
				{
					
					if (Temp != NULL)
					{
						if (Temp->GetType() == 2 && m_pCaveBool == false)
						{
							m_pCave = Temp1;
							m_pCaveBool = true;
							m_pvObject.push_back(Temp);

						}
						if(Temp->GetType() !=2 )
							m_pvObject.push_back(Temp);

					
					


					}

				}
			}
			
		}
		else
		{
			bool n = false;

			for (int i = 0; i < m_pvPointObject.size(); i++)
			{
				for (int j = 1; j < m_pvObject.size(); j++)
				{
					if (!m_pvPointObject[i]->Coll2d(m_pvObject[j]->Get2DVector(), m_pvObject[j]->GetSclVector()))
					{
						n = true;
						break;
					}
				}
			}
			if (n == false)
			{
				int number = 0;
				for (int i = 1; i < m_pvObject.size(); i++)
				{
					if (i == m_NowObjectChage)
						continue;

					if (m_pvObject[i]->Coll2d(m_pvObject[m_NowObjectChage]->Get2DVector(), m_pvObject[m_NowObjectChage]->GetSclVector()))
					{
						number = -1;
					}
					else
					{
						number = i;
						break;
					}
				}
				if (number == -1 || m_pvObject.size() == 1)
					m_NowObjectChage = -1;
			}
		
		}
	}
	
}


void cGame::SKeyBoard(int Type, int key, int x, int y) //스페셜
{
	if (m_load)
		return;
	if (Type == KEYBOARDDOWN)
	{
		if (m_Chage == STATE3D)
		{
			if (key == GLUT_KEY_F1)
			{
				m_NowCam = FPSCAM;
				m_pEdge->Setting(m_NowCam);


			}
			else if (key == GLUT_KEY_F2)
			{
				m_NowCam = VIEWCAM;
				m_pCam[m_NowCam]->SetEye(910, 580, -567);
				m_pCam[m_NowCam]->SetLook(-0.86, -0.43, 0.26);
				m_pCam[m_NowCam]->SetXAngle(2.84);
				m_pCam[m_NowCam]->SetYAngle(-0.44);
				m_pEdge->Setting(m_NowCam);

			}
			else if (key == GLUT_KEY_F3)
			{
				m_NowCam = FREECAM;
				m_pCam[m_NowCam]->SetEye(m_pCam[VIEWCAM]->GetEye());
				m_pCam[m_NowCam]->SetLook(m_pCam[VIEWCAM]->GetLook());
				m_pCam[m_NowCam]->SetXAngle(m_pCam[VIEWCAM]->GetXAngle());
				m_pCam[m_NowCam]->SetYAngle(m_pCam[VIEWCAM]->GetYAngle());
				m_pEdge->Setting(m_NowCam);

			}
		}
		else
		{
			if (key == GLUT_KEY_F1)
			{
				m_Mode = 0;
				printf("POINT MOVEING , CREATE MODE\n");
				for (int i = 0; i < m_pvPointObject.size(); i++)
				{
					m_pvPointObject[i]->ChageMode(m_Mode);
				}
				for (int i = 0; i < m_pvObject.size(); i++)
					m_pvObject[i]->ChageMode(m_Mode);
				for (int i = 0; i < m_pvObject.size(); i++)
					m_pvObject[i]->m_DrawFont = 0;
				m_NowChage = -1;
				m_NowObjectChage = -1;
			}
			else if (key == GLUT_KEY_F2)
			{
				m_Mode = 1;
				printf("OJBECTS MOVEING , CREATE MODE\n");
				for (int i = 0; i < m_pvPointObject.size(); i++)
				{
					m_pvPointObject[i]->ChageMode(m_Mode);
				}
				for (int i = 0; i < m_pvObject.size(); i++)
					m_pvObject[i]->ChageMode(m_Mode);
				for (int i = 0; i < m_pvObject.size(); i++)
					m_pvObject[i]->m_DrawFont = 0;
				m_NowChage = -1;
				m_NowObjectChage = -1;
			}
			else if (key == GLUT_KEY_F3)
			{
				m_Mode = 2;
				printf("Z SIZE  MODE\n");
				for (int i = 0; i < m_pvPointObject.size(); i++)
				{
					m_pvPointObject[i]->ChageMode(m_Mode);
				}
				for (int i = 0; i < m_pvObject.size(); i++)
					m_pvObject[i]->ChageMode(m_Mode);
				for (int i = 0; i < m_pvObject.size(); i++)
					m_pvObject[i]->m_DrawFont = 0;
				m_NowChage = -1;
				m_NowObjectChage = -1;
				m_draw = 0;

			}
		}
		
	}


}
void cGame::KeyBoard(int Type, unsigned  char  key, int x, int y) //일반키
{

	if (Type == KEYBOARDDOWN)
	{
		if (m_Chage == STATE2D)
		{
			if (key == 'S' || key == 's')
			{
				printf("세이브모드\n");
				printf("이름 입력: (100자아래)\n");
				char test[104] = { 0, };
				scanf("%s", &test);
				int n = strlen(test);
				test[n] = '.';
				test[n + 1] = 't';
				test[n + 2] = 'x';
				test[n + 3] = 't';
				test[n + 4] = NULL;

				printf("입력 하신 파일 이름 (.txt 자동추가) %s\n", test);
				string t = "res/Map/";
				t += test;
				FILE* fp = fopen(t.c_str(), "w");

				fprintf(fp, "%d\n", (m_pvObject.size() + m_pvPointObject.size())-1);
				for (int i = 0; i < m_pvPointObject.size(); i++)
				{
					fprintf(fp, "%d %f %f %f 1 1 1 0\n", -1, m_pvPointObject[i]->Get2DVector().x, m_pvPointObject[i]->Get2DVector().y, m_pvPointObject[i]->GetSclVector().z);
				}
				for (int i = 1; i < m_pvObject.size(); i++)
				{
					fprintf(fp, "%d %f %f %f %d %d %d %d\n", m_pvObject[i]->GetType(), m_pvObject[i]->Get2DVector().x,
						m_pvObject[i]->Get2DVector().y, m_pvObject[i]->GetSclVector().z, m_pvObject[i]->m_Color[0], m_pvObject[i]->m_Color[1], m_pvObject[i]->m_Color[2],m_pvObject[i]->m_CaveAngle);
				}

				fclose(fp);
				printf("저장완료\n");
			}
			if (key == 'L' || key == 'l')
			{
				printf("로드모드\n");
				printf("이름 입력: (100자아래 txt제외.)\n");
				char test[104] = { 0, };
				scanf("%s", &test);
				int n = strlen(test);
				test[n] = '.';
				test[n + 1] = 't';
				test[n + 2] = 'x';
				test[n + 3] = 't';
				test[n + 4] = NULL;
				string t = "res/Map/";
				t += test;
				FILE* fp = fopen(t.c_str(), "r");

				if (fp == NULL)
				{
					printf("파일 이름 잘못됨(txt입력했는지 ,res/Map/안에있는지확인!\n");
					return;
				}
				int number = 0;
				fscanf(fp, "%d\n", &number);
				for (int i = 0; i < m_pvObject.size(); i++)
					SAFE_DELETE(m_pvObject[i]);
				for (int i = 0; i < m_pvPointObject.size(); i++)
					SAFE_DELETE(m_pvPointObject[i]);
				SAFE_DELETE(m_pEdge);
				m_pvPointObject.clear();
				m_pvObject.clear();


				m_pEdge = new cEdge();
				m_pvObject.push_back(new cBackGround());
				int number1 = 0;

				for (int i = 0; i < number; i++)
				{
					int type;
					float x;
					float y;
					float z;
					int r;
					int g;
					int b;
					int angle;
					fscanf(fp, "%d %f %f %f %d %d %d %d\n", &type,&x,&y,&z,&r,&g,&b,&angle);
					if (type == -1)
					{
						if (m_pvPointObject.size() == 0)
						{
							cPointObject* Temp = new cPointObject;
							Temp->Set2DVector(cVector(x, y, z));
							Temp->StartObject();
							Temp->SetSclVector(cVector(Temp->GetSclVector().x, Temp->GetSclVector().y, z));

							m_pvPointObject.push_back(Temp);
						}
						else
						{
							cPointObject* Temp = new cPointObject;
							Temp->Set2DVector(cVector(x, y, z));
							Temp->SetSclVector(cVector(Temp->GetSclVector().x, Temp->GetSclVector().y, z));

							m_pvPointObject.push_back(Temp);
						}
					}
					else
					{
						if (type == 0)
						{
							cTree*	Temp = new cTree;
							Temp->Set2DVector(cVector(x, y, z));
							Temp->SetSclVector(cVector(Temp->GetSclVector().x, Temp->GetSclVector().y, z));

							m_pvObject.push_back(Temp);
						}
						else if (type == 1)
						{
							cCity*	Temp = new cCity;
							Temp->Setting(r, g, b);
							Temp->Set2DVector(cVector(x, y, z));
							Temp->SetSclVector(cVector(Temp->GetSclVector().x, Temp->GetSclVector().y, z));
							m_pvObject.push_back(Temp);
						}
						else if (type == 2)
						{
							cCave*	Temp = new cCave;
							Temp->Set2DVector(cVector(x, y, z));
							Temp->m_CaveAngle = angle;
							Temp->SetSclVector(cVector(Temp->GetSclVector().x, Temp->GetSclVector().y, z));

							m_pCave = Temp;
							m_pvObject.push_back(Temp);
							m_pCaveBool = true;

						}
						else if (type == 4)
						{
							cLightObject*	Temp = new cLightObject;
							

							Temp->Set2DVector(cVector(x, y, z));
							Temp->SetSclVector(cVector(Temp->GetSclVector().x, Temp->GetSclVector().y, z));
							Temp->Setting(number1);
							number1++;
							m_pvObject.push_back(Temp);
						}

					}

				}
				m_pEdge->SettingPoint(m_pvPointObject);
				m_pEdge->GetSP2DLine();
				printf("로드완료\n");
			}
		
		}
		if (m_Mode == 1)
		{

			if (key == '1')
			{
				if (m_Chage == STATE2D) // 나무그리기모드
				{
					m_CreateObjectNumber = 0;
					printf("나무그리기모드!\n");
				}
			}
			else if (key == '2')
			{
				if (m_Chage == STATE2D) // 시티그리기모드
				{
					m_CreateObjectNumber = 1;
					printf("시티그리기모드!\n");

				}
			}
			else if (key == '3')
			{
				if (m_Chage == STATE2D)
				{
					if (m_CreateObjectNumber == 3)
					{
						if (m_pCaveBool)
						{
							printf("동굴 5도씩 회전\n");
							m_pCave->SetAngle(5);



						}
					}
					else
					{
						m_CreateObjectNumber = 3;
						printf("동굴그리기모드\n");
					}

				}
			}
		}
	if (key == 'p' || key == 'P')
		{
			m_Chage == STATE2D ? m_Chage = STATE3D : m_Chage = STATE2D;
			ChageView();
			for (int i = 0; i < m_pvPointObject.size(); i++)
				m_pvPointObject[i]->Chage2Dto3D();
			for (int i = 0; i < m_pvObject.size(); i++)
				m_pvObject[i]->Chage2Dto3D();
			m_pEdge->SettingPoint(m_pvPointObject);
			m_pEdge->GetSPline();

			m_NowChage = -1;
			m_NowObjectChage = -1;
			m_draw = 0;
			m_pEdge->SettingCam(m_pCam[0]);

		}
	
	}
	else
	{
		

	}
	if (m_Chage == STATE3D)
	{
		if (Type == KEYBOARDDOWN)
		{

			if (key == 'M' || key == 'm')
			{
				m_pDay[m_nowDay]->ClearRe();
				m_nowDay++;
				m_nowDay %= MAXDAY;
			}

			m_pEdge->Key(key);
		}
		m_pCam[m_NowCam]->KeyBoard(Type, key);
	}


}