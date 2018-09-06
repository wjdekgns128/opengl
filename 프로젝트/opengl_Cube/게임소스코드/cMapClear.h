#ifndef _CMAPCLEAR_H
#define _CMAPCLEAR_H
#include <stdio.h>
#include <vector>
#include <io.h>
#include <stdlib.h>
#include "cMyDefine.h"
#include "cVector.h"
using namespace std;

#define GETCLEAR (cMapClear::GetInstance())

class cMapClear
{
private:
	vector<int>		m_vSaveData; // 클리어횟수
	int				m_LoadCheck;
	string			m_Fname;
public:
	cMapClear()
	{
		m_LoadCheck = false;
	}
	~cMapClear()
	{
		;
	}
	
	void Load(); //  없으면 0으로초기화후 생성
	void Save();
	
	static cMapClear* GetInstance()
	{
		static cMapClear _instance;
		return &_instance;
	}

	int GetClearCount(int number)
	{
		return m_vSaveData[number];
	}
	void SetClearCount(int number, int temp)
	{
		m_vSaveData[number] = temp;
	}
	string GetPathName()
	{
		return m_Fname;
	}
};

#endif