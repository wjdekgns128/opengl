

#ifndef _CPARTICLEBASE_H
#define _CPARTICLEBASE_H
#include <gl/glut.h>
#include <vector>
#include "cMyDefine.h"
#include "cMyInclude.h"
using namespace std;

class cParticleObject
{
private:
	int				m_type;
	cVector			m_Postion;
	cVector			m_Color;
	cVector			m_Speed;
	float			m_Apl;
	float			m_DownApl;
	bool			m_state;
	float			m_scale;
public:
	cParticleObject();
	~cParticleObject();
public: //type == 0 네모 1이면 원 //int 형 값
	void Setting(int type, cVector Postion,cVector minspeed, cVector maxspeed, float downapl) //좌표,최소컬러~최대,최소 속도~최대속도
	{
		m_Apl = 255.0;
		m_state = false;
		m_type = type;
		m_DownApl = downapl;
		m_Postion = Postion;
		int colorr = 97;
		int colorg = 55;
		int colorb = 26;
		int x = minspeed.x * 100 ;
		int x1 = maxspeed.x * 100;
		int y = minspeed.y * 100;
		int y1 = maxspeed.y * 100;
		int z = minspeed.z * 100;
		int z1 = maxspeed.z * 100;
		int a = rand() % 7 + 4;
		m_scale = a*0.02;
		float speedX = (rand() % (x + ((x1 - x) + 1))) *0.01;
		float speedY = (rand() % (y + ((y1 - y) + 1))) *0.01;
		float speedZ = (rand() % (z + ((z1 - z) + 1)))*0.01;
		int RandX = rand() % 2;
		int RandY = rand() % 2;
		int RandZ = rand() % 2;
		RandX == 0 ? speedX : speedX *= -1;
		RandY == 0 ? speedY : speedY *= -1;
		RandZ == 0 ? speedZ : speedZ *= -1;


		m_Color = cVector(colorr, colorg, colorb);
		m_Speed = cVector(speedX, speedY, speedZ);
	}
	void Start()
	{
		m_state = true;
	}
	void End()
	{
		m_state = false;
	}
	bool GetState()
	{
		return m_state;
	}
public:
	void Update(float time);
	void Render();
};

#endif