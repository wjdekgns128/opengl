#ifndef __CFLOOR_H
#define __CFLOOR_H
#include "cBaseObject.h"
#include "cStartObject.h"
#include "cWallObject.h"
#include "cHardWallObject.h"
#include "cEmptyObject.h"
#include "cEndObject.h"
#include "cParticleBase.h"
#include "cPortalObject.h"
class cFloor
{
private:
	cParticleBase*		m_pParticleBase[5][5];
	cBaseObject*		m_pObject[5][5]; //x,z
	int					m_mynumber;


	int					m_Angle;
	int					m_RealAngle; 
	bool				m_AngleCheck;//회전가능한층인지 확인

	int					m_BoomType;
	bool				m_Moveing;
public:
	cFloor(int num);
	~cFloor();
public:
	void Render();
	void Update(float time);
	bool RotatedFloor(); //한층회전
	void RotatedSetting(); // 회전후 정리
	void SetBoomType(int _Type)
	{
		m_BoomType = _Type;
	}
	int GetBoomType()
	{
		return m_BoomType;
	}
	cBaseObject* GetBaseObject(int x, int z)
	{
		return m_pObject[x][z];
	}
public:
	void SettingTo(int x ,int z)
	{
		cPortalObject* temp = (cPortalObject*)m_pObject[x][z];
		temp->m_Moveing = false;
		m_Moveing = false;
	}
	void Openning()
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				m_pObject[i][j]->SettingOpenning();
			}
		}
	}
	void SettingObject(int x, int z, int type);
	void ReSetting()
	{
		m_Angle = 0;
		m_RealAngle = 0;
		m_AngleCheck = true;
		m_BoomType = 0;
		m_Moveing = true;

	}
public:
	int GetType(int x, int z)
	{
		return m_pObject[x][z]->GetType();
	}
	void PrintfFloorType()
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				printf("%d ", m_pObject[i][j]->GetType());
			}
			printf("\n");
		}
	}
};
#endif