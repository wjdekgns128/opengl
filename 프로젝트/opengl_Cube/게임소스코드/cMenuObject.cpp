#include "cMenuObject.h"

cMenuObject::cMenuObject()
{
	m_type = -1;
/*
	m_TempColor[0].x = 1;
	m_TempColor[0].y = 0;
	m_TempColor[0].z = 0;


	m_TempColor[1].x = 0;
	m_TempColor[1].y = 1;
	m_TempColor[1].z = 0;


	m_TempColor[2].x = 0;
	m_TempColor[2].y = 0;
	m_TempColor[2].z = 1;*/
}
cMenuObject::~cMenuObject()
{

}

void cMenuObject::Update()
{

}
void cMenuObject::Render()
{

	// TEST DRAW CUBE
	if (m_type == -1)
		return;
	float ctrlpoints[3][3][3] =
	{ { { m_Vector.x - (SIZECUBE / 2), m_Vector.y - (SIZECUBE / 2), m_Vector.z - (SIZECUBE / 2) },
		{ m_Vector.x - (SIZECUBE / 2) ,m_Vector.y ,m_Vector.z - (SIZECUBE / 2) },
		{ m_Vector.x - (SIZECUBE / 2),m_Vector.y + (SIZECUBE / 2) ,m_Vector.z - (SIZECUBE / 2) } },

		{ { m_Vector.x - (SIZECUBE / 2), m_Vector.y - (SIZECUBE / 2), m_Vector.z  },
		{ m_Vector.x - (SIZECUBE / 2) ,m_Vector.y  ,m_Vector.z  },
		{ m_Vector.x - (SIZECUBE / 2),m_Vector.y + (SIZECUBE / 2) ,m_Vector.z } },

		{ { m_Vector.x - (SIZECUBE / 2), m_Vector.y - (SIZECUBE / 2), m_Vector.z + (SIZECUBE / 2) },
		{ m_Vector.x - (SIZECUBE / 2) ,m_Vector.y  ,m_Vector.z + (SIZECUBE / 2) },
		{ m_Vector.x - (SIZECUBE / 2),m_Vector.y + (SIZECUBE / 2) ,m_Vector.z + (SIZECUBE / 2) } }
	};

	glPushMatrix();
	glColor3f(RGBFloat(m_pColor.x), RGBFloat(m_pColor.y), RGBFloat(m_pColor.z));//

	glNormal3f(-1, 0, 0);
	glMap2f(GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 3, 0.0, 1.0, 9, 3, &ctrlpoints[0][0][0]);
	glEnable(GL_MAP2_VERTEX_3);
	glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
	glEvalMesh2(GL_FILL, 0, 20, 0, 20);
	//glBegin(GL_QUADS); // ¾Õ¸é
	//glVertex3f(m_Vector.x - (SIZECUBE / 2), m_Vector.y - (SIZECUBE / 2) , m_Vector.z - (SIZECUBE / 2));
	//glVertex3f(m_Vector.x - (SIZECUBE / 2), m_Vector.y - (SIZECUBE / 2), m_Vector.z + (SIZECUBE / 2));
	//glVertex3f(m_Vector.x - (SIZECUBE / 2), m_Vector.y + (SIZECUBE / 2), m_Vector.z + (SIZECUBE / 2));
	//glVertex3f(m_Vector.x - (SIZECUBE / 2), m_Vector.y + (SIZECUBE / 2), m_Vector.z - (SIZECUBE / 2));
	//glEnd();

	glNormal3f(0, 0, 1);

	glBegin(GL_QUADS); // ¿·¸é¿Þ
	glVertex3f(m_Vector.x - (SIZECUBE / 2), m_Vector.y - (SIZECUBE / 2), m_Vector.z - (SIZECUBE / 2));
	glVertex3f(m_Vector.x + (SIZECUBE / 2), m_Vector.y - (SIZECUBE / 2), m_Vector.z - (SIZECUBE / 2));
	glVertex3f(m_Vector.x + (SIZECUBE / 2), m_Vector.y + (SIZECUBE / 2), m_Vector.z - (SIZECUBE / 2));
	glVertex3f(m_Vector.x - (SIZECUBE / 2), m_Vector.y + (SIZECUBE / 2), m_Vector.z - (SIZECUBE / 2));
	glEnd();

	glNormal3f(0, 0, -1);

	glBegin(GL_QUADS); // ¿·¸é
	glVertex3f(m_Vector.x - (SIZECUBE / 2), m_Vector.y - (SIZECUBE / 2), m_Vector.z + (SIZECUBE / 2));
	glVertex3f(m_Vector.x + (SIZECUBE / 2), m_Vector.y - (SIZECUBE / 2), m_Vector.z + (SIZECUBE / 2));
	glVertex3f(m_Vector.x + (SIZECUBE / 2), m_Vector.y + (SIZECUBE / 2), m_Vector.z + (SIZECUBE / 2));
	glVertex3f(m_Vector.x - (SIZECUBE / 2), m_Vector.y + (SIZECUBE / 2), m_Vector.z + (SIZECUBE / 2));
	glEnd();
	glNormal3f(0, 1,0);

	glBegin(GL_QUADS); // À­¸é
	glVertex3f(m_Vector.x - (SIZECUBE / 2), m_Vector.y + (SIZECUBE / 2), m_Vector.z - (SIZECUBE / 2));
	glVertex3f(m_Vector.x + (SIZECUBE / 2), m_Vector.y + (SIZECUBE / 2), m_Vector.z - (SIZECUBE / 2));
	glVertex3f(m_Vector.x + (SIZECUBE / 2), m_Vector.y + (SIZECUBE / 2), m_Vector.z + (SIZECUBE / 2));
	glVertex3f(m_Vector.x - (SIZECUBE / 2), m_Vector.y + (SIZECUBE / 2), m_Vector.z + (SIZECUBE / 2));
	glEnd();

	glNormal3f(0, -1, 0);
	glBegin(GL_QUADS); // ¾Æ·¡¸é
	glVertex3f(m_Vector.x - (SIZECUBE / 2), m_Vector.y - (SIZECUBE / 2), m_Vector.z - (SIZECUBE / 2));
	glVertex3f(m_Vector.x + (SIZECUBE / 2), m_Vector.y - (SIZECUBE / 2), m_Vector.z - (SIZECUBE / 2));
	glVertex3f(m_Vector.x + (SIZECUBE / 2), m_Vector.y - (SIZECUBE / 2), m_Vector.z + (SIZECUBE / 2));
	glVertex3f(m_Vector.x - (SIZECUBE / 2), m_Vector.y - (SIZECUBE / 2), m_Vector.z + (SIZECUBE / 2));
	glEnd();
	//glTranslatef(m_Vector.x, m_Vector.y, m_Vector.z);
	//glutSolidCube(SIZECUBE);
	glPopMatrix();



}