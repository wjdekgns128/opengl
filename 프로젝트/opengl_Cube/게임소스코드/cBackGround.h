#ifndef _CBACKGROUND_H
#define _cBACKGROUND_H
#include "cVector.h"
#include "cMyDefine.h"
#include "cMyInclude.h"
class cBackGround
{
public:
	cVector		m_MathPostion;
	int			m_Type;
	cVector		m_EndPointVector; // µµÂøÁ¡ ÁÂÇ¥
	float		m_EndAngle;
private:
	float		m_Angle;
	GLfloat		m_Orange[4];
	GLfloat		m_Purple[4];
	float		m_EndRealAngle;
public:
	cBackGround();
	~cBackGround();
public:
	void Setting();
	void Render();
public:
	void MathPostion()
	{

		glPushMatrix();
		glLoadIdentity();
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


		GLfloat matrixMV[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, matrixMV);
		m_MathPostion = cVector(matrixMV[12], matrixMV[13], matrixMV[14]);

		glPopMatrix();
		glPopMatrix();
	}
	void SetAngle(float _angle)
	{
		m_Angle = _angle;
	}
	void SetAddAngle(float _angle)
	{
		m_Angle += _angle;
	}
	void SetOnLight()
	{
		glEnable(GL_LIGHT1);
		glEnable(GL_LIGHT2);
		glEnable(GL_LIGHT3);
		glEnable(GL_LIGHT4);
		glEnable(GL_LIGHT5);
		//glEnable(GL_LIGHT6);

	}
	void SetOffLight()
	{
		glDisable(GL_LIGHT1);
		glDisable(GL_LIGHT2);
		glDisable(GL_LIGHT3);
		glDisable(GL_LIGHT4);
		glDisable(GL_LIGHT5);
		//glDisable(GL_LIGHT6);

	}
	void ReSetting()
	{
		m_EndAngle = 0;
		m_EndRealAngle = 0;
		m_Angle = 0;
	}
private:

};
#endif