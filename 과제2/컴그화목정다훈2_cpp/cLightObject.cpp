#include "cLightObject.h"
#include <random>
int cLightObject::number = 0;
cLightObject::cLightObject()
{
	m_type = 4;
	m_NowMode = 0;
	m_angle = rand()%360;
	m_Scal = cVector(40, 40, 30/*+ rand() % 200*/);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT3);
	glEnable(GL_LIGHT4);
	glEnable(GL_LIGHT5);
}
cLightObject::~cLightObject()
{
	glDisable(GL_LIGHT2);
	glDisable(GL_LIGHT1);
	glDisable(GL_LIGHT3);
	glDisable(GL_LIGHT4);
	glDisable(GL_LIGHT5);
}
void cLightObject::Render2D()
{
	glBegin(GL_POLYGON);
	glColor3ub(160, 80, 0);
	for (int i = 0; i < 360;i++)
	{
		glVertex2f(cos(ToRadian(i)) * m_Scal.x / 2 + m_2DVector.x + 20, sin(ToRadian(i)) * m_Scal.x / 2 + m_2DVector.y+20);
	}
	glEnd();

	if (m_NowMode == 2)
	{
		glColor3f(0, 0, 0);
		char st[1000];
		sprintf(st, "%d", (int)m_Scal.z);
		glRasterPos2d(m_2DVector.x  +10, m_2DVector.y + 22);
		for (unsigned int i = 0; i < strlen(st); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
	}

}
void cLightObject::Render3D()
{

	glPushMatrix();
	glColor3ub(128, 128, 128);
	glTranslatef(m_3DVector.x, m_Scal.z / 2 + 0.5, m_3DVector.y);
	glScalef(m_Scal.x/2, m_Scal.z, m_Scal.y/2);
	glutSolidCube(1);

	glColor3ub(160, 80, 0);
	glPushMatrix();
	glRotatef(m_angle, 0, 1, 0);
	glTranslatef(0, 1 - 1/m_Scal.z, 0);
	glScalef(0.5 , 0.25, 0.5 );
	glutWireSphere(1, 15, 15);
	if (m_anglecheck == 1)
	{
		GLfloat qaDiffuseLight[] = { 1, 0.5, 0, 1.0 };
		GLfloat qaLightPosition[] = { 0, 0, 1.5, 1 };
		GLfloat dirVector0[] = { 0.0, 0.0, 1, 0.0 };

		if (m_now == 0)
		{
			glLightfv(GL_LIGHT1, GL_DIFFUSE, qaDiffuseLight);
			glLightfv(GL_LIGHT1, GL_POSITION, qaLightPosition);
			glLightfv(GL_LIGHT1, GL_SPOT_DIRECTION, dirVector0);
			glLightf(GL_LIGHT1, GL_SPOT_EXPONENT, 1);
			glLightf(GL_LIGHT1, GL_SPOT_CUTOFF, 30.0);
			
		}

		if (m_now == 1)
		{
			glLightfv(GL_LIGHT2, GL_DIFFUSE, qaDiffuseLight);
			glLightfv(GL_LIGHT2, GL_POSITION, qaLightPosition);
			glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, dirVector0);
			glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 1);
			glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 30.0);
			


		}

		if (m_now == 2)
		{
			glLightfv(GL_LIGHT3, GL_DIFFUSE, qaDiffuseLight);
			glLightfv(GL_LIGHT3, GL_POSITION, qaLightPosition);
			glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, dirVector0);
			glLightf(GL_LIGHT3, GL_SPOT_EXPONENT, 1);
			glLightf(GL_LIGHT3, GL_SPOT_CUTOFF, 30.0);
		}

		if (m_now == 3)
		{
			glLightfv(GL_LIGHT4, GL_DIFFUSE, qaDiffuseLight);
			glLightfv(GL_LIGHT4, GL_POSITION, qaLightPosition);
			glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, dirVector0);
			glLightf(GL_LIGHT4, GL_SPOT_EXPONENT, 1);
			glLightf(GL_LIGHT4, GL_SPOT_CUTOFF, 30.0);
		}

		if (m_now == 4)
		{
			glLightfv(GL_LIGHT5, GL_DIFFUSE, qaDiffuseLight);
			glLightfv(GL_LIGHT5, GL_POSITION, qaLightPosition);
			glLightfv(GL_LIGHT5, GL_SPOT_DIRECTION, dirVector0);
			glLightf(GL_LIGHT5, GL_SPOT_EXPONENT, 1);
			glLightf(GL_LIGHT5, GL_SPOT_CUTOFF, 30.0);
		}
	}
	glPushMatrix();
	glTranslatef(0, 0, 1.5);
	glScalef(0.2, 0.2, 1.2);
	glColor3ub(0, 0, 0);
	glutSolidCube(1);
	glPopMatrix();
	glPopMatrix();
	glPopMatrix();
	if (m_anglecheck == 1)
	{
		m_angle++;
	}
}
void cLightObject::Update()
{

}
void cLightObject::Mouse(int button, int state, int x, int y)
{
}
