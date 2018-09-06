#include "cBackGround.h"
cBackGround::cBackGround()
{
}
void cBackGround::Setting()
{

	GLfloat ambientLight[] = { RGBFloat(80),RGBFloat(80), RGBFloat(80), 1 };
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);			
	// 조명값들 
	glMateriali(GL_FRONT, GL_SHININESS, 128);
	////배경

	m_Orange[0] = RGBFloat(255);
	m_Orange[1] = RGBFloat(128);
	m_Orange[2] = RGBFloat(0);
	m_Orange[3] = 1;
	m_Purple[0] = RGBFloat(0);
	m_Purple[1] = RGBFloat(0);
	m_Purple[2] = RGBFloat(255);
	m_Purple[3] = 1;

	ReSetting();
	SetOnLight();

}

cBackGround::~cBackGround()
{
	
	SetOffLight();
}
void cBackGround::Render()
{
	if (m_EndAngle != 0)
	{
		m_EndRealAngle += 10;
		m_EndAngle -= 10;
	}
	GLfloat qaLightPosition[] = { 0,0,0, 1 };
	GLfloat dirVector0[] = { 0.0, 0, 1, 0.0 };
	GLfloat Dir[] = { 0,-1,0,1 };
	GLfloat color[] = { 1,1,1,1 };

#pragma region _LIGHT01

	glPushMatrix();

	glTranslatef(5, 0, 5);
	glRotatef(m_Angle, 0, 1, 0);
	glTranslatef(-5, 0, -5);

	glPushMatrix();
	glTranslatef(5, -2, -10);
	glRotatef(-25, 1, 0, 0);

	glLightfv(GL_LIGHT1, GL_DIFFUSE, m_Orange);
	glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition);
	glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, dirVector0);
	glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 5);
	glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 35);

	glPopMatrix();
	glPopMatrix();

#pragma endregion
#pragma region _LIGHT02

	glPushMatrix();

	glTranslatef(5, 0, 5);
	glRotatef(m_Angle, 0, 1, 0);
	glTranslatef(-5, 0, -5);

	glPushMatrix();
	glTranslatef(5, 14, -10);
	glRotatef(30, 1, 0, 0);

	glLightfv(GL_LIGHT2, GL_DIFFUSE, m_Purple);
	glLightfv(GL_LIGHT2, GL_POSITION, qaLightPosition);
	glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, dirVector0);
	glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 5);
	glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 35);

	glPopMatrix();
	glPopMatrix();
#pragma endregion
#pragma region _LIGHT03

	glPushMatrix();

	glTranslatef(5, 0, 5);
	glRotatef(m_Angle+90, 0, 1, 0);
	glTranslatef(-5, 0, -5);

	glPushMatrix();
	glTranslatef(5, -2, -10);
	glRotatef(-25, 1, 0, 0);

	glLightfv(GL_LIGHT3, GL_DIFFUSE, m_Orange);
	glLightfv(GL_LIGHT3, GL_POSITION, qaLightPosition);
	glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, dirVector0);
	glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 5);
	glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 35);

	glPopMatrix();
	glPopMatrix();

#pragma endregion
#pragma region _LIGHT04

	glPushMatrix();

	glTranslatef(5, 0, 5);
	glRotatef(m_Angle+90, 0, 1, 0);
	glTranslatef(-5, 0, -5);

	glPushMatrix();
	glTranslatef(5, 14, -10);
	glRotatef(30, 1, 0, 0);

	glLightfv(GL_LIGHT4, GL_DIFFUSE, m_Purple);
	glLightfv(GL_LIGHT4, GL_POSITION, qaLightPosition);
	glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, dirVector0);
	glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, 5);
	glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 35);

	glPopMatrix();
	glPopMatrix();
	glPushMatrix();
	



#pragma endregion

	glPushMatrix();
	glTranslatef(5, 0, 5);
	glRotatef(m_EndRealAngle, 0, 1, 0);
	glTranslatef(-5, 0, -5);
	glPushMatrix();
	if (m_EndPointVector.z <= 0)
	{
		glTranslatef(m_EndPointVector.x + (m_EndPointVector.x + 1), m_EndPointVector.y - 1, m_EndPointVector.z - 2);
	}
	else if (m_EndPointVector.z >= 4)
	{
		glTranslatef(m_EndPointVector.x + (m_EndPointVector.x + 1), m_EndPointVector.y - 1, m_EndPointVector.z + 8);
	}
	else if (m_EndPointVector.x <= 0)
	{
		glTranslatef(m_EndPointVector.x - 2, m_EndPointVector.y - 1, m_EndPointVector.z + (m_EndPointVector.z + 1));
	}
	else if (m_EndPointVector.x >= 4)
	{
		glTranslatef(m_EndPointVector.x + 8, m_EndPointVector.y - 1, m_EndPointVector.z + (m_EndPointVector.z + 1));
	}



	glNormal3f(0, 1, 0);
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i += 5)
	{
		glVertex3f(1 * cos(ToRadian(i)), 1, (1 * sin(ToRadian(i))));
	}
	glEnd();
	/*glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 3, 0.0, 1.0, 9, 3, &ctrlpoints[0][0][0]);
	glEnable(GL_MAP2_VERTEX_3);
	glMapGrid2f(100, 0.0, 1.0, 100, 0.0, 1.0);
	glEvalMesh2(GL_FILL, 0, 100, 0, 100);*/


	GLfloat qaLightPosition1[] = { 0,0,0, 1 };
	glTranslatef(0, 5, 0);
	glLightfv(GL_LIGHT5, GL_DIFFUSE, color);
	glLightfv(GL_LIGHT5, GL_POSITION, qaLightPosition1);
	glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, Dir);
	glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, 1);
	glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, 15);
	glPopMatrix();
	glPopMatrix();


	//glPushMatrix();
	//glTranslatef(5, 0, 5);
	//glRotatef(m_EndRealAngle, 0, 1, 0);
	//glTranslatef(-5, 0, -5);
	//glPushMatrix();
	// if (m_EndPointVector.x <= 0)
	//{
	//	glTranslatef(m_EndPointVector.x - 2, m_EndPointVector.y - 1, m_EndPointVector.z + (m_EndPointVector.z + 1));
	//}
	//else if (m_EndPointVector.x >= 4)
	//{
	//	glTranslatef(m_EndPointVector.x + 8, m_EndPointVector.y - 1, m_EndPointVector.z + (m_EndPointVector.z + 1));
	//}
	//else	if (m_EndPointVector.z <= 0)
	//{
	//	glTranslatef(m_EndPointVector.x + (m_EndPointVector.x + 1), m_EndPointVector.y - 1, m_EndPointVector.z - 2);
	//}
	//else if (m_EndPointVector.z >= 4)
	//{
	//	glTranslatef(m_EndPointVector.x + (m_EndPointVector.x + 1), m_EndPointVector.y - 1, m_EndPointVector.z + 8);
	//}



	//glNormal3f(0, 1, 0);
	//glColor3f(1, 1, 1);
	//glBegin(GL_POLYGON);
	//for (int i = 0; i < 360; i += 5)
	//{
	//	glVertex3f(1 * cos(ToRadian(i)), 1, (1 * sin(ToRadian(i))));
	//}
	//glEnd();
	///*glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 3, 0.0, 1.0, 9, 3, &ctrlpoints[0][0][0]);
	//glEnable(GL_MAP2_VERTEX_3);
	//glMapGrid2f(100, 0.0, 1.0, 100, 0.0, 1.0);
	//glEvalMesh2(GL_FILL, 0, 100, 0, 100);*/


	//glTranslatef(0, 5, 0);
	//glLightfv(GL_LIGHT6, GL_DIFFUSE, color);
	//glLightfv(GL_LIGHT6, GL_POSITION, qaLightPosition1);
	//glLightfv(GL_LIGHT6, GL_SPOT_DIRECTION, Dir);
	//glLightf(GL_LIGHT6, GL_SPOT_EXPONENT, 1);
	//glLightf(GL_LIGHT6, GL_SPOT_CUTOFF, 15);
	//glPopMatrix();
	//glPopMatrix();

	glPopMatrix();

}

