#include "cGame.h"
#include "cMain.h"
bool			g_Moveing = false;
int				g_Type = 0;
void Selete(int v);
void SeleteMap(int v);
int				m_xCount =5 ;
int				m_zCount = 5;
int				m_yCount= 7;
bool			g_Gird= true;
cBaseObject*		m_pSeleteObject = NULL;
void Selete(int v)
{
	if (m_pSeleteObject != NULL)
		SAFE_DELETE(m_pSeleteObject);
	if (v == START)
	{
		m_pSeleteObject = new cStartObject();
		g_Type = START;
	}
	else if (v == END)
	{
		m_pSeleteObject = new cEndObject();
		g_Type = END;
	}
	else if (v == WALL)
	{
		m_pSeleteObject = new cWallObject();
		g_Type = WALL;
	}
	else if (v == EMPTY)
	{
		m_pSeleteObject = new cEmptyObject();
		g_Type = EMPTY;
	}
	else if (v == HARDWALL)
	{
		m_pSeleteObject = new cHardWallObject();
		g_Type = HARDWALL;
	}
}
void SeleteMap(int v)
{
	if (v == 0)
	{
		m_zCount = 5;
		m_xCount = 5;
		m_yCount = 7;
	}
	else if (v == 1)
	{
		m_zCount = 5;
		m_xCount = 5;
		m_yCount = 8;
	}
	else if (v == 2)
		g_Gird = !g_Gird;
}
cGame::cGame()
{
	m_angle = 0;
	m_createstate = false;
	m_anglecheck = 0;
	m_pFPSCamera = NULL;
	m_pPlayer = NULL;
	m_pShow = NULL;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			for (int z = 0; z < 8; z++)
				m_pppObject[i][j][z] = nullptr;
		}
	}
	//cBaseObject**		_test[5][5];
	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j < 5; j++)
	//		_test[i][j] = new cBaseObject*[8];
	//}
}
cGame::~cGame()
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_pFPSCamera);
	SAFE_DELETE(m_pShow);
	for (int i = 0; i < m_xCount; i++)
	{
		for (int j = 0; j < m_zCount; j++)
		{
			for (int z = 0; z < m_yCount; z++)
			{
				SAFE_DELETE(m_pppObject[i][j][z]);
				SAFE_DELETE(m_pppCreateObject[i][j][z]);
			}
		}
	}
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
	if (m_pFPSCamera == NULL)
	{
		m_pFPSCamera = new cFPSCamera;
		CamReSetting();

	}
	for (int i = 0; i < m_xCount; i++)
	{
		for (int j = 0; j < m_zCount; j++)
		{
			for (int z = 0; z < m_yCount; z++)
			{
				m_pppObject[i][j][z] = new cEmptyObject(cVector((2 * i), (2 * z), (2 * j)), 0);
				m_pppCreateObject[i][j][z] = NULL;
			}
		}
	}
	if (m_pPlayer == NULL)
	{
		m_pPlayer = new cPlayer();
	}
	if (m_pShow == NULL)
		m_pShow = new cShow(m_yCount-1);
	m_viewcheck = false;
	m_createstate = false;
	GLint SubMenu = glutCreateMenu(SeleteMap);

	glutAddMenuEntry("5x5x7", 0);
	glutAddMenuEntry("5x5x8", 1);
	glutAddMenuEntry("그리드 on/off", 2);
	glutCreateMenu(SeleteMap);
	GLint SubMenu1 = glutCreateMenu(Selete);
	glutAddMenuEntry("EmptyObject", 0);
	glutAddMenuEntry("StartObject", 1);
	glutAddMenuEntry("EndObject", 2);
	glutAddMenuEntry("WallObject", 3);
	glutAddMenuEntry("HardWallObject", 4);

	glutCreateMenu(Selete);

	glutAddSubMenu("MapSize/그리드", SubMenu);
	glutAddSubMenu("Object Type", SubMenu1);

	
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	printf("키보드 1 : 자유이동\n");
	printf("키보드 R or r : 시점 원위치\n");
	printf("오브젝트설치 마우스오른쪽 파업창으로\n");
	printf("도형 파업창에서 w a s d y h 로 도형이동가능\n");
}
void cGame::Destroy()
{
	SAFE_DELETE(m_pFPSCamera);
	for (int i = 0; i < m_xCount; i++)
	{
		for (int j = 0; j < m_zCount; j++)
		{
			for (int z = 0; z < m_yCount; z++)
			{
				SAFE_DELETE(m_pppObject[i][j][z]);
				SAFE_DELETE(m_pppCreateObject[i][j][z]);
			}
		}
	}
}
int cGame::CollPlayer()
{
	int xNumber = (m_pPlayer->m_SettingVetor.x) / 2;
	int yNumber = (m_pPlayer->m_SettingVetor.y-0.7) / 2;
	int zNumber = (m_pPlayer->m_SettingVetor.z) / 2;
	//printf("%d %d %d\n", xNumber, yNumber, zNumber);

	if (xNumber >= m_xCount || yNumber >= m_yCount || zNumber >= m_zCount)
		return -1;
	if (xNumber < 0 || yNumber < 0 || zNumber < 0 || m_pPlayer->GetY() < -1)
		return -2;
	return m_pppCreateObject[xNumber][zNumber][yNumber]->GetType();
}
void cGame::Update(float time)
{
	static float Downtime = 0;

	if (m_createstate == false)
	{
		Downtime = 0;
		if (m_viewcheck)
			glutWarpPointer(m_WindowsW / 2, m_WindowsH / 2);
		if (m_pSeleteObject != NULL)
			m_pSeleteObject->Update();
	}
	else
	{
		if (m_anglecheck != 0)
		{
			if (m_anglecheck == 2)
			{
				m_pFPSCamera->m_DisAngle -= 5;
				m_angle -= 5;
				if (m_angle <= 0)
					m_anglecheck = 0;
			}
			else if (m_anglecheck == 1)
			{
				m_pFPSCamera->m_DisAngle += 5;
				m_angle += 5;
				if (m_angle >= 0)
					m_anglecheck = 0;
			}
		}
		int TempType = CollPlayer();
		if (TempType == START)
		{
			m_pPlayer->SetYDown(0.4 * Downtime);
			Downtime += time;
		}
		else if (TempType == EMPTY)
		{
			m_pPlayer->SetYDown(0.4 * Downtime);
			Downtime += time;
		}
		else if (TempType == END) // z축 -> 아래로 x축 한칸뛰고 y축
		{
			m_pPlayer->SetYDown(0.4 * Downtime);
			Downtime += time;
			printf("클리어\n");
			printf("세이브할 이름입력 (.txt)붙어서: \n");
			char name[100];
			scanf("%s", name);
			FILE* fp = fopen(name, "w");
			fprintf(fp, "%d %d\n", m_yCount - 7, m_Count);
			for (int z = 0; z < m_yCount; z++)
			{
				for (int i = 0; i < m_xCount; i++)
				{
					for (int j = 0; j < m_zCount; j++)
					{
						if(j != m_zCount -1)
							fprintf(fp, "%d ", m_pppObject[i][j][z]->GetType());
						else
							fprintf(fp, "%d", m_pppObject[i][j][z]->GetType());



					}
					fprintf(fp, "\n");
				}
				fprintf(fp, "\n");
			}


			fclose(fp);
			printf("%s 세이브완료\n", name);
			CamReSetting();
			m_createstate = false;
			m_pPlayer->SetState(0);
			glutAttachMenu(GLUT_RIGHT_BUTTON);
		}
		else if (TempType == -2)
		{
			Downtime = 0;
		}
		else
		{
			Downtime = 0;
		}

	}
	//printf("%f %f %f %f %f\n", m_pFPSCamera->GetEye().x, m_pFPSCamera->GetEye().y, m_pFPSCamera->GetEye().z, ToDegree(m_pFPSCamera->GetXAngle()), ToDegree(m_pFPSCamera->GetYAngle()));

}
void cGame::Render() //드로우
{
	Render3D();
	Render2D();
	glutSwapBuffers();

}
void cGame::DrawGrid()
{
	for (int y = 0; y < m_yCount; y++)
	{
		for (int i = 0; i < m_zCount; i++)
		{
			for (int j = 0; j < m_xCount; j++)
			{
				glBegin(GL_LINE_LOOP);
				glColor3f(1, 1, 1);
				glVertex3f(0, y * 2, 0);
				glVertex3f(0, y * 2, (j + 1) * 2);
				glVertex3f((i + 1) * 2, y * 2, (j + 1) * 2);
				glVertex3f((i + 1) * 2, y * 2, 0);
				glEnd();
				/*	glPushMatrix();
				glColor3f(i*0.1, j*0.1, y*0.1);
				glTranslatef((j * 2) + 1, y * 2 + 1, i * 2 + 1);
				glutSolidCube(2);
				glPopMatrix();*/
			}
		}
	}
}
void cGame::MouseClick(int button, int state, int x, int y) // 마우스클릭상태
{
}

void cGame::Render2D()
{
	glLoadIdentity();
	glDisable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, (GLdouble)m_WindowsW, 0.0, (GLdouble)m_WindowsH);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if (m_createstate)
	{
		glColor3f(1, 1, 1);
		char str1[100] = { 0, };
		_itoa_s(m_Count, str1, 10);
		glRasterPos2d(300, 570);
		for (unsigned int i = 0; i< strlen(str1); i++)
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str1[i]);
	}


}
void cGame::RotateSetting(int y)
{
	
	
	cBaseObject*		TempObject[5][5][8];
	for (int i = 0; i < m_xCount; i++)
	{
		for (int j = 0; j < m_zCount; j++)
		{
			int TempCheck = m_pppCreateObject[i][j][y]->GetType();
			cVector Temp = m_pppCreateObject[i][j][y]->GetVector();
			switch (TempCheck)
			{
			case START:
				TempObject[i][j][y] = new cStartObject();
				break;
			case END:
				TempObject[i][j][y] = new cEndObject();
				break;
			case WALL:
				TempObject[i][j][y] = new cWallObject();
				break;
			case EMPTY:
				TempObject[i][j][y] = new cEmptyObject();
				break;
			case HARDWALL:
				TempObject[i][j][y] = new cHardWallObject();
				break;


			}
			TempObject[i][j][y]->SetVector(Temp);
			TempObject[i][j][y]->SetAngle(m_pppCreateObject[i][j][y]->GetAngle());
		}
	}
	for (int i = 0; i < m_xCount; i++)
	{
		for (int j = 0; j < m_zCount; j++)
		{
		
				SAFE_DELETE(m_pppCreateObject[i][j][y]);
		}
	}
	for (int i = 0; i < m_xCount; i++)
	{
		for (int j = 0; j < m_zCount; j++)
		{
			int x = (int)((TempObject[i][j][y]->m_MathVector.x) / 2);
			int z = (int)((TempObject[i][j][y]->m_MathVector.z) / 2);
			int TempCheck = TempObject[i][j][y]->GetType();
			cVector Temp = TempObject[i][j][y]->GetVector();
			switch (TempCheck)
			{
			case START:
				m_pppCreateObject[x][z][y] = new cStartObject();
				break;
			case END:
				m_pppCreateObject[x][z][y] = new cEndObject();
				break;
			case WALL:
				m_pppCreateObject[x][z][y] = new cWallObject();
				break;
			case EMPTY:
				m_pppCreateObject[x][z][y] = new cEmptyObject(0);
				break;
			case HARDWALL:
				m_pppCreateObject[x][z][y] = new cHardWallObject();
				break;
			}
			m_pppCreateObject[x][z][y]->SetVector(Temp);
			m_pppCreateObject[x][z][y]->SetAngle(TempObject[i][j][y]->GetAngle());
		}
	}
	/*int x = (int)((m_pppCreateObject[i][j][y]->m_MathVector.x) / 2);
	int z = (int)((m_pppCreateObject[i][j][y]->m_MathVector.z) / 2);
	printf("%f %f %d %d %d %d\n", m_pppCreateObject[i][j][y]->m_MathVector.x, m_pppCreateObject[i][j][y]->m_MathVector.z, i, j, x, z);
	m_pppCreateObject[x][z][y]->SetVector(m_pppCreateObject[i][j][y]->GetVector());
	m_pppCreateObject[x][z][y]->SetType(m_pppCreateObject[i][j][y]->GetType());*/
}
void cGame::Render3D()
{
	glLoadIdentity();
	glEnable(GL_DEPTH_TEST);
	GLfloat fAspect = (GLfloat)m_WindowsW / (GLfloat)m_WindowsH;
	glViewport(0, 0, m_WindowsW, m_WindowsH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, fAspect, 1.0, 200.0);
	glMatrixMode(GL_MODELVIEW);
	m_pFPSCamera->Update(); //오차방지 업데이트(좌표셋팅)후 드로우
	/*static float x = 112.0 / 255.0;
	static int number = 0;*//*
	for (int i = 0; i < 5; i++)
	{*/

	glClearColor(30./ 255.0, 30. / 255.0, 30./ 255.0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	//x -= 0.0001;
	//}
	if (m_createstate == false)
	{
		if (g_Gird)
		{
			DrawGrid();
		}
		for (int i = 0; i < m_xCount; i++)
		{
			for (int j = 0; j < m_zCount; j++)
			{
				for (int z = 0; z < m_yCount; z++)
				{
					if (m_pppObject[i][j][z] != NULL)
						m_pppObject[i][j][z]->Render();
				}
			}
		}
		if (m_pSeleteObject != NULL)
		{
			m_pSeleteObject->Render();
			glPushMatrix();
			glLineWidth(10);

			glColor3f(0.5, 0.8, 1);
			glTranslatef(m_pSeleteObject->GetVector().x + 1, m_pSeleteObject->GetVector().y + 1, m_pSeleteObject->GetVector().z + 1);

			glutWireCube(2);
			glPopMatrix();
			glLineWidth(1);
		}
	}
	else
	{
		for (int i = 0; i < m_xCount; i++)
		{
			for (int j = 0; j < m_zCount; j++)
			{
				for (int z = 0; z < m_yCount; z++)
				{
					if (m_pppCreateObject[i][j][z] != NULL)
					{
						m_pppCreateObject[i][j][z]->Render();
					}
				}
			}
		}
		m_pPlayer->Render();
		m_pShow->Redner();
	}

}
void cGame::MouseMove(int x, int y) //마우스무드상태
{
	if (m_viewcheck)
	{
		int dx = x - m_WindowsW / 2;
		int dy = m_WindowsH / 2 - y;
		if (dx)
			m_pFPSCamera->SetAddXAngle(ToRadian(0.2*dx));
		if (dy)
			m_pFPSCamera->SetAddYAngle(ToRadian(0.2*dy));

	}

}
void cGame::SKeyBoard(int Type, int key, int x, int y) //스페셜
{
	if (m_createstate)
	{

		if (Type == KEYBOARDDOWN)
		{
			if (m_anglecheck == 0)
			{
				if (key == GLUT_KEY_RIGHT)
				{
					m_angle -= 90;
					m_anglecheck = 1;
				}
				else if (key == GLUT_KEY_LEFT)
				{
					m_angle += 90;
					m_anglecheck = 2;
				}
				else if (key == GLUT_KEY_UP)
				{
					m_pShow->m_NowY += 1;
					m_pShow->m_NowY %= m_yCount;
				}
				else if (key == GLUT_KEY_DOWN)
				{
					m_pShow->m_NowY -= 1;
					m_pShow->m_NowY < 0 ? m_pShow->m_NowY = m_yCount-1 : m_pShow->m_NowY = m_pShow->m_NowY;
				}
			}
			
		}
	}
}
void cGame::KeyBoard(int Type, unsigned  char  key, int x, int y) //일반키
{
	if (m_createstate == false)
	{
		if (m_viewcheck)
		{
			if (Type == KEYBOARDDOWN)
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

			}
		}
		else
		{
			if (Type == KEYBOARDDOWN)
			{
				if (m_pSeleteObject != NULL)
				{
					cVector Temp = m_pSeleteObject->GetVector();
					if (key == 'w')
					{
						Temp.x += 2;
						Temp.x = MIN(Temp.x, (m_xCount - 1) * 2);
					}
					else if (key == 's')
					{
						Temp.x -= 2;
						Temp.x = MAX(Temp.x, 0);

					}
					else if (key == 'a')
					{
						Temp.z -= 2;
						Temp.z = MAX(Temp.z, 0);

					}
					else if (key == 'd')
					{
						Temp.z += 2;
						Temp.z = MIN(Temp.z, (m_zCount - 1) * 2);

					}
					else if (key == 'y')
					{
						Temp.y += 2;
						Temp.y = MIN(Temp.y, (m_yCount - 1) * 2);

					}
					else if (key == 'g')
					{
						Temp.y -= 2;
						Temp.y = MAX(Temp.y, 0);

					}
					else if (key == 32)
					{
						ObjectSetting(Temp);
					}
					m_pSeleteObject->SetVector(Temp);

				}
			}
		}
		if (Type == KEYBOARDDOWN)
		{
			if (key == '1')
				m_viewcheck = !m_viewcheck;
			else if (key == 'r' || key == 'R')
				CamReSetting();


			if (key == 'p')
			{
				CamReSetting();
				m_viewcheck = false;
				m_createstate = true;
				glutDetachMenu(GLUT_RIGHT_BUTTON);
				CreateChage();
			}
		}

	}
	else
	{
		if (Type == KEYBOARDDOWN)
		{
			if (key == 'p')
			{
				CamReSetting();
				m_createstate = false;
				m_pPlayer->SetState(0);

				glutAttachMenu(GLUT_RIGHT_BUTTON);
			}
			if (key == ' ') // 스페이스바
			{
				for (int i = 0; i < m_xCount; i++)
				{
					for (int j = 0; j < m_zCount; j++)
					{
						if (m_pppCreateObject[i][j][m_pShow->m_NowY]->GetType() == HARDWALL)
							return;
					}
				}
				if((int)((m_pPlayer->GetVector().y+0.3)/2) == (m_pShow->m_NowY-1))
				m_pPlayer->SetAddAngle(90);
				for (int i = 0; i < m_xCount; i++)
				{
					for (int j = 0; j < m_zCount; j++)
					{
						m_pppCreateObject[i][j][m_pShow->m_NowY]->SetAddAngle(90);
					}
				}
				RotateSetting(m_pShow->m_NowY);
				m_Count++;
			}
		}
	}

}
void cGame::CreateChage()
{
	for (int i = 0; i < m_xCount; i++)
	{
		for (int j = 0; j < m_zCount; j++)
		{
			for (int z = 0; z < m_yCount; z++)
			{
				SAFE_DELETE(m_pppCreateObject[i][j][z]);
			}
		}
	}
	for (int i = 0; i < m_xCount; i++)
	{
		for (int j = 0; j < m_zCount; j++)
		{
			for (int z = 0; z < m_yCount; z++)
			{
				int TempCheck = m_pppObject[i][j][z]->GetType();
				cVector Temp = m_pppObject[i][j][z]->GetVector();
				switch (TempCheck)
				{
				case START:
					m_pppCreateObject[(int)(Temp.x / 2)][(int)(Temp.z / 2)][(int)(Temp.y / 2)] = new cStartObject();
					m_pPlayer->SetVector(Temp);
					m_pPlayer->SetTempVector(Temp);
					m_pPlayer->SetAngle(0);
					m_pPlayer->SetState(1);

					break;
				case END:
					m_pppCreateObject[(int)(Temp.x / 2)][(int)(Temp.z / 2)][(int)(Temp.y / 2)] = new cEndObject();
					break;
				case WALL:
					m_pppCreateObject[(int)(Temp.x / 2)][(int)(Temp.z / 2)][(int)(Temp.y / 2)] = new cWallObject();
					break;
				case EMPTY:
					m_pppCreateObject[(int)(Temp.x / 2)][(int)(Temp.z / 2)][(int)(Temp.y / 2)] = new cEmptyObject(0);
					break;
				case HARDWALL:
					m_pppCreateObject[(int)(Temp.x / 2)][(int)(Temp.z / 2)][(int)(Temp.y / 2)] = new cHardWallObject();
					break;
				}
				m_pppCreateObject[(int)(Temp.x / 2)][(int)(Temp.z / 2)][(int)(Temp.y / 2)]->SetVector(Temp);
			}
		}
	}

}
void cGame::ObjectSetting(cVector Temp)
{
	SAFE_DELETE(m_pppObject[(int)(Temp.x / 2)][(int)(Temp.z / 2)][(int)(Temp.y / 2)]);
	switch (m_pSeleteObject->GetType())
	{
	case START:
		m_pppObject[(int)(Temp.x / 2)][(int)(Temp.z / 2)][(int)(Temp.y / 2)] = new cStartObject();
		break;
	case END:
		m_pppObject[(int)(Temp.x / 2)][(int)(Temp.z / 2)][(int)(Temp.y / 2)] = new cEndObject();
		break;
	case WALL:
		m_pppObject[(int)(Temp.x / 2)][(int)(Temp.z / 2)][(int)(Temp.y / 2)] = new cWallObject();
		break;
	case EMPTY:
		m_pppObject[(int)(Temp.x / 2)][(int)(Temp.z / 2)][(int)(Temp.y / 2)] = new cEmptyObject(0);
		break;
	case HARDWALL:
		m_pppObject[(int)(Temp.x / 2)][(int)(Temp.z / 2)][(int)(Temp.y / 2)] = new cHardWallObject();
		break;
	}
	m_pppObject[(int)(Temp.x / 2)][(int)(Temp.z / 2)][(int)(Temp.y / 2)]->SetVector(Temp);
		
}