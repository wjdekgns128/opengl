#ifndef _CPLAYER_H
#define _CPLAYER_H
#include "cMyDefine.h"
#include "cMyInclude.h"
#define PLAYERMAXSCALE  0.7
class cPlayer
{
public:
	cVector				m_Postion;
	int					m_angle;
	int				m_realangle;
	int				m_MathAngle;
private:
	cVector				m_MathPostion;


	float			m_Scale; // 커지는스케일값

	int				m_state; // 0이면 x 1이면 애니메이션시작(커진) 2이면 다커진상태에서 내려오는상태, 3부터 플레이가능하게

	float			m_eventTime; //오프닝,등등 모든 이벤트 시간관리

	bool			m_MoveIng; //움직이는중인지.

	float			m_RotionAngle;
	bool			m_End;
	float			 tim;
	
public:
	cPlayer(cVector _startpoint);
	cPlayer();
	~cPlayer();

public:
	
	void Render();
	void Update(float time);
	void CollManager(int Type,float time); //들어와있는 타일번호넘김
public:
	bool GetMvoeing()
	{
		return m_MoveIng;
	}
	void MathPostion()
	{
		glPushMatrix();
		glLoadIdentity();
		glTranslatef(5, 0, 5);
		glRotatef(m_MathAngle, 0, 1, 0);
		glTranslatef(-5, 0, -5);
		glTranslatef(m_Postion.x, m_Postion.y, m_Postion.z);

		GLfloat matrixMV[16];
		glGetFloatv(GL_MODELVIEW_MATRIX, matrixMV);
		m_MathPostion = cVector(matrixMV[12], matrixMV[13], matrixMV[14]);

		glPopMatrix();
	}
public:
	
	void RotatedPlayer()
	{
		m_angle += 90;
		m_MathAngle += 90;
	}
	void SetPostion(cVector _temp)
	{
		m_Postion = _temp;
	}
	

public:
	void    SetAngle(int _Set)
	{
		m_angle = _Set;
	}
	cVector GetPostion()
	{
		return m_Postion;
	}
	cVector GetMathPostion()
	{
	
		return m_MathPostion;
	}
	int GetState()
	{
		return m_state;
	}
	void SetState(int _sel)
	{
		m_state = _sel;
	}
};

#endif