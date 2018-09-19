#ifndef _CLIGHT_H
#define _CLIGHT_H
#include <gl/glut.h>
class cLight
{
public:
	int   m_state = 0;

	float AmbientLight[4];
	float specref1[4];

	int   m_check = 0;
	float m_nube;
	float m_nube1;


	float MaxF;
	float Speed;
	float Speed1;
public:
	void ReSetting()
	{
		m_nube = 0;
		m_nube1 = -105;
		MaxF = 0.8f;
		Speed = 0.045;
		Speed1 = 0.045;
		m_state = 0;
		m_check = 0;
		AmbientLight[0] = 0.8;
		AmbientLight[1] = 0.8;
		AmbientLight[2] = 0.8;
		AmbientLight[3] = 0.8;

	
		GLfloat specref[] = { 0, 0, 0, 1.0f };
		GLfloat specref1[] = { 0, 0, 0, 1.0f };

		glLightfv(GL_LIGHT0, GL_AMBIENT, AmbientLight);
		glLightfv(GL_LIGHT0, GL_DIFFUSE, specref1);
		glLightfv(GL_LIGHT0, GL_SPECULAR, specref);
		glEnable(GL_LIGHT0);
	/*	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, AmbientLight);
		glLightModelf(GL_LIGHT_MODEL_LOCAL_VIEWER, 0.0);
		glLightModelf(GL_LIGHT_MODEL_TWO_SIDE, 0.0);
		glMaterialfv(GL_FRONT, GL_SPECULAR, specref);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, specref1);*/


	}
	cLight();
	~cLight();
public:
	void Update();
	void Render();
	void Off() {
		glDisable(GL_LIGHT0);
		m_nube = 0;
	}
	void On()
	{
		glEnable(GL_LIGHT0);
		m_nube = 0;
	}
};
#endif