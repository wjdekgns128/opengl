#ifndef _CBASEOBJECT_H
#define _CBASEOBJECT_H
#include "cVector.h"
#include "cMyInclude.h"
class cBaseObject
{
public:
	cVector				m_MathVector;//실제
protected:
	cVector				m_Vector; // Move값
	int					m_type; // 타입
	float				m_angle;
	
public:
	cBaseObject();
	~cBaseObject();

public:
	virtual void Render() = 0;
	virtual void Update() = 0;
public:
	void SetType(int type)
	{
		m_type = type;
	}
	void SetVector(cVector _vector)
	{
		m_Vector = _vector;
	}
	void SetVector(float x, float y, float z)
	{
		m_Vector = cVector(x, y, z);
	}
	cVector GetVector()
	{
		return m_Vector;
	}
	int GetType()
	{
		return m_type;
	}
	void SetAngle(float _angle)
	{
		m_angle = _angle;
		glPushMatrix();
		glLoadIdentity();
		glTranslatef(5, 0, 5);
		glRotatef(m_angle, 0, 1, 0);
		glTranslatef(-5, 0, -5);
		glTranslatef(m_Vector.x + 1, m_Vector.y + 2.1, m_Vector.z + 1);
		GLfloat matrixMV[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, matrixMV);
		m_MathVector = cVector(matrixMV[12], matrixMV[13], matrixMV[14]);
		glPopMatrix();
	}
	void SetAddAngle(float _angle)
	{
		m_angle += _angle;
		glPushMatrix();

		glLoadIdentity();
		glTranslatef(5, 0, 5);
		glRotatef(m_angle, 0, 1, 0);
		glTranslatef(-5, 0, -5);
		glTranslatef(m_Vector.x + 1, m_Vector.y + 2.1, m_Vector.z + 1);
		GLfloat matrixMV[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, matrixMV);
		m_MathVector = cVector(matrixMV[12], matrixMV[13], matrixMV[14]);
		glPopMatrix();

	}
	float GetAngle()
	{
		return m_angle;
	}
};
#endif // !_CBASEOBJECT_h
