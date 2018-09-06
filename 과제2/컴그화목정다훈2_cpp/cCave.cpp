#include "cCave.h"
#include <random>
cCave::cCave()
{
	m_type = 2;
	m_CaveAngle = 0;
	m_NowMode = 0;
	m_Scal = cVector(130, 90, 80/*+ rand() % 200*/);
}
cCave::~cCave()
{

}
void cCave::Render2D()
{

	glPushMatrix();
	glColor3ub(138, 138, 138);
	glTranslatef(m_2DVector.x + m_Scal.x/2, m_2DVector.y + m_Scal.y/2, 0);
	glRotatef(m_CaveAngle,0, 0, 1);
	glTranslatef(-(m_2DVector.x + +m_Scal.x/2), -(m_2DVector.y + +m_Scal.y/2), 0);

	glRectf(m_2DVector.x, m_2DVector.y, m_2DVector.x + m_Scal.x, m_2DVector.y + m_Scal.y);
	if (m_NowMode == 2)
	{
		glColor3f(0, 0, 0);
		char st[1000];
		sprintf(st, "%d", (int)m_Scal.z);
		glRasterPos2d(m_2DVector.x+40, m_2DVector.y + 25);
		for (unsigned int i = 0; i < strlen(st); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, st[i]);
	}
	glPopMatrix();


}
void cCave::Render3D()
{
	glPushMatrix();
	glColor3ub(70, 128, 128);

	glTranslatef(m_3DVector.x , m_Scal.z / 2 + 0.5, m_3DVector.y);
	glRotatef(m_CaveAngle, 0, 1, 0);

	glScalef(m_Scal.x, m_Scal.z, m_Scal.y);
	glutSolidCube(1);
	
	
	glPopMatrix();

	glPushMatrix();

	GLfloat ctrlpoints[3][3][3] = { { { m_3DVector.x - m_Scal.x / 2, m_Scal.z, m_3DVector.y - m_Scal.y/2 },{ m_3DVector.x - m_Scal.x/2 ,m_Scal.z + 220, m_3DVector.y  },{ m_3DVector.x - m_Scal.x / 2, m_Scal.z, m_3DVector.y + m_Scal.y / 2 } },
									{ { m_3DVector.x, m_Scal.z, m_3DVector.y - m_Scal.y / 2 },{ m_3DVector.x, m_Scal.z + 220, m_3DVector.y },{ m_3DVector.x , m_Scal.z, m_3DVector.y + m_Scal.y / 2 } },
									{ { m_3DVector.x+ m_Scal.x / 2, m_Scal.z, m_3DVector.y - m_Scal.y / 2 },{ m_3DVector.x + m_Scal.x/2, m_Scal.z + 220,  m_3DVector.y },{ m_3DVector.x + m_Scal.x / 2, m_Scal.z, m_3DVector.y + m_Scal.y / 2 } } };
	// 곡면 제어점 설정
	glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 3, 0.0, 1.0, 9, 3, &ctrlpoints[0][0][0]);
	glEnable(GL_MAP2_VERTEX_3);
	// 그리드를 이용한 곡면 드로잉
	glMapGrid2f(10, 0.0, 1.0, 10, 0.0, 1.0);
	// 선을 이용하여 그리드 연결
	glColor3ub(168, 168, 168);
	glTranslatef(m_3DVector.x, m_Scal.z / 2 + 0.5, m_3DVector.y);
	glRotatef(m_CaveAngle, 0, 1, 0);
	glTranslatef(-m_3DVector.x, -(m_Scal.z / 2 + 0.5),- m_3DVector.y);

	glEvalMesh2(GL_FILL, 0, 10, 0, 10);
	glPopMatrix();

}
void cCave::Update()
{

}
void cCave::Mouse(int button, int state, int x, int y)
{
}
