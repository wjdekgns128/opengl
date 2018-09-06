#include "cPlayer.h"
#include "cMapLoad.h"
cPlayer::cPlayer(cVector _startpoint)
{
	m_Postion = _startpoint;
	m_MathPostion = _startpoint;

	m_angle = 0;
	m_realangle = 0;
	m_state = 0;
	m_Scale = 0.0;
	m_eventTime = 0.0;
	m_MoveIng = true;
	m_RotionAngle = 0;
	m_End = false;
	m_MathAngle = 0;
	tim = 0;
}
cPlayer::cPlayer()
{
	m_Postion = cVector(0, 0, 0);
	m_MathPostion = cVector(0, 0, 0);
	m_angle = 0;
	m_realangle = 0;
	m_state = 0;
	m_Scale = 0.0;
	m_eventTime = 0.0;
	m_MoveIng = true;
	m_RotionAngle = 0;
	m_MathAngle = 0;
	m_End = false;
	tim = 0;
}
cPlayer::~cPlayer()
{

}
void cPlayer::Render()
{
	glPushMatrix();

	glColor3ub(255, 255, 255);
	glTranslatef(5, 0, 5);
	glRotatef(m_realangle, 0, 1, 0);
	glTranslatef(-5, 0, -5);
	glTranslatef(m_Postion.x, m_Postion.y, m_Postion.z);
	glRotatef(m_RotionAngle, 1, 0, 0);
	glutSolidSphere(m_Scale, 15, 15);
	glPopMatrix();
	MathPostion();

}
void cPlayer::CollManager(int Type,float time)
{
	if (m_state == 3 || m_state == 4 || m_state == 5 || m_state == 6)
		return;
	tim += time;
	m_MoveIng = true;
	if (Type == -1)
	{
		m_Postion.y -= 0.3 * tim;
		m_RotionAngle -= 3;
	}
	else if (Type == START)
	{
		m_Postion.y -= 0.3*tim;
		m_RotionAngle -=3;

	}
	else if (Type == PORTAL)
	{
		m_Postion.y -= 0.3*tim;
		m_RotionAngle -= 3;
	}
	else if (Type == EMPTY)
	{
		m_Postion.y -= 0.3*tim;
		m_RotionAngle -= 3;

	}
	else if (Type == END)
	{
		tim = 0;
		m_MoveIng = false;
		m_state = 3;
	}
	else if (Type == -2)
	{
			m_Postion.y -= 0.3*tim;
			m_RotionAngle -= 3;
			if (m_Postion.y < -23)
			{
				m_Postion.y = -23;
				m_state = 6; //이스테이지 클리어못함
			}

	}
	else
	{
		tim = 0;
		m_MoveIng = false;
	}

}
void cPlayer::Update(float time)
{
	if (m_angle != 0)
	{
		m_realangle += 10;
		m_angle -= 10;
	}
	if (m_state == 0)
	{

	}
	else if (m_state == 1)
	{
		m_Scale += 0.1;
		if (PLAYERMAXSCALE <= m_Scale)
		{
			m_Scale = PLAYERMAXSCALE;
			m_state = 2;
		}
	}
	else if (m_state == 3)
	{
		m_Postion.y -= 0.15;
		m_RotionAngle -= 2;
		if (m_Postion.y <= 0.7)
		{
			m_Postion.y = 0.7;
				m_state = 4;
		}
	}
	else if (m_state == 4) // 4이면 종료후 앞으로나오기
	{
	
		if ( GETLOAD->GetNowNumber() == 7)
		{
			if (m_realangle == 0)
			{
				m_Postion.z -= 0.05;
				m_RotionAngle -= 2;
				if (m_Postion.z <= -2)
				{
					m_Postion.z = -2;
					m_state = 5; //5이면 다음스테이지 ,6이면 실패
				}
			}
			else if ( m_realangle == 270)
			{
				m_Postion.x -= 0.05;
				m_RotionAngle -= 2;
				if (m_Postion.x <= -2)
				{
					m_Postion.x = -2;
					m_state = 5; //5이면 다음스테이지 ,6이면 실패
				}
			}
			else
			{
				m_Postion.x += 0.05;
				m_RotionAngle -= 2;
				if (m_Postion.x >= 12)
				{
					m_Postion.x = 12;
					m_state = 5; //5이면 다음스테이지 ,6이면 실패
				}
			}
		}
		else if (GETLOAD->GetNowNumber() == 3 || GETLOAD->GetNowNumber() == 2 )
		{
			m_Postion.x += 0.05;
			m_RotionAngle -= 2;
			if (m_Postion.x >= 12)
			{
				m_Postion.x = 12;
				m_state = 5; //5이면 다음스테이지 ,6이면 실패
			}
		}
		else if(GETLOAD->GetNowNumber() == 9 )
		{
			m_Postion.x -= 0.05;
			m_RotionAngle -= 2;
			if (m_Postion.x <= -2)
			{
				m_Postion.x = -2;
				m_state = 5; //5이면 다음스테이지 ,6이면 실패
			}
		}
		else
		{
			m_Postion.z -= 0.05;
			m_RotionAngle -= 2;
			if (m_Postion.z <= -2)
			{
				m_Postion.z = -2;
				m_state = 5; //5이면 다음스테이지 ,6이면 실패
			}
		}
			
	
		
	}

}