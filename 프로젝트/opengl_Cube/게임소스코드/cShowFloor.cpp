#include "cShowFloor.h"

struct RGBColor {

	float R;
	float G;
	float B;

};

RGBColor Vert_Color[4] = {

	{ 230.0, 200.0, 100.0 },
	{50, 120.0, 150.0},
	{100.0, 90.0, 150.0},
	{ 230.0, 130.0, 30.0 }


};




cShowFloor::cShowFloor()
{
	m_NowSelete = 0;

	alpha = 255;
	alpha_flag = 0;
	m_AddAngle = 0;
}

cShowFloor::~cShowFloor()
{

}


void cShowFloor::Render()
{
	glLineWidth(5);
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glScalef(10, 2, 10);
	glTranslatef(0.5, m_NowSelete + 0.5, 0.5);

	
	glBegin(GL_LINE_LOOP);
	glColor4f(Vert_Color[0].R / 255.0, Vert_Color[0].G / 255.0, Vert_Color[0].B / 255.0, alpha / 255.0);
		glVertex3f(-0.5, 0.5, -0.5);

	glColor4f(Vert_Color[1].R / 255.0, Vert_Color[1].G / 255.0, Vert_Color[1].B / 255.0, alpha / 255.0);
		glVertex3f(0.5, 0.5, -0.5);

	glColor4f(Vert_Color[2].R / 255.0, Vert_Color[2].G / 255.0, Vert_Color[2].B / 255.0, alpha / 255.0);
		glVertex3f(0.5, 0.5, 0.5);

	glColor4f(Vert_Color[3].R / 255.0, Vert_Color[3].G / 255.0, Vert_Color[3].B / 255.0, alpha / 255.0);
		glVertex3f(-0.5, 0.5, 0.5);

	glEnd();

	glBegin(GL_LINE_LOOP);
	glColor4f(Vert_Color[0].R / 255.0, Vert_Color[0].G / 255.0, Vert_Color[0].B / 255.0, alpha / 255.0);
		glVertex3f(-0.5, -0.5, -0.5);

	glColor4f(Vert_Color[1].R / 255.0, Vert_Color[1].G / 255.0, Vert_Color[1].B / 255.0, alpha / 255.0);
		glVertex3f(0.5, -0.5, -0.5);

	glColor4f(Vert_Color[2].R / 255.0, Vert_Color[2].G / 255.0, Vert_Color[2].B / 255.0, alpha / 255.0);
		glVertex3f(0.5, -0.5, 0.5);
	
	glColor4f(Vert_Color[3].R / 255.0, Vert_Color[3].G / 255.0, Vert_Color[3].B / 255.0, alpha / 255.0);
		glVertex3f(-0.5, -0.5, 0.5);
	glEnd();

	glBegin(GL_LINES);
	glColor4f(Vert_Color[0].R / 255.0, Vert_Color[0].G / 255.0, Vert_Color[0].B / 255.0, alpha / 255.0);
		glVertex3f(-0.5, -0.5, -0.5);
		glVertex3f(-0.5, 0.5, -0.5);

	glColor4f(Vert_Color[1].R / 255.0, Vert_Color[1].G / 255.0, Vert_Color[1].B / 255.0, alpha / 255.0);
		glVertex3f(0.5, -0.5, -0.5);
		glVertex3f(0.5, 0.5, -0.5);

	glColor4f(Vert_Color[2].R / 255.0, Vert_Color[2].G / 255.0, Vert_Color[2].B / 255.0, alpha / 255.0);
		glVertex3f(0.5, -0.5, 0.5);
		glVertex3f(0.5, 0.5, 0.5);

	glColor4f(Vert_Color[3].R / 255.0, Vert_Color[3].G / 255.0, Vert_Color[3].B / 255.0, alpha / 255.0);
		glVertex3f(-0.5, -0.5, 0.5);
		glVertex3f(-0.5, 0.5, 0.5);
	glEnd();

	glPopMatrix();
	glEnable(GL_LIGHTING);
	InGameBG();

	glDisable(GL_BLEND);
	glLineWidth(1);
}
void cShowFloor::Update()
{
	if (alpha >= 220)		alpha_flag = 0;
	if (alpha <= 160)		alpha_flag = 1;


	if (alpha_flag)		alpha += 1;
	if (!alpha_flag)	alpha -= 1;
}


void cShowFloor::InGameBG()
{
	glPushMatrix();
	glTranslatef(5, 0, 5);
	glRotatef(m_AddAngle, 0, 1, 0);
	glTranslatef(15, 7, 0);
	glRotatef(90, 0, 1, 0);
	glScalef(1, 1, 0);
	glBegin(GL_POLYGON);
	glColor4f(RGBFloat(100), RGBFloat(90), RGBFloat(150), RGBFloat(alpha));//¿ìÃø »ó´Ü
	glVertex3f(-15, 15, -15);
	glColor4f(RGBFloat(230), RGBFloat(200), RGBFloat(100), RGBFloat(alpha));//Áß¾Ó
	glVertex3f(-15, -8, -15);
	glColor4f(RGBFloat(230), RGBFloat(130), RGBFloat(30), RGBFloat(alpha));//ÁÂÃø ÇÏ´Ü
	glVertex3f(15, -8, -15);
	glColor4f(RGBFloat(100), RGBFloat(90), RGBFloat(150), RGBFloat(alpha));//ÁÂÃø »ó´Ü
	glVertex3f(15, 15, -15);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5, 0, 5);
	glRotatef(m_AddAngle, 0, 1, 0);
	glTranslatef(0, 7, 15);
	glScalef(1, 1, 0);
	glBegin(GL_POLYGON);
	glColor4f(RGBFloat(100), RGBFloat(90), RGBFloat(150), RGBFloat(alpha));
	glVertex3f(15, 15, -15);
	glColor4f(RGBFloat(230), RGBFloat(200), RGBFloat(100), RGBFloat(alpha));//Áß¾Ó
	glVertex3f(15, -8, -15);
	glColor4f(RGBFloat(230), RGBFloat(130), RGBFloat(30), RGBFloat(alpha));
	glVertex3f(-15, -8, -15);
	glColor4f(RGBFloat(100), RGBFloat(90), RGBFloat(150), RGBFloat(alpha));
	glVertex3f(-15, 15, -15);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glTranslatef(5, 0, 5);
	glRotatef(m_AddAngle, 0, 1, 0);
	glTranslatef(0, -1, 0);
	glRotatef(90, 1, 0, 0);
	glScalef(1, 1, 0);
	glBegin(GL_POLYGON);
	glColor4f(RGBFloat(230), RGBFloat(130), RGBFloat(90), RGBFloat(alpha));
	glVertex3f(-15, 15, -15);
	glColor4f(RGBFloat(230), RGBFloat(200), RGBFloat(255), RGBFloat(alpha));
	glVertex3f(-15, -15, -15);
	glColor4f(RGBFloat(230), RGBFloat(130), RGBFloat(90), RGBFloat(alpha));
	glVertex3f(15, -15, -15);
	glColor4f(RGBFloat(200), RGBFloat(180), RGBFloat(90), RGBFloat(alpha));//Áß¾Ó
	glVertex3f(15, 15, -15);
	glEnd();
	glPopMatrix();

}