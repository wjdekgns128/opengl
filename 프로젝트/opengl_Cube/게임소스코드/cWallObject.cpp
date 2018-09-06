#include "cWallObject.h"
cWallObject::cWallObject()
{
	m_type = WALL;
	m_Vector = cVector(0, 0, 0);
	m_angle = 0;
}

cWallObject::cWallObject(cVector vector)
{
	m_type = WALL;
	m_Vector = vector;
	m_angle = 0;

}
cWallObject::~cWallObject()
{

}
void cWallObject::RenderObject()
{
#pragma region _RENDEROBJECT_
	glPushMatrix();
	//float ctrlpoints[3][3][3] =
	//{{ { m_Vector.x - 0.99, m_Vector.y - 0.99, m_Vector.z - 0.99 }, { m_Vector.x ,m_Vector.y - 0.99 ,m_Vector.z - 0.99 }, { m_Vector.x + 0.99,m_Vector.y - 0.99 ,m_Vector.z - 0.99 } },
	//};

	glColor3ub(97, 55, 26);
	glNormal3f(0, 0, -1);
	glBegin(GL_QUADS);
	/*glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 3, 0.0, 1.0, 9, 3, &ctrlpoints[0][0][0]);
	glEnable(GL_MAP2_VERTEX_3);
	glMapGrid2f(100, 0.0, 1.0, 100, 0.0, 1.0);
	glEvalMesh2(GL_FILL, 0, 100, 0, 100);*/
	glVertex3f(m_Vector.x - 0.99, m_Vector.y - 0.99, m_Vector.z - 0.99);
	glVertex3f(m_Vector.x + 0.99, m_Vector.y - 0.99, m_Vector.z - 0.99);
	glVertex3f(m_Vector.x + 0.99, m_Vector.y + 0.99, m_Vector.z - 0.99);
	glVertex3f(m_Vector.x - 0.99, m_Vector.y + 0.99, m_Vector.z - 0.99);
	glEnd();
	glNormal3f(0, 0, 1);

	glBegin(GL_QUADS);
	glVertex3f(m_Vector.x - 0.99, m_Vector.y - 0.99, m_Vector.z + 0.99);
	glVertex3f(m_Vector.x + 0.99, m_Vector.y - 0.99, m_Vector.z + 0.99);
	glVertex3f(m_Vector.x + 0.99, m_Vector.y + 0.99, m_Vector.z + 0.99);
	glVertex3f(m_Vector.x - 0.99, m_Vector.y + 0.99, m_Vector.z + 0.99);


	glEnd();
	glNormal3f(0, 1, 0);

	glBegin(GL_QUADS);
	glVertex3f(m_Vector.x - 0.99, m_Vector.y + 0.99, m_Vector.z - 0.99);
	glVertex3f(m_Vector.x + 0.99, m_Vector.y + 0.99, m_Vector.z - 0.99);
	glVertex3f(m_Vector.x + 0.99, m_Vector.y + 0.99, m_Vector.z + 0.99);
	glVertex3f(m_Vector.x - 0.99, m_Vector.y + 0.99, m_Vector.z + 0.99);


	glEnd();
	glNormal3f(0, -1, 0);

	glBegin(GL_QUADS);
	glVertex3f(m_Vector.x - 0.99, m_Vector.y - 0.99, m_Vector.z - 0.99);
	glVertex3f(m_Vector.x + 0.99, m_Vector.y - 0.99, m_Vector.z - 0.99);
	glVertex3f(m_Vector.x + 0.99, m_Vector.y - 0.99, m_Vector.z + 0.99);
	glVertex3f(m_Vector.x - 0.99, m_Vector.y - 0.99, m_Vector.z + 0.99);


	glEnd();
	glNormal3f(1, 0, 0);

	glBegin(GL_QUADS);
	glVertex3f(m_Vector.x + 0.99, m_Vector.y + 0.99, m_Vector.z - 0.99);
	glVertex3f(m_Vector.x + 0.99, m_Vector.y + 0.99, m_Vector.z + 0.99);
	glVertex3f(m_Vector.x + 0.99, m_Vector.y - 0.99, m_Vector.z + 0.99);
	glVertex3f(m_Vector.x + 0.99, m_Vector.y - 0.99, m_Vector.z - 0.99);


	glEnd();
	glNormal3f(-1, 0, 0);


	glBegin(GL_QUADS);
	glVertex3f(m_Vector.x - 0.99, m_Vector.y + 0.99, m_Vector.z - 0.99);
	glVertex3f(m_Vector.x - 0.99, m_Vector.y + 0.99, m_Vector.z + 0.99);
	glVertex3f(m_Vector.x - 0.99, m_Vector.y - 0.99, m_Vector.z + 0.99);
	glVertex3f(m_Vector.x - 0.99, m_Vector.y - 0.99, m_Vector.z - 0.99);


	glEnd();
	glPopMatrix();

	
#pragma endregion

}

void cWallObject::Render()
{
	RenderObject();


	if(m_LineLight)
	glDisable(GL_LIGHTING);

	glPushMatrix();
	glLineWidth(0.01);
	glColor3ub(80, 80, 80);
	glTranslatef(m_Vector.x, m_Vector.y, m_Vector.z);
	glutWireCube(1.99);
	glPopMatrix();
	if (m_LineLight)
	glEnable(GL_LIGHTING);
}
void cWallObject::Update(float time)
{
	UpdateOpenning(time);
}